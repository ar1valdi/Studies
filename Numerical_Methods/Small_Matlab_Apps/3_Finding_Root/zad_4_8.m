a = 1;
b = 60000;
ytolerance = 1E-12;
max_iterations = 100;

[n_bisection,ysolution_B,iterations_B,xtab_B,xdif_B] = bisection_method(a,b,max_iterations,ytolerance,@estimate_execution_time);
[n_secant,ysolution_S,iterations_S,xtab_S,xdif_S] = secant_method(a,b,max_iterations,ytolerance,@estimate_execution_time);

subplot(2,1,1);
x = 1:length(xtab_B);
plot(x,xtab_B)
x = 1:length(xtab_S);
hold on
plot(x,xtab_S)
hold off
xlabel("Iterations")
ylabel("Values")
title("Time values on subsequent iterations")
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
title("Time differences on subsequent iterations")
legend("Bisection", "Secant")
