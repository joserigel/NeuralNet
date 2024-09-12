#include "Layer.hpp"

std::string Layer::to_string() {
    std::string result = "";
    for (int i = 0; i < getOutputSize(); i++) {
        result += expressions[i]->to_string() + "\n";
    }
    return result;
}

std::vector<float> Layer::feed(std::vector<float> input) {
    if (getInputSize() != input.size()) {
        throw std::invalid_argument("input size mismatch!");
    }

    std::map<Variable*, float> interpretation;
    
    for (unsigned int i = 0; i < input.size(); i++) {
        interpretation[variables[i].get()] = input[i];
    }

    std::vector<float> result;
    for (unsigned int i = 0; i < getOutputSize(); i++) {
        result.push_back(expressions[i].get()->eval(interpretation));
    }
    return result;
}

Layer::~Layer() {
    delete[] variables;
    delete[] weights;
    delete[] weightValues;
    delete[] expressions;
}

unsigned int Layer::getInputSize() {
    return inputs;
}

unsigned int Layer::getOutputSize() {
    return outputs;
}

std::vector<std::shared_ptr<Variable>> Layer::getWeights() {
    return std::vector<std::shared_ptr<Variable>>(
        weights, weights + weightCount
    );
}

std::vector<std::shared_ptr<Variable>> Layer::getVariables() {
    return std::vector<std::shared_ptr<Variable>>(
        variables, variables + getInputSize()
    );
}

std::vector<std::shared_ptr<Expression>> Layer::getExpressions() {
    return std::vector<std::shared_ptr<Expression>>(
        expressions, expressions + getOutputSize()
    );
}

std::vector<float> Layer::getWeightValues() {
    return std::vector<float>(
        weightValues, weightValues + weightCount
    );
}

std::vector<std::shared_ptr<Expression>> Layer::bakeInputToExpressions(std::vector<float> input) {
    if (input.size() != getInputSize()) {
        throw std::invalid_argument("Input size mismatch!");
    }

    std::vector<std::shared_ptr<Expression>> result;
    for (unsigned int out = 0; out < getOutputSize(); out++) {
        std::shared_ptr<Expression> exp(expressions[out]);

        for (unsigned int in = 0; in < getInputSize(); in++) {
            std::shared_ptr<Expression> value(new Constant(input[in]));
            std::shared_ptr<Expression> newExp = exp->replace(variables[in], value);
            exp.swap(newExp);
        }
        result.push_back(exp);
    }
    return result;
}