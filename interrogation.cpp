#include <iostream>

#include "customStack.h"

int main(){
    StackLL<int> stack;
    stack.push(29);
    stack.push(5);
    stack.push(79);
    stack.push(109);

    std::cout << "Before pop(s)" << std::endl;
    stack.pop();
    //stack.pop();
    //stack.pop();
    //stack.pop();
    std::cout << "After pop(s)" << std::endl;

    return 0;
}
