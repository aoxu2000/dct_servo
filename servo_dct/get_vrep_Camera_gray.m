function [res, resolution_gray, image_gray] = get_vrep_Camera_gray(vrep, clientID, VisionHandle_camera)
%% ��ȡ���VisionHandle_camera��rgbͼ��
[res, resolution_rgb, image_rgb] = get_vrep_Camera_rgb(vrep, clientID, VisionHandle_camera);
resolution_gray = resolution_rgb;
image_gray = rgb2gray(image_rgb);
end