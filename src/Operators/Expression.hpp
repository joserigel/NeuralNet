#ifndef Expression_HPP
#define Expression_HPP

#include <string>
#include <set>

class Variable;

class Expression {
    public:
        virtual std::set<Variable*> getVariables() = 0;
        virtual std::string to_string() = 0;
};

class Variable: public Expression {
    private:
        std::string name;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        Variable(std::string name);
};

class Constant: public Expression {
    private:
        float value;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        Constant(float value);
};

class Addition: public Expression {
    private:
        Expression* left;
        Expression* right;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        Addition(Expression* left, Expression* right);

};

class Multiplication: public Expression {
    private:
        Expression* left;
        Expression* right;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        Multiplication(Expression* left, Expression* right);
};

class Division: public Expression {
    private:
        Expression* numerator;
        Expression* denominator;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        Division(Expression* numerator, Expression* denominator);
};

class Power: public Expression {
    private:
        Expression* base;
        Expression* exponent;
    public:
        std::set<Variable*> getVariables() override;
        std::string to_string() override;
        Power(Expression* base, Expression* exponent);
};

#endif