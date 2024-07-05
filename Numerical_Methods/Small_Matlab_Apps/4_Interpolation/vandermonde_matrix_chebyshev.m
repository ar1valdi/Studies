function V = vandermonde_matrix_chebyshev(N)
    x_coarse = get_Chebyshev_nodes(N);
    V = zeros(N, N);
    for i = 1:N
        for j = 1:N
            V(i,j) = x_coarse(i)^(j-1);
        end
    end
end