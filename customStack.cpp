#include "customStack.h"
#include <exception>
#include "emptystack.h"

#include <iostream>

/*
template <typename T> 
StackLL<T>::~StackLL() {
    while (top != nullptr) {
        pop();
    }
}
*/

template <typename T> 
bool StackLL<T>::empty() const { 
    return top == nullptr;
}

template <typename T> 
void StackLL<T>::push(T t) {
    SNode<T>* node = new SNode<T>;
    node->data = t;
    node->next = top;
    top = node;
    ++n;
}

template <typename T>
void StackLL<T>::pop() { 
    if (empty())
        throw emptyStack();
    SNode<T>* node = top;
    top = top->next;
    delete (node);
    --n;
}

template <typename T>
const T &StackLL<T>::show_top() const { 
    if (empty())
        throw emptyStack(); 
    return top->data;
}

template <typename T>
void StackLL<T>::print_stack() const{ 
    SNode<T>* ptr;
    T tempclass;
    if (empty()) {
        std::cout << "Stack is empty!" << std::endl;
    } else {
        for (ptr = top; ptr != nullptr; ptr = ptr->next) {
            tempclass = ptr->data;                           // Changed print to ONLY work for classes with pre-defined print functions
            tempclass.print();
        }
    }
}

template <typename T> 
int StackLL<T>::size() const {
    return n;
}
