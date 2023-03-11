#include <iostream>
#include <string>

#include "emptystack.h"
#include "customStack.h"
#include "runner.h"


int main() {
    StackLL<int> istack; 
    StackLL<Runner> runnerstack;
    StackLL<Teacher> teacherstack; // To include teacher class 
    
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
    std::string runnerName , runnerGrade;
    int runnerAge;
    float runnerTime = 0.0f;           // This can be float depending on the value of time


    // Temp runner objects needed for print
    Runner temp;

    std::cout << "Hello runners! I see you are looking for some extra credit. Let's get started!\n";
    while (flag){
        try {
            // Ask for runner details
            std::cout << "Enter your name: ";
            std::cin >> runnerName;
            std::cout << "Enter your age: ";
            std::cin >> runnerAge;
            std::cout << "Enter your grade: ";
            std::cin >> runnerGrade;

            /*
            Add the necessary timer functionality here. Should return final time that can be given to a runner.
            This can be best lap time and is stored in variable runnerTime
            */

            // Create runner object with those details and add to runnerstack
            runnerstack.push(Runner(runnerName,runnerAge,runnerGrade,runnerTime));

            
            // Continue?
            while (ch == 'y'){
                std::cout << "Are there any more runner? (y/n): ";
                std::cin >> ch;
                if (ch == 'n'){
                    flag = false;
                }else if (ch == 'y'){
                    std::cout << "\nAnother runner! Let's get started!\n";
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
                    temp = runnerstack.show_top();
                    std::cout << "Details about most recent runner...\n";
                    std::cout.width(20); std::cout << std::left << "Name";
                    std::cout.width(20); std::cout << std::left << "Age";
                    std::cout.width(20); std::cout << std::left << "Grade";
                    std::cout << std::left << "Best Time\n";
                    std::cout << "====================================================================\n";
                    std::cout << "\n";
                    temp.print();
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
