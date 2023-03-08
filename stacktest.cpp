#include <iostream>
#include "customStack.h"

int main(){
    StackLL<int> iStack;
    std::cout << iStack.empty();
    iStack.push(1);
    std::cout << iStack.empty();
    iStack.pop();
    std::cout << iStack.empty();
    return 0;
}
