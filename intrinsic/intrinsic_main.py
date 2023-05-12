import time
from intrinsic import calc
import cv2
import math3d as m3d
import urx
from vidcap import VideoCapture, us_crop


def main():
    # init ur, *** using urx SW3.5 branch ***
    IP_ROBOT = '192.168.10.106'
    rob = urx.Robot(IP_ROBOT, True)
    print('ur connected')

    rob.set_pose(m3d.Transform([-0.046, 0.680, -0.030, 2.795, -2.310, 2.175]), acc=0.01, vel=0.01)
    print('ur set to initial pose')

    # init camera
    vid = VideoCapture(0)

    # 2) workflow
    img1 = vid.read()
    img1 = us_crop(img1)
    cv2.imwrite('intrinsic/img1.png', img1)

    dist = 0.005

    pose = rob.get_pose().pose_vector
    pose[2] -= dist
    rob.set_pose(m3d.Transform(pose))

    img2 = vid.read()
    img2 = us_crop(img2)
    cv2.imwrite('intrinsic/img2.png', img2)

    # 3) calc
    calc(img1, img2, dist)


if __name__ == '__main__':
    main()
