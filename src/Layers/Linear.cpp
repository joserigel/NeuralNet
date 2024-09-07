#include "Linear.hpp"

Linear::Linear(unsigned int input, unsigned int output) {
    // Syntax: weights[output][input]
    if (input == 0 || output == 0) {
        throw std::invalid_argument("input and output count must be bigger than 0");
    }
    for (unsigned int out = 0; out < output; out++) {
        for (unsigned int in = 0; in < input; in++) {
            Variable* var = new Variable("x_" + std::to_string(in));
            variables.push_back(var);

            Variable* weight = new Variable("w_" + std::to_string(in));
            weights.push_back(weight);
        }
        Variable* b = new Variable("b");
        weights.push_back(b);

        Expression* exp = b;
        
        for (long int in = input - 1; in >= 0; in--) {
            Multiplication* mult = new Multiplication(weights[in], variables[in]);
            Addition* add = new Addition(mult, exp);
            exp = add;
        }

        expressions.push_back(exp);
    }
    
}