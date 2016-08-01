function [x_best, f_best] = abc(func, dim, lb, ub, foodNumber, limit, max_iter)
    fs = FoodSources(func, dim, foodNumber, limit, lb, ub);
    
    for i = 1:max_iter
        fs = SendEmployedBees(func, fs);
        fs = SendOnlookerBees(func, fs);
        fs = fs.MemorizeBestSource();
        fs = SendScoutBees(fs);
        fprintf('%f\n', fs.objValOfGlobalMin);
    end
    
    x_best = fs.paramsOfGlobalMin;
    f_best = fs.objValOfGlobalMin;
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