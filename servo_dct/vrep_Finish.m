function vrep_Finish(vrep, clientID)
%% ����vrep����
vrep.simxStopSimulation(clientID,vrep.simx_opmode_oneshot_wait);% simx_opmode_oneshot_wait: ��ʾ�Ұ����ݷ���ȥ֮��Ϳ�ʼִ�к������䣬�����㷢����û
vrep.simxFinish(clientID);% close the connection to V-REP:
vrep.delete(); % call the destructor!
end