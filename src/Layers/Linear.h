#include "Layer.h"

#include <vector>
#include <string>
#include <stdexcept>

class Linear: public Layer {
    private:
        std::vector<std::vector<float>> weights;
    public:
        unsigned int getInputs();
        unsigned int getOutputs();

        std::string to_string();
        std::vector<float> feed(std::vector<float> input);
        void train(
            std::vector<std::vector<float>> inputs, 
            std::vector<std::vector<float>> labels, 
            float learningRate
            );
    Linear(unsigned int input, unsigned int output);
};