#include <iostream>

#include "timer.h"

void selectOption(char& i);

int main (){
    Timer timer; 
    char input = 'a';
    while (input != 'e'){
        selectOption(input);

        switch (input){
            case 's': //start
                std::cout << "Starting Stopwatch:" << std::endl;
                timer.Restart();
                timer.PrintTimeStamp();
            break;
            case 'l': //lap
                std::cout << "Lapping Stopwatch:" << std::endl;
                timer.PrintTimeStamp();
            break;
            case 'e': //end
                std::cout << "Ending Stopwatch. Final Time:" << std::endl;
                timer.PrintTimeStamp();
            break;
            default: 
                std::cout << "Invalid Entry! Make another Selection." << std::endl;
        }
    }
    return 0;
}


void selectOption(char& i){
    std::cout << "Select option:" << std::endl;
    std::cout << "s. Start" << std::endl;
    std::cout << "l. Lap" << std::endl;
    std::cout << "e. End" << std::endl;
    


    std::cout << "Option: ";
    std::cin >> i;

}
