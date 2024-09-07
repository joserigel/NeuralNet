#include "Expression.hpp"

Variable::Variable(std::string name) {
    this->name = name;
}

std::string Variable::to_string() {
    return name;
}

std::set<Variable*> Variable::getVariables() {
    std::set<Variable*> res;
    res.insert(this);
    return res;
}

Constant::Constant(float value) {
    this->value = value;
}

std::string Constant::to_string() {
    return std::to_string(value);
}

std::set<Variable*> Constant::getVariables() {
    return std::set<Variable*>();
}
