% Optimizes a given function with the Asexual Reproduction Algorithm. 
% [X] = ARO(FITNESSFCN, NVARS) finds a local unconstrained minimum X to the
% FITNESSFCN using aro. NVARS is the dimension (number of design variables)
% of the FITNESSFCN. FITNESSFCN accepts a vector X of size 1-by-NVARS, and 
% returns a scalar evaluated at X.
%
% X = ARO(FITNESSFCN,NVARS, lb,ub) defines a set of lower and upper bounds 
% on the design variables, X, so that a solution is found in the range 
% lb <= X <= ub. Use empty matrices for lb and ub if no bounds exist. 
%
% X = ARO(FITNESSFCN,NVARS,lb,ub,options) minimizes with the default 
% optimization parameters replaced by values in the structure OPTIONS. 
% OPTIONS can be created with the AROOPTIONS function. See AROOPTIONS for 
% details.
% 
% [X,FVAL] = ARO(FITNESSFCN, ...) returns FVAL, the value of the fitness
% function FITNESSFCN at the solution X.
% 
% [X,FVAL, GENERATIONS] = ARO(FITNESSFCN, ...) returns GENERATIONS, a 
% matrix that contains the value of X at each iteration of the algorithm.
% 
% [X,FVAL, GENERATIONS, FVAL_GENERATIONS] = ARO(FITNESSFCN, ...) returns
% FVAL_GENERATIONS, the value of the fitness function at each iteration of 
% the algorithm. 
% 
% Asexual Reproduction Algorithm was first Proposed by Alireza Farasata, 
% Mohammad B. Menhaj, Taha Mansouri, Mohammad Reza Sadeghi Moghadamd in:
% Alireza Farasat, Mohammad B. Menhaj, Taha Mansouri, Mohammad Reza Sadeghi 
% Moghadam, ARO: A new model-free optimization algorithm inspired from 
% asexual reproduction, Applied Soft Computing, Volume 10, Issue 4, 
% September 2010, Pages 1284-1292, ISSN 1568-4946, 
% http://dx.doi.org/10.1016/j.asoc.2010.05.011.
% (http://www.sciencedirect.com/science/article/pii/S1568494610001122)
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function [x, fval, generations, fval_generations] = aro(func, nvar, lb, ub, setting)

    if nvar <= 0
        error('Dimension cannot be zero or negative');
    end
    
    if exist('ub', 'var') == 0 || isempty(ub)
        ub = repmat(double(intmax), 1, nvar);
    end
    
    if exist('lb', 'var') == 0 || isempty(lb)
        lb = repmat(double(intmin), 1, nvar);
    end
    
    [m, n] = size(lb);
    if m== 0 || n == 0
        error('Bounds cannot be empty')
    end
    if(m ~= size(ub, 1))
        error('Dimensions of bounds mismatch')
    end
    if(n ~= size(ub, 2))
        error('Dimensions of bounds mismatch')
    end
    if(m ~= 1 && n ~= 1)
        error('Bounds must be a vector')
    end
    if m~= 1 
        lb = lb';
        ub = ub';
    end
    
    if exist('setting', 'var') == 0
        setting = arooptions('default');
    end
    
    max_iterations = setting.Generations;
    parent = setting.InitialParent;
        
    if isempty(parent)
        parent = lb + (ub - lb) * rand;
    end
    
    generations = zeros(max_iterations, n);
    fval_generations = zeros(max_iterations, 1);
    for i = 1:max_iterations
        fit_parent = func(parent);
        bud = aro_reproduce(parent, lb, ub);
        fit_bud = func(bud);
        if(fit_parent > fit_bud)
            parent = bud;
            fval_generations(i) = fit_bud;
        else
            fval_generations(i) = fit_parent;
        end
        generations(i, :) = parent;
        aro_display(setting, i, fval_generations(i))
    end
    
    fval = func(parent);
    x = parent;
end

function aro_display(setting, iteration, fval)
    switch setting.Display
        case 'off' 
            return
        case 'iter'
            fprintf('Generation: %d \t f(x): %f\n', iteration, fval)
            drawnow update
            return;
        case 'final'
            if iteration == setting.Generations
                fprintf('Generation: %d \t f(x): %f\n', iteration, fval)
            end
    end
end





