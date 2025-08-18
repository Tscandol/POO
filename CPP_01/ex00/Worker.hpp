#ifndef WORKER_HPP
#define WORKER_HPP

#include <vector>
#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"

class Tool;     // forward
class Workshop; // forward

class Worker {
private:
    Position              _coordonnee;   // composition
    Statistic             _stat;         // composition
    std::vector<Tool*>    _tools;        // agrégation multiple
    std::vector<Workshop*> _workshops;   // associations

    Worker(Worker const &);
    Worker & operator=(Worker const &);
public:
    Worker(int x, int y, int z, int lvl, int xp)
    : _coordonnee(x,y,z), _stat(lvl,xp) {
        std::cout << "[Worker] constructor\n";
    }
    ~Worker();

    void print() const;

    // Tools management
    void addTool(Tool & t);
    void removeTool(Tool & t);
    void listTools() const;
    void useAllTools();

    template <typename T>
    T * getTool() {
        for (std::vector<Tool*>::iterator it=_tools.begin(); it!=_tools.end(); ++it) {
            T *casted = dynamic_cast<T*>(*it);
            if (casted) return casted;
        }
        return 0;
    }

    // Workshops internal (called by Workshop)
    void _registerWorkshop(Workshop * w);
    void _unregisterWorkshop(Workshop * w);
    bool isInWorkshop(Workshop * w) const;

    void work();
};

#endif // WORKER_HPP
