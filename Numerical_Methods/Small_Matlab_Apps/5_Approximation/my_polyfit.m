function [b] = my_polyfit(x, y, m)
    
    n = length(x);
    X = zeros(n, m+1);
    for i = 1:n
        for j = 1:m+1
            X(i, j) = x(i) ^ (j-1);
        end
    end
    
    y = reshape(y, n, 1);
    Xt = transpose(X);
    a = (Xt*X)\Xt*y;
    
    for i = 1:length(a)
        b(i) = a(length(a) + 1 - i);
    end
end