function [V, original_Runge, original_sine, interpolated_Runge, interpolated_sine] = zadanie1()
% Rozmiar tablic komórkowych (cell arrays) V, interpolated_Runge, interpolated_sine: [1,4].
% V{i} zawiera macierz Vandermonde wyznaczoną dla liczby węzłów interpolacji równej N(i)
% original_Runge - wektor wierszowy zawierający wartości funkcji Runge dla wektora x_fine=linspace(-1, 1, 1000)
% original_sine - wektor wierszowy zawierający wartości funkcji sinus dla wektora x_fine
% interpolated_Runge{i} stanowi wierszowy wektor wartości funkcji interpolującej 
%       wyznaczonej dla funkcji Runge (wielomian stopnia N(i)-1) w punktach x_fine
% interpolated_sine{i} stanowi wierszowy wektor wartości funkcji interpolującej
%       wyznaczonej dla funkcji sinus (wielomian stopnia N(i)-1) w punktach x_fine
    N = 4:4:16;
    x_fine = linspace(-1, 1, 1000);
    original_Runge = zeros(1, length(x_fine));
    for i = 1:length(x_fine)
        original_Runge(i) = 1 / (1 + 25 * x_fine(i) * x_fine(i));
    end

    subplot(2,1,1);
    plot(x_fine, original_Runge);
    xlabel("x")
    ylabel("approx y")
    title("interpolation on different nodes number - Runge")
    hold on;
    for i = 1:length(N)
        V{i} = vandermonde_matrix(N(i));

        y_val = zeros(N(i), 1);
        for j = 1:N(i)
            x = V{i}(j,2);
            y_val(j) = calc_runge(x);
        end
        c_runge = V{i}\y_val; % współczynniki wielomianu interpolującego
        interpolated_Runge{i} = polyval(flipud(c_runge), x_fine); % interpolacja
        plot (x_fine, interpolated_Runge{i})
    end
    legend("original", "4", "8", "12", "16")
    hold off

    original_sine = sin(2 * pi * x_fine);
    subplot(2,1,2);
    plot(x_fine, original_sine);
    xlabel("x")
    ylabel("approx y")
    title("interpolation on different nodes number - sine")
    hold on;
    for i = 1:length(N)
        V{i} = vandermonde_matrix(N(i));

        y_val = zeros(N(i), 1);
        for j = 1:N(i)
            x = V{i}(j,2);
            y_val(j) = sin(2 * pi * x);
        end
        c_runge = V{i}\y_val; % współczynniki wielomianu interpolującego
        interpolated_sine{i} = polyval(flipud(c_runge), x_fine); % interpolacja
        plot (x_fine, interpolated_sine{i})
    end
    legend("original", "4", "8", "12", "16")
    hold off
end

