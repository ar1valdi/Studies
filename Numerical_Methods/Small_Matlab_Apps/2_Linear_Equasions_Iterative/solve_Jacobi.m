function [A,b,M,bm,x,err_norm,time,iterations,index_number] = solve_Jacobi(N)
% A - macierz z równania macierzowego A * x = b
% b - wektor prawej strony równania macierzowego A * x = b
% M - macierz pomocnicza opisana w instrukcji do Laboratorium 3
% bm - wektor pomocniczy opisany w instrukcji do Laboratorium 3
% x - rozwiązanie równania macierzowego
% err_norm - norma błędu rezydualnego rozwiązania x; err_norm = norm(A*x-b)
% time - czas wyznaczenia rozwiązania x
% iterations - liczba iteracji wykonana w procesie iteracyjnym metody Jacobiego
% index_number - Twój numer indeksu
index_number = 193237;
max_iter = 1000;
err_norm = 1;
acc_err = 1E-12;
L1 = 7;
[A,b] = generate_matrix(N, L1);

x = ones(N,1);
L = tril(A, -1);
U = triu(A, 1);
D = diag(diag(A));
M = -D \ (L+U);
bm = D \ b;
iterations = 0;

tic
for i = 1:max_iter
    x = M*x + bm;
    err_norm = norm(A*x-b);
    iterations = iterations + 1;

    if err_norm < acc_err
        break
    end
end
time = toc;

end