function plot_problem_5(N,time_Jacobi,time_Gauss_Seidel,iterations_Jacobi,iterations_Gauss_Seidel)
% Opis wektorów stanowiących parametry wejściowe:
% N - rozmiary analizowanych macierzy
% time_Jacobi - czasy wyznaczenia rozwiązania metodą Jacobiego
% time_Gauss_Seidel - czasy wyznaczenia rozwiązania metodą Gaussa-Seidla
% iterations_Jacobi - liczba iteracji wymagana do wyznaczenia rozwiązania metodą Jacobiego
% iterations_Gauss_Seide - liczba iteracji wymagana do wyznaczenia rozwiązania metodą Gauss-Seidla

subplot(2,1,1);
plot(N, time_Jacobi)
hold on
plot(N, time_Gauss_Seidel)
hold off

ylabel("Time")
xlabel("Matrix size")
legend("Jacobi", "Gauss Seidel", 'Location','eastoutside')
title("Calc time on given matrix size")

subplot(2,1,2);
bar_data = [iterations_Jacobi; iterations_Gauss_Seidel];
bar(N,bar_data)

ylabel("Iterations")
xlabel("Matrix size")
legend("Jacobi", "Gauss Seidel", 'Location','eastoutside')
title("Iterations on given matrix size")
end