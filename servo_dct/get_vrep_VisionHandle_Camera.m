function [res, MotorHandle_Arm_Right_camera, MotorHandle_Arm_Left_camera, MotorHandle_Vehicle_camera] = get_vrep_VisionHandle_Camera(vrep, clientID)
%% 获取各相机句柄 
% 1: depth  2: rgb
MotorHandle_Arm_Right_camera = zeros(2,1); 
MotorHandle_Arm_Left_camera = zeros(2,1);
MotorHandle_Vehicle_camera = zeros(2,1);
% depth camera
[res_1,MotorHandle_Arm_Right_camera(1)] = vrep.simxGetObjectHandle(clientID,'kinect_depth',vrep.simx_opmode_blocking);
[res_2,MotorHandle_Arm_Left_camera(1)] = vrep.simxGetObjectHandle(clientID,'kinect_depth#0',vrep.simx_opmode_blocking);
[res_3,MotorHandle_Vehicle_camera(1)] = vrep.simxGetObjectHandle(clientID,'kinect_depth#1',vrep.simx_opmode_blocking);
% rgb camera
[res_4,MotorHandle_Arm_Right_camera(2)] = vrep.simxGetObjectHandle(clientID,'kinect_rgb',vrep.simx_opmode_blocking);
[res_5,MotorHandle_Arm_Left_camera(2)] = vrep.simxGetObjectHandle(clientID,'kinect_rgb#0',vrep.simx_opmode_blocking);
[res_6,MotorHandle_Vehicle_camera(2)] = vrep.simxGetObjectHandle(clientID,'kinect_rgb#1',vrep.simx_opmode_blocking);
res = res_1 + res_2 + res_3 + res_4 + res_5 + res_6;

if res == 0
    % depth buffer
    vrep.simxGetVisionSensorDepthBuffer2(clientID,MotorHandle_Arm_Right_camera(1),vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorDepthBuffer2(clientID,MotorHandle_Arm_Left_camera(1),vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorDepthBuffer2(clientID,MotorHandle_Vehicle_camera(1),vrep.simx_opmode_streaming);
    % sensor image
    vrep.simxGetVisionSensorImage2(clientID,MotorHandle_Arm_Right_camera(2),0,vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorImage2(clientID,MotorHandle_Arm_Left_camera(2),0,vrep.simx_opmode_streaming);
    vrep.simxGetVisionSensorImage2(clientID,MotorHandle_Vehicle_camera(2),0,vrep.simx_opmode_streaming);
end

end