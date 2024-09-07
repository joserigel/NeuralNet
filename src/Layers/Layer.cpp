#include "Layer.hpp"

std::string Layer::to_string() {
    std::string result = "";
    for (Expression* exp: expressions) {
        result += exp->to_string() + "\n";
    }
    return result;
}

std::vector<float> Layer::feed(std::vector<float> input) {
    if (variables.size() != input.size()) {
        throw std::invalid_argument("input size mismatch!");
    }

    std::map<Variable*, float> interpretation;
    
    for (unsigned int i = 0; i < input.size(); i++) {
        interpretation[variables[i]] = input[i];
    }

    std::vector<float> result;
    for (unsigned int i = 0; i < expressions.size(); i++) {
        result.push_back(expressions[i]->eval(interpretation));
    }
    return result;
}