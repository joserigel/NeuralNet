#ifndef Layer_HPP
#define Layer_HPP

#include "../Operators/Expression.hpp"

#include <vector>
#include <string>
#include <stdexcept>

class Layer {
    protected:
        std::shared_ptr<Variable>* variables;
        std::shared_ptr<Variable>* weights;
        float* weightValues;
        std::shared_ptr<Expression>* expressions;
        unsigned int inputs;
        unsigned int outputs;
    public:
        std::vector<float> feed(std::vector<float> input);
        std::string to_string();
        unsigned int getInputSize();
        unsigned int getOutputSize();
        ~Layer();
};

#endif