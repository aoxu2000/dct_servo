function L_I = get_interaction_matrix_gray(image_gray, Para_Camera_Intrinsic, I_z)
%% 计算灰度误差的交互矩阵（直接视觉伺服DVS）
[row, col] = size(image_gray);
[I_x, I_y] = get_image_gradient(image_gray, Para_Camera_Intrinsic);
L_I = zeros(row*col, 6);
%% L_e
cnt = 1;
for i = 1 : col
    for j = 1 : row
        point = [i; j; 1];
        
        corn_right_norm = Para_Camera_Intrinsic \ point;
        x = corn_right_norm(1);
        y = corn_right_norm(2);

        L_I(cnt, :) = [I_x(j,i), ...
                       I_y(j,i), ...
                       I_z(j,i), ...
                       y * I_z(j,i), ...
                       -x * I_z(j,i), ...
                       x * I_y(j,i) - y * I_x(j,i)];
        cnt = cnt + 1;
    end
end
end
    