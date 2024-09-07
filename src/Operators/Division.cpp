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

float Division::partialAndEval(Variable* var, std::map<Variable*, float> interpretation) {
    const float numeratorEval = numerator->eval(interpretation);
    const float denominatorEval = denominator->eval(interpretation);
    const float numeratorDerived = numerator->partialAndEval(var, interpretation);
    const float denominatorDerived = denominator->partialAndEval(var, interpretation);
    return ((denominatorEval * numeratorDerived) - (numeratorEval * denominatorDerived)) 
        / (denominatorEval * denominatorEval);
}

float Division::eval(std::map<Variable*, float> interpretation) {
    return numerator->eval(interpretation) / denominator->eval(interpretation);
}

Expression* Division::replace(Variable* var, Expression* substitute) {
    return new Division(numerator->replace(var, substitute), denominator->replace(var, substitute));
}