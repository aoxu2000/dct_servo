function order = get_order_adaption(image_gray_new_init, image_gray_new, ...
                                image_gray_old, order_min, order_max)
%% 计算Hahn矩的阶数
%
err = (image_gray_new(:) - image_gray_old(:));
err_0 = (image_gray_new_init(:) - image_gray_old(:));
error_pixel_ave = err' * err / length(err);
error_pixel_ave_0 = err_0' * err_0 / length(err_0);

k = 10;
if error_pixel_ave > error_pixel_ave_0
    error_pixel_ave = error_pixel_ave_0;
end
t = exp(-k*(error_pixel_ave / (error_pixel_ave_0 - error_pixel_ave)));
order_ = (order_max - order_min)*t + order_min;
order = round(order_);
end


