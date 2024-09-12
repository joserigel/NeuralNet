#include "Expression.hpp"

Constant::Constant(float value) {
    this->value = value;
}

std::string Constant::to_string() {
    return std::to_string(value);
}

std::set<Variable*> Constant::getVariables() {
    return std::set<Variable*>();
}

float Constant::partialAndEval(Variable* var, std::map<Variable*, float> interpretation) {
    return 0;
}

float Constant::eval(std::map<Variable*, float> interpretation) {
    return this->value;
}

std::shared_ptr<Expression> Constant::replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) {
    return std::shared_ptr<Expression>(new Constant(this->value));
}