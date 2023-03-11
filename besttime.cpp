#include <iostream>
#include "emptystack.h"
#include "customStack.h"
#include "runner.h"
#include "timer.h"

void selectOption(char& i);
bool singleRunnerStopwatch(Timer& timer, Runner& runner);

int main(){
    StackLL<float> total_times;
    Runner runner("Noah", 20, 90.2f, 1.2f);
    Timer timer;
    runner.print();
    
    //default runner values
    std::string runnerName = "Unknown";
    int runnerAge = 0;
    float runnerGrade = 0.0f;
    float runnerTime = 0.0f;

    char ch = 'n';

    std::cout << "Enter your name: ";
    std::cin >> runnerName;
    std::cout << "Enter your age (as interger): ";
    std::cin >> runnerAge;
    std::cout << "Enter your grade (as float): ";
    std::cin >> runnerGrade;

    bool flag = true;
    while(flag){
        flag = singleRunnerStopwatch(timer, runner);
    }
    ch = 'n';
    while (ch == 'y'){
        std::cout << "Would you like to continue?";
        std::cin >> ch;
        if (ch == 'n'){
            flag = false;
        }else if (ch == 'y'){
            std::cout << "\nAnother runner! Great! Input their information below.\n";
            flag = true;
            break;
        }else{
            std::cout << "INVALID OPTION!\n";
            ch = 'y';
        }
    }


    std::cout << "Good Job! Don't forget to hydrate!" << std::endl;

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

bool singleRunnerStopwatch(Timer& timer, Runner& runner){
    char input = 'a';
    int count = 0;
    while (input != 'e' && count < 3){

        selectOption(input);

        switch (input){
            case 's': //start/restart
                count = 0;
                std::cout << "Starting Stopwatch:" << std::endl;
                timer.Restart();
                //timer.PrintTimeStamp(); // don't really need to print this here
                //runner.setLaps(count, 0.0f);
                break;
            case 'l': //lap
                // accounting for 3 laps:
                switch (count){
                    case 0: //fallthrough:
                    case 1:
                        std::cout << "Lapping Stopwatch:" << std::endl;
                        timer.PrintTimeStamp();
                        runner.setLapTime(timer.GetDeltaTime());
                        ++count;
                        break;
                    case 2: 
                        std::cout << "Final Time:" << std::endl;
                        timer.PrintTimeStamp();
                        runner.setLapTime(timer.GetDeltaTime());
                        runner.setBestTime(timer.GetDeltaTime());
                        ++count;
                        input = 'e'; // end of input
                        break;
                    default:
                        std::cout << "ABORT: There was a problem with counting laps" << std::endl;
                        break;
                }
                break;
            default: 
                std::cout << "Invalid Entry! Make another Selection." << std::endl;
        }
    }
    return true;
}
