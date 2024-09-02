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

Linear::Linear(unsigned int input, unsigned int output) {
    for (unsigned int i=0; i<output; i++) {
        weights.push_back(std::vector<float>(input + 1));
    }
}

std::vector<float> Linear::feed(std::vector<float> input) {
    std::vector<float> result(weights.size());
    for (unsigned int i = 0; i < weights.size(); i++) {
        for (unsigned int j = 0; j < weights[i].size() - 1; j++) {
            result[i] += input[j] * weights[i][j];
        }
        result[i] += weights[i][weights[i].size() - 1];
    }
    return result;
}