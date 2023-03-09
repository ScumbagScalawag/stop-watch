#include <iostream>

#include "timer.h"
#include "runner.h"

void selectOption(char& i);

int main (){
    Timer timer; 
    char input = 'a';
    int count = 0;

    //testing runner with timer 
    Runner runner;

    while (input != 'e' && count < 3){

        selectOption(input);

        switch (input){
            case 's': //start/restart
                count = 0;
                std::cout << "Starting Stopwatch:" << std::endl;
                timer.Restart();
                timer.PrintTimeStamp();
                //runner.setLaps(count, 0.0f);
                break;
            case 'l': //lap
                // accounting for 3 laps:
                switch (count){
                    case 0: //fallthrough:
                    case 1:
                        std::cout << "Lapping Stopwatch:" << std::endl;
                        timer.PrintTimeStamp();
                        runner.setLaps(timer.GetDeltaTime());
                        ++count;
                        break;
                    case 2: 
                        std::cout << "Final Time:" << std::endl;
                        timer.PrintTimeStamp();
                        runner.setLaps(timer.GetDeltaTime());
                        runner.setBestTime(timer.GetDeltaTime());
                        ++count;
                        input = 'e'; // end of input
                        std::cout << "Good Job! Don't forget to hydrate!" << std::endl;
                        break;
                    default:
                        std::cout << "ABORT: There was a problem with counting laps" << std::endl;
                        return 1;
                        break;
                }
                break;
            default: 
                std::cout << "Invalid Entry! Make another Selection." << std::endl;
        }
    }
    return 0;
}

void selectOption(char& i){
    std::cout << "Select option:" << std::endl;
    std::cout << "s. Start/Restart" << std::endl;
    std::cout << "l. Lap" << std::endl;
    std::cout << "e. End" << std::endl;
    std::cout << "Option: ";
    std::cin >> i;
}
