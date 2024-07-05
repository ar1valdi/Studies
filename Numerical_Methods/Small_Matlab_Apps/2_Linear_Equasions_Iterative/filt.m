data = load("filtr_dielektryczny.mat");
A = data.A;
b = data.b;


tic
x = A\b;
time_direct = toc
err_norm = norm(A*x-b)

[A,b,M,bm,x,err_norm,err,time,iterations,index_number] = solve_Jacobi_Ab(A, b, 1000);
err1 = err;

[A,b,M,bm,x,err_norm,err,time,iterations,index_number] = solve_Gauss_Seidel_Ab(A, b, 1000);
err2 = err;

N = 1:1:1000;
loglog(N, err1)
hold on
loglog(N, err2)
hold off

xlabel("Iterations")
ylabel("Error norm")
title("Error norm using different iter. methods")
legend("Jacobi", "Gauss Seidel", 'Location','eastoutside')