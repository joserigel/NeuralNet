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

float Power::partialAndEval(Variable* var, std::map<Variable*, float> interpretation) {
    const float exponentDerivedEval = exponent->partialAndEval(var, interpretation);
    const float baseDerivedEval = base->partialAndEval(var, interpretation);
    const float baseEval = base->eval(interpretation);
    const float a = exponentDerivedEval * std::log(baseEval);
    const float b = baseDerivedEval * (exponent->eval(interpretation) / baseEval);
    return this->eval(interpretation) * (a + b);
}

float Power::eval(std::map<Variable*, float> interpretation) {
    return std::pow(base->eval(interpretation), exponent->eval(interpretation));
}

Expression* Power::replace(Variable* var, Expression* substitute) {
    return new Power(base->replace(var, substitute), exponent->replace(var, substitute));
}