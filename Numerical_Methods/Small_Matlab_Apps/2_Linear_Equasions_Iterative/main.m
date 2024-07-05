% 3.1
% N = 100;
% [A,b,x,time_direct,err_norm,index_number] = solve_direct(N);

% 3.2
% N = 1000:1000:8000;
% n = length(N);
% vtime_direct = ones(1,n); 

% for index = 1:n
%    [A,b,x,time_direct,err_norm,index_number] = solve_direct(N(index));
%    vtime_direct(index) = time_direct;
% end

% plot_direct(N,vtime_direct);

% 3.3
%[A,b,M,bm,x,err_norm,time,iterations,index_number] = solve_Jacobi(1000);

% 3.4
% [A,b,M,bm,x,err_norm,time,iterations,index_number] = solve_Gauss_Seidel(1000);

% 3.5
N = 1000:1000:8000;
n = length(N);
time_Jacobi = ones(1,n);
time_Gauss_Seidel = 2*ones(1,n);
iterations_Jacobi = 40*ones(1,n);
iterations_Gauss_Seidel = 40*ones(1,n);

for i = 1:n
    [A,b,M,bm,x,err_norm,time,iterations,index_number] = solve_Jacobi(N(i));
    time_Jacobi(1,i) = time;
    iterations_Jacobi(1, i) = iterations;
    [A,b,M,bm,x,err_norm,time,iterations,index_number] = solve_Gauss_Seidel(N(i));
    time_Gauss_Seidel(1,i) = time;
    iterations_Gauss_Seidel(1, i) = iterations;
end

plot_problem_5(N,time_Jacobi,time_Gauss_Seidel,iterations_Jacobi,iterations_Gauss_Seidel);