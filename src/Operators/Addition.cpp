#include "Expression.hpp"

Addition::Addition(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
    left(left), right(right) {
}

std::string Addition::to_string() {
    return left->to_string() + "+" + right->to_string();
}

std::set<Variable*> Addition::getVariables() {
    std::set<Variable*> a = left->getVariables();
    std::set<Variable*> b = right->getVariables();
    a.insert(b.begin(), b.end());
    return a;
}

float Addition::partialAndEval(Variable* var, std::map<Variable*, float> interpretation) {
    return left->partialAndEval(var, interpretation) + right->partialAndEval(var, interpretation);
}

float Addition::eval(std::map<Variable*, float> interpretation) {
    return left->eval(interpretation) + right->eval(interpretation);
}

std::shared_ptr<Expression> Addition::replace(Variable* var, std::shared_ptr<Expression> substitute) {
    return std::shared_ptr<Expression>(new Addition(left->replace(var, substitute), right->replace(var, substitute)));
}