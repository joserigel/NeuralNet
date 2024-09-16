#ifndef Expression_HPP
#define Expression_HPP

#include <string>
#include <set>
#include <map>
#include <stdexcept>
#include <memory>
#include <cmath>


class Variable;
class Expression;

class Expression: public std::enable_shared_from_this<Expression> {
    public:
        virtual std::set<Variable*> getVariables() = 0;
        virtual std::string to_string() = 0;
        virtual float eval(std::map<Variable*, float> interpretation) = 0;
        virtual float partialAndEval(Variable* var, std::map<Variable*, float> interpretation) = 0;
        virtual std::shared_ptr<Expression> replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) = 0;
};

class Variable: public Expression {
    private:
        std::string name;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        float partialAndEval(Variable* var, std::map<Variable*, float> interpretation) override;
        float eval(std::map<Variable*, float> interpretation) override;
        std::shared_ptr<Expression> replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) override;
        Variable(std::string name);
};

class Constant: public Expression {
    private:
        float value;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        float partialAndEval(Variable* var, std::map<Variable*, float> interpretation) override;
        float eval(std::map<Variable*, float> interpretation) override;
        std::shared_ptr<Expression> replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) override;
        Constant(float value);
};

class Addition: public Expression {
    private:
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        float partialAndEval(Variable* var, std::map<Variable*, float> interpretation) override;
        float eval(std::map<Variable*, float> interpretation) override;
        std::shared_ptr<Expression> replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) override;
        Addition(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

};

class Subtraction: public Expression {
    private:
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        float partialAndEval(Variable* var, std::map<Variable*, float> interpretation) override;
        float eval(std::map<Variable*, float> interpretation) override;
        std::shared_ptr<Expression> replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) override;
        Subtraction(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

};

class Multiplication: public Expression {
    private:
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        float partialAndEval(Variable* var, std::map<Variable*, float> interpretation) override;
        float eval(std::map<Variable*, float> interpretation) override;
        std::shared_ptr<Expression> replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) override;
        Multiplication(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
};

class Division: public Expression {
    private:
        std::shared_ptr<Expression> numerator;
        std::shared_ptr<Expression> denominator;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        float partialAndEval(Variable* var, std::map<Variable*, float> interpretation) override;
        float eval(std::map<Variable*, float> interpretation) override;
        std::shared_ptr<Expression> replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) override;
        Division(std::shared_ptr<Expression> numerator, std::shared_ptr<Expression> denominator);
};

class Power: public Expression {
    private:
        std::shared_ptr<Expression> base;
        std::shared_ptr<Expression> exponent;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        float partialAndEval(Variable* var, std::map<Variable*, float> interpretation) override;
        float eval(std::map<Variable*, float> interpretation) override;
        std::shared_ptr<Expression> replace(std::shared_ptr<Variable> var, std::shared_ptr<Expression> substitute) override;
        Power(std::shared_ptr<Expression> base, std::shared_ptr<Expression> exponent);
};

#endif