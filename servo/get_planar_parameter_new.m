function planar_parameter = get_planar_parameter_new(T, R)
%% 已知平面坐标系相对于视觉坐标系的位姿，计算平面参数
% R为将平面坐标系z轴转动到法方向的旋转矩阵
% 例子：
    % [res, T_world_VisualTarget] = get_Object_Transform(vrep, clientID, VisionHandle_VisualTarget, -1);
    % R_world_VisualTarget = T_world_VisualTarget(1:3, 1:3)';
    % planar_parameter_ReferenceCameraLeftVisual = get_planar_parameter(T_ReferenceCameraLeftVisual_VisualTarget, R_world_VisualTarget);
T(1:3, 1:3) = T(1:3, 1:3) * R;
n = T(1:3, 3);
P0 = T(1:3, 4);
planar_parameter = 1 / (n' * P0) * n;

%% 计算平面参数的导数

end