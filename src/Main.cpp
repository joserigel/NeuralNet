#include "Layers/Linear.hpp"
#include "Operators/Expression.hpp"
#include "Optimizer/Loss.hpp"
#include "Optimizer/SGD.hpp"
#include <iostream>
#include <string>

void LinearRegressionDemo() {
    Linear linear(1, 1);
    // Input initialize
    std::cout << linear.to_string() << std::endl;

    std::vector<float> inp;
    inp.push_back(1);

    std::vector<float> label;
    label.push_back(1);

    std::vector<std::vector<float>> inputs;
    inputs.push_back(inp);
    inputs.push_back(inp);

    std::vector<std::vector<float>> labels;
    labels.push_back(label);
    
    std::cout << "test " << linear.bakeInputToExpressions(inp)[0]->to_string() << std::endl;

    MeanSquaredError mse;
    std::shared_ptr<Expression> loss = mse.calculate(&linear, inputs, labels);
    std::cout << "MSE: " << loss->to_string() << std::endl;

    std::cout << "BEFORE TRAINING" << std::endl;
    for (std::shared_ptr<Expression> weight: linear.getVariables()) {
        std::cout << weight->to_string() << std::endl;
    }

    SGD sgd;
    for (unsigned int epoch = 0; epoch < 1000; epoch++) {
        sgd.train(&linear, &mse, inputs, labels);
    }

    std::cout << "AFTER TRAINING" << std::endl;
    for (float weight: linear.getWeightValues()) {
        std::cout << weight << std::endl;
    }
    std::cout << "done!";
    
}

void ExpressionDemo() {
    std::shared_ptr<Variable> A(new Variable("A"));
    std::shared_ptr<Variable> B(new Variable("B"));

    std::shared_ptr<Expression> D(new Division(A, B));
    std::map<Variable*, float> interpretation;
    interpretation[A.get()] = 1;
    interpretation[B.get()] = 5;
    
    std::shared_ptr<Expression> Test = D->replace(B, B);

    std::cout << D->eval(interpretation) << std::endl;
    std::cout << D->partialAndEval(B.get(), interpretation) << std::endl;
    
}

int main() {
    LinearRegressionDemo();
    ExpressionDemo();
    return 0;
}
