#include <string>
#include <set>

class Expression {
    public:
        std::set<string> getVariables();
}

class Variable: public Expression {
    private:
        string name;
    public:
        Variable(string name);
}

class Addition: public Expression {
    private:
        Expression left;
        Expression right;
    public:
        Addition(Expression left, Expression right);

}

class Multiplication: public Expression {
    private:
        Expression left;
        Expression right;
    public:
        Multiplication(Expression left, Expression right);
}

class Division: public Expression {
    private:
        Expression numerator;
        Expression denominator;
    public:
        Division(Expression numerator, Expression denominator);

}

class Power: public Expression {
    private:
        Expression base;
        Expression exponent;
    public:
        Power(Expression base, Expression exponent);
}