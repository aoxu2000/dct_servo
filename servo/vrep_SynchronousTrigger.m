function vrep_SynchronousTrigger(vrep, clientID)
%% 触发vrep与matlab同步
vrep.simxGetPingTime(clientID);
vrep.simxSynchronousTrigger(clientID);
end