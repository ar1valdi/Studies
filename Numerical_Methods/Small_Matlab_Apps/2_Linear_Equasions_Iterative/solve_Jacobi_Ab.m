function [A,b,M,bm,x,err_norm,err,time,iterations,index_number] = solve_Jacobi_Ab(A, b, max_iter)
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
err_norm = 1;
acc_err = 1E-12;
err = zeros(100, 1);

N = size(A, 1);

x = ones(N,1);
L = tril(A, -1);
U = triu(A, 1);
D = diag(diag(A));
M = -(D \ (L+U));
bm = D \ b;

tic
for iterations = 1:max_iter
    x = M*x + bm;
    err_norm = norm(A*x-b);
    err(iterations) = err_norm;
    
    if err_norm < acc_err
        break
    end
end
time = toc;

end