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