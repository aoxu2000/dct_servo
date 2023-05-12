%% Direct Dense Visual Servoing (DVS)
% 期望相机与平面平行
%% 开始
clc;
close all;
clear;
%% 连接V-Rep软件并获取句柄
%连接V-Rep软件
[vrep, clientID] = get_vrep_connect();
% 获取图像句柄
[res, VisionHandle_Vision_old, VisionHandle_Vision_new] = get_vrep_VisionHandle_3D_Camera(vrep, clientID);
% 获取相机句柄
[res, VisionHandle_camera_new] = vrep.simxGetObjectHandle(clientID,'camera_new',vrep.simx_opmode_blocking);
[res, VisionHandle_camera_old] = vrep.simxGetObjectHandle(clientID,'camera_old',vrep.simx_opmode_blocking); 
% 获取目标句柄
object_name = 'photo';
[res, VisionHandle_visual_target] = vrep.simxGetObjectHandle(clientID,object_name,vrep.simx_opmode_blocking);
% 初始化参数
dt_sim = 0.05; 
sim_time = 100;
num_sim = sim_time / dt_sim;

% 收敛精度
epsilon_rotate = 5e-4;
epsilon_translation = 5e-4;
% 读取相机内参矩阵
near = 0.01; far = 10; angle = 57;
resolution_x = 640;
resolution_y = 480;
Para_Camera_Intrinsic = get_Camera_Intrinsic_new(near, far, angle, resolution_x, resolution_y);
% 摄像头相对于相机基座的位姿
% T_b_v = [-1, 0, 0, 0; 0, -1, 0, 0.05; 0, 0, 1, 0.03; 0, 0, 0, 1];
T_b_v = [0, 0, 1, 0.015; 1, 0, 0, -0.0324985; 0, 1, 0, 0.00000005635; 0, 0, 0, 1];
% 图像显示准备
figure_gray = figure;       set(gcf,'name','gray');
figure_depth = figure;      set(gcf,'name','depth');
%%
% 设置为同步模式并开始仿真
vrep_Start(vrep, clientID);
% 设置当前相机位姿
% P_C = [-1.5000e-02; -2.5000e-02; +10.0000e-01];
% R_C = rotx(-1.1674e+02) * roty(-7.8831e+01) * rotz(+6.8698e+01);
% T_C = RpToTrans(R_C, P_C);
% set_vrep_Camera_move(vrep, clientID, VisionHandle_camera_new, -1, T_C);  
% 同步触发
vrep_SynchronousTrigger(vrep, clientID); 
% 读取灰度图像并显示
[res_gray_old, ~, image_gray_old] = get_vrep_Camera_gray(vrep, clientID, VisionHandle_Vision_old);
[res_gray_new, ~, image_gray_new] = get_vrep_Camera_gray(vrep, clientID, VisionHandle_Vision_new);
image_gray_old_norm = get_image_gray_norm(image_gray_old);
image_gray_new_norm = get_image_gray_norm(image_gray_new);
figure(figure_gray);       
subplot(121); imshow(image_gray_old_norm, [0,1]);   
subplot(122); imshow(image_gray_new_norm, [0,1]);   
% 读取深度图像并显示
% [res_depth_old, ~, image_depth_old] = get_vrep_Camera_depth(vrep, clientID, VisionHandle_Vision_old);
[res_depth_new, ~, image_depth_new] = get_vrep_Camera_depth(vrep, clientID, VisionHandle_Vision_new);
figure(figure_depth);       
% subplot(121); imshow(image_depth_old, [min(image_depth_old(:)), max(image_depth_old(:))]);   
subplot(122); imshow(image_depth_new, [min(image_depth_new(:)), max(image_depth_new(:))]); 
% 计算平面相对于世界坐标系的旋转矩阵 为计算平面参数做准备
% [res, T_world_target] = get_Object_Transform(vrep, clientID, VisionHandle_visual_target, -1);
% R_world_VisualTarget = T_world_target(1:3, 1:3)';
% 计算期望相机坐标系下的平面参数
% [res, T_vision_target] = get_Object_Transform(vrep, clientID, VisionHandle_visual_target, VisionHandle_Vision_old);
% planar_parameter_old = get_planar_parameter_new(T_vision_target, R_world_VisualTarget);
% 数据存储
error_feature = zeros(num_sim+1, 6);
error_trans = zeros(num_sim+1, 6);
velocity = zeros(num_sim+1, 6);
t = zeros(num_sim+1, 1);
T = zeros(4, 4, num_sim+1);
%% 视觉伺服控制
for i = 0 : num_sim

    T_w_camera_next = servo_step(vrep, clientID, VisionHandle_Vision_new, ...
    image_gray_old_norm, Para_Camera_Intrinsic, T_b_v);


	% 设置相机运动
	set_vrep_Camera_move(vrep, clientID, VisionHandle_camera_new, -1, T_w_camera_next); 
	% 同步触发
	vrep_SynchronousTrigger(vrep, clientID);     
end
%% 结束仿真
% 记录数据
error_trans = error_trans(1:i+1,:);
velocity = velocity(1:i+1,:);
t = t(1:i+1);
T = T(:, :, i+1);
% 结束
vrep_Finish(vrep, clientID);
%% 绘图
figure;
f_t = plot(t, error_trans); 
grid on; legend('e_{tx}', 'e_{ty}', 'e_{tz}', 'e_{\omega x}', 'e_{\omega y}', 'e_{\omega z}', 'Location', 'southeast'); 
figure;
f_v = plot(t, velocity); grid on;
grid on; legend('v_{x}', 'v_{y}', 'v_{z}', '\omega_x', '\omega_y', '\omega_z', 'Location', 'southeast'); 













