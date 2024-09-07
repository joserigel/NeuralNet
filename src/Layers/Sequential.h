#include "Layer.h"

#include <vector>

class Sequential: public Layer {
    private:
        std::vector<Layer*> *layers;
    public:
        std::vector<float> feed(std::vector<float> inputs) override;
        Sequential(std::vector<Layer*>& layers);
};