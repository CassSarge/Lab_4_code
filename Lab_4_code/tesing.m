%
% clear;
% clc;
% close all;
clear; clc; arrayfun(@cla,findall(0,'type','axes'));
warning('off')

% Params
m_r = 0.095;
m_p = 0.024;
L_r = 0.085;
L_p = 0.129;
J_r = 5.7E-5;
J_p = 3.3E-5;
K_t = 0.042;
R_m = 8.4;
D_r = 0.0015;
D_p = 0.0004;
k = 0.0008;
g = 9.8;
J_T = J_p*m_p*L_r^2 + J_r*J_p + 0.25*J_r*m_p*L_p^2;

% In the question params
N = -(J_p + 0.25 * m_p * L_p^2);
O = 0.5*m_p*L_p*L_r*D_p;
P = 0.25*m_p^2*L_p^2*L_r*g;
Q = J_p + 0.25*m_p*L_p^2;

R = 0.5*m_p*L_p*L_r;
S = -(J_r + m_p*L_r^2)*D_p;
T = -0.5*m_p*L_p*g*(J_r + m_p*L_r^2);
V = -0.5*m_p*L_p*L_r;

A = [0 0 1 0; 0 0 0 1; N*k/J_T P/J_T N*D_r/J_T O/J_T; R*k/J_T T/J_T R*D_r/J_T S/J_T];
B = [0; 0; Q*K_t/(J_T * R_m); V*K_t/(J_T * R_m)];

w = [B, A*B, A^2*B, A^3*B];
disp(rank(w))
disp(w)


syms s;
detA = det(s*eye(4)-A);
detA = vpa(detA, 4);

syms a1 a2 a3 a4;

A_tilde = [-a1, -a2, -a3, -a4; 1 0 0 0; 0 1 0 0; 0 0 1 0];
detA_tilde = det(s*eye(4) - A_tilde);
detA_tilde = vpa(detA_tilde, 4);

disp('detA = ');
disp(detA);
disp('detA_tilde = ')
disp(detA_tilde);


a = vpa(coeffs(detA), 5);
A_t = [-a(4) -a(3) -a(2) -a(1); 1 0 0 0; 0 1 0 0; 0 0 1 0];
B_tilde = [1; 0; 0; 0];
w_tilde = [B_tilde, A_t*B_tilde, A_t^2*B_tilde, A_t^3*B_tilde];

T = vpa((w_tilde * inv(w)), 5);
disp('T');
disp(T);

%
zeta = 4; % chosen arbitrarily overdamped
% AMONGUS
% TODO: change zeta so that it is damped normally// or justify overdamp
t_s = 9; % settling time of 5s
w_n = 3.93/t_s/zeta; % jesse what the fuck are you talking about

% Choosing poles based on these numbers....
%
%          |-----|
%          |     |
%       ___|=====|___
%         /       \
%        |   0  0  |
%        | .   >  .|
%         \  . . . /  
%          /       \
%         /     .   \
%        |           |
%         \     .    /
%        /            \
%       |       .      |
%        \             /
%         \           / 
%          -----------
%
%   Snowman break!
%


p1 = -40 + 0.1i;
p2 = -40 - 0.1i;

eq1 = (s^2 + 2*zeta*w_n*s + w_n^2)*(s - p1)*(s - p2);
temp = vpa(expand(eq1),5);

coefficients = (vpa(coeffs(temp),3));

K_gains = double(vpa((coefficients - a),5));

K_gains = K_gains(1:end-1);

%T = double(vpa(T,3))

K_gains = K_gains*T;

fprintf("k = %.5f\n", K_gains(4));
fprintf("k = %.5f\n", K_gains(3));
fprintf("k = %.5f\n", K_gains(2));
fprintf("k = %.5f\n", K_gains(1));



%poles = [-1.53781, -1.5378, -2.17993, -761]; % Theta, Theta dot, alpha, alpha dot 
% 10 -50 5 0 
%K = place(A, B, poles);
%disp(K)
% fprintf("s1 = %.5f\n", poles(1));
% fprintf("s2 = %.5f\n", poles(2));
% fprintf("s3 = %.5f\n", poles(3));
% fprintf("s4 = %.5f\n", poles(4));

% k_theta = 10;
% k_alpha = -50;
% k_theta_dot = 5;
% k_alpha_dot = 0;
k_theta = double(K_gains(4));
k_alpha = double(K_gains(3));
k_theta_dot = double(K_gains(2));
k_alpha_dot = double(K_gains(1));


%10, -50, 5, 0 gives response of 9.418s


sim('cranePlantSimulationWithVisualizer15')

figure(1)
subplot(2,1,1)
plot(values.time, values.signals.values(:,1))
hold on
plot(references.time, references.signals.values(:,1))
title('tesing')

subplot(2,1,2)
plot(values.time, values.signals.values(:,2))
hold on
plot(references.time, references.signals.values(:,2))
hold off