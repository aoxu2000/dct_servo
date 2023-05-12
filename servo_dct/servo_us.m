function Sc = servo_us(pose, image_gray_new, Para_Camera_Intrinsic, image_gray_target, I_z)

pose = pose';
T_w_nb = [MatrixExp3(VecToso3(pose(4:6))), pose(1:3); 0 0 0 1];

% image_gray_target_norm = get_image_gray_norm(image_gray_target);
image_gray_new_norm = get_image_gray_norm(image_gray_new);
% image_gray_new_norm_init = get_image_gray_norm(image_gray_new);
image_gray_old_norm = get_image_gray_norm(image_gray_target);
% order_min = 4;
% order_max = 8;
order = 50

[error_s, L_e] = get_FeaturesError_InteractionMatrix_DCT_Adaption(...
                        image_gray_new_norm, image_gray_old_norm, ...
                        Para_Camera_Intrinsic, I_z, order);

Bc = -1 * pinv(L_e) * error_s;

% Bc(3) = Bc(3) * 3; 

Sc = [T_w_nb(1:3,1:3) * Bc(1:3); T_w_nb(1:3,1:3) * Bc(4:6)];

e = mean(abs(error_s));

Sc = [Sc; e];

disp(e)
    









