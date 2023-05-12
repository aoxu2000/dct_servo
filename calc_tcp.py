import math3d as m3d
import numpy as np

T = np.array([[1, 0, 0, 0],
              [0, 0, -1, 0],
              [0, 1, 0, 200],
              [0, 0, 0, 1]])

t_m3d = m3d.Transform(T)
print(t_m3d.pose_vector)
