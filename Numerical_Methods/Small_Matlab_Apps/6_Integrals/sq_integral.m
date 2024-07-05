function f = sq_integral(fun, N)
    f = 0;
    x = linspace(0, 5, N+1);

    for i = 2:N+1
        delta_x = x(i) - x(i-1);
        midpoint = x(i-1) + delta_x/2;
        height = fun(midpoint);
        f = f + height * delta_x;
    end

end