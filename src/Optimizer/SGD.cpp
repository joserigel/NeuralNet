#include "SGD.hpp"

void SGD::train(
    Layer* model, 
    Loss* loss,
    std::vector<std::vector<float>>* inputs,
    std::vector<std::vector<float>>* labels
    ) {
    
    // Get parameters
    std::shared_ptr<Expression> expression = loss->calculate(model, inputs, labels);
    std::vector<std::shared_ptr<Variable>> weights = model->getWeights();
    std::map<Variable*, float> weightValues = model->getWeightValues();

    // Update weights
    for (std::shared_ptr<Variable> weight: weights) {
        float val = weightValues[weight.get()];
        const float gradient = expression->partialAndEval(weight.get(), weightValues);
        val -= gradient * learningRate;
    
        model->setWeight(weight.get(), val);
    }
}