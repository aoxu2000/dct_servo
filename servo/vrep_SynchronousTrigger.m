function vrep_SynchronousTrigger(vrep, clientID)
%% ����vrep��matlabͬ��
vrep.simxGetPingTime(clientID);
vrep.simxSynchronousTrigger(clientID);
end