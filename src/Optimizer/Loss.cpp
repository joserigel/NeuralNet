#include "Loss.hpp"


std::shared_ptr<Expression> perRowLoss(
    Layer* model,
    std::vector<float> input, 
    std::vector<float> label
    ) {
    std::shared_ptr<Expression> result = 0;
    std::vector<std::shared_ptr<Expression>> bakedExpression 
        = model->bakeInputToExpressions(input);

    std::shared_ptr<Expression> sum = 0;
    for (unsigned int j = 0; j < bakedExpression.size(); j++) {
        std::shared_ptr<Expression> labelFeature(new Constant(label[j]));
        std::shared_ptr<Expression> difference(new Subtraction(bakedExpression[j], labelFeature));
        std::shared_ptr<Expression> exponent(new Constant(2));
        std::shared_ptr<Expression> squared(new Power(difference, exponent));
        
        if (sum) {
            std::shared_ptr<Expression> add(new Addition(sum, squared));
            sum.swap(add);
        } else {
            sum.swap(squared);
        }
    }
    return sum;
}



std::shared_ptr<Expression> MeanSquaredError::calculate(
    Layer* model,
    std::vector<std::vector<float>>* inputs, 
    std::vector<std::vector<float>>* labels
    ) {
        if (inputs->size() == 0 || labels->size() == 0) {
            throw std::invalid_argument("inputs and labels must be bigger than 0!");
        }

        if (inputs->size() != labels->size()) {
            throw std::invalid_argument("inputs and labels size mismatch!");
        }


        std::shared_ptr<Expression> result = perRowLoss(
            model,
            (*inputs)[0],
            (*labels)[0]
        );
        for (unsigned int i = 1; i < inputs->size(); i++) {
            std::shared_ptr<Expression> add(new Addition(
                perRowLoss(model, (*inputs)[i], (*labels)[i]),
                result
                ));
            result.swap(add);
        }

        std::shared_ptr<Expression> rowCount(new Constant(inputs->size()));
        std::shared_ptr<Expression> divide(new Division(result, rowCount));
        return divide;
}