#include <iostream>
#include <string>

#include "customStack.h"
#include "emptystack.h"
#include "runner.h"


int main() {
    StackLL<int> istack; 
    StackLL<Runner> runnerstack; 
    std::cout << "Welcome runner! Good luck for your race! Fill in your details and get to running!\n\n";
    
    // While loop functionality (default values)
    char ch = 'y';
    bool flag = true;

    // Initialize variables for runner
    std::string runnerName , runnerGrade;
    int runnerAge;
    float runnerTime = 0.0f;           // This can be float depending on the value of time


    // Temp runner objects needed for print
    Runner temp;

    while (flag){
        try {
            // Ask for runner details
            std::cout << "Enter your name: ";
            std::cin >> runnerName;
            std::cout << "Enter your age: ";
            std::cin >> runnerAge;
            std::cout << "Enter your grade: ";
            std::cin >> runnerGrade;


            // Start timer, get time
            /* runnerTime = getTime() */

            // Create runner object with those details and add to runnerstack
            runnerstack.push(Runner(runnerName,runnerAge,runnerGrade,runnerTime));

            // Print all runners
            std::cout << "Printing all runners...\n";
            std::cout << "TOP\n";
            runnerstack.print_stack();
            std::cout << "\n";

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
            

        } catch (emptyStack &es) {
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


    std::cout << "Thank you for participating\n";
    return 0;
}
