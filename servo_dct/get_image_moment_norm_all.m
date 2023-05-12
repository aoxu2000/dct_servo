function M = get_image_moment_norm_all(image_binary_camera, Para_Camera_Intrinsic, delta_x, delta_y)
%% 计算所有用到的图像矩
% 准备
image = double(image_binary_camera);
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
xg = M10 / M00;         yg = M01 / M00; 
C02 = M02 - yg * M01;
C20 = M20 - xg * M10;
C11 = M11 - M10*yg - xg*M01 + xg*yg*M00;
% 整理成结构体
M = struct('M00', M00, 'M01', M01, 'M10', M10, 'M02', M02, 'M20', M20, 'M11', M11, ...
           'M03', M03, 'M30', M30, 'M12', M12, 'M21', M21, 'C02', C02, 'C20', C20, 'C11', C11);
end