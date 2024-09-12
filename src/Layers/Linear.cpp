#include "Linear.hpp"

Linear::Linear(unsigned int input, unsigned int output) {
    // Syntax: weights[output][input]
    if (input == 0 || output == 0) {
        throw std::invalid_argument("input and output count must be bigger than 0");
    }


    // initialize data members
    variables = new std::shared_ptr<Variable>[input];
    weights = new std::shared_ptr<Variable>[(input + 1) * output];
    weightValues = new float[(input + 1) * output];
    expressions = new std::shared_ptr<Expression>[output];

    inputs = input;
    outputs = output;
    weightCount = (input + 1) * output;

    // Initialize variables
    for (unsigned int in = 0; in < input; in++) {
        variables[in] = std::shared_ptr<Variable>(new Variable("x_" + std::to_string(in)));       
    }

    // Initialize expressions
    for (unsigned int out = 0; out < output; out++) {
        
        // Initialize weights
        for (unsigned int in = 0; in < input; in++) {
            weights[(out * (input + 1)) + in] = std::shared_ptr<Variable>(new Variable("w_" + std::to_string(in)));
        }

        // Initialize biases
        std::shared_ptr<Variable> bias(new Variable("b"));
        weights[(out * (input + 1)) + input] = bias;

        //Prepare expressions
        std::shared_ptr<Expression> exp(bias);
        for (long int in = input - 1; in >= 0; in--) {
            std::shared_ptr<Expression> weight = weights[(out * (input + 1)) + in];
            std::shared_ptr<Expression> var = variables[in];
            
            std::shared_ptr<Expression> mult(new Multiplication(weight, var));
            std::shared_ptr<Expression> add(new Addition(mult, exp));
            exp.swap(add);
        }
        expressions[out] = exp;
    }
}

void Layer::updateWeight(unsigned int index, float newWeight) {
    weightValues[index] = newWeight;
}