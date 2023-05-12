function [res, resolution_rgb, image_rgb] = get_vrep_Camera_rgb(vrep, clientID, VisionHandle_camera)
%% 获取相机VisionHandle_camera的rgb图像
[res, resolution_rgb, image_rgb]= ...
    vrep.simxGetVisionSensorImage2(clientID, VisionHandle_camera,0,vrep.simx_opmode_blocking); % vrep.simx_opmode_blocking  vrep.simx_opmode_buffer
end