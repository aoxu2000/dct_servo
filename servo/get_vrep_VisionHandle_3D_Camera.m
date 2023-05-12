function [res, VisionHandle_Camera_old, VisionHandle_Camera_new] = get_vrep_VisionHandle_3D_Camera(vrep, clientID)
%% 获取图像矩视觉伺服仿真vrep中的相机句柄
% depth camera old
[res_1,VisionHandle_Camera_old] = vrep.simxGetObjectHandle(clientID,'depth_rgb_old',vrep.simx_opmode_blocking);
[res_2,VisionHandle_Camera_new] = vrep.simxGetObjectHandle(clientID,'depth_rgb_new',vrep.simx_opmode_blocking);
% 验证相机句柄是否读取成果
res = res_1 + res_2;
if res == 0
    % depth buffer
    vrep.simxGetVisionSensorDepthBuffer2(clientID,VisionHandle_Camera_old,vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorDepthBuffer2(clientID,VisionHandle_Camera_new,vrep.simx_opmode_streaming);
    % sensor image
    vrep.simxGetVisionSensorImage2(clientID,VisionHandle_Camera_old,0,vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorImage2(clientID,VisionHandle_Camera_new,0,vrep.simx_opmode_streaming);
end
end