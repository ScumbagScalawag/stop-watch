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
    const T &show_top() const;        // Return type here should be T
    void print_stack() const; 
    int size() const;
    void push(T t);
    void pop();
};

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
const T &Stack<T>::show_top() const { // Return type needs to be T
    if (empty())
        throw emptyStack(); //needs to return an int->needs to throw if empty
    return top->data;
}

template <typename T>
void Stack<T>::print_stack() const{ /* Don't need throw, empty stack is not a problem
                                  here */
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

int main() {
    //Stack<int> stack; // should this be type Stack* or Stack? How does things change?

    // Using just Stack instead of Stack* works
    Stack<Runner> runnerstack; 
    std::cout << "Welcome runner! Good luck for your race! Fill in your details and get to running!\n\n";
    
    // While loop functionality
    char ch = 'y';
    bool flag = true;

    // Initialize variables for runner
    std::string runnerName;
    int runnerAge;
    int runnerTime = 0;           // This can be float depending on the value of time


    // Temp runner objects needed for print
    Runner temp;

    while (flag){
        try {
            // Ask for runner details
            std::cout << "Enter your name: ";
            std::cin >> runnerName;
            std::cout << "Enter your age: ";
            std::cin >> runnerAge;

            // Start timer, get time
            /* runnerTime = getTime() */

            // Create runner object with those details and add to runnerstack
            runnerstack.push(Runner(runnerName,runnerAge,runnerTime));

            // Print all runners
            std::cout << "Printing all runners...\n";
            std::cout << "TOP\n";
            runnerstack.print_stack();
            std::cout << "\n";

            // Continue?
            while (ch == 'y'){
                std::cout << "Would you like to continue? (y/n): ";
                std::cin >> ch;
                if (ch == 'n'){
                    flag = false;
                }else if (ch == 'y'){
                    break;
                }else{
                    std::cout << "INVALID OPTION!\n";
                    ch = 'y';
                }
            }
            

        } catch (emptyStack es) {
            std::cout << "ERROR: ";
            std::cout << es.what() << std::endl;
            std::cout << "ABORTING PROGRAM" << std::endl;
            return 1;
        }
    }

    std::cout << "Thank you for participating\n";
    return 0;
}
