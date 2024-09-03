#include "Layers/Linear.h"
#include "Layers/Sequential.h"
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
    for (unsigned int epoch = 0; epoch < 3000; epoch++) {
        linear.train(inputs, labels, 0.02);
        
    }


    std::vector<Layer*> l;
    l.push_back(&linear);
    l.push_back(&linear);
    
    

    Sequential sequential(l);
    std::cout << linear.to_string();
    std::cout << sequential.feed(std::vector<float>(1, 1))[0] << std::endl;
    return 0;
}
