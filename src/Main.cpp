#include "Layers/Linear.h"
#include <iostream>
#include <string>

int main() {
    Linear linear(1, 1);

    // Input initialize
    std::vector<std::vector<float>> inputs;
    inputs.push_back(std::vector<float>(1, 1));
    inputs.push_back(std::vector<float>(1, 5));
    inputs.push_back(std::vector<float>(1, 13));

    std::vector<std::vector<float>> labels;
    labels.push_back(std::vector<float>(1, 3));
    labels.push_back(std::vector<float>(1, 4));
    labels.push_back(std::vector<float>(1, 51));

    float decay = 1;
    for (unsigned int epoch = 0; epoch < 800; epoch++) {
        linear.train(inputs, labels, 0.015);
        
    }
    std::cout << linear.to_string();
    return 0;
}
