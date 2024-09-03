#include "Sequential.h"

Sequential::Sequential(std::vector<Layer*>& layers) {
    this->layers = &layers;
}
    
std::vector<float> Sequential::feed(std::vector<float> inputs) {
    std::vector<float> result = inputs;
    for (std::vector<Layer*>::iterator iter = (*layers).begin(); iter < (*layers).end(); iter++) {
        result = (*iter)->feed(result);
    }
    return result;
}