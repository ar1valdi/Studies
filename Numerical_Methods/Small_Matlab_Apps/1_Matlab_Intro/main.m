clear all
close all
format compact

import is_circle_valid.*
import generate_circles.*
import plot_circles.*

n_max = 200;
a = 100;
r_max = a/2; 

circles = generate_circles(a, r_max, n_max);

plot_circles(circles);
% plot_circle(a, 0, 0)