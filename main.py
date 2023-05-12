import urx
import math3d as m3d
import matlab
import matlab.engine
import cv2
import numpy as np
import copy
from vidcap import VideoCapture


def main():
    # 1) init
    # init ur, *** using urx SW3.5 branch ***
    IP_ROBOT = '192.168.3.124'
    rob = urx.Robot(IP_ROBOT, True)
    print('ur connected')

    # rob.set_pose(m3d.Transform([0.5334, 0.2121, 0, 2.41, -2.41, 2.45]), acc=0.01, vel=0.01)
    pose_base_origin = rob.get_pose()
    rob.set_pose(pose_us2base(pose_base_origin, m3d.Transform([0.005, -0.005, 0.005, 0.02, -0.02, 0.02])), acc=0.01, vel=0.01)
    print('ur set to initial pose')

    # init camera
    vid = VideoCapture(0)
    k = np.array([[8000, 0, 200], [0, 8000, 200], [0, 0, 1]])

    # init matlab
    engine = matlab.engine.start_matlab('MATLAB_R2022b')
    engine.cd('servo', nargout=0)
    print('matlab loaded')

    # target
    target = cv2.imread('target.png')
    cv2.imshow('Target', target)
    cv2.waitKey(100)
    target = cv2.cvtColor(target, cv2.COLOR_BGR2GRAY)

    # servo
    while True:

        img = vid.read()
        # img = cv2.GaussianBlur(img, (5, 5), 1)

        cv2.imshow('Servo', img)
        cv2.waitKey(10)

        pose0 = rob.get_pose().pose_vector

        # scan
        print('scanning')

        dist = 1  # mm
        imgs = scan(rob, vid, dist=dist)

        ret = np.array(engine.test_of_servo(matlab.double(pose0.tolist()),
                                            matlab.double(imgs.tolist()),
                                            matlab.double(dist),
                                            matlab.double(k.tolist()),
                                            matlab.double(target.tolist())))

        v = 0.0001 * ret[0:6]
        print(v)

        for vi in v:
            if vi > 0.02:
                continue

        rob.speedl(v.squeeze(axis=1), acc=0.01, min_time=0.2)
        # rob.set_pose(m3d.Transform(v), acc=0.01, vel=0.01)

        # if e < ...:
        #     break

    engine.quit()
    del vid
    # rob.set_pose(m3d.Transform([-0.085, 0.731, 0.231, 0.1132, -3.1387, 0.0325]), acc=0.01, vel=0.01)
    rob.close()


def scan(rob, vid, k=5, dist=1):
    """

    :param rob:
    :param vid:
    :param k: images
    :param dist: mm
    :return:
    """

    zs = np.arange(-(k // 2), (k // 2) + 1, dist, dtype=int) / 1000
    imgs = np.zeros([0, 400, 400])
    pose_base_origin = rob.get_pose()
    for z in zs:
        pose_us = m3d.Transform([0, 0, z, 0, 0, 0])
        pose_base = pose_us2base(pose_base_origin, pose_us)
        rob.set_pose(pose_base)
        img = np.expand_dims(vid.read(), axis=0)
        imgs = np.concatenate((imgs, img), axis=0)

    rob.set_pose(pose_base_origin)

    ret_imgs = np.array([imgs[2], imgs[0], imgs[1], imgs[3], imgs[4]])
    ret_imgs = np.reshape(ret_imgs, [400, 400, 5])

    return ret_imgs


def pose_us2base(pose_base_origin: m3d.transform.Transform, pose_us) -> m3d.transform.Transform:
    """
    :return: math3d obj
    """
    pose_base = pose_base_origin * pose_us
    return pose_base


if __name__ == '__main__':
    main()
