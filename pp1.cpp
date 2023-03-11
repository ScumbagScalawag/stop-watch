#include <iostream>
#include <string>

#include "emptystack.h"
#include "runner.h"
#include "customStack.h"
#include "timer.h"

void singleRunnerStopwatch(Timer& timer, Runner& runner);
void selectOption(char& i);

int main() {
    StackLL<Teacher> teacherstack;
    
    //Initialize teacherstack to include Professor Neal
    teacherstack.push(Teacher("Tempest Neal",30,"Data Structures in C++"));
    teacherstack.push(Teacher("Noah",20,"Project Lead"));

    std::cout << "\nIf your best time is less than 3 seconds, you will be getting extra credit for the following class:\n";
    std::cout << "====================================================================\n";
    std::cout.width(20); std::cout << std::left << "Name";
    std::cout.width(20); std::cout << std::left << "Age";
    std::cout << std::left << "Subject\n";
    teacherstack.print_stack();

    // Initialize target goal
    float goal = 3.0f;
    
    // Initialize variables for runner
    std::string runnerName = "Unknown";
    int runnerAge = 0;
    float runnerGrade = 0.0f;
    float runnerTime = 0.0f;

    // Temp runner objects needed for print
    Runner temp_runner;
    Timer timer;

    std::cout << "Hello runner! I see you are looking for some extra credit. Let's get started!\n";
    

            /* ----------------------------------------------------------------------------------------------
            Add the necessary timer functionality here. Should return final time that can be given to a runner.
            This can be best lap time and is stored in variable runnerTime
            ---------------------------------------------------------------------------------------------- */
            bool flag = true;
            char ch = 'y';

            while (flag == true){
                // Ask for runner details
                std::cout << "Enter your name: ";
                std::cin >> runnerName;
                std::cout << "Enter your age (as interger): ";
                std::cin >> runnerAge;
                std::cout << "Enter your grade (as float): ";
                std::cin >> runnerGrade;

                temp_runner = Runner(runnerName, runnerAge, runnerGrade, runnerTime);//time initialied as 0.0f

                singleRunnerStopwatch(timer, temp_runner);

                // Show details
                std::cout << "\nThank you for participating here are the results\n";
                
                temp_runner.printLaps();
                std::cout << std::endl << std::endl;
                
                std::cout << "Your total time for all 3 laps: " << temp_runner.addLapTimes(); 
                std::cout << std::endl << std::endl;

                temp_runner.setBestTime(temp_runner.addLapTimes());
                std::cout << "All your details: \n";
                std::cout.width(20); std::cout << std::left << "Name";
                std::cout.width(20); std::cout << std::left << "Age";
                std::cout.width(20); std::cout << std::left << "Grade";
                std::cout << std::left << "Best Time\n";
                std::cout << "====================================================================\n";
                temp_runner.print(); 

                if (temp_runner.getBestTime() < goal){
                    std::cout << "Congrats! You will be getting extra credit!\n";
                    flag = false;
                }else{
                    std::cout << "Unfortunately you didn't beat the target of 3 seconds\n";
                    while (ch == 'y'){
                        std::cout << "Would you like to try again? (y/n): ";
                        std::cin >> ch;
                        if (ch == 'y'){
                            flag = true;
                            break;
                        }else if (ch =='n'){
                            flag = false;
                            break;
                        }else{
                            std::cout << "Invalid input!";
                            ch = 'y';
                        }
                    }
                }
            }      
    
    std::cout << "\nThank you for participating!\n";
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
