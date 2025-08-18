#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

struct Position {
    int x;
    int y;
    int z;

    Position(int x_=0, int y_=0, int z_=0)
    : x(x_), y(y_), z(z_) {
        std::cout << "[Position] constructor (" << x << "," << y << "," << z << ")\n";
    }

    Position(Position const & other)
    : x(other.x), y(other.y), z(other.z) {
        std::cout << "[Position] copy constructor\n";
    }

    Position & operator=(Position const & other) {
        if (this != &other) {
            x = other.x; y = other.y; z = other.z;
            std::cout << "[Position] operator=\n";
        }
        return *this;
    }

    ~Position() {
        std::cout << "[Position] destructor\n";
    }
};

#endif // POSITION_HPP
