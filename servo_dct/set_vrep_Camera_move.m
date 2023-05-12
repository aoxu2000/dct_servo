function res = set_vrep_Camera_move(vrep, clientID, objectHandle, relativeToObjectHandle, T)
%% 移动vrep中objectHandle的位姿
% 确定位移和欧拉角
[R_ob_nb, p_ob_nb] = TransToRp(T);
eul_ob_nb = rotm2eul(R_ob_nb,'XYZ');
% 移动
vrep.simxPauseCommunication(clientID,1);
vrep.simxSetObjectPosition(clientID, objectHandle, relativeToObjectHandle, p_ob_nb, vrep.simx_opmode_oneshot); % vrep.simx_opmode_blocking  vrep.simx_opmode_oneshot
vrep.simxSetObjectOrientation(clientID, objectHandle, relativeToObjectHandle, eul_ob_nb, vrep.simx_opmode_oneshot);% vrep.simx_opmode_blocking  vrep.simx_opmode_oneshot
vrep.simxPauseCommunication(clientID,0);
end



% % vrep左右相机及基座相对于世界坐标系的位姿
% P_r_w_o = [+9.5875e-07; +2.5000e-02; +1.6000e+00];
% P_l_w_o = [+9.5363e-07; -2.5000e-02; +1.6000e+00];
% P_b_w_o = [+1.0151e-06; -7.4985e-03; +1.6150e+00];
% R_r_w_o = rotx(+1.8000e+02) * roty(+1.2522e-06) * rotz(+9.0000e+01);
% R_l_w_o = rotx(+1.8000e+02) * roty(+1.2522e-06) * rotz(+9.0000e+01);
% R_b_w_o = rotx(+0.0000e+00) * roty(-9.0000e+01) * rotz(+1.8000e+02);
% P_r_w_n = [+2.6303e-01; +5.1174e-01; +2.0878e+00];
% P_l_w_n = [+2.3532e-01; +4.7584e-01; +2.1088e+00];
% P_b_w_n = [+2.5000e-01; +4.9250e-01; +2.1150e+00];
% R_r_w_n = rotx(+1.6318e+02) * roty(-1.9400e+01) * rotz(+1.2600e+02);
% R_l_w_n = rotx(+1.6318e+02) * roty(-1.9400e+01) * rotz(+1.2600e+02);
% R_b_w_n = rotx(-8.2249e+01) * roty(-4.9741e+01) * rotz(+1.2093e+02);
% T_r_w_o = [R_r_w_o, P_r_w_o; 0, 0, 0, 1];
% T_l_w_o = [R_l_w_o, P_l_w_o; 0, 0, 0, 1];
% T_b_w_o = [R_b_w_o, P_b_w_o; 0, 0, 0, 1];
% T_r_w_n = [R_r_w_n, P_r_w_n; 0, 0, 0, 1];
% T_l_w_n = [R_l_w_n, P_l_w_n; 0, 0, 0, 1];
% T_b_w_n = [R_b_w_n, P_b_w_n; 0, 0, 0, 1];
% % 相机摄像头相对于基座
% T_b_o_n = TransInv(T_b_w_o) * T_b_w_n;
% % 摄像头相对位姿(期望)T_o_n
% T_r_o_n = TransInv(T_r_w_o) * T_r_w_n;
% T_l_o_n = TransInv(T_l_w_o) * T_l_w_n;