#include "Layer.hpp"

Layer::Layer(
    unsigned int inputs,
    unsigned int outputs,
    unsigned int weights
    ) {
    // Initialize data members
    this->variables = new std::shared_ptr<Variable>[inputs];
    this->weights = new std::shared_ptr<Variable>[weights];
    this->expressions = new std::shared_ptr<Expression>[outputs];

    // Initialize variables
    for (unsigned int in = 0; in < inputs; in++) {
        this->variables[in] = std::shared_ptr<Variable>(new Variable("x_" + std::to_string(in)));       
    }

    // Initialize weights
    for (unsigned int w = 0; w < weights; w++) {
        this->weights[w] = std::shared_ptr<Variable>(new Variable("w_" + std::to_string(w)));
    }

    // Initialize weight values
    for (unsigned int i = 0; i < weights; i++) {
        weightValues[this->weights[i].get()] = 0;
    }

    // Save arguments
    this->inputs = inputs;
    this->outputs = outputs;
    this->weightCount = weights;
}

Layer::~Layer() {
    delete[] variables;
    delete[] weights;
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

std::map<Variable*, float> Layer::getWeightValues() {
    return weightValues;
}

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

    std::map<Variable*, float> interpretation = getWeightValues();
    
    for (unsigned int i = 0; i < input.size(); i++) {
        interpretation[variables[i].get()] = input[i];
    }

    std::vector<float> result;
    for (unsigned int i = 0; i < getOutputSize(); i++) {
        result.push_back(expressions[i].get()->eval(interpretation));
    }
    return result;
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

void Layer::setWeight(Variable* var, float newValue) {
    weightValues[var] = newValue;
}