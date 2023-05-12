function T_w_camera_next = servo_step(vrep, clientID, VisionHandle_Vision_new, ...
    image_gray_old_norm, Para_Camera_Intrinsic, T_b_v)
    
%% 准备
% 记录时间
% 记录当前摄像头位姿
[~, T_w_nb] = get_Object_Transform(vrep, clientID, VisionHandle_Vision_new, -1);
% 读取当前灰度图和深度图
[~, ~, image_gray_new] = get_vrep_Camera_gray(vrep, clientID, VisionHandle_Vision_new);
image_gray_new_norm = get_image_gray_norm(image_gray_new);
[~, ~, image_depth_new] = get_vrep_Camera_depth(vrep, clientID, VisionHandle_Vision_new);
% 计算当前相机坐标系下的平面参数
%     [res, T_vision_target] = get_Object_Transform(vrep, clientID, VisionHandle_visual_target, VisionHandle_Vision_new);
%     planar_parameter_new = get_planar_parameter_new(T_vision_target, R_world_VisualTarget);
%% 计算特征误差和交互矩阵
[error_s, L_e] = get_FeaturesError_InteractionMatrix_DVS(...
                    image_gray_new_norm, image_gray_old_norm, ...
                    Para_Camera_Intrinsic, image_depth_new);
% 计算摄像头速度
Vc = -20  * pinv(L_e) * error_s;   
% 
% %% 相机运动
% % 计算下一时刻摄像头速度旋量及位姿
% Sc = Vc * 0.2; 
% T_next = [MatrixExp3(VecToso3(Sc(4:6))), Sc(1:3); 0 0 0 1];
% % 下一时刻摄像头位姿
% T_w_nb_next = T_w_nb * T_next;
% % 下一时刻相机位姿
% T_w_camera_next = T_w_nb_next * TransInv(T_b_v);



%% 相机运动
% 计算下一时刻摄像头速度旋量及位

% camera
Bc = 0.2 * Vc;
% Bc = [0; 0; 0; 0.05; 0; 0];
% Bc = [0; 0; 0; 0.1; 0; 0]


T_next = [MatrixExp3(VecToso3(Bc(4:6))), Bc(1:3); 0 0 0 1];
% 下一时刻摄像头位姿

T_w_nb_next = T_w_nb * T_next;

T_w_next_tip = T_w_nb_next * TransInv(T_b_v);

T_w_tip = T_w_nb * TransInv(T_b_v);


% -------------------------------------------------------

% R = T_w_tip(1:3, 1:3)' * T_w_next_tip(1:3, 1:3);

[w_old, theta_old] = AxisAng3(so3ToVec(MatrixLog3(T_w_tip(1:3, 1:3))));
%
[w_new, theta_new] = AxisAng3(so3ToVec(MatrixLog3(T_w_next_tip(1:3, 1:3))));


% -------------------------------------------------------

% [w, theta] = AxisAng3(so3ToVec(MatrixLog3(R)));

t = T_w_next_tip(1:3, 4) - T_w_tip(1:3, 4);
% VecToso3(w * theta)*(T_w_nb_next(1:3, 4) - T_w_nb(1:3, 4));

Sc = [t; theta_new * w_new - theta_old * w_old];



T_w_camera_next = T_w_next_tip


end