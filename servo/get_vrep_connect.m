function [vrep, clientID] = get_vrep_connect()
%% ����vrep���
vrep=remApi('remoteApi');
vrep.simxFinish(-1); 
clientID=vrep.simxStart('127.0.0.1',19997,true,true,5000,5);
end