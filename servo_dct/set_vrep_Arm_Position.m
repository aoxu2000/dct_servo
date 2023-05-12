function set_vrep_Arm_Position(vrep, clientID, MotorHandle_Arm_joint, thetalist)
%% 设置机械臂关节位置 (单位：rad)
vrep.simxPauseCommunication(clientID,1);
vrep.simxSetJointTargetPosition(clientID,MotorHandle_Arm_joint(1,1),thetalist(1),vrep.simx_opmode_oneshot);
vrep.simxSetJointTargetPosition(clientID,MotorHandle_Arm_joint(2,1),thetalist(2),vrep.simx_opmode_oneshot);
vrep.simxSetJointTargetPosition(clientID,MotorHandle_Arm_joint(3,1),thetalist(3),vrep.simx_opmode_oneshot);
vrep.simxSetJointTargetPosition(clientID,MotorHandle_Arm_joint(4,1),thetalist(4),vrep.simx_opmode_oneshot);
vrep.simxSetJointTargetPosition(clientID,MotorHandle_Arm_joint(5,1),thetalist(5),vrep.simx_opmode_oneshot);
vrep.simxSetJointTargetPosition(clientID,MotorHandle_Arm_joint(6,1),thetalist(6),vrep.simx_opmode_oneshot);
vrep.simxPauseCommunication(clientID,0);
end