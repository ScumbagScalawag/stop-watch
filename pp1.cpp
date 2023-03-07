#include <iostream>
#include <string>

#include "emptystack.h"
#include "runner.h"

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
    const int &show_top() const;
    void print_stack() const; 
    int size() const;
    void push(T t);
    void pop();
};

/* Ok so here's some random text that supposedly I can stage line-by-line
 * the changes.
 * Here is the last line to be included. */
template <typename T> 
Stack<T>::Stack() { top = nullptr; }

template <typename T> 
Stack<T>::~Stack() {
    while (top != nullptr) {
        pop();
    }
}

template <typename T> 
bool Stack<T>::empty() const { /* alternative to throw? */
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
const int &Stack<T>::show_top() const { 
    if (empty())
        throw emptyStack(); //needs to return an int->needs to throw if empty
    return top->data;
}

template <typename T>
void Stack<T>::print_stack() const{ /* Don't need throw, empty stack is not a problem
                                  here */
    Stack *ptr;
    if (empty()) {
        std::cout << "Stack is empty!" << std::endl;
    } else {
        for (ptr = top; ptr != nullptr; ptr = ptr->next) {
            std::cout << ptr->data << " ";
        }
        std::cout << std::endl;
        std::cout << "^Top" << std::endl;
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

int main() {
    Stack<int> stack; // should this be type Stack* or Stack? How does things change?
    //Stack<Runner*> rs; 
    try {
        std::cout << "Empty? : " << stack.empty() << std::endl;
        stack.push(5);
        std::cout << "Empty? : " << stack.empty() << std::endl;
        std::cout << "Top: " << stack.show_top() << std::endl;
        std::cout << "The whole stack: " << std::endl;
        stack.print_stack();
        //popping the last element 
        stack.pop(); //stack now empty!
        //std::cout << "Top: " << stack.show_top() << std::endl; //stack empty!!
        std::cout << "The whole stack: ";
        stack.print_stack();

        /* ------- Runner Stack -------- 
        rs.push(new Runner("Noah", 20, 6985));
        rs.show_top();
        */

    } catch (emptyStack es) {
        std::cout << "ERROR: ";
        std::cout << es.what() << std::endl;
        std::cout << "ABORTING PROGRAM" << std::endl;
        return 1;
    }

    return 0;
}
