%% Optimize the 'sin' function
func = @sin;

[x, f] = aro(func, 1);
fprintf('Optimized the SIN function: x = %f, fval = %f\n\n', x, f);

% Bound the search space from -pi to pi.
[x, f] = aro(func, 1, -pi, pi);
fprintf('Optimized the SIN function bounded from -pi to pi: x = %f, fval = %f\n\n', x, f);


%% Optimize the Rastrigin function with default algorithm settings
func = @rastriginsfcn;
dim = 10;

lb = repmat(-10, 1, dim);
ub = repmat(10, 1, dim);
options = arooptions('default');
[x, f, generation, fvals] = aro(func, dim, lb, ub, options);
fprintf('Optimized the RASTRIGIN function with default settings.  x = %s, fval = %f\n\n', mat2str(x), f);
figure
plot(1:length(fvals), fvals)
legend('Rastrigin')
xlabel('Iterations')
ylabel('Function Value')
title('Optimized by ARO with its default settings')
drawnow

% Change the default number of iterations. 
lb = repmat(-100, 1, dim);
ub = repmat(100, 1, dim);
options = arooptions('default');
options.Generations = 2000;
[x, f, generation, fvals] = aro(func, dim, lb, ub, options);
fprintf('Optimized the RASTRIGIN function with %d iterations.  x = %s, fval = %f\n\n', options.Generations, mat2str(x), f);
figure
plot(1:length(fvals), fvals)
drawnow
legend('Rastrigin')
xlabel('Iterations')
ylabel('Function Value')
title('Optimized by ARO')

% Use an initial parent
lb = repmat(-100, 1, dim);
ub = repmat(100, 1, dim);
parent = repmat(0.1, 1, dim);
options = arooptions('Generations', 2000, 'InitialParent', parent);
options.Generations = 2000;
[x, f, generation, fvals] = aro(func, dim, lb, ub, options);
fprintf('Optimized the RASTRIGIN function with %d iterations and an initial parent.  x = %s, fval = %f\n\n', options.Generations, mat2str(x), f);
figure
plot(1:length(fvals), fvals)
drawnow
legend('Rastrigin')
xlabel('Iterations')
ylabel('Function Value')
title('Optimized by ARO using an initial parent')

% Set ARO to display its iterations 
options.Display = 'iter'; % use 'off' to display nothing, use 'final' to output final result
[x, f, generation, fvals] = aro(func, dim, lb, ub, options);