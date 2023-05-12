function Sc = test_of_servo(pose, M, step, Para_Camera_Intrinsic, image_gray_target)
% 
% coder.extrinsic('quat2axang');
% ppose = [pose(7); pose(4:6)]';
% A = quat2axang(ppose);
% qpose = zeros(6,1);
% qpose = [pose(1:3)', A(4) * [A(1:3)]]';
pose = pose';
T_w_nb = [MatrixExp3(VecToso3(pose(4:6))), pose(1:3); 0 0 0 1];

% M = ones(400, 400, 5);
% step = 1;
% step_num = 4;
[H,W,C] = size(M);
step_num = C - 1;

image_gray_target_norm = get_image_gray_norm(image_gray_target);
for i = 1 : C
    M(:,:,i) = get_image_gray_norm(M(:,:,i));
end

minus_delta_I_z = ones(H, W, step_num);
step_z = ones(H, W, step_num);
I_z = ones(H, W);

for i = 1:step_num
    minus_delta_I_z(:,:,i) = M(:,:,1) - M(:,:,i+1);
end

for i = 1:step_num
    step_z(:,:,i) = ((i - step_num / 2 - 1) * (i <= step_num / 2)...
        + (i - step_num / 2) * (i > step_num /2)) * step .* ones(H, W);
end

for i = 1 : W
    for j = 1 : H
        Y = [];
        X = [];
        for k = 1 : step_num
            Y = [Y; minus_delta_I_z(j,i,k)];
            X = [X; [1, step_z(j,i,k)]];
        end
        B = pinv(X) * Y;
        I_z(j,i) = B(2);
    end
end

[error_s, L_e] = get_FeaturesError_InteractionMatrix_DVS(...
                    M(:,:,1), image_gray_target_norm, ...
                    Para_Camera_Intrinsic, I_z);

Bc = -3 * pinv(L_e) * error_s; 

Sc = [T_w_nb(1:3,1:3) * Bc(1:3); T_w_nb(1:3,1:3) * Bc(4:6)];
    









