#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "Tool.hpp"

class Hammer : public Tool {
public:
    Hammer(int uses=7) : Tool(uses) {
        std::cout << "[Hammer] constructor\n";
    }
    ~Hammer() {
        std::cout << "[Hammer] destructor\n";
    }
    void use();
};

#endif // HAMMER_HPP
