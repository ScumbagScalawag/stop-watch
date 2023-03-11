#ifndef MY_CUSTOM_STACK_H
#define MY_CUSTOM_STACK_H

#include <string>
#include <iostream>
#include "emptystack.h"

template <typename T>
class SNode { 
public: 
    T data; 
    SNode<T>* next; 
    
    template <typename>
    friend class StackLL;
};

template <typename T> 
class StackLL {
private:
    SNode<T>* top;
    int n = 0; 

public:
    StackLL()
    : top(NULL){};
    StackLL(const StackLL& s);
    ~StackLL(){
        while (!this->empty()) {
            pop();
        }
    };
    
    bool empty() const;
    const T &show_top() const; 
    void print_stack() const; 
    void print_stack(bool builtin) const; 
    int size() const;
    void push(T t);
    void pop();
};

/*------------------- Keeping until last second!!!!------------------------
template <typename T>
StackLL<T>::StackLL(const StackLL& copy){
    top = NULL;
    SNode<T>* ptr;
    for (ptr = copy.top; ptr != NULL; ptr->next){
        push(ptr->data);
    }
    n = copy.n;
}
*/

//Returns true if stack is empty
template <typename T> 
bool StackLL<T>::empty() const { 
    return top == NULL;
}

//Pushes a new object to the stack
template <typename T> 
void StackLL<T>::push(T t) {
    SNode<T>* node = new SNode<T>;
    node->data = t;
    node->next = top;
    top = node;
    ++n;
}

//Pops the top element of the stack
template <typename T>
void StackLL<T>::pop() { 
    if (empty()){
        std::cout << "Error: Stack is empty!" << std::endl;
    }
    else{
        //throw emptyStack("Cannot Pop from an empty Stack");
        SNode<T>* node = top;
        /*
        std::cout << "DELETING top->data = " << top->data << std::endl;//testing
        std::cout << std::endl;//testing
        */
        top = top->next;
        node->next = NULL;//not necessary, but maybe helpful
        delete (node);
    }
    --n;
}

//Returns the value (data) of the top element of the stack
template <typename T>
const T &StackLL<T>::show_top() const { 
    if (empty())
        throw emptyStack(); 
    return top->data;
}

//overloaded to allow for built-in object types to use StackLL::print_stack
//Prints the stack of built-in data types;
template <typename T>
void StackLL<T>::print_stack(bool builtin) const{ 
    std::cout << "Start of print_stack()\n";
    SNode<T>* ptr;
    T obj;
    if (builtin){
        if (empty()) {
            std::cout << "Stack is empty!" << std::endl;
        } else {
            for (ptr = this->top; ptr != NULL; ptr = ptr->next) {
                obj = ptr->data;
                std::cout << obj << " | "; //works for classes of built-in types
            }
        }
    }
    else{
        std::cout << "Invalid use of StackLL<T>::print_stack().\n";
        std::cout << "Pass either \"true\" to represent printing a stack of built-in types,\n";
        std::cout << "or pass nothing to print the information of an object with a \"print()\" function\n";
    }
}

//Only prints information of objects with a "print()" function 
template <typename T>
void StackLL<T>::print_stack() const{ 
    SNode<T>* ptr;
    T obj;
    if (empty()) {
        std::cout << "Stack is empty!" << std::endl;
    } else {
        for (ptr = top; ptr != NULL; ptr = ptr->next) {
            obj = ptr->data;
            obj.print();//calls object's pre-defined print function
        }
        std::cout << std::endl;
    }
}

//Returns the number of elements in the stack
template <typename T> 
int StackLL<T>::size() const {
    return n;
}

#endif
