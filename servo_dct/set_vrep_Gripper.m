function set_vrep_Gripper(vrep, clientID, MotorHandle_gripper, force_gripper, velocity_gripper, flag)
%% ¿ØÖÆ¼Ð×¦ÔË¶¯
vrep.simxPauseCommunication(clientID,1);
if(flag == "close")
    vrep.simxSetJointForce (clientID, MotorHandle_gripper, force_gripper, vrep.simx_opmode_oneshot);
    vrep.simxSetJointTargetVelocity(clientID, MotorHandle_gripper, -velocity_gripper, vrep.simx_opmode_oneshot);
elseif (flag == "open")
    vrep.simxSetJointForce (clientID, MotorHandle_gripper, force_gripper, vrep.simx_opmode_oneshot);
    vrep.simxSetJointTargetVelocity(clientID, MotorHandle_gripper,velocity_gripper, vrep.simx_opmode_oneshot);    
end
vrep.simxPauseCommunication(clientID,0);
end