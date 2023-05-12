function Sc = get_I_z(pose, image_gray_new, k, image_gray_old, I_z)
    
% disp(pose)
% disp(mean(image_gray_new))
% disp(mean(image_gray_old))
% disp(mean(image_depth_new))
% disp(k)

% [imagePoints, boardSize]=detectCheckerboardPoints(image_gray_old)
% J = insertText(image_gray_old,imagePoints,1:size(imagePoints,1));
% J = insertMarker(J,imagePoints,'o','Color','red','Size',5);
% imshow(image_gray_old);
% title(sprintf('Detected a %d x %d Checkerboard',boardSize));

% image_depth_new(image_depth_new==0) = 0.3;
% mean_d = mean(image_depth_new);
% mean_f = mean(mean_d);
% sizea = size(mean_d);
% image_depth_new = mean_f * ones(size(image_depth_new));

% T_b_v = [1, 0, 0, 0.03; 0, 1, 0, 0.05; 0, 0, 1, 0.03; 0, 0, 0, 1];
% extrinsic matrix
% T_b_v = [1, 0, 0, 0; 0, 1, 0, 0; 0, 0, 1, 0; 0, 0, 0, 1];

%% 准备
% 记录时间
% 记录当前摄像头位姿
% [~, T_w_nb] = get_Object_Transform(vrep, clientID, VisionHandle_Vision_new, -1);
% disp(pose)

coder.extrinsic('quat2axang');
ppose = [pose(7); pose(4:6)]';
A = quat2axang(ppose);
qpose = zeros(6,1);
qpose = [pose(1:3)', A(4) * [A(1:3)]]';
T_w_nb = [MatrixExp3(VecToso3(qpose(4:6))), qpose(1:3); 0 0 0 1];

% 读取当前灰度图和深度图

% [~, ~, image_gray_new] = get_vrep_Camera_gray(vrep, clientID, VisionHandle_Vision_new);
image_gray_new_norm = get_image_gray_norm(image_gray_new);
% [~, ~, image_depth_new] = get_vrep_Camera_depth(vrep, clientID, VisionHandle_Vision_new);

k(1, 1) = -k(1, 1);
k(2, 2) = -k(2, 2);
Para_Camera_Intrinsic = k;

image_gray_old_norm = get_image_gray_norm(image_gray_old);
%% 计算特征误差和交互矩阵
[error_s, L_e] = get_FeaturesError_InteractionMatrix_DVS(...
                    image_gray_new_norm, image_gray_old_norm, ...
                    Para_Camera_Intrinsic, I_z);
% 计算摄像头速度
Bc = -3 * pinv(L_e) * error_s; 

%% 相机运动
% 计算下一时刻摄像头速度旋量及位

% camera
% Bc = Vc;
% Bc = [0; 0; 0; 0; 0; 0.05];
% Bc = [0; 0; 0; 0.1; 0; 0]


% T_next = [MatrixExp3(VecToso3(Bc(4:6))), Bc(1:3); 0 0 0 1];
% % 下一时刻摄像头位姿
% 
% T_w_nb_next = T_w_nb * T_next;
% 
% T_w_next_tip = T_w_nb_next * TransInv(T_b_v);
% 
% T_w_tip = T_w_nb * TransInv(T_b_v);

% R = T_w_tip(1:3, 1:3)' * T_w_next_tip(1:3, 1:3);

% [w_old, theta_old] = AxisAng3(so3ToVec(MatrixLog3(T_w_tip(1:3, 1:3))));
%
% [w_new, theta_new] = AxisAng3(so3ToVec(MatrixLog3(T_w_next_tip(1:3, 1:3))));



% coder.extrinsic('dcm2quat');
% q = dcm2quat(T_w_tip(1:3,1:3)); 
% B = quat2axang(q);
% bpose = zeros(6,1);
% bpose = [T_w_tip(1:3,4)', B(4) * [B(1:3)]]';

% bbpose = tr2angvec(T_w_tip)


% qq = dcm2quat(T_w_next_tip(1:3,1:3)); 
% C = quat2axang(qq);
% cpose = zeros(6,1);
% cpose = [T_w_next_tip(1:3,4)', C(4) * [C(1:3)]]';


% [w, theta] = AxisAng3(so3ToVec(MatrixLog3(R)));

% t = T_w_next_tip(1:3, 4) - T_w_tip(1:3, 4);
% VecToso3(w * theta)*(T_w_nb_next(1:3, 4) - T_w_nb(1:3, 4));

Sc = [T_w_nb(1:3,1:3) * Bc(1:3); T_w_nb(1:3,1:3) * Bc(4:6)]
% Sc = [0.01; 0; 0; 0; 0; 0];
% disp(Sc)
% Sc = [Sc(1), Sc(2), Sc(3), 0, 0, 0]

% 下一时刻相机位

end