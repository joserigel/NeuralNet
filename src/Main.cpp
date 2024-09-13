#include "Layers/Linear.hpp"
#include "Operators/Expression.hpp"
#include "Optimizer/Loss.hpp"
#include "Optimizer/SGD.hpp"
#include <iostream>
#include <string>

void LinearRegressionDemo() {
    std::vector<std::vector<float>> inputs = {
        {1, 2, 3},
        {3, 4, 5}
    };

    std::vector<std::vector<float>> labels = {
        {1, 2},
        {3, 2}
    };

    Linear linear(3, 2);
    SGD sgd;
    MeanSquaredError mse;
    for (unsigned int epoch = 0; epoch < 1000; epoch++) {
        sgd.train(&linear, &mse, inputs, labels);
    }

    std::cout << linear.to_string();
}

int main() {
    LinearRegressionDemo();
    return 0;
}
