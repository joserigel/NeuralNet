#include "Expression.h"

Power::Power(Expression* base, Expression* exponent) {
    this->base = base;
    this->exponent = exponent;
}

std::string Power::to_string() {
    return base->to_string() + "^" + exponent->to_string();
}

std::set<std::string> Power::getVariables() {
    std::set<std::string> a = base->getVariables();
    std::set<std::string> b = exponent->getVariables();
    a.insert(b.begin(), b.end());
    return a;
}