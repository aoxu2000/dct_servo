function M_3D = get_image_moment_3D(image_binary, image_depth, Para_Camera_Intrinsic)
%% 计算3维图像矩
%% 准备
image = double(image_binary);
[id_row, id_col] = find(image == 1);
XYZ = zeros(length(id_row), 3);
%% 计算XYZ
for i = 1 : length(id_row)
    point = [id_col(i); id_row(i); 1];
    point_norm = Para_Camera_Intrinsic \ point;
    XYZ(i,:) = point_norm' * image_depth(id_row(i), id_col(i));   
end
%% 计算各阶图像矩
X = XYZ(:,1);   Y = XYZ(:,2);   Z = XYZ(:,3); 
% 0阶
M000 = sum((X.^0) .* (Y.^0) .* (Z.^0));
% 1阶
M001 = sum((X.^0) .* (Y.^0) .* (Z.^1));
M010 = sum((X.^0) .* (Y.^1) .* (Z.^0));
M100 = sum((X.^1) .* (Y.^0) .* (Z.^0));
% 2阶
M002 = sum((X.^0) .* (Y.^0) .* (Z.^2));
M020 = sum((X.^0) .* (Y.^2) .* (Z.^0));
M200 = sum((X.^2) .* (Y.^0) .* (Z.^0));
M011 = sum((X.^0) .* (Y.^1) .* (Z.^1));
M101 = sum((X.^1) .* (Y.^0) .* (Z.^1));
M110 = sum((X.^1) .* (Y.^1) .* (Z.^0));
% 3阶
M003 = sum((X.^0) .* (Y.^0) .* (Z.^3));
M030 = sum((X.^0) .* (Y.^3) .* (Z.^0));
M300 = sum((X.^3) .* (Y.^0) .* (Z.^0));
M021 = sum((X.^0) .* (Y.^2) .* (Z.^1));
M012 = sum((X.^0) .* (Y.^1) .* (Z.^2));
M102 = sum((X.^1) .* (Y.^0) .* (Z.^2));
M201 = sum((X.^2) .* (Y.^0) .* (Z.^1));
M120 = sum((X.^1) .* (Y.^2) .* (Z.^0));
M210 = sum((X.^2) .* (Y.^1) .* (Z.^0));
M111 = sum((X.^1) .* (Y.^1) .* (Z.^1));
% 中心
Xg = M100 / M000;	Yg = M010 / M000;   Zg = M001 / M000;  
%% 计算各阶中心矩
X_C = XYZ(:,1) - Xg;    Y_C = XYZ(:,2) - Yg;    Z_C = XYZ(:,3) - Zg;    
% 2阶
C002 = sum((X_C.^0) .* (Y_C.^0) .* (Z_C.^2));
C020 = sum((X_C.^0) .* (Y_C.^2) .* (Z_C.^0));
C200 = sum((X_C.^2) .* (Y_C.^0) .* (Z_C.^0));
C011 = sum((X_C.^0) .* (Y_C.^1) .* (Z_C.^1));
C101 = sum((X_C.^1) .* (Y_C.^0) .* (Z_C.^1));
C110 = sum((X_C.^1) .* (Y_C.^1) .* (Z_C.^0));
% 3阶
C003 = sum((X_C.^0) .* (Y_C.^0) .* (Z_C.^3));
C030 = sum((X_C.^0) .* (Y_C.^3) .* (Z_C.^0));
C300 = sum((X_C.^3) .* (Y_C.^0) .* (Z_C.^0));
C021 = sum((X_C.^0) .* (Y_C.^2) .* (Z_C.^1));
C012 = sum((X_C.^0) .* (Y_C.^1) .* (Z_C.^2));
C102 = sum((X_C.^1) .* (Y_C.^0) .* (Z_C.^2));
C201 = sum((X_C.^2) .* (Y_C.^0) .* (Z_C.^1));
C120 = sum((X_C.^1) .* (Y_C.^2) .* (Z_C.^0));
C210 = sum((X_C.^2) .* (Y_C.^1) .* (Z_C.^0));
C111 = sum((X_C.^1) .* (Y_C.^1) .* (Z_C.^1));
%% 整理成结构体
M_3D = struct('Xg', Xg, 'Yg', Yg, 'Zg', Zg,...
               'M000', M000, 'M100', M100, 'M010', M010, 'M001', M001, ...
               'M002', M002, 'M020', M020, 'M200', M200, ...
               'M011', M011, 'M101', M101, 'M110', M110, ...
               'M003', M003, 'M030', M030, 'M300', M300, ...
               'M012', M012, 'M021', M021, 'M102', M102, 'M201', M201, ...
               'M120', M120, 'M210', M210, 'M111', M111, ...
               'C002', C002, 'C020', C020, 'C200', C200, ...
               'C011', C011, 'C101', C101, 'C110', C110, ...
               'C003', C003, 'C030', C030, 'C300', C300, ...
               'C012', C012, 'C021', C021, 'C102', C102, 'C201', C201, ...
               'C120', C120, 'C210', C210, 'C111', C111);
%% 绘图
% figure; plot(X, Y, '.'); xlabel('x'); ylabel('y');
% figure; plot(Z, X, '.'); xlabel('z'); ylabel('x');
% figure; plot(Y, Z, '.'); xlabel('y'); ylabel('z');
% figure; plot3(X, Y, Z, '.'); xlabel('x'); ylabel('y'); zlabel('z'); 
% hold on;
% plot3([Xg, 0], [Yg, 0], [Zg, 0],'.', 'MarkerSize', 15);
end

