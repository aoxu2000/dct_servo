function Y = openlp(new_img, old_img, move_vector, intrinsic_matrix)

new_img_norm = get_image_gray_norm(new_img);
old_img_norm = get_image_gray_norm(old_img);

[I_x, I_y] = get_image_gradient(old_img_norm, intrinsic_matrix);

Y = new_img_norm - old_img_norm - I_x .* move_vector(1) - I_y .* move_vector(2);
% theta = Y ./ move_vector(3);
end
