function [res, resolution_depth, image_depth, resolution_gray, image_gray] = get_vrep_Camera(vrep, clientID, VisionHandle_camera)
%% 从vrep中读取depth和gray图像
[res_1, resolution_depth, image_depth] = get_vrep_Camera_depth(vrep, clientID, VisionHandle_camera(1));
[res_2, resolution_gray, image_gray] = get_vrep_Camera_gray(vrep, clientID, VisionHandle_camera(2));
res = res_1 + res_2;
end