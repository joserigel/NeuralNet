#include "Layers/Linear.h"
#include <iostream>
#include <string>

int main() {
    Linear linear(1, 1);

    // Input initialize
    std::vector<std::vector<float>> inputs;
    inputs.push_back(std::vector<float>(1, 1));
    inputs.push_back(std::vector<float>(1, 2));

    std::vector<std::vector<float>> labels;
    labels.push_back(std::vector<float>(1, 2));
    labels.push_back(std::vector<float>(1, 4));

    float decay = 1;
    for (unsigned int epoch = 0; epoch < 101; epoch++) {
        linear.train(inputs, labels, 0.08);
        std::cout << linear.loss(inputs, labels) << std::endl;
    }
    std::cout << linear.to_string();
    std::cout << linear.getOutputs() << std::endl;
    return 0;
}
