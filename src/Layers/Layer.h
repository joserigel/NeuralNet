#ifndef Layer_H
#define Layer_H
#include <vector>


class Layer {
    public:
        virtual std::vector<float> feed(std::vector<float> input) = 0;
};
#endif