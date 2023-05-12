function Sc = servo_sp(M, step)
% Sc = servo_sp(pose, image_gray_new, k, image_gray_old, I_z)

coder.extrinsic('quat2axang');
ppose = [pose(7); pose(4:6)]';
A = quat2axang(ppose);
qpose = zeros(6,1);
qpose = [pose(1:3)', A(4) * [A(1:3)]]';
T_w_nb = [MatrixExp3(VecToso3(qpose(4:6))), qpose(1:3); 0 0 0 1];

image_gray_new_norm = get_image_gray_norm(image_gray_new);

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

Sc = [T_w_nb(1:3,1:3) * Bc(1:3); T_w_nb(1:3,1:3) * Bc(4:6)]

end