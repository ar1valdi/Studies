function res = is_circle_valid(x, y, r, circles, sudden_end)
    for i = 1:sudden_end
        dist = sqrt((x - circles(i, 1))^2 + (y - circles(i, 2))^2);
        if dist < r + circles(i, 3)
            res = false;
            return;
        end
    end

    res = true;
    return;
end