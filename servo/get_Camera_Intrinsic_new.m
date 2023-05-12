function Para_Camera_Intrinsic = get_Camera_Intrinsic_new(near, far, angle, resolution_x, resolution_y)
% 输出Vrep相机的内参数
% 调整裁剪平面 [D_n,D_f]（范围之外不可视）
% 调整张角 theta
% 调整分辨率 (w,h)

D_n = near; D_f = far; % 最大观测范围
theta = angle/180*pi / 2; % 张角
w = resolution_x; h = resolution_y;      % 图片尺寸

Para_Camera_Intrinsic = zeros(3, 3);

f_alpha =  -w / (2 * D_f * tan(theta));
f_beta =  -h / (2 * D_f * tan(theta));
u0 = w / 2;
v0 = h / 2;

Para_Camera_Intrinsic(1,1) = f_alpha;
Para_Camera_Intrinsic(2,2) = f_beta;
Para_Camera_Intrinsic(3,3) = 1;
Para_Camera_Intrinsic(1,3) = u0;
Para_Camera_Intrinsic(2,3) = v0;

Para_Camera_Intrinsic(1:2, 1:2) = Para_Camera_Intrinsic(1:2, 1:2) * D_f;
end
