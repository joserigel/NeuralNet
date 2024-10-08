#include "Expression.hpp"

Power::Power(std::shared_ptr<Expression> base, std::shared_ptr<Expression> exponent):
    base(base), exponent(exponent) {}

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

    if (exponentDerivedEval != 0) {
        return this->eval(interpretation) * (a + b);
    } else {
        return this->eval(interpretation) * (b);
    }
    
}

float Power::eval(std::map<Variable*, float> interpretation) {
    return std::pow(base->eval(interpretation), exponent->eval(interpretation));
}

std::shared_ptr<Expression> Power::replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) {
    return std::shared_ptr<Expression>(new Power(base->replace(var, substitute), exponent->replace(var, substitute)));
}