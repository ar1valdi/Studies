function f = simp_integral(fun, N)
    f = 0;
    x = linspace(0, 5, N+1);

    for i = 1:N
        f = f + fun(x(i)) + 4 * fun((x(i+1) + x(i)) / 2) + fun(x(i+1)); 
    end
    f = f * (x(2) - x(1)) / 6;
end