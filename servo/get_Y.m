function Y = get_Y(new_img, old_img, dx, dy, intrinsic_matrix)

new_img_norm = get_image_gray_norm(new_img);
old_img_norm = get_image_gray_norm(old_img);

[I_x, I_y] = get_image_gradient(old_img_norm, intrinsic_matrix);

Y = new_img_norm - old_img_norm - I_x .* dx - I_y .* dy;

end