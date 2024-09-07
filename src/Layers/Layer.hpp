#ifndef Layer_HPP
#define Layer_HPP

#include "../Operators/Expression.hpp"

#include <vector>
#include <string>
#include <stdexcept>

class Layer {
    protected:
        std::vector<Variable*> variables;
        std::vector<Variable*> weights;
        std::vector<float> weightValues;
        std::vector<Expression*> expressions;
    public:
        std::vector<float> feed(std::vector<float> input);
        std::string to_string();
};

#endif