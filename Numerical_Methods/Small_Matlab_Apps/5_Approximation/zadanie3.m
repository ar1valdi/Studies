function [country, source, degrees, y_original, y_approximation, mse] = zadanie3(energy)


country = 'Brazil';
source = 'Gas';
degrees = 1:4;
x_coarse = [];
x_fine = [];
y_original = [];
y_approximation = [];
mse = zeros(1,4);

if isfield(energy, country) && isfield (energy.(country), source)
    y_original = energy.(country).(source).EnergyProduction;
    dates = energy.(country).(source).Dates;
    
    n_years = floor(length(y_original) / 12);
    y_cut = y_original(end-12*n_years+1:end);
    y4sum = reshape(y_cut, [12 n_years]);
    y_yearly = sum(y4sum,1)';

    N = length(y_yearly);
    P = 10*N;
    x_coarse = linspace(-1, 1, N)';
    x_fine = linspace(-1, 1, P)';

    subplot(2,1,1);
    hold on
    plot(x_coarse, y_yearly, DisplayName="original");
    % pętla po stopniach wielomianów
    for i = 1:length(degrees)
        p = my_polyfit(x_coarse, y_yearly, degrees(i));
        y_approximation{i} = polyval(p, x_fine);
        for_mse = polyval(p, x_coarse);
        mse(i) = my_mse(y_yearly, for_mse);
        plot(x_fine, y_approximation{i}, DisplayName="Approx deg=" + degrees(i));
    end

    hold off
    title("Approximation comparasion");
    xlabel("Y");
    ylabel("X");
    legend();

    subplot(2,1,2);
    bar(mse);
    set(gca, 'XTickLabel', degrees);
    title("MSE value on polynomial degrees")
    ylabel("MSE")
    xlabel("Degrees")
else
    disp(['Dane dla (country=', country, ') oraz (source=', source, ')nie są dostępne']);
end
end