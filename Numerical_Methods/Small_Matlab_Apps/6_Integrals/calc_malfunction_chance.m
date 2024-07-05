function f = calc_malfunction_chance(t)
    f = 1/(3 * sqrt(2*pi));
    up = (-(t-10)^2) / 18;
    f = f * exp(up);
end