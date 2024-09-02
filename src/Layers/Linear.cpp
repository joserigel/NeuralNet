#include "Linear.h"

unsigned int Linear::getInputs() {
    return weights[0].size() - 1;
}

unsigned int Linear::getOutputs() {
    return weights.size();
}

std::string Linear::to_string() {
    std::string res = "";
    for (unsigned int i = 0; i < getOutputs(); i++) {
        for (unsigned int j = 0; j < getInputs(); j++) {
            res += 
                std::to_string(weights[i][j]) + 
                "x_" + std::to_string(i) + "_" + std::to_string(j) + " + ";
        }
        res += std::to_string(weights[i][getInputs()]) + "\n";
    }
    return res;
}

Linear::Linear(unsigned int input, unsigned int output) {
    // Syntax: weights[output][input]
    if (input == 0 || output == 0) {
        throw std::invalid_argument("input and output count must be bigger than 0");
    }
    for (unsigned int i=0; i<output; i++) {
        weights.push_back(std::vector<float>(input + 1));
    }
}

float Linear::loss(
    std::vector<std::vector<float>> inputs,
    std::vector<std::vector<float>> labels
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
    float result = 0;
    for (unsigned int out = 0; out < getOutputs(); out++) {
        for (unsigned int m = 0; m < batchSize; m++) {
            float distance = 0;
            for (unsigned int in = 0; in < getInputs(); in++) {
                distance += weights[out][in] * inputs[m][in];
            }
            distance += weights[out][getInputs()];
            distance -= labels[m][out];

            distance *= distance;
            result += distance;
        }
    }
    return result / batchSize;
    
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

    for (unsigned int out = 0; out < getOutputs(); out++) {
        // Preprocess distance
        std::vector<float> distances(batchSize);
        for (unsigned int m = 0; m < batchSize; m++) {
            distances[m] = 0;
            for (unsigned int in = 0; in < getInputs(); in++) {
                distances[m] += weights[out][in] * inputs[m][in];
            }
            distances[m] += weights[out][getInputs()];
            distances[m] -= labels[m][out];
        }

        // Update weights
        for (unsigned int in = 0; in < getInputs(); in++) {
            float slope = 0;
            for (unsigned int m = 0; m < batchSize; m++) {
                slope += 2 * inputs[m][in] * distances[m];
            }
            slope /= batchSize;

            weights[out][in] -= learningRate * slope;
        }

        // Update bias
        float slope = 0;
        for (unsigned int m = 0; m < batchSize; m++) {
            slope += 2 * distances[m];
        }
        slope /= batchSize;

        weights[out][getInputs()] -= learningRate * slope;
    }
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