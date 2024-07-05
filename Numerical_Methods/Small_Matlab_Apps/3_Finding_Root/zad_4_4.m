a = 1;
b = 50;
ytolerance = 1E-12;
max_iterations = 100;

[omega_bisection,ysolution_B,iterations_B,xtab_B,xdif_B] = bisection_method(a,b,max_iterations,ytolerance,@impedance_magnitude);
[omega_secant,ysolution_S,iterations_S,xtab_S,xdif_S] = secant_method(a,b,max_iterations,ytolerance,@impedance_magnitude);

subplot(2,1,1);
x = 1:length(xtab_B);
plot(x,xtab_B)
x = 1:length(xtab_S);
hold on
plot(x,xtab_S)
hold off
xlabel("Iterations")
ylabel("Values")
title("X0 values on subsequent iterations")
legend("Bisection", "Secant")


subplot(2,1,2);
x = 1:length(xdif_B);
semilogy(x,xdif_B)
x = 1:length(xdif_S);
hold on
semilogy(x,xdif_S)
hold off
xlabel("Iterations")
ylabel("Differences")
title("X0 differences on subsequent iterations")
legend("Bisection", "Secant")
