#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>

class Worker; // forward

class Tool {
protected:
    int     _usesLeft;
    Worker* _holder;
    Tool(Tool const &);
    Tool & operator=(Tool const &);
public:
    Tool(int uses=5) : _usesLeft(uses), _holder(0) {
        std::cout << "[Tool] constructor uses=" << _usesLeft << "\n";
    }
    virtual ~Tool() {
        std::cout << "[Tool] destructor\n";
    }
    virtual void use() = 0;

    int getUsesLeft() const { return _usesLeft; }
    Worker* getHolder() const { return _holder; }

    void detachHolder() { _holder = 0; }

    friend class Worker; // Worker gère _holder pour transferts
};

#endif // TOOL_HPP
