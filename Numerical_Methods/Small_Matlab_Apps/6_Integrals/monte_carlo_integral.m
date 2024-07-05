function [f, xr, yr] = monte_carlo_integral(fun, N, yrmax)
    f = 0;
    N1 = 0;

    for i = 1:N
        xr(i) = 5 * rand();
        yr(i) = yrmax * rand();
        if fun(xr(i)) >= yr(i)
            N1 = N1 + 1;
        end
    end

    f = N1/N * (5*yrmax);
end