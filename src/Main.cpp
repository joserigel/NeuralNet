#include "Layers/Linear.h"
#include <iostream>
#include <string>

int main() {
    Linear linear(1, 3);
    std::cout << linear.getInputs() << ":" << linear.getOutputs() << std::endl;    
    return 0;
}
