import urx
import math3d as m3d
import matlab
import matlab.engine
import cv2
import numpy as np
import copy
from vidcap import VideoCapture
import time

def main():
    # 1) init
    # init ur, *** using urx SW3.5 branch ***
    IP_ROBOT = '192.168.3.124'
    rob = urx.Robot(IP_ROBOT, True)
    print('ur connected')

    # init camera
    vid = VideoCapture(0)
    k = np.array([[8000, 0, 200], [0, 8000, 200], [0, 0, 1]])

    folder = 'servo_dct'
    # folder = 'servo'

    # init matlab
    engine = matlab.engine.start_matlab('MATLAB_R2022b')
    engine.cd(folder, nargout=0)
    print('matlab loaded')

    # target
    target = cv2.imread('target.png')
    cv2.imshow('Target', target)
    cv2.waitKey(100)
    target = cv2.cvtColor(target, cv2.COLOR_BGR2GRAY)

    # cv2.namedWindow("Servo", cv2.WINDOW_NORMAL)

    # rob.set_pose(m3d.Transform([0.406, 0.226, 0.025, 2.45, 2.45, -2.34]), acc=0.05, vel=0.05)
    # print('ur set to initial pose1')
    #
    # time.sleep(1)
    #
    # rob.set_pose(m3d.Transform([0.409, 0.221, -0.007, 2.45, 2.45, -2.34]), acc=0.05, vel=0.05)
    # print('ur set to initial pose2')
 
    # open-loop control process
    move_vector = [0.0002, 0.0002, -0.0002, 0, 0, 0]
    dx = move_vector[0] * np.ones(target.shape)
    dy = move_vector[1] * np.ones(target.shape)
    window_size = 7
    epsidon = 0.9
    print("start open-loop control process")
    phi, Y, theta, images = openlp(rob, vid, k, engine, window_size=window_size, move_vector=move_vector, epsidon=epsidon)
    print("finish open-loop control process")

    image_ind = 0
    while True:

        img = vid.read()
        cv2.imshow('Servo', img)
        cv2.waitKey(1)

        # update images
        image = np.expand_dims(img, axis=0)
        images = np.concatenate((images, image), axis=0)

        # update Y
        Yl = np.array(engine.get_Y(matlab.double(images[-1].tolist()),
                                    matlab.double(images[-2].tolist()),
                                    matlab.double(dx.tolist()),
                                    matlab.double(dy.tolist()),
                                    matlab.double(k.tolist())))
        Yl = np.expand_dims(Yl, axis=0)
        Y = np.concatenate((Y, Yl), axis=0)

        # estimate theta
        R = np.zeros(img.shape)
        Q = np.zeros(img.shape)
        thetal = np.zeros(img.shape)
        for i in range(window_size):
            R = R + np.power(epsidon, window_size - 1 - i) * np.multiply(phi[i - window_size], phi[i - window_size])
            Q = Q + np.power(epsidon, window_size - 1 - i) * np.multiply(phi[i - window_size], Y[i - window_size])
        for i in range(img.shape[0]):
            for j in range(img.shape[1]):
                if R[i, j] > np.power(0.00001, 2):
                    thetal[i, j] = Q[i, j] / R[i, j]
                else:
                    thetal[i, j] = theta[-1][i, j]
        thetal = np.expand_dims(thetal, axis=0)
        theta = np.concatenate((theta, thetal), axis=0)

        # servo step
        pose0 = rob.get_pose()
        v = np.array(engine.servo_us(matlab.double(pose0.pose_vector.tolist()),
                                       matlab.double(img.tolist()),
                                       matlab.double(k.tolist()),
                                       matlab.double(target.tolist()),
                                       matlab.double(theta[-1])))

        e = v[6]
        v = v[0:6].squeeze(axis=1)

        if folder == 'servo' :
            v *= 5
        elif folder == 'servo_dct':
            v *= 40
        print(v)

        for i, vi in enumerate(v):
            if vi > 0.02 and i < 3:
                print('continued')
                continue
        rob.speedl(v, acc=0.02, min_time=1)

        pose1 = rob.get_pose()

        # T = np.dot(np.linalg.inv(pose0.array), pose1.array)
        T = np.dot(np.linalg.inv(pose0.array), pose1.array - pose0.array)

        # update phi
        ret = np.array(engine.get_phil(matlab.double(T.tolist()),
                                      matlab.double(img.tolist()),
                                      matlab.double(k.tolist())))
        dx = ret[0:400, :]
        dy = ret[400:800, :]
        phil = ret[800:1200, :]

        phil = np.expand_dims(phil, axis=0)
        phi = np.concatenate((phi, phil), axis=0)

        # save images
        cv2.imwrite(f'images/{image_ind}-{e}.png', img)
        image_ind += 1

        if e < 0.02:
            break

    time.sleep(30)
    engine.quit()
    del vid
    # rob.set_pose(m3d.Transform([-0.173, 0.601, -0.028, 2.96, -2.18, 2.24]), acc=0.01, vel=0.01)
    rob.close()


def openlp(rob, vid, intrinsic_matrix, engine, window_size=3, move_vector=[0.001, 0.001, 0.001, 0, 0, 0], epsidon = 0.9):
    """
    Args:
        rob:
        vid:
        window_size:
        intrinsic_matrix:
        move_vector:

    Returns:

    """
    img_0 = vid.read()
    [H, W] = img_0.shape
    imgs = np.zeros([window_size + 1, H, W])
    imgs[0] = img_0
    Y = np.zeros([window_size + 1, H, W])
    theta = np.zeros([window_size + 1, H, W])
    phi = np.zeros([window_size + 1, H, W])

    for i in range(window_size):
        pose_base_origin = rob.get_pose()
        pose_us = m3d.Transform(move_vector)
        pose_base = pose_us2base(pose_base_origin, pose_us)
        rob.set_pose(pose_base)
        imgs[i+1] = vid.read()
        Y[i+1] = np.array(engine.openlp(matlab.double(imgs[i+1].tolist()),
                                                  matlab.double(imgs[i].tolist()),
                                                  matlab.double(move_vector),
                                                  matlab.double(intrinsic_matrix.tolist())))
        phi[i+1] = move_vector[2] * np.ones([H, W])

    pose_base_origin = rob.get_pose()
    pose_us = m3d.Transform(move_vector)
    pose_base = pose_us2base(pose_base_origin, pose_us)
    rob.set_pose(pose_base)

    return phi, Y, theta, imgs

def pose_us2base(pose_base_origin: m3d.transform.Transform, pose_us) -> m3d.transform.Transform:
    """
    :return: math3d obj
    """
    pose_base = pose_base_origin * pose_us
    return pose_base


if __name__ == '__main__':
    main()
