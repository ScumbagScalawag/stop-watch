#ifndef EMPTY_STACK
#define EMPTY_STACK

#include <exception> 
#include <string>

class emptyStack : public std::exception {
public: 
    std::string what();
};

#endif
