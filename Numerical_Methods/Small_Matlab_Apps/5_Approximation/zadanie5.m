function [country, source, degrees, x_coarse, x_fine, y_original, y_yearly, y_approximation, mse, msek] = zadanie5(energy)
    
country = 'Brazil';
source = 'Gas';
degrees = [1,2,3,4];
x_coarse = [];
x_fine = [];
y_original = [];
y_yearly = [];
y_approximation = [];
mse = [];
msek = [];

if isfield(energy, country) && isfield (energy.(country), source)
    y_original = energy.(country).(source).EnergyProduction;
    dates = energy.(country).(source).Dates;
    
    n_years = floor(length(y_original) / 12);
    y_cut = y_original(end-12*n_years+1:end);
    y4sum = reshape(y_cut, [12 n_years]);
    y_yearly = sum(y4sum,1)';

    N = length(y_yearly);
    P = (N-1)*8+1;
    x_coarse = linspace(-1, 1, N)';
    x_fine = linspace(-1, 1, P)';
    % pętla po stopniach wielomianów
    for i = 1:N-1
        X = dct2_custom(y_yearly, i);
        y_approximation{i} = idct2_custom(X, i, N, P);
        for_mse = idct2_custom(X, i, N, N);
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

function X = dct2_custom(x, kmax)
    N = length(x);
    X = zeros(kmax, 1);
    c2 = sqrt(2/N);
    c3 = pi/2/N;
    nn = (1:N)';

    X(1) = sqrt(1/N) * sum( x(nn) );
    for k = 2:kmax
        X(k) = c2 * sum( x(nn) .* cos(c3 * (2*(nn-1)+1) * (k-1)) );
    end
end

function x = idct2_custom(X, kmax, N, P)
    x = zeros(P, 1);
    kk = (2:kmax)';
    c1 = sqrt(1/N);
    c2 = sqrt(2/N);
    c3 = pi*(N - 1)/(2*N*(P - 1));
    c4 = -(pi*(N - P))/(2*N*(P - 1));

    for n = 1:P
        x(n) = c1*X(1) + c2*sum( X(kk) .* cos((c3*(2*(n-1)+1)+c4) * (kk-1)) );
    end
end