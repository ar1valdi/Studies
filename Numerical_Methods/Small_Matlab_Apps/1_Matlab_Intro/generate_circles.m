function circles = generate_circles(a, r_max, n_max)
    circles = zeros(n_max, 3);   % (x,y,r)
    n_max_c = n_max;
    
    for i = 1:n_max_c
        r = rand * r_max;
        x = rand * (a - 2 * r) + r;
        y = rand * (a - 2 * r) + r;
        hold on
        plot_circle(r,x,y);

        while ~is_circle_valid(x, y, r, circles, i - 1)
            hold off 
            plot_circle(0,0,0)
            plot_circles(circles, i-1)
            r = rand * r_max;
            x = rand * (a - 2 * r) + r;
            y = rand * (a - 2 * r) + r;
            hold on
            plot_circle(r,x,y);
        end
        
        circles(i,:) = [x,y,r];
        hold off
        plot_circle(0,0,0)
        plot_circles(circles, i);
    end
end