function [error_s, L_e] = get_FeaturesError_InteractionMatrix_DCT_Adaption(...
                                image_gray_new, image_gray_old, ...
                                Para_Camera_Intrinsic, I_z, order)
%% 计算特征误差和交互矩阵 DCT矩伺服伺服(HMVS)
%% 自适应阶数n
% order = get_order_adaption(image_gray_new_norm_init, image_gray_new, image_gray_old, order_min, order_max);
% fprintf('order=%d\n', order);
%% 准备
num = (order + 2) * (order+1) / 2;
Dnm_new= zeros(num, 1);
Dnm_old= zeros(num, 1);
L_e =  zeros(num, 6);
% L_e_old =  zeros(num, 6);
cnt = 1;
[N, M] = size(image_gray_new);
Dnx = get_orthogonal_polynomial_DCT(N, order);
Dny = get_orthogonal_polynomial_DCT(M, order);
%% 计算
% 计算图像梯度
L_I_new = get_interaction_matrix_gray(image_gray_new, Para_Camera_Intrinsic, I_z);
% L_I_old = get_interaction_matrix_gray(image_gray_old, Para_Camera_Intrinsic, I_z);
% 计算特征误差即交互矩阵
for l = 0 : order
    for k = 0 : order
        if l + k > order
            continue;
        else 
            %%
            % 准备
            DnX = repmat(Dnx(l+1,:)', 1, M); % 图像横坐标为X,纵坐标为Y
            DnY = repmat(Dny(k+1,:), N, 1);
            DnXY = DnX .* DnY;
            % 计算特征
            Product_new = DnXY .* image_gray_new;
            Product_old = DnXY .* image_gray_old;
            Dnm_new(cnt, 1) = sum(Product_new(:));
            Dnm_old(cnt, 1) = sum(Product_old(:));
            % 计算交互矩阵
            L_e(cnt, :) = sum(DnXY(:) .* L_I_new);
%             L_e_old(cnt, :) = sum(DnXY(:) .* L_I_old);
            % 计数
            cnt = cnt + 1;            
        end
    end
end
%% 
error_s = Dnm_new - Dnm_old;
% L_e = 0.5 * (L_e_new + L_e_old);

end




