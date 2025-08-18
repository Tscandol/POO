#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Tool.hpp"

class Shovel : public Tool {
public:
    Shovel(int uses=5) : Tool(uses) {
        std::cout << "[Shovel] constructor\n";
    }
    ~Shovel() {
        std::cout << "[Shovel] dtor\n";
    }
    void use();
};

#endif // SHOVEL_HPP
