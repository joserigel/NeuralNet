#include "Expression.h"

Variable::Variable(std::string name) {
    this->name = name;
}

std::string Variable::to_string() {
    return name;
}

std::set<std::string> Variable::getVariables() {
    std::set<std::string> res;
    res.insert(this->name);
    return res;
}

Constant::Constant(float value) {
    this->value = value;
}

std::string Constant::to_string() {
    return std::to_string(value);
}

std::set<std::string> Constant::getVariables() {
    return std::set<std::string>();
}
