A = [1,  2, -1, -1; ...
    -2, -1,  0, -1; ...
    3,  0,  4, -1; ...
    -4, -1, -3,  1; ...
    5,  3,  2,  3]';
b = [1, 2, 3, 4]';
lam = 5.0;

[m, n] = size(A);

f = quadLoss(1, zeros(m, 1));
g = l1Norm(lam);
aff = {A, -b};

opt.Lf = 1e2;
opt.method = 'fbs';
opt.variant = 'fast';
opt.tol = 1e-14;
opt.display = 1;

out = forbes(f, g, zeros(n, 1), aff, [], opt);
