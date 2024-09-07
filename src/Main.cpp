#include "Layers/Linear.h"
#include "Layers/Sequential.h"
#include "Operators/Expression.hpp"
#include <iostream>
#include <string>

void LinearRegressionDemo() {
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
}

void ExpressionDemo() {
    Variable v1("A");
    Variable v2("B");
    Division d(&v1, &v2);
    Addition a(&d, &v2);
    Constant c(7);
    Power p(&v1, &c);

    std::map<Variable*, float> interpretation;
    interpretation[&v1] = 3;
    interpretation[&v2] = 5;

    std::cout << a.to_string() << std::endl;

    std::set<Variable*> test = a.getVariables();
    for (Variable* v: test) {
        std::cout << v->to_string() << std::endl;
    }

    std::cout << p.partialAndEval(&v1, interpretation) << std::endl;
}

int main() {
    ExpressionDemo();
    return 0;
}
