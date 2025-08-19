#include "Worker.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"
#include <algorithm>

Worker::~Worker() {
    std::cout << "[Worker] dtor\n";
    for (std::vector<Tool*>::iterator it=_tools.begin(); it!=_tools.end(); ++it) {
        if (*it && (*it)->getHolder() == this) (*it)->detachHolder();
    }
    _tools.clear();
    for (std::vector<Workshop*>::iterator it=_workshops.begin(); it!=_workshops.end(); ++it) {
        // Workshop destructor will also handle unregister; we just signal
        std::cout << "[Worker] still registered in a workshop\n";
    }
}

void Worker::print() const {
    std::cout << "[Worker] tools=" << _tools.size() << " workshops=" << _workshops.size() << "\n";
}

void Worker::addTool(Tool & t) {
    if (t.getHolder() == this) {
        std::cout << "[Worker] déjà propriétaire\n";
        return;
    }
    if (t.getHolder() != 0) {
        std::cout << "[Worker] transfert outil\n";
        Worker * prev = t.getHolder();
        prev->removeTool(t);
    }
    _tools.push_back(&t);
    t.attachTo(this); // use public API instead of friend access
    std::cout << "[Worker] outil ajouté\n";
}

void Worker::removeTool(Tool & t) {
    for (std::vector<Tool*>::iterator it=_tools.begin(); it!=_tools.end(); ++it) {
        if (*it == &t) {
            std::cout << "[Worker] outil retiré\n";
            if (t.getHolder() == this) t.detachHolder();
            _tools.erase(it);
            return;
        }
    }
    std::cout << "[Worker] outil absent\n";
}

void Worker::listTools() const {
    std::cout << "[Worker] liste outils count=" << _tools.size() << "\n";
}

void Worker::useAllTools() {
    for (std::vector<Tool*>::iterator it=_tools.begin(); it!=_tools.end(); ++it) {
        (*it)->use();
    }
}

void Worker::_registerWorkshop(Workshop * w) {
    for (std::vector<Workshop*>::iterator it=_workshops.begin(); it!=_workshops.end(); ++it)
        if (*it == w) return;
    _workshops.push_back(w);
}

void Worker::_unregisterWorkshop(Workshop * w) {
    for (std::vector<Workshop*>::iterator it=_workshops.begin(); it!=_workshops.end(); ++it) {
        if (*it == w) { _workshops.erase(it); return; }
    }
}

bool Worker::isInWorkshop(Workshop * w) const {
    for (std::vector<Workshop*>::const_iterator it=_workshops.begin(); it!=_workshops.end(); ++it)
        if (*it == w) return true;
    return false;
}

void Worker::work() {
    std::cout << "[Worker] work: utilisation des outils\n";
    useAllTools();
}
