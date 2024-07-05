function f = trap_integral(fun, N)
    f = 0;
    x = linspace(0, 5, N+1);
    delta_x = x(2) - x(1);

    for i = 2:N+1
        f = f + (fun(x(i)) + fun(x(i-1)));
    end
    f = f*delta_x/2;
end