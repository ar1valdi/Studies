function [mse] = my_mse(org, pred)
    mse = 0;
    for i = 1:length(org)
        mse = mse + (org(i) - pred(i)) ^ 2;
    end
    mse = mse / length(org);
end