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
        std::map<Variable*, float> weightValues;
        std::shared_ptr<Expression>* expressions;
        unsigned int inputs;
        unsigned int weightCount;
        unsigned int outputs;
    public:
        std::vector<float> feed(std::vector<float> input);
        std::string to_string();
        unsigned int getInputSize();
        unsigned int getOutputSize();
        std::vector<std::shared_ptr<Variable>> getVariables();
        std::vector<std::shared_ptr<Variable>> getWeights();
        std::vector<std::shared_ptr<Expression>> getExpressions();
        std::vector<std::shared_ptr<Expression>> bakeInputToExpressions(std::vector<float> input);
        std::map<Variable*, float> getWeightValues();
        void setWeight(Variable* var, float newValue);
        Layer(unsigned int inputs, unsigned int outputs, unsigned int weights);
        ~Layer();
};

#endif