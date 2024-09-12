#include "Expression.hpp"

Variable::Variable(std::string name): name(name) {}

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

std::shared_ptr<Expression> Variable::replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) {
    if (var.get() == this) {
        return substitute;
    } else {
        return shared_from_this();
    }
}