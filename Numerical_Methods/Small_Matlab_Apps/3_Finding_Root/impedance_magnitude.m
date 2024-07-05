function impedance_delta = impedance_magnitude(omega)

if omega <= 0
    error("omega value is <= 0")
end

R = 525;        %Ohm
C = 7E-5;  %F
L = 3;          %H
M = 75; % docelowa wartość modułu impedancji

low = 1/(R*R) + (omega*C - 1/(omega * L))^2;
Z = 1/(sqrt(low));

impedance_delta = Z - M;

end