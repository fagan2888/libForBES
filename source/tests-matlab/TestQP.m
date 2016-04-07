Q = [3,     1,     1,    0; ...
    1,     3,     0,   -1; ...
    1,     0,     3,    1; ...
    0,    -1,     1,    5];
q = [1, 2, 3, 4]';
lb = -1;
ub = +1;
H = [1, 1, 1, 1];

% n: dimension of primal
% m: dimension of dual
[m, n] = size(H);

f = quadratic(Q, q);
g = indBox(lb, ub);
constr = {H, -1, zeros(m, 1)};

opt.Lf = 10;
opt.method = 'fbs';
opt.variant = 'fast';
opt.tol = 1e-14;
opt.display = 1;

out = forbes(f, g, zeros(m, 1), [], constr, opt);
