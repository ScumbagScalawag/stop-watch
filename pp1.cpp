#include <iostream>
#include <string>

#include "emptystack.h"
#include "customStack.h"
#include "runner.h"
#include "timer.h"

void singleRunnerStopwatch(Timer& timer, Runner& runner);
void selectOption(char& i);

int main() {
    StackLL<Runner> runnerstack;
    StackLL<Teacher> teacherstack;
    
    //Initialize teacherstack to include Professor Neal
    teacherstack.push(Teacher("Tempest Neal",30,"Data Structures in C++"));
    std::cout << "\nYou will be getting extra credit for the following class:\n";
    std::cout << "====================================================================\n";
    std::cout.width(20); std::cout << std::left << "Name";
    std::cout.width(20); std::cout << std::left << "Age";
    std::cout << std::left << "Subject\n";
    teacherstack.print_stack();
    
    // While loop functionality (default values)
    char ch = 'y';
    bool flag = true;

    // Initialize variables for runner
    std::string runnerName = "Unknown";
    int runnerAge = 0;
    float runnerGrade = 0.0f;
    float runnerTime = 0.0f;

    // Temp runner objects needed for print
    Runner temp_runner;
    Timer timer;

    std::cout << "Hello runners! I see you are looking for some extra credit. Let's get started!\n";
    while (flag){
        try {
            // Ask for runner details
            std::cout << "Enter your name: ";
            std::cin >> runnerName;
            std::cout << "Enter your age (as interger): ";
            std::cin >> runnerAge;
            std::cout << "Enter your grade (as float): ";
            std::cin >> runnerGrade;

            temp_runner = Runner(runnerName, runnerAge, runnerGrade, runnerTime);//time initialied as 0.0f

            /* ----------------------------------------------------------------------------------------------
            Add the necessary timer functionality here. Should return final time that can be given to a runner.
            This can be best lap time and is stored in variable runnerTime
            ---------------------------------------------------------------------------------------------- */

            singleRunnerStopwatch(timer, temp_runner); 

            std::cout << "Your total time for all 3 laps: " << temp_runner.addLapTimes(); 
            std::cout << std::endl;

            temp_runner.printLaps();

            std::cout << std::endl;


            // Create runner object with those details and add to runnerstack
            runnerstack.push(temp_runner);

            // Continue?
            while (ch == 'y'){
                std::cout << "Are there any more runners? (y/n): ";
                std::cin >> ch;
                if (ch == 'n'){
                    flag = false;
                }else if (ch == 'y'){
                    std::cout << "\nAnother runner! Great! Input their information below.\n";
                    break;
                }else{
                    std::cout << "INVALID OPTION!\n";
                    ch = 'y';
                }
            }

        } catch (emptyStack &es) {
            std::cout << "ERROR: ";
            std::cout << es.what() << std::endl;
            std::cout << "ABORTING PROGRAM" << std::endl;
            return 1;
        }
    }

    // Menu based operations to check runnerstack functions
    flag = true;
    std::cout << "\nNow that the runners have been finalized, what would you like to do?\n";
    while (flag){
        try{  
            int option = 4;
            ch = 'y';
            while(ch == 'y'){
                std::cout << "1. Print All Runner\n2. Pop Runner\n3. Return Most Recent Runner\n";
                std::cout << "Enter option (1-3): ";
                std::cin >> option;
                while(option < 1 || option >3){
                    std::cout << "INVALID OPTION! Enter option (1-3): ";
                    std::cin >> option;
                }

                switch (option)
                {
                case 1:
                    std::cout << "Printing all runners...\n";
                    std::cout.width(20); std::cout << std::left << "Name";
                    std::cout.width(20); std::cout << std::left << "Age";
                    std::cout.width(20); std::cout << std::left << "Grade";
                    std::cout << std::left << "Best Time\n";
                    std::cout << "====================================================================\n";
                    runnerstack.print_stack();
                    break;
                
                case 2:
                    runnerstack.pop();
                    std::cout << "Most recent runner has been removed...\n";
                    break;
                
                case 3:
                    temp_runner = runnerstack.show_top();
                    std::cout << "Details about most recent runner...\n";
                    std::cout.width(20); std::cout << std::left << "Name";
                    std::cout.width(20); std::cout << std::left << "Age";
                    std::cout.width(20); std::cout << std::left << "Grade";
                    std::cout << std::left << "Best Time\n";
                    std::cout << "====================================================================\n";
                    std::cout << "\n";
                    temp_runner.print();
                    break;
                
                default:
                    break;
                }

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
            }
        }catch (emptyStack &es) {
            std::cout << "ERROR: ";
            std::cout << es.what() << std::endl;
            std::cout << "ABORTING PROGRAM" << std::endl;
            return 1;
        }
    }


    /* Best time( after 3 "laps") gets 5 points extra credit! */
    /*
    for (i = (start of runner stack); i != (end); ++i){

        print each students grade
        if (student.time = best_time)
            student.setGrade(student.getGrade + 5)
            print some neat message that points to the winner of the pack 

    
    }



    */


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
