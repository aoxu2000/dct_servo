function M = get_image_moment_norm_gray(image_gray_camera, Para_Camera_Intrinsic, delta_x, delta_y)
%% 计算所有用到的图像矩
% 准备
image = double(image_gray_camera);
[m, n] = size(image);
xxMatrix = zeros(m, n);                
yyMatrix = zeros(m, n); 
for i = 1 : n
    for j = 1 : m
        point = [i-delta_x; j-delta_y; 1];
        corn_right_norm = Para_Camera_Intrinsic \ point;
        xxMatrix(j,i) = corn_right_norm(1);
        yyMatrix(j,i) = corn_right_norm(2);
    end
end
% 几何矩
M00 = sum(sum((xxMatrix.^0) .* (yyMatrix.^0) .* image));
M01 = sum(sum((xxMatrix.^0) .* (yyMatrix.^1) .* image));
M10 = sum(sum((xxMatrix.^1) .* (yyMatrix.^0) .* image));
M02 = sum(sum((xxMatrix.^0) .* (yyMatrix.^2) .* image));
M20 = sum(sum((xxMatrix.^2) .* (yyMatrix.^0) .* image));
M11 = sum(sum((xxMatrix.^1) .* (yyMatrix.^1) .* image));
M03 = sum(sum((xxMatrix.^0) .* (yyMatrix.^3) .* image));
M30 = sum(sum((xxMatrix.^3) .* (yyMatrix.^0) .* image));
M12 = sum(sum((xxMatrix.^1) .* (yyMatrix.^2) .* image));
M21 = sum(sum((xxMatrix.^2) .* (yyMatrix.^1) .* image));
% 中心距
xg = M10 / M00;         
yg = M01 / M00; 
C02 = sum(sum(((xxMatrix-xg).^0) .* ((yyMatrix-yg).^2) .* image));
C20 = sum(sum(((xxMatrix-xg).^2) .* ((yyMatrix-yg).^0) .* image));
C11 = sum(sum(((xxMatrix-xg).^1) .* ((yyMatrix-yg).^1) .* image));
C03 = sum(sum(((xxMatrix-xg).^0) .* ((yyMatrix-yg).^3) .* image));
C30 = sum(sum(((xxMatrix-xg).^3) .* ((yyMatrix-yg).^0) .* image));
C12 = sum(sum(((xxMatrix-xg).^1) .* ((yyMatrix-yg).^2) .* image));
C21 = sum(sum(((xxMatrix-xg).^2) .* ((yyMatrix-yg).^1) .* image));
%% shift point 中心距
% alpha = 0.5*atan(2*C11/(C20 - C02));
% theta_1 = alpha;    theta_2 = alpha + pi/2;
% xsh_1 = sqrt(M00) * cos(theta_1);   xsh_2 = sqrt(M00) * cos(theta_2);
% ysh_1 = sqrt(M00) * sin(theta_1);   ysh_2 = sqrt(M00) * sin(theta_2);
% C03_sh1 = sum(sum(((xxMatrix-xg+xsh_1).^0) .* ((yyMatrix-yg+ysh_1).^3) .* image));
% C30_sh1 = sum(sum(((xxMatrix-xg+xsh_1).^3) .* ((yyMatrix-yg+ysh_1).^0) .* image));
% C12_sh1 = sum(sum(((xxMatrix-xg+xsh_1).^1) .* ((yyMatrix-yg+ysh_1).^2) .* image));
% C21_sh1 = sum(sum(((xxMatrix-xg+xsh_1).^2) .* ((yyMatrix-yg+ysh_1).^1) .* image));
% C04_sh1 = sum(sum(((xxMatrix-xg+xsh_1).^0) .* ((yyMatrix-yg+ysh_1).^4) .* image));
% C13_sh1 = sum(sum(((xxMatrix-xg+xsh_1).^1) .* ((yyMatrix-yg+ysh_1).^3) .* image));
% C22_sh1 = sum(sum(((xxMatrix-xg+xsh_1).^2) .* ((yyMatrix-yg+ysh_1).^2) .* image));
% C31_sh1 = sum(sum(((xxMatrix-xg+xsh_1).^3) .* ((yyMatrix-yg+ysh_1).^1) .* image));
% C40_sh1 = sum(sum(((xxMatrix-xg+xsh_1).^4) .* ((yyMatrix-yg+ysh_1).^0) .* image));
% C03_sh2 = sum(sum(((xxMatrix-xg+xsh_2).^0) .* ((yyMatrix-yg+ysh_2).^3) .* image));
% C30_sh2 = sum(sum(((xxMatrix-xg+xsh_2).^3) .* ((yyMatrix-yg+ysh_2).^0) .* image));
% C12_sh2 = sum(sum(((xxMatrix-xg+xsh_2).^1) .* ((yyMatrix-yg+ysh_2).^2) .* image));
% C21_sh2 = sum(sum(((xxMatrix-xg+xsh_2).^2) .* ((yyMatrix-yg+ysh_2).^1) .* image));
% C04_sh2 = sum(sum(((xxMatrix-xg+xsh_2).^0) .* ((yyMatrix-yg+ysh_2).^4) .* image));
% C13_sh2 = sum(sum(((xxMatrix-xg+xsh_2).^1) .* ((yyMatrix-yg+ysh_2).^3) .* image));
% C22_sh2 = sum(sum(((xxMatrix-xg+xsh_2).^2) .* ((yyMatrix-yg+ysh_2).^2) .* image));
% C31_sh2 = sum(sum(((xxMatrix-xg+xsh_2).^3) .* ((yyMatrix-yg+ysh_2).^1) .* image));
% C40_sh2 = sum(sum(((xxMatrix-xg+xsh_2).^4) .* ((yyMatrix-yg+ysh_2).^0) .* image));
% 整理成结构体
M = struct('M00', M00, 'M01', M01, 'M10', M10, 'M02', M02, 'M20', M20, 'M11', M11, ...
           'M03', M03, 'M30', M30, 'M12', M12, 'M21', M21, ...
           'C02', C02, 'C20', C20, 'C11', C11, 'C03', C03, ...
           'C30', C30, 'C12', C12, 'C21', C21);
%            'C03_sh1', C03_sh1, 'C30_sh1', C30_sh1, 'C12_sh1', C12_sh1, 'C21_sh1', C21_sh1,...
%            'C04_sh1', C04_sh1, 'C13_sh1', C13_sh1, 'C22_sh1', C22_sh1, 'C31_sh1', C31_sh1, 'C40_sh1', C40_sh1,...
%            'C03_sh2', C03_sh2, 'C30_sh2', C30_sh2, 'C12_sh2', C12_sh2, 'C21_sh2', C21_sh2,...
%            'C04_sh2', C04_sh2, 'C13_sh2', C13_sh2, 'C22_sh2', C22_sh2, 'C31_sh2', C31_sh2, 'C40_sh2', C40_sh2);
end