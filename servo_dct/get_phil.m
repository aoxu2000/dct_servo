function ret = get_phil(T, image_gray_new, Para_Camera_Intrinsic)

[row, col] = size(image_gray_new);
dx = zeros(row, col);
dy = zeros(row, col);
phi = zeros(row, col);

for i = 1 : col
    for j = 1 : row
        point = [i; j; 1];
        
        corn_right_norm = Para_Camera_Intrinsic \ point;
        x = corn_right_norm(1);
        y = corn_right_norm(2);

        new_coordinate = T * [x;y;0;1];
        dx(j,i) = new_coordinate(1);
        dy(j,i) = new_coordinate(2);
        phi(j,i) = new_coordinate(3);
    end
end

ret = [dx; dy; phi];

end









