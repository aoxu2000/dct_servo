function [res, resolution_depth, image_depth] = get_vrep_Camera_depth(vrep, clientID, VisionHandle_camera)
%% 获取相机VisionHandle_camera的depth图像
[res, resolution_depth, image_depth_temp]= vrep.simxGetVisionSensorDepthBuffer2(clientID,VisionHandle_camera,vrep.simx_opmode_blocking);  % vrep.simx_opmode_blocking  vrep.simx_opmode_buffer
% image_depth = image_depth_temp;
Far = 10;
Near = 0.01;
image_depth = (Far - Near) * double(image_depth_temp) + Near;
end

