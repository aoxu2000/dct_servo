function [res,thetalise] = get_vrep_Joint_angle(vrep, clientID, MotorHandle_Arm_joints)
%% 读取vrep中机械臂关节角度
thetalise = zeros(6,1);        
[res_1, thetalise(1)] = vrep.simxGetJointPosition(clientID,MotorHandle_Arm_joints(1),vrep.simx_opmode_oneshot_wait);
[res_2, thetalise(2)] = vrep.simxGetJointPosition(clientID,MotorHandle_Arm_joints(2),vrep.simx_opmode_oneshot_wait);
[res_3, thetalise(3)] = vrep.simxGetJointPosition(clientID,MotorHandle_Arm_joints(3),vrep.simx_opmode_oneshot_wait);
[res_4, thetalise(4)] = vrep.simxGetJointPosition(clientID,MotorHandle_Arm_joints(4),vrep.simx_opmode_oneshot_wait);
[res_5, thetalise(5)] = vrep.simxGetJointPosition(clientID,MotorHandle_Arm_joints(5),vrep.simx_opmode_oneshot_wait);
[res_6, thetalise(6)] = vrep.simxGetJointPosition(clientID,MotorHandle_Arm_joints(6),vrep.simx_opmode_oneshot_wait);
res = res_1 + res_2 + res_3 + res_4 + res_5 + res_6;
end