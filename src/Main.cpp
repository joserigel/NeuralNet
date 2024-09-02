#include "Layers/Linear.h"
#include <iostream>
#include <string>

int main() {
    Linear linear(10, 3);
    std::cout << linear.to_string();
    std::cout << linear.feed(std::vector<float>(10))[0];
    return 0;
}
