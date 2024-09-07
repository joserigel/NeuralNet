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

float Variable::eval(std::map<Variable*, float> interpretation) {
    if (interpretation.contains(this)) {
        return interpretation[this];
    } else {
        throw std::invalid_argument("Variable " + this->to_string() + " not defined!");
    }
}

float Variable::partialAndEval(Variable* var, std::map<Variable*, float> interpretation) {
    if (var == this) {
        return 1;
    } else {
        return 0;
    }
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

float Constant::partialAndEval(Variable* var, std::map<Variable*, float> interpretation) {
    return 0;
}

float Constant::eval(std::map<Variable*, float> interpretation) {
    return this->value;
}
