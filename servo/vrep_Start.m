function vrep_Start(vrep, clientID)
%% ½áÊøvrep·ÂÕæ
vrep.simxSynchronous(clientID, true);
vrep.simxStartSimulation(clientID,vrep.simx_opmode_oneshot);
end