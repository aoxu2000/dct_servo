function [res, VisionHandle_Arm_Right_camera_old, VisionHandle_Arm_Left_camera_old, VisionHandle_Arm_Right_camera_new, ...
    VisionHandle_Arm_Left_camera_new] = get_vrep_VisionHandle_Camera_ImageMoment(vrep, clientID)
%% 获取图像矩视觉伺服仿真vrep中的相机句柄
VisionHandle_Arm_Right_camera_old = zeros(2,1); 
VisionHandle_Arm_Left_camera_old = zeros(2,1);
VisionHandle_Arm_Right_camera_new = zeros(2,1); 
VisionHandle_Arm_Left_camera_new = zeros(2,1);
% depth camera old
[res_1,VisionHandle_Arm_Right_camera_old(1)] = vrep.simxGetObjectHandle(clientID,'kinect_right_depth',vrep.simx_opmode_blocking);
[res_2,VisionHandle_Arm_Left_camera_old(1)] = vrep.simxGetObjectHandle(clientID,'kinect_left_depth',vrep.simx_opmode_blocking);
% rgb camera old
[res_3,VisionHandle_Arm_Right_camera_old(2)] = vrep.simxGetObjectHandle(clientID,'kinect_right_rgb',vrep.simx_opmode_blocking);
[res_4,VisionHandle_Arm_Left_camera_old(2)] = vrep.simxGetObjectHandle(clientID,'kinect_left_rgb',vrep.simx_opmode_blocking);
% depth camera new
[res_5,VisionHandle_Arm_Right_camera_new(1)] = vrep.simxGetObjectHandle(clientID,'kinect_new_right_depth',vrep.simx_opmode_blocking);
[res_6,VisionHandle_Arm_Left_camera_new(1)] = vrep.simxGetObjectHandle(clientID,'kinect_new_left_depth',vrep.simx_opmode_blocking);
% rgb camera new
[res_7,VisionHandle_Arm_Right_camera_new(2)] = vrep.simxGetObjectHandle(clientID,'kinect_new_right_rgb',vrep.simx_opmode_blocking);
[res_8,VisionHandle_Arm_Left_camera_new(2)] = vrep.simxGetObjectHandle(clientID,'kinect_new_left_rgb',vrep.simx_opmode_blocking);
% 验证相机句柄是否读取成果
res = res_1 + res_2 + res_3 + res_4 + res_5 + res_6 + res_7 + res_8;
if res == 0
    % depth buffer
    vrep.simxGetVisionSensorDepthBuffer2(clientID,VisionHandle_Arm_Right_camera_old(1),vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorDepthBuffer2(clientID,VisionHandle_Arm_Left_camera_old(1),vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorDepthBuffer2(clientID,VisionHandle_Arm_Right_camera_new(1),vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorDepthBuffer2(clientID,VisionHandle_Arm_Left_camera_new(1),vrep.simx_opmode_streaming);
    % sensor image
    vrep.simxGetVisionSensorImage2(clientID,VisionHandle_Arm_Right_camera_old(2),0,vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorImage2(clientID,VisionHandle_Arm_Left_camera_old(2),0,vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorImage2(clientID,VisionHandle_Arm_Right_camera_new(2),0,vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorImage2(clientID,VisionHandle_Arm_Left_camera_new(2),0,vrep.simx_opmode_streaming);
end


end