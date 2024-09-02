#include "Linear.h"


std::string Linear::to_string() {
    std::string res = "";
    for (unsigned int i = 0; i < weights.size(); i++) {
        for (unsigned int j = 0; j < weights[i].size(); j++) {
            res += std::to_string(weights[i][j]) + ", ";
        }
        res += "\n";
    }
    return res;
}

unsigned int Linear::getInputs() {
    return weights[0].size() - 1;
}

unsigned int Linear::getOutputs() {
    return weights.size();
}

Linear::Linear(unsigned int input, unsigned int output) {
    if (input == 0 || output == 0) {
        throw std::invalid_argument("input and output count must be bigger than 0");
    }
    for (unsigned int i=0; i<output; i++) {
        weights.push_back(std::vector<float>(input + 1));
    }
}

void Linear::train(
    std::vector<std::vector<float>> inputs,
    std::vector<std::vector<float>> labels,
    float learningRate
) {
    if (inputs.size() != labels.size()) {
        throw std::invalid_argument("input and label size mismatch!");
    }

    if (inputs.size() == 0) {
        throw std::invalid_argument("batch empty!");
    }

    if (inputs[0].size() != getInputs()) {
        throw std::invalid_argument("input shape mismatch!");
    }

    if (labels[0].size() != getOutputs()) {
        throw std::invalid_argument("output and label shape mismatch!");
    }
    
    unsigned int batchSize = inputs.size();
}

std::vector<float> Linear::feed(std::vector<float> input) {
    if (input.size() != getInputs()) {
        throw std::invalid_argument("input shape mismatch!");
    }
    
    std::vector<float> result(getOutputs());
    for (unsigned int i = 0; i < getOutputs(); i++) {
        for (unsigned int j = 0; j < getInputs(); j++) {
            result[i] += input[j] * weights[i][j];
        }
        result[i] += weights[i][getInputs()];
    }
    return result;
}