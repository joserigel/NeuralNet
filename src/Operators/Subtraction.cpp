#include "Expression.hpp"

Subtraction::Subtraction(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
    left(left), right(right) {
}

std::string Subtraction::to_string() {
    return left->to_string() + "-" + right->to_string();
}

std::set<Variable*> Subtraction::getVariables() {
    std::set<Variable*> a = left->getVariables();
    std::set<Variable*> b = right->getVariables();
    a.insert(b.begin(), b.end());
    return a;
}

float Subtraction::partialAndEval(Variable* var, std::map<Variable*, float> interpretation) {
    return left->partialAndEval(var, interpretation) - right->partialAndEval(var, interpretation);
}

float Subtraction::eval(std::map<Variable*, float> interpretation) {
    return left->eval(interpretation) - right->eval(interpretation);
}

std::shared_ptr<Expression> Subtraction::replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) {
    return std::shared_ptr<Expression>(new Subtraction(left->replace(var, substitute), right->replace(var, substitute)));
}