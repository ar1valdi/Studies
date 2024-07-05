function plot_direct(N,vtime_direct)
    % N - wektor zawierający rozmiary macierzy dla których zmierzono czas obliczeń metody bezpośredniej
    % vtime_direct - czas obliczeń metody bezpośredniej dla kolejnych wartości N
    
    plot(N, vtime_direct)
    xlabel("Size of matrix")
    ylabel("Time required to calculate")
    title("Time vs size of matrix on r=A/b")
end