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
    IP_ROBOT = '192.168.10.103'
    rob = urx.Robot(IP_ROBOT, True)
    print('ur connected')

    rob.set_pose(m3d.Transform([0.5334, 0.2121, 0.235, 2.41, -2.41, 2.45]), acc=0.1, vel=0.1)
    print('ur set to initial pose1')

    time.sleep(1)

    rob.set_pose(m3d.Transform([0.533, 0.2123, -0.002, 2.41, -2.41, 2.45]), acc=0.02, vel=0.02)
    print('ur set to initial pose2')

    pose_orig_base = rob.get_pose()

    time.sleep(5)

    # set range of 6 axis
    PI = 3.14
    x = 0.0015  # 2mm
    y = 0.0015  # 1 cm
    z = 0.0015  # 0.5 cm
    rx = PI / 360
    ry = PI / 360
    rz = PI / 360
    np.random.seed(int(time.time()))

    for i in range(10):
        _x = np.random.uniform(-(x / 2), x / 2)
        _y = np.random.uniform(-(y / 2), y / 2)
        _z = np.random.uniform(-(z / 2), z / 2)
        _rx = np.random.uniform(-(rx / 2), rx / 2)
        _ry = np.random.uniform(-(ry / 2), ry / 2)
        _rz = np.random.uniform(-(rz / 2), rz / 2)

        pose0_tcp = [_x, _y, _z, _rx, _ry, _rz]  # pose0 in origin csys
        print(pose0_tcp)

        pose_new_base = pose_tcp2base(pose_orig_base, pose0_tcp)
        shift(rob, pose_new_base)


def shift(rob, pose_new_base):
    dzs = np.array([0, 0.2, 0.4]) / 1000  # 0.1 mm as step
    for i, dz in enumerate(dzs):
        pose_tcp = [0, 0, dz, 0, 0, 0]
        pose_base = pose_tcp2base(pose_new_base, pose_tcp)
        rob.set_pose(m3d.Transform(pose_base), acc=0.02, vel=0.02)


def pose_tcp2base(pose_base_org, pose_tcp):
    return pose_base_org * m3d.Transform(pose_tcp)


if __name__ == '__main__':
    main()
