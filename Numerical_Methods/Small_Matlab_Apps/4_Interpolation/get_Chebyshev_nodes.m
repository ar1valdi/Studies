function nodes = get_Chebyshev_nodes(N)
    nodes = zeros(1, N);
    for i = 0:N-1
        nodes(i+1) = cos(i * pi / (N-1));
    end
end