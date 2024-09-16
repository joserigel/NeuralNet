#include "Layers/Linear.hpp"
#include "Operators/Expression.hpp"
#include "Optimizer/Loss.hpp"
#include "Optimizer/SGD.hpp"
#include <iostream>
#include <string>

void LinearRegressionDemo() {
    std::vector<std::vector<float>> inputs = {
        {1, 2},
        {3, 2}
    };

    std::vector<std::vector<float>> labels = {
        {1, 2},
        {3, 2}
    };

    Linear linear(2, 2);
    SGD sgd;
    MeanSquaredError mse;
    sgd.learningRate = 0.03;
    std::cout << linear.to_string();
    
    for (unsigned int epoch = 0; epoch < 500; epoch++) {
        sgd.train(&linear, &mse, &inputs, &labels);
    }

    std::cout << mse.calculate(&linear, &inputs, &labels)->to_string() << std::endl;

    std::cout << linear.feed(inputs[0])[0] << " " << linear.feed(inputs[0])[1] << std::endl;
}

int main() {
    LinearRegressionDemo();
    return 0;
}
