function  error_s = get_feature_error_gray_moment_Chaumette(M_new, M_old, Z_star)
%%  计算特征误差
% A Direct Dense Visual Servoing Approach Using Photometric Moments
%% 准备
xg_old = M_old.M10 / M_old.M00;
yg_old = M_old.M01 / M_old.M00;
xg_new = M_new.M10 / M_new.M00;
yg_new = M_new.M01 / M_new.M00;
%% 计算期望特征
an_old = Z_star;
xn = xg_old * an_old;
yn = yg_old * an_old;




end