#include <iostream>
#include <string>

#include "emtptyStack.h"
#include "runner.h"

template <typename T> class Stack {
private:
    T data;
    Stack *next;
    Stack *top;
    std::string stack_empty;

public:
    Stack();
    ~Stack();
    bool empty();
    void push(int d = 0);
    void pop() throw(emptyStack());
    const int &show_top() const throw(emptyStack());
    void print_stack();
    int size();
    void clear_stack(); /* is this necessary or helpful? */
};

template <typename T> Stack<T>::Stack() { top = nullptr; }

template <typename T> Stack<T>::~Stack() {
    while (top != nullptr) {
        pop();
    }
}

template <typename T> bool Stack<T>::empty() { /* alternative to throw? */
    return top == nullptr;
}

template <typename T> void Stack<T>::push(int d) {
    Stack *node = new Stack;
    node->data = d;
    node->next = top;
    top = node;
}

template <typename T>
void Stack<T>::pop() throw(emptyStack()) { /* add throw exception!!! */
    if (empty())
        throw emptyStack();
    Stack *node = top;
    top = top->next;
    delete (node);
}

template <typename T>
const int &Stack<T>::show_top() const
throw(emptyStack()) { /* add throw exception!!! */
    if (empty())
        throw emptyStack();
    return top->data;
}

template <typename T>
void Stack<T>::print_stack() { /* Don't need throw, empty stack is not a problem
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

template <typename T> int Stack<T>::size() {
    int i = 0;
    Stack *ptr;
    for (ptr = top; ptr != nullptr; ptr = ptr->next) {
        ++i;
    }
    return i;
}

int main() {
    Stack<int>
    stack; // should this be type Stack* or Stack? How does things change?
    std::cout << "Empty? : " << stack.empty() << std::endl;
    stack.push(5);
    std::cout << "Empty? : " << stack.empty() << std::endl;
    std::cout << "Top: " << stack.show_top() << std::endl;
    std::cout << "The whole stack: " << std::endl;
    stack.print_stack();
    /* need THROW exception(s) for this stuff to work:
  stack.pop();
  std::cout << "Top: " << stack.show_top() << std::endl;
  std::cout << "The whole stack: " << std::endl;
  stack.print_stack();
  */

    return 0;
}
