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
    std::shared_ptr<Variable> A(new Variable("A"));
    std::shared_ptr<Variable> B(new Variable("B"));

    std::shared_ptr<Expression> D(new Division(A, B));
    std::map<Variable*, float> interpretation;
    interpretation[A.get()] = 1;
    interpretation[B.get()] = 5;

    std::cout << D->eval(interpretation) << std::endl;
    std::cout << D->partialAndEval(B.get(), interpretation) << std::endl;
}

int main() {
    LinearRegressionDemo();
    ExpressionDemo();
    return 0;
}
