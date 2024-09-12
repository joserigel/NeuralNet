#ifndef Loss_HPP
#define Loss_HPP

#include "../Operators/Expression.hpp"
#include "../Layers/Layer.hpp"

#include <vector>

class Loss {
    public:
        virtual std::shared_ptr<Expression> calculate(
            Layer* model, 
            std::vector<std::vector<float>> inputs, 
            std::vector<std::vector<float>> labels
            ) = 0;
};

class MeanSquaredError : public Loss {
    public:
        std::shared_ptr<Expression> calculate(
            Layer* model, 
            std::vector<std::vector<float>> inputs, 
            std::vector<std::vector<float>> labels
            ) override;
};

#endif