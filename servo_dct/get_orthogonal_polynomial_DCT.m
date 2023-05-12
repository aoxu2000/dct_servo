function Dn = get_orthogonal_polynomial_DCT(N, order)
%% 计算DCT正交多项式 
% Hn = [0 1 2 ... N-1
%       1   .
%       2     .
%       .       .
%       .
%       .
%       n     ...   ]
%% 初始化
Dn = zeros(order+1, N);
for u = 0 : order
    for x = 0 : N-1
        Dn(u+1, x+1) = 1/sqrt(2) * cos(u * (2*x + 1)*pi / (2*N));
    end
    Dn(u+1, :) = Dn(u+1, :) / norm(Dn(u+1, :));
end
end


