#include "Expression.hpp"

Division::Division(Expression* numerator, Expression* denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

std::string Division::to_string() {
    return numerator->to_string() + "/" + denominator->to_string();
}

std::set<Variable*> Division::getVariables() {
    std::set<Variable*> a = numerator->getVariables();
    std::set<Variable*> b = denominator->getVariables();
    a.insert(b.begin(), b.end());
    return a;
}

float Division::eval(std::map<Variable*, float> interpretation) {
    return numerator->eval(interpretation) / denominator->eval(interpretation);
}