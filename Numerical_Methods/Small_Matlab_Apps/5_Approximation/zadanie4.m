function [country, source, degrees, x_coarse, x_fine, y_original, y_yearly, y_approximation, mse, msek] = zadanie4(energy)
    
country = 'Brazil';
source = 'Gas';
degrees = [1,2,3,4];
x_coarse = [];
x_fine = [];
y_original = [];
y_yearly = [];
y_approximation = [];
mse = zeros(5,1);
msek = zeros(4,1);

if isfield(energy, country) && isfield (energy.(country), source)
    y_original = energy.(country).(source).EnergyProduction;
    dates = energy.(country).(source).Dates;
    
    n_years = floor(length(y_original) / 12);
    y_cut = y_original(end-12*n_years+1:end);
    y4sum = reshape(y_cut, [12 n_years]);
    y_yearly = sum(y4sum,1)';

    N = length(y_yearly);
    P = (N-1)*10+1;
    x_coarse = linspace(-1, 1, N)';
    x_fine = linspace(-1, 1, P)';
    % pętla po stopniach wielomianów
    for i = 1:N-1
        p = my_polyfit(x_coarse, y_yearly, i);
        y_approximation{i} = polyval(p, x_fine);
        for_mse = polyval(p, x_coarse);
        mse(i) = my_mse(y_yearly, for_mse);
        
        if i > 1
            msek(i-1) = my_mse(y_approximation{i}, y_approximation{i-1});
        end
    end

    subplot(3,1,1);
    hold on
    plot(x_coarse, y_yearly, DisplayName="original");
    for i = 1:length(degrees)
        plot(x_fine, y_approximation{degrees(i)}, DisplayName="Approx deg=" + degrees(i));
    end
    hold off
    title("Approximation comparasion");
    xlabel("Y");
    ylabel("X");
    legend();

    subplot(3,1,2)
    semilogy(linspace(1, N-1, N-1), mse);
    title("MSE on subsequent nodes num")
    xlabel("Nodes num")
    ylabel("MSE")

    subplot(3,1,3)
    semilogy(linspace(1, N-2, N-2), msek);
    title("MSEk on subsequent nodes num")
    xlabel("Nodes num")
    ylabel("MSE")
else
    disp(['Dane dla (country=', country, ') oraz (source=', source, ')nie są dostępne']);
end
end