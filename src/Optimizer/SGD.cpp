#include "SGD.hpp"

void SGD::train(
    Layer* model, 
    Loss* loss,
    std::vector<std::vector<float>> inputs,
    std::vector<std::vector<float>> labels
    ) {
    
    std::shared_ptr<Expression> expression = loss->calculate(model, inputs, labels);
    std::vector<std::shared_ptr<Variable>> weights = model->getWeights();
    std::vector<float> weightValues = model->getWeightValues();

    std::map<Variable*, float> interpretation;
    for (unsigned int i = 0; i < weights.size(); i++) {
        interpretation[weights[i].get()] = weightValues[i];
    }

    for (unsigned int i = 0; i < weights.size(); i++) {
        float weight = weightValues[i];
        
        const float gradient = expression->partialAndEval(weights[i].get(), interpretation);
        std::cout << "grad: " << gradient << std::endl;
        weight -= gradient * learningRate;
        

        model->updateWeight(i, weight);
    }
}