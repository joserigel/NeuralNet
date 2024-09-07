#include "Expression.h"

Addition::Addition(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

std::string Addition::to_string() {
    return left->to_string() + "+" + right->to_string();
}

std::set<std::string> Addition::getVariables() {
    std::set<std::string> a = left->getVariables();
    std::set<std::string> b = right->getVariables();
    a.insert(b.begin(), b.end());
    return a;
}