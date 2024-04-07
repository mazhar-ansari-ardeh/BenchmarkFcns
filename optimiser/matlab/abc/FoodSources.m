classdef FoodSources
    properties
       problem
       foodNumber;

        %
        % A food source which could not be improved through "limit" trials is abandoned by its employed bee.
        %
        limit

        stallCounter

        % The dimension of problem that is being solved.
        dimension;

        % The lower bound of the problem space
        LowerBound;

        % The upper bound of the problem space
        UpperBound;


        % Represents all food sources. Foods is the population of food sources. Each row of Foods matrix is a vector
        % holding D parameters to be optimized. The number of rows of Foods matrix equals to the this.fs.foodNumber
        % Type: double, two dimensional
        foods;

        % Represents objective-function values for all food sources
        % Type: double, one dimensional
        ofValue;

        % Holds fitness value of food sources
        % Type: double, one dimensional
        fitness

        % For each food source, holds the number of times that the bees could not improve that
        % food source.
        % Type: double, one dimensional
        trial;

        %
        % For each food source, holds the probability with which the onlooker bees choose the corresponding food source.
        % Type: double, one dimensional
        prob;

%       % Implementation specific. This variable could be defined local, but for performance reasons, it is considered global.
%       % It is a temporary variable that different parts of the the algorithm use to pass information among each other.
%       % Type: double, one dimensional
        solution;

        % Implementation specific. This variable could be defined local, but for performance reasons, it is considered global.
        % It holds the value of the objective function of <code>solution</code>.
        % Type: double, scalar
        ObjValSol;

        % Implementation specific. This variable could be defined local, but for performance reasons, it is considered global.
        % It holds the fitness of the <code>solution</code>.
        % Type: double, scalar
        FitnessSol;

        %
        % Holds the value of the objective function for the best solution found.
        % Type: double, scalar
        objValOfGlobalMin;

        %
        % Holds the parameters (food source) that yield the best solution.
        % Type: double, one dimensional
        paramsOfGlobalMin;

%       private int swarmSize = 5;
%       private double swarmProb = 0.5;
    end % Properties

    methods
        function this = FoodSources(a_problem, dimension, foodNumber, limit, lb, ub, initialPopulation)
            if (exist('initialPopulation', 'var') == false)
                initialPopulation = [];
            else
                if  isempty(initialPopulation) == false
                    assert(dimension == size(initialPopulation, 2), 'Given Dimension does not match given initial population')
                    assert(foodNumber == size(initialPopulation, 1), 'Given food source size does not match initial population')
                end
            end
            this.problem = a_problem;
            this.dimension = dimension;
            this.foodNumber = foodNumber;
            this.limit = limit;
            this.foods = zeros(foodNumber, dimension);
            this.ofValue =  zeros(1, foodNumber);
            this.fitness = zeros(1, foodNumber);
            this.trial  = zeros(1, foodNumber);
            this.prob   = zeros(1, foodNumber);
            this.solution = zeros(1, dimension);
            this.paramsOfGlobalMin = zeros(1, dimension);
            this.LowerBound = lb;
            this.UpperBound = ub;
            this.stallCounter = 0;
            this = initializeFoodSources(this, initialPopulation);
            this.objValOfGlobalMin = min(this.ofValue);
            this.paramsOfGlobalMin = this.foods(this.ofValue == this.objValOfGlobalMin, :);
        end

        function this = initializeFoodSources(this, initialPopulation)
            if(nargin > 1 && isempty(initialPopulation) == false)
                this.foods = initialPopulation;
                for index = 1:size(initialPopulation, 1)
                    this.ofValue(index) = this.problem(this.foods(index, :));
                    this.fitness(index) = this.calculateFitness(this.ofValue(index));
                end
                return
            end

            for i = 1:this.foodNumber
                this = newFoodSource(this, i);
                this.objValOfGlobalMin = this.ofValue(1);
                this.paramsOfGlobalMin = this.foods(1, :);
            end
        end

        % Creates a new random food source.
        % @param index
        function this =  newFoodSource(this, index)
            for j = 1:this.dimension
                r = ( rand * 32767 / (32767+ 1) );
                this.foods(index, j) = r * (this.UpperBound(j) - this.LowerBound(j)) + this.LowerBound(j);
            end
%             this.solution = this.foods(index, :);
            this.ofValue(index) = this.problem(this.foods(index, :));
            this.fitness(index) = this.calculateFitness(this.ofValue(index));
            this.trial(index) = 0;
        end

        function result = calculateFitness(this, fun)
            if(fun >= 0)
                result = 1 / (fun + 1);
            else
                result = 1 + abs(fun);
            end
        end

        function this = calculateProbabilities(this)
            maxFit = max(this.fitness);
            this.prob = (0.9 * (this.fitness / maxFit)) + 0.1;
        end

        % Updates the knowledge of the best food location in this
        % collection of food sources
        function this = MemorizeBestSource(this)
            minOfVal = min(this.ofValue);
            if(minOfVal < this.objValOfGlobalMin)
                this.objValOfGlobalMin = min(this.ofValue);
                this.paramsOfGlobalMin = this.foods(this.ofValue == this.objValOfGlobalMin, :);
                this.stallCounter = 0;
            else
                this.stallCounter = this.stallCounter + 1;
            end
        end

        function solution = createFoodSourceRandomlyFrom(this, from)
            dim = this.dimension;

            r = ( rand * 32767 / (32767 + 1) );
            param2change= ceil(r * dim);

            r = ( rand * 32767 / (32767+ 1) );
            neighbour = ceil(r * this.foodNumber);

            while(neighbour == from)
                r = ( rand * 32767 / (32767 + 1) );
                neighbour = ceil(r * this.foodNumber);
            end

            solution = this.foods(from, :);

            r = ( rand * 32767 / (32767 + 1) );
            solution(param2change) = this.foods(from, param2change)+(this.foods(from, param2change) - this.foods(neighbour, param2change))*(r-0.5)*2;

            % if generated parameter value is out of boundaries, it is shifted onto the boundaries
            if solution(param2change) > this.UpperBound(param2change)
                solution(param2change) = this.UpperBound(param2change);
            end
            if solution(param2change) < this.LowerBound(param2change)
                solution(param2change) = this.LowerBound(param2change);
            end

%           fs.ObjValSol = calculateFunction(fs.solution);
%           fs.FitnessSol = calculateFitness(fs.ObjValSol);
        end

    end

end
