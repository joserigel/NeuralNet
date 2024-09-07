#include "Layers/Linear.hpp"
#include "Operators/Expression.hpp"
#include <iostream>
#include <string>

void LinearRegressionDemo() {
    Linear linear(3, 3);

    // Input initialize
    std::cout << linear.to_string() << std::endl;
}

void ExpressionDemo() {
    Variable v1("A");
    Variable v2("B");
    Division d(&v1, &v2);
    Addition a(&d, &v2);
    Constant c(1.0f/3.0f);
    Power p(&v1, &c);

    std::map<Variable*, float> interpretation;
    interpretation[&v1] = 8;
    interpretation[&v2] = 5;

    std::cout << a.to_string() << std::endl;

    std::set<Variable*> test = a.getVariables();
    for (Variable* v: test) {
        std::cout << v->to_string() << std::endl;
    }

    std::cout << p.eval(interpretation) << std::endl;
}

int main() {
    LinearRegressionDemo();
    ExpressionDemo();
    return 0;
}
