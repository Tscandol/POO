#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <vector>
#include <string>
#include <iostream>

class Worker; // forward

class Workshop {
private:
    std::string         _name;
    std::vector<Worker*> _workers;
    Workshop(Workshop const &);
    Workshop & operator=(Workshop const &);
public:
    Workshop(std::string const & name) : _name(name) {
        std::cout << "[Workshop] constructor " << _name << "\n";
    }
    ~Workshop();

    void registerWorker(Worker & w);
    void releaseWorker(Worker & w);
    void executeWorkDay();

    const std::string & getName() const { return _name; }
};

#endif // WORKSHOP_HPP
