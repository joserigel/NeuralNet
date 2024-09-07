#include "Expression.hpp"

Power::Power(Expression* base, Expression* exponent) {
    this->base = base;
    this->exponent = exponent;
}

std::string Power::to_string() {
    return base->to_string() + "^" + exponent->to_string();
}

std::set<Variable*> Power::getVariables() {
    std::set<Variable*> a = base->getVariables();
    std::set<Variable*> b = exponent->getVariables();
    a.insert(b.begin(), b.end());
    return a;
}

float Power::eval(std::map<Variable*, float> interpretation) {
    return std::pow(base->eval(interpretation), exponent->eval(interpretation));
}