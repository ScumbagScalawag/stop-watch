#include "customStack.h"
#include "emptystack.h"

#include <iostream>

template <typename T> 
Stack<T>::Stack() { top = nullptr; }

template <typename T> 
Stack<T>::~Stack() {
    while (top != nullptr) {
        pop();
    }
}

template <typename T> 
bool Stack<T>::empty() const { 
    return top == nullptr;
}

template <typename T> 
void Stack<T>::push(T t) {
    Stack *node = new Stack;
    node->data = t;
    node->next = top;
    top = node;
}

template <typename T>
void Stack<T>::pop() { 
    if (empty())
        throw emptyStack();
    Stack *node = top;
    top = top->next;
    delete (node);
}

template <typename T>
const T &Stack<T>::show_top() const { 
    if (empty())
        throw emptyStack(); 
    return top->data;
}

template <typename T>
void Stack<T>::print_stack() const{ 
    Stack *ptr;
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
int Stack<T>::size() const {
    int i = 0;
    Stack *ptr;
    for (ptr = top; ptr != nullptr; ptr = ptr->next) {
        ++i;
    }
    return i;
}
