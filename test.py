import numpy as np

imgs = np.ones([3, 4, 4])
image = 2 * np.ones([4,4])
imgs[0] = image
# img = np.expand_dims(image, axis=0)
# imgs = np.concatenate((imgs, img), axis=0)


# # [H, W] = imgs.shape
# # print(H)
# img_0 = 2 * imgs
# img_1 = 3 * imgs[1]
# img_2 = 4 * imgs[2]
# print(img_0)
# move_vector = [0.001, 0.001, 0.001, 0, 0, 0]
# a = (move_vector[2] * np.ones([3, 1])).squeeze(axis=1)
# images = [1,2,3,4]
#
# print(images[-2])
print(imgs)
# print(img_0)
# for i in range(4):
#     print(i)