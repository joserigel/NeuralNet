#include "Linear.hpp"

Linear::Linear(unsigned int inputs, unsigned int outputs):
    Layer(inputs, outputs, (inputs + 1) * outputs) {
    // Syntax: weights[output][input]
    if (inputs == 0 || outputs == 0) {
        throw std::invalid_argument("input and output count must be bigger than 0");
    }

    // Initialize expressions
    for (unsigned int out = 0; out < outputs; out++) {
        //Prepare expressions
        std::shared_ptr<Expression> exp(weights[(out * (inputs + 1)) + inputs]);
        for (long int in = inputs - 1; in >= 0; in--) {
            std::shared_ptr<Expression> weight = weights[(out * (inputs + 1)) + in];
            std::shared_ptr<Expression> var = variables[in];
            
            std::shared_ptr<Expression> mult(new Multiplication(weight, var));
            std::shared_ptr<Expression> add(new Addition(mult, exp));
            exp.swap(add);
        }
        expressions[out] = exp;
    }
}