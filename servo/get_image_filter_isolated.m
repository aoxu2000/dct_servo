function image_binary_filter= get_image_filter_isolated(image_binary, k)
%% 孤立点滤波
%% 准备
[row, col] = size(image_binary);
image_binary_filter = zeros(row, col);
%% 计算
for i = 1 : row
    for j = 1 : col
        % 确定范围
        if i-k < 1, i_min = 1; else, i_min = i - k; end
        if i+k > row, i_max = row; else, i_max = i + k; end
        if j-k < 1, j_min = 1; else, j_min = j - k; end
        if j+k > col, j_max = col; else, j_max = j + k; end
        i_temp = i_min : i_max; 
        j_temp = j_min : j_max;      
        if image_binary(i,j) == 0 % 孤立0点
            if sum(sum(image_binary(i_temp,j_temp))) == (i_temp(end)-i_temp(1)+1) * (j_temp(end)-j_temp(1)+1) - 1
                image_binary_filter(i,j) = 1;
            else
                image_binary_filter(i,j) = 0;
            end
        elseif image_binary(i,j) == 1 % 孤立1点
             if sum(sum(image_binary(i_temp,j_temp))) == 1
                image_binary_filter(i,j) = 0;
             else
                image_binary_filter(i,j) = 1;
            end           
        end
    end
end




end