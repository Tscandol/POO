#include "Workshop.hpp"
#include "Worker.hpp"
#include <algorithm>

Workshop::~Workshop() {
    std::cout << "[Workshop] dtor " << _name << "\n";
    for (std::vector<Worker*>::iterator it=_workers.begin(); it!=_workers.end(); ++it) {
        if (*it) (*it)->_unregisterWorkshop(this);
    }
}

void Workshop::registerWorker(Worker & w) {
    for (std::vector<Worker*>::iterator it=_workers.begin(); it!=_workers.end(); ++it)
        if (*it == &w) {
            std::cout << "[Workshop] déjà inscrit\n";
            return;
        }
    _workers.push_back(&w);
    w._registerWorkshop(this);
    std::cout << "[Workshop] worker inscrit\n";
}

void Workshop::releaseWorker(Worker & w) {
    for (std::vector<Worker*>::iterator it=_workers.begin(); it!=_workers.end(); ++it) {
        if (*it == &w) {
            _workers.erase(it);
            w._unregisterWorkshop(this);
            std::cout << "[Workshop] worker retiré\n";
            return;
        }
    }
    std::cout << "[Workshop] worker absent\n";
}

void Workshop::executeWorkDay() {
    std::cout << "[Workshop] journée de travail " << _name << "\n";
    for (std::vector<Worker*>::iterator it=_workers.begin(); it!=_workers.end(); ++it) {
        if (*it) (*it)->work();
    }
}
