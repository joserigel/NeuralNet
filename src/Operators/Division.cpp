#include "Expression.h"

Division::Division(Expression* numerator, Expression* denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

std::string Division::to_string() {
    return numerator->to_string() + "/" + denominator->to_string();
}

std::set<std::string> Division::getVariables() {
    std::set<std::string> a = numerator->getVariables();
    std::set<std::string> b = denominator->getVariables();
    a.insert(b.begin(), b.end());
    return a;
}