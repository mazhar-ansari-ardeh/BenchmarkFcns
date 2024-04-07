% Optimizes a given function with the Artificial Bee Colony algorithm (ABC).
% [X] = ABC(FITNESSFCN, NVARS) finds a local unconstrained minimum X to the
% FITNESSFCN using abc. NVARS is the dimension (number of design variables)
% of the FITNESSFCN. FITNESSFCN accepts a vector X of size 1-by-NVARS, and
% returns a scalar evaluated at X.
%
% X = ABC(FITNESSFCN,NVARS, lb,ub) defines a set of lower and upper bounds
% on the design variables, X, so that a solution is found in the range
% lb <= X <= ub. Use empty matrices for lb and ub if no bounds exist.
%
% X = ABC(FITNESSFCN,NVARS,lb,ub,options) minimizes with the default
% optimization parameters replaced by values in the structure OPTIONS.
% OPTIONS can be created with the AROOPTIONS function. See ABCOPTIONS for
% details.
%
% [X,FVAL] = ABC(FITNESSFCN, ...) returns FVAL, the value of the fitness
% function FITNESSFCN at the solution X.
%
% [X,FVAL, GENERATIONS] = ARO(FITNESSFCN, ...) returns GENERATIONS, a
% matrix that contains the the food source at each iteration of the
% algorithm that had the best fitness at that generation.
%
% [X,FVAL, GENERATIONS, FVAL_GENERATIONS] = ARO(FITNESSFCN, ...) returns
% FVAL_GENERATIONS, the value of the best fitness at each iteration of
% the algorithm.
%
% [X,FVAL, GENERATIONS, FVAL_GENERATIONS, POPULATIONS] = ARO(FITNESSFCN, ...)
% returns POPULATIONS, a cell array that contains values for population
% (food sources) of the algorithm at each iterations.
%
% Artificial Bee Colony was first Proposed by Dervis Karaboga in:
% D. Dervis Karaboga, An Idea Based On Honey Bee Swarm for Numerical
% Optimization, Technical Report-TR06,Erciyes University, Engineering
% Faculty, Computer Engineering Department 2005.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function [x_best, f_best, generations, fval_generations, populations] = abc(func, nvar, lb, ub, setting)

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
        setting = abcoptions('default');
    end

    max_iter = setting.Generations;

    InitialPopulation = setting.InitialPopulation;
    limit = setting.Limit;
    foodNumber = setting.PopulationSize;
    fs = FoodSources(func, nvar, foodNumber, limit, lb, ub, InitialPopulation);

    generations = zeros(max_iter, n);
    fval_generations = zeros(max_iter, 1);
    populations = cell(1, max_iter);
    for i = 1:max_iter
        fs = SendEmployedBees(func, fs);
        fs = SendOnlookerBees(func, fs);
        fs = fs.MemorizeBestSource();
        fs = SendScoutBees(fs);

        Display(setting, i, fs.objValOfGlobalMin)

        generations(i, :) = fs.paramsOfGlobalMin;
        fval_generations = fs.objValOfGlobalMin;
        populations{i} = fs.foods;

        if fs.stallCounter > setting.StallLimit
            break;
        end
    end

    x_best = fs.paramsOfGlobalMin;
    f_best = fs.objValOfGlobalMin;
end

function Display(setting, iteration, fval)
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

% Determines the food sources whose trial counter exceeds the "limit" value.
% In Basic ABC, only one scout is allowed to occur in each cycle
function fs = SendScoutBees(fs)
    maxtrialindex = find(max(fs.trial) == fs.trial, 1);
    if fs.trial(maxtrialindex) >= fs.limit
        fs = fs.newFoodSource(maxtrialindex);
    end
end

function fs = SendOnlookerBees(func, fs)
        fs = fs.calculateProbabilities();
        i = 1; t = 0;
        while(t <= fs.foodNumber)
            r = ( rand * 32767 / (32767 + 1) );
            if(r < fs.prob(i)) % choose a food source depending on its probability to be chosen*/
                t = t + 1;
                solution = fs.createFoodSourceRandomlyFrom(i);
                ObjValSol = func(solution);
                FitnessSol = fs.calculateFitness(ObjValSol);
                if (FitnessSol > fs.fitness(i))
                    % If the mutant solution is better than the current solution i, replace the solution with the mutant and reset the trial counter of solution i*/
                    fs.trial(i)=0;
                    fs.foods(i, :) = solution;
                    fs.ofValue(i) = ObjValSol;
                    fs.fitness(i) = FitnessSol;
                else
                    % if the solution i can not be improved, increase its trial counter*/
                    fs.trial(i) = fs.trial(i) + 1;
                end
            end
            i = i + 1;
            if (i == (fs.foodNumber))
                i = 1;
            end
        end % while
end

function fs = SendEmployedBees(func, fs)
    for i = 1: fs.foodNumber
            solution = fs.createFoodSourceRandomlyFrom(i);
            ObjValSol = func(solution);
            FitnessSol = fs.calculateFitness(ObjValSol);
            if (FitnessSol > fs.fitness(i))
                fs.trial(i)=0;
                fs.foods(i, :) = solution;
                fs.ofValue(i)= ObjValSol;
                fs.fitness(i) = FitnessSol;
            else
                % if the solution i can not be improved, increase its trial counter*/
                fs.trial(i) = fs.trial(i) + 1;
            end
    end
end
