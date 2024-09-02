#include <vector>
#include <string>
#include "Layer.h"

class Linear: public Layer {
    public:
        std::vector<std::vector<float>> weights;
        std::string to_string();
        std::vector<float> feed(std::vector<float> input);
    Linear(unsigned int input, unsigned int output);
};