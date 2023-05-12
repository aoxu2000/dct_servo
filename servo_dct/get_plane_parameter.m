function plame_para = get_plane_parameter(T_w_x, T_w_visual_target)
%% 利用坐标变换求平面参数 A B C
% T_w_x：相机相对于世界坐标系的位姿
% T_w_visual_target：目标相对于世界坐标系的位姿
%%
T = TransInv(T_w_x) * T_w_visual_target;
[R, P] = TransToRp(T);
plame_para = R(:, 3) ./ (R(:, 3)'*P);
%%
% para_right_old = [0, 0, 0.8]';
% R_r_w_old = [0 -1 0; -1 0 0; 0 0 -1]; 
% P_r_w_old = [+9.5875e-07; +2.5000e-02; +1.6000e+00];
% T_r_w_old = RpToTrans(R_r_w_old, P_r_w_old);
% p_w_visual_target_old = [+0.0000e+00; +0.0000e+00; +3.5000e-01];
% R_w_visual_target_old = [1 0 0; 0 1 0; 0 0 1];
% T_w_visual_target_old = RpToTrans(R_w_visual_target_old, p_w_visual_target_old);
% plame_para = ([para_right_old; -1]' * TransInv(T_r_w_old) * T_w_x)';
% plame_para = T_w_visual_target_old * TransInv(T_w_visual_target) * plame_para;
% plame_para = plame_para(1:3) / (-plame_para(4));
end