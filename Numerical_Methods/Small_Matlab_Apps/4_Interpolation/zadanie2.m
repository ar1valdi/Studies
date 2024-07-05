function [nodes_Chebyshev, V, V2, original_Runge, interpolated_Runge, interpolated_Runge_Chebyshev] = zadanie2()
% nodes_Chebyshev - wektor wierszowy zawierający N=16 węzłów Czebyszewa drugiego rodzaju
% V - macierz Vandermonde obliczona dla 16 węzłów interpolacji rozmieszczonych równomiernie w przedziale [-1,1]
% V2 - macierz Vandermonde obliczona dla węzłów interpolacji zdefiniowanych w wektorze nodes_Chebyshev
% original_Runge - wektor wierszowy zawierający wartości funkcji Runge dla wektora x_fine=linspace(-1, 1, 1000)
% interpolated_Runge - wektor wierszowy wartości funkcji interpolującej określonej dla równomiernie rozmieszczonych węzłów interpolacji
% interpolated_Runge_Chebyshev - wektor wierszowy wartości funkcji interpolującej wyznaczonej
%       przy zastosowaniu 16 węzłów Czebyszewa zawartych w nodes_Chebyshev 
    x_fine = linspace(-1, 1, 1000);
    nodes_Chebyshev = get_Chebyshev_nodes(16);
    y_coarse = zeros(1, length(nodes_Chebyshev));
    original_Runge = zeros(1, length(x_fine));
    for i = 1:length(x_fine)
        original_Runge(i) = 1 / (1 + 25 * x_fine(i) * x_fine(i));
    end
    for i = 1:length(nodes_Chebyshev)
        y_coarse(i) = 1 / (1 + 25 * nodes_Chebyshev(i) * nodes_Chebyshev(i));
    end

    subplot(2,1,1);
    plot(x_fine, original_Runge);
    xlabel("x")
    ylabel("approx y")
    title("interpolation using evenly spaced nodes")
    hold on;
    
    V = vandermonde_matrix(16);
    V2 = vandermonde_matrix_chebyshev(16);

    y_val = zeros(16, 1);
    for j = 1:16
        x = V(j,2);
        y_val(j) = calc_runge(x);
    end
    c_runge = V\y_val; % współczynniki wielomianu interpolującego
    interpolated_Runge = polyval(flipud(c_runge), x_fine); % interpolacja
    plot (x_fine, interpolated_Runge)
    plot(nodes_Chebyshev, y_coarse, 'o')
    legend('original', 'interpolated', 'org on nodes')

    hold off
    subplot(2,1,2);
    plot(x_fine, original_Runge);
    xlabel("x")
    ylabel("approx y")
    title("interpolation using chebyshev nodes")
    hold on;

    y_val = zeros(16, 1);
    for j = 1:16
        x = V2(j,2);
        y_val(j) = calc_runge(x);
    end
    c_runge = V2\y_val; % współczynniki wielomianu interpolującego
    interpolated_Runge_Chebyshev = polyval(flipud(c_runge), x_fine); % interpolacja
    plot (x_fine, interpolated_Runge_Chebyshev)
    plot(nodes_Chebyshev, y_coarse, 'o')
    legend("original", "interpolated", "org val on Cheb. nodes")
    hold off
end