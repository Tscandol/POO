#include "Hammer.hpp"
#include "Worker.hpp"

void Hammer::use() {
    if (_usesLeft <= 0) {
        std::cout << "[Hammer] usé\n";
        return;
    }
    --_usesLeft;
    std::cout << "[Hammer] frappe (reste=" << _usesLeft << ")\n";
}
