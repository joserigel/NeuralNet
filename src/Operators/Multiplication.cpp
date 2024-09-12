#include "Expression.hpp"

Multiplication::Multiplication(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
    : left(left), right(right) {
}

std::string Multiplication::to_string() {
    return left->to_string() + "*" + right->to_string();
}

std::set<Variable*> Multiplication::getVariables() {
    std::set<Variable*> a = left->getVariables();
    std::set<Variable*> b = right->getVariables();
    a.insert(b.begin(), b.end());
    return a;
}

float Multiplication::partialAndEval(Variable* var, std::map<Variable*, float> interpretation) {
    const float leftEval = left->eval(interpretation);
    const float leftDerivedEval = left->partialAndEval(var, interpretation);
    const float rightEval = right->eval(interpretation);
    const float rightDerivedEval = right->partialAndEval(var, interpretation);
    return (leftEval * rightDerivedEval) + (rightEval * leftDerivedEval);
}

float Multiplication::eval(std::map<Variable*, float> interpretation) {
    return left->eval(interpretation) * right->eval(interpretation);
}

std::shared_ptr<Expression> Multiplication::replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) {
    return std::shared_ptr<Expression>(new Multiplication(left->replace(var, substitute), right->replace(var, substitute)));
}