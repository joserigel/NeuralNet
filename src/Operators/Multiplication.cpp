#include "Expression.hpp"

Multiplication::Multiplication(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
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