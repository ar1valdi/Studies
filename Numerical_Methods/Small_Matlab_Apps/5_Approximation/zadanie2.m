function [country, source, degrees, y_original, y_movmean, y_approximation, mse] = zadanie2(energy)


country = 'Brazil';
source = 'Gas';
degrees = [1, 5, 15, 25];
y_original = [];
y_approximation = [];
mse = [];
y_movmean = [];

if isfield(energy, country) && isfield (energy.(country), source)
    y_original = energy.(country).(source).EnergyProduction;
    y_movmean = movmean(y_original, [11, 0]);
    dates = energy.(country).(source).Dates;

    x = linspace(-1, 1, length(y_original));
    subplot(2,1,1);
    hold on
    plot(x, y_original, DisplayName="original");
    plot(x, y_movmean, DisplayName="movmean");
    % pętla po stopniach wielomianów
    for i = 1:length(degrees)
        p = polyfit(x, y_movmean, degrees(i));
        y_approximation{i} = polyval(p, x)';
        mse(i) = my_mse(y_movmean, y_approximation{i});
        plot(x, y_approximation{i}, DisplayName="Approx deg=" + degrees(i));
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