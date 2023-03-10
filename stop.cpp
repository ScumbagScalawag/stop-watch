#include <iostream>

#include "timer.h"
#include "runner.h"

void selectOption(char& i);
void singleRunnerStopwatch(Timer& timer, Runner& runner);

int main (){
    Timer timer; 
    Runner runner("John", 20, "A");

    // std::cout << "Your total time for all 3 laps: " << runner.addLapTimes(); //testing
    // std::cout << std::endl;
    runner.printLaps();

    singleRunnerStopwatch(timer, runner); //working

    runner.printLaps();//working
    std::cout << "Number of laps ran: " << runner.numLaps() << std::endl; //working 
    std::cout << "Your total time for all 3 laps: " << runner.addLapTimes(); //testing
    std::cout << std::endl;
    std::cout << "After addLapTimes() called" << std::endl;

    std::cout << "SOME TEXT AFTER ALL THAT STUFF" << std::endl;

    runner.printLaps();

    // runner.printLaps();//doesn't work -> pobably because of a problem with runner.laps
    //being affected by the call of addLapTimes()

    float i = runner.addLapTimes(); // second call is where things go wrong!!!!!!!!!!!!!
    std::cout << "Your total time for all 3 laps: " << i << std::endl;

    // runner.setBestTime(i);
    // runner.print();
    
    std::cout << std::endl;

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

void singleRunnerStopwatch(Timer& timer, Runner& runner){
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
                        std::cout << "Good Job! Don't forget to hydrate!" << std::endl;
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
}
