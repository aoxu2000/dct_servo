function T_C = get_camera_new_pose(flag)
%% 得到当前相机位姿 用于开始仿真、
switch flag
    case 'z_translation'
        P_C = [-2.5000e-02; -3.5000e-02; +10.0000e-01];
        R_C = rotx(0) * roty(-90) * rotz(180);



end

T_C = RpToTrans(R_C, P_C);
end