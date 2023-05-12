function [T_C, T_O] = CameraPose_Vrep_3D(flag_C, flag_O)
%% 设置Vrep中当前和期望相机的位姿
%% 当前相机
switch flag_C
    case 1 % z轴旋转20°
        P_C = [+1.5000e-01; -4.1000e-01; +2.0000e+00];
        R_C = rotx(-4.2059e+01) * roty(-6.1330e+01) * rotz(+1.2046e+02);
    case 2 % z轴旋转120°
        P_C = [+1.5000e-01; -4.1000e-01; +2.0000e+00];
        R_C = rotx(-7.9101e+01) * roty(+3.4030e+01) * rotz(+1.0707e+02);
    case 3 % y轴旋转20°
        P_C = [+1.5000e-01; -4.1000e-01; +2.0000e+00];
        R_C = rotx(0) * roty(-7.5000e+01) * rotz(+1.8000e+02);     
    case 4 % x轴旋转20°
        P_C = [+1.5000e-01; -4.1000e-01; +2.0000e+00];
        R_C = rotx(-1.1989e+02) * roty(-8.2246e+01) * rotz(+4.1003e+01); 
    otherwise
        disp('其他数值');
end
T_C = RpToTrans(R_C, P_C);
%% 期望相机
switch flag_O
    case 1 % 与平面平行
        P_O = [+2.5000e-01; -1.6000e-01; +1.6150e+00];
        R_O = rotx(0) * roty(-90) * rotz(180);
    case 2 % 与平面不平行
        P_O = [+2.5000e-01; -1.6000e-01; +1.6150e+00];
        R_O = rotx(0) * roty(-7.5000e+01) * rotz(160);  
    otherwise
        disp('其他数值');
end
T_O = RpToTrans(R_O, P_O);
end