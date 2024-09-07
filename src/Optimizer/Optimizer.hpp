#ifndef Optimizer_HPP
#define Optimizer_HPP

#include "Loss.hpp"
#include "../Layers/Layer.hpp"

#include <vector>

class Optimizer {
    public:
        virtual void train(
            Layer* model, 
            Loss* loss,
            std::vector<std::vector<float>> inputs,
            std::vector<std::vector<float>> labels
            ) = 0;
};

class SGD: public Optimizer {
    public:
        void train(
            Layer* model, 
            Loss* loss,
            std::vector<std::vector<float>> inputs,
            std::vector<std::vector<float>> labels
            ) override;
}

#endif