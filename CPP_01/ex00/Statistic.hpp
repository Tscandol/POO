#ifndef STATISTIC_HPP
#define STATISTIC_HPP

#include <iostream>

struct Statistic {
    int level;
    int exp;

    Statistic(int lvl=1, int xp=0)
    : level(lvl), exp(xp) {
        std::cout << "[Statistic] constructor (level=" << level << ", exp=" << exp << ")\n";
    }

    Statistic(Statistic const & other)
    : level(other.level), exp(other.exp) {
        std::cout << "[Statistic] copy constructor\n";
    }

    Statistic & operator=(Statistic const & other) {
        if (this != &other) {
            level = other.level; exp = other.exp;
            std::cout << "[Statistic] operator=\n";
        }
        return *this;
    }

    ~Statistic() {
        std::cout << "[Statistic] destructor\n";
    }
};

#endif // STATISTIC_HPP
