#include "Shovel.hpp"
#include "Worker.hpp"

void Shovel::use() {
    if (_usesLeft <= 0) {
        std::cout << "[Shovel] plus d'utilisations\n";
        return;
    }
    --_usesLeft;
    std::cout << "[Shovel] creuse (reste=" << _usesLeft << ")\n";
}
