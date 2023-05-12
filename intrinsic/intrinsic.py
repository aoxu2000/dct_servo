from sift.sift import sift
import numpy as np
from sympy import symbols, Eq, solve


def calc(img1, img2, dist):
    x_norm1 = calc_two_pic(img1, img2)

    print(x_norm1 / dist)

    return


def calc_two_pic(img1, img2, num=3):
    pts1, pts2 = sift(img1, img2, num)
    d_pts = pts1 - pts2

    # mean first
    x_mean = d_pts[:, 0].mean()
    y_mean = d_pts[:, 1].mean()
    norm = np.linalg.norm([x_mean, y_mean], axis=0)
    return norm
