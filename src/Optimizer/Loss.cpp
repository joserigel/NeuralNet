#include "Loss.hpp"

std::shared_ptr<Expression> MeanSquaredError::calculate(
    Layer* model,
    std::vector<std::vector<float>>* inputs, 
    std::vector<std::vector<float>>* labels
    ) {
        std::shared_ptr<Expression> res;
        for (unsigned int i = 0; i < inputs->size(); i++) {
            std::vector<std::shared_ptr<Expression>> baked =
                model->bakeInputToExpressions((*inputs)[i]);
            std::shared_ptr<Expression> sum;
            for (unsigned int j = 0; j < baked.size(); j++) {
                std::shared_ptr<Constant> label(new Constant(-1 * (*labels)[i][j]));
                std::shared_ptr<Expression> add(new Addition(baked[0], label));
                std::shared_ptr<Expression> exponent(new Multiplication(add, add));
                
                if (j == 0) {
                    sum.swap(exponent);
                } else {
                    std::shared_ptr<Expression> clause(new Addition(exponent, sum));
                    sum.swap(clause);
                }
            }

            if (i == 0) {
                res.swap(sum);
            } else {
                std::shared_ptr<Expression> clause(new Addition(res, sum));
                res.swap(clause);
            }
        }
        std::shared_ptr<Expression> batchSize(new Constant(inputs->size()));
        std::shared_ptr<Expression> divide(new Division(res, batchSize));
        return divide;
        
}