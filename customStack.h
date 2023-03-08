#ifndef MY_CUSTOM_STACK_H
#define MY_CUSTOM_STACK_H

#include <string>

template <typename T> 
class Stack {
private:
    T data;
    Stack *next;
    Stack *top;
    std::string stack_empty;

public:
    Stack();
    ~Stack();
    bool empty() const;
    const T &show_top() const;
    void print_stack() const; 
    int size() const;
    void push(T t);
    void pop();
};

#endif
