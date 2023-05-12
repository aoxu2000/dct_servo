function M_3D_projection = get_image_moment_3D_projection(image_binary, image_depth, Para_Camera_Intrinsic)
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
%% 计算整体中心点
X = XYZ(:,1);   Y = XYZ(:,2);   Z = XYZ(:,3); 
% 0阶
M000 = sum((X.^0) .* (Y.^0) .* (Z.^0));
% 1阶
M001 = sum((X.^0) .* (Y.^0) .* (Z.^1));
M010 = sum((X.^0) .* (Y.^1) .* (Z.^0));
M100 = sum((X.^1) .* (Y.^0) .* (Z.^0));
% 中心
Xg = M100 / M000;	Yg = M010 / M000;   Zg = M001 / M000;  
%% 映射X-Y
% 剔除重复项
P_XY = [X,Y];
[P_XY_unique, ia_XY] = unique(P_XY, 'rows');
X_XY_unique = P_XY_unique(:,1);
Y_XY_unique = P_XY_unique(:,2);
Z_XY_unique = Z(ia_XY);
% 计算0阶矩
M000_XY = sum((X_XY_unique.^0) .* (Y_XY_unique.^0) .* (Z_XY_unique.^0));
% 计算1阶矩
M100_XY = sum((X_XY_unique.^1) .* (Y_XY_unique.^0) .* (Z_XY_unique.^0));
M010_XY = sum((X_XY_unique.^0) .* (Y_XY_unique.^1) .* (Z_XY_unique.^0));
M001_XY = sum((X_XY_unique.^0) .* (Y_XY_unique.^0) .* (Z_XY_unique.^1));
% 计算中心
Xg_XY = M100_XY / M000_XY;
Yg_XY = M010_XY / M000_XY;
Zg_XY = M001_XY / M000_XY;
% 计算3阶中心矩
X_C_XY = X_XY_unique - Xg_XY;    
Y_C_XY = Y_XY_unique - Yg_XY;
Z_C_XY = Z_XY_unique - Zg_XY;
C003_XY = sum((X_C_XY.^0) .* (Y_C_XY.^0) .* (Z_C_XY.^3));
C030_XY = sum((X_C_XY.^0) .* (Y_C_XY.^3) .* (Z_C_XY.^0));
C300_XY = sum((X_C_XY.^3) .* (Y_C_XY.^0) .* (Z_C_XY.^0));
C120_XY = sum((X_C_XY.^1) .* (Y_C_XY.^2) .* (Z_C_XY.^0));
C210_XY = sum((X_C_XY.^2) .* (Y_C_XY.^1) .* (Z_C_XY.^0));
C111_XY = sum((X_C_XY.^1) .* (Y_C_XY.^1) .* (Z_C_XY.^1));
%% 映射Y-Z
% 剔除重复项
P_YZ = [Y,Z];
[P_YZ_unique, ia_YZ] = unique(P_YZ, 'rows');
Y_YZ_unique = P_YZ_unique(:,1);
Z_YZ_unique = P_YZ_unique(:,2);
X_YZ_unique = X(ia_YZ);
% 计算0阶矩
M000_YZ = sum((X_YZ_unique.^0) .* (Y_YZ_unique.^0) .* (Z_YZ_unique.^0));
% 计算1阶矩
M100_YZ = sum((X_YZ_unique.^1) .* (Y_YZ_unique.^0) .* (Z_YZ_unique.^0));
M010_YZ = sum((X_YZ_unique.^0) .* (Y_YZ_unique.^1) .* (Z_YZ_unique.^0));
M001_YZ = sum((X_YZ_unique.^0) .* (Y_YZ_unique.^0) .* (Z_YZ_unique.^1));
% 计算中心
Xg_YZ = M100_YZ / M000_YZ;
Yg_YZ = M010_YZ / M000_YZ;
Zg_YZ = M001_YZ / M000_YZ;
% 计算3阶中心矩
X_C_YZ = X_YZ_unique - Xg_YZ;  
Y_C_YZ = Y_YZ_unique - Yg_YZ;    
Z_C_YZ = Z_YZ_unique - Zg_YZ;
C300_YZ = sum((X_C_YZ.^3) .* (Y_C_YZ.^0) .* (Z_C_YZ.^0));
C030_YZ = sum((X_C_YZ.^0) .* (Y_C_YZ.^3) .* (Z_C_YZ.^0));
C003_YZ = sum((X_C_YZ.^0) .* (Y_C_YZ.^0) .* (Z_C_YZ.^3));
C012_YZ = sum((X_C_YZ.^0) .* (Y_C_YZ.^1) .* (Z_C_YZ.^2));
C021_YZ = sum((X_C_YZ.^0) .* (Y_C_YZ.^2) .* (Z_C_YZ.^1));
C111_YZ = sum((X_C_YZ.^1) .* (Y_C_YZ.^1) .* (Z_C_YZ.^1));
%% 映射Z-X
% 剔除重复项
P_ZX = [Z,X];
[P_ZX_unique, ia_ZX] = unique(P_ZX, 'rows');
Z_ZX_unique = P_ZX_unique(:,1);
X_ZX_unique = P_ZX_unique(:,2);
Y_ZX_unique = Y(ia_ZX);
% 计算0阶矩
M000_ZX = sum((X_ZX_unique.^0) .* (Y_ZX_unique.^0) .* (Z_ZX_unique.^0));
% 计算1阶矩
M100_ZX = sum((X_ZX_unique.^1) .* (Y_ZX_unique.^0) .* (Z_ZX_unique.^0));
M010_ZX = sum((X_ZX_unique.^0) .* (Y_ZX_unique.^1) .* (Z_ZX_unique.^0));
M001_ZX = sum((X_ZX_unique.^0) .* (Y_ZX_unique.^0) .* (Z_ZX_unique.^1));
% 计算中心
Xg_ZX = M100_ZX / M000_ZX;
Yg_ZX = M010_ZX / M000_ZX;
Zg_ZX = M001_ZX / M000_ZX;
% 计算3阶中心矩
Z_C_ZX = Z_ZX_unique - Zg_ZX; 
Y_C_ZX = Y_ZX_unique - Yg_ZX; 
X_C_ZX = X_ZX_unique - Xg_ZX;
C300_ZX = sum((X_C_ZX.^3) .* (Y_C_ZX.^0) .* (Z_C_ZX.^0));
C030_ZX = sum((X_C_ZX.^0) .* (Y_C_ZX.^3) .* (Z_C_ZX.^0));
C003_ZX = sum((X_C_ZX.^0) .* (Y_C_ZX.^0) .* (Z_C_ZX.^3));
C201_ZX = sum((X_C_ZX.^2) .* (Y_C_ZX.^0) .* (Z_C_ZX.^1));
C102_ZX = sum((X_C_ZX.^1) .* (Y_C_ZX.^0) .* (Z_C_ZX.^2));
C111_ZX = sum((X_C_ZX.^1) .* (Y_C_ZX.^1) .* (Z_C_ZX.^1));
%% 整理成结构体
M_3D_projection = struct('Xg', Xg, 'Yg', Yg, 'Zg', Zg,...
               'C030_XY', C030_XY, 'C300_XY', C300_XY, 'C120_XY', C120_XY, 'C210_XY', C210_XY, 'C111_XY', C111_XY, 'C003_XY', C003_XY,...
               'C003_YZ', C003_YZ, 'C030_YZ', C030_YZ, 'C012_YZ', C012_YZ, 'C021_YZ', C021_YZ, 'C111_YZ', C111_YZ, 'C300_YZ', C300_YZ,...
               'C300_ZX', C300_ZX, 'C003_ZX', C003_ZX, 'C201_ZX', C201_ZX, 'C102_ZX', C102_ZX, 'C111_ZX', C111_ZX, 'C030_ZX', C030_ZX);
%% 绘图
figure;
figure; subplot(1,2,1); plot(X, Y, '.'); subplot(1,2,2); plot(X_XY_unique, Y_XY_unique, '.'); 
figure; subplot(1,2,1); plot(Z, X, '.'); subplot(1,2,2); plot(Z_ZX_unique, X_ZX_unique, '.'); 
figure; subplot(1,2,1); plot(Y, Z, '.'); subplot(1,2,2); plot(Y_YZ_unique, Z_YZ_unique, '.'); 
figure; plot3(X, Y, Z, '.');
xlabel('x'); ylabel('y'); zlabel('z'); 
hold on;
plot3([Xg, 0], [Yg, 0], [Zg, 0],'.', 'MarkerSize', 15);
end

