#ifndef SGD_HPP
#define SGD_HPP

#include "Optimizer.hpp"

class SGD: public Optimizer {
    public:
        float learningRate = 0.01;
        void train(
            Layer* model, 
            Loss* loss,
            std::vector<std::vector<float>>* inputs,
            std::vector<std::vector<float>>* labels
            ) override;
};

#endif