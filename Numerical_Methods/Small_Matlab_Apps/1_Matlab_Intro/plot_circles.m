function plot_circles(circles, amount)
    hold on
    for i = 1:amount
        plot_circle(circles(i, 3), circles(i, 1), circles(i, 2))
    end
end