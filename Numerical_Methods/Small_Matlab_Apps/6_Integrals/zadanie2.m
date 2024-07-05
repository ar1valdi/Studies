function [integration_error, Nt, ft_5, integral_1000] = zadanie2()
    % Numeryczne całkowanie metodą prostokątów.
    % Nt - wektor zawierający liczby podprzedziałów całkowania
    % integration_error - integration_error(1,i) zawiera błąd całkowania wyznaczony
    %   dla liczby podprzedziałów równej Nt(i). Zakładając, że obliczona wartość całki
    %   dla Nt(i) liczby podprzedziałów całkowania wyniosła integration_result,
    %   to integration_error(1,i) = abs(integration_result - reference_value),
    %   gdzie reference_value jest wartością referencyjną całki.
    % ft_5 - gęstość funkcji prawdopodobieństwa dla n=5
    % integral_1000 - całka od 0 do 5 funkcji gęstości prawdopodobieństwa
    %   dla 1000 podprzedziałów całkowania

    reference_value = 0.0473612919396179; % wartość referencyjna całki

    Nt = 5:50:10^4;
    integration_error = zeros(1, length(Nt));
    integration_result = zeros(1, length(Nt));
    
    ft_5 = calc_malfunction_chance(5);
    integral_1000 = trap_integral(@(i) calc_malfunction_chance(i), 1000);
    
    for i = 1:length(Nt)
        integration_result(i) = trap_integral(@(i) calc_malfunction_chance(i), Nt(i));
        integration_error(i) = abs(integration_result(i) - reference_value);
    end

    loglog(Nt, integration_error);
    xlabel("Trapezes num");
    ylabel("Error");
    title("Errors using trapeze integral");
end