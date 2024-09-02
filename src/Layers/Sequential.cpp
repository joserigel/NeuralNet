#include "Layer.h"
#include <vector>
class Sequential: Layer {
    public:
        std::vector<Layer> layers;

    Sequential(std::vector<Layer> layers) {
        this->layers = layers;
    }
    
    std::vector<float> feed(std::vector<float> inputs) {
        std::vector<float> result = inputs;
        for (std::vector<Layer>::iterator iter = layers.begin(); iter < layers.end(); iter++) {
            result = iter->feed(result);
        }
        return result;
    }
};