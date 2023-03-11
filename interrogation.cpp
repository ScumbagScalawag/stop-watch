#include <iostream>

#include "customStack.h"
#include "runner.h"

int main(){
    Runner runner("Holly", 21, 93.2f, 27.6f);
    Runner sec_run(runner);

    runner.print();
    std::cout << runner.getBestTime() << std::endl;
    sec_run.print();
    std::cout << sec_run.getBestTime() << std::endl;

    return 0;
}
