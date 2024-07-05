function [integration_error, Nt, ft_5, xr, yr, yrmax] = zadanie4()
    % Numeryczne całkowanie metodą Monte Carlo.
    %
    %   integration_error - wektor wierszowy. Każdy element integration_error(1,i)
    %       zawiera błąd całkowania obliczony dla liczby losowań równej Nt(1,i).
    %       Zakładając, że obliczona wartość całki dla Nt(1,i) próbek wynosi
    %       integration_result, błąd jest definiowany jako:
    %       integration_error(1,i) = abs(integration_result - reference_value),
    %       gdzie reference_value to wartość referencyjna całki.
    %
    %   Nt - wektor wierszowy zawierający liczby losowań, dla których obliczano
    %       wektor błędów całkowania integration_error.
    %
    %   ft_5 - gęstość funkcji prawdopodobieństwa dla n=5
    %
    %   [xr, yr] - tablice komórkowe zawierające informacje o wylosowanych punktach.
    %       Tablice te mają rozmiar [1, length(Nt)]. W komórkach xr{1,i} oraz yr{1,i}
    %       zawarte są współrzędne x oraz y wszystkich punktów zastosowanych
    %       do obliczenia całki przy losowaniu Nt(1,i) punktów.
    %
    %   yrmax - maksymalna dopuszczalna wartość współrzędnej y losowanych punktów

    reference_value = 0.0473612919396179; % wartość referencyjna całki

    Nt = 5:50:10^4;
    integration_error = zeros(1, length(Nt));
    integration_result = zeros(1, length(Nt));
    
    ft_5 = calc_malfunction_chance(5);
    yrmax = ft_5 * 1.1;
    integral_1000 = monte_carlo_integral(@(i) calc_malfunction_chance(i), 1000, yrmax);
    
    for i = 1:length(Nt)
        [integration_result(i), xr{i}, yr{i}] = monte_carlo_integral(@(i) calc_malfunction_chance(i), Nt(i), yrmax);
        integration_error(i) = abs(integration_result(i) - reference_value);
    end

    loglog(Nt, integration_error);
    xlabel("Points num");
    ylabel("Error");
    title("Errors using Monte Carlo integral");
end