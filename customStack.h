#ifndef MY_CUSTOM_STACK_H
#define MY_CUSTOM_STACK_H

#include <string>

//the each stack node
template <typename T>
class SNode { 
public: // figure out friend class and making this private!!!
    T data; 
    SNode<T>* next; 
    //friend class StackLinkedList<T>; // provide StackLinkedList access
};

template <typename T> 
class StackLL { //gotta implement the stack as a singly linked list of elements
private:
    SNode<T>* top;
    std::string stack_empty;
    //OtherLinkedList<T> S; // alternative to SNode<T>* top;
    size_t n; //number of elements in stack

public:
    StackLL()
    : top(NULL){};
    ~StackLL(){
        // while (top != nullptr) {
        //     pop();
        // }
    };
    bool empty() const;
    const T &show_top() const;
    void print_stack() const; 
    int size() const;
    void push(T t);
    void pop();
};

#endif
