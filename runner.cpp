#include "runner.h"
#include<iostream>

//Person::Person(){};
Person::Person(const std::string new_name, const int new_age)
    : name(new_name),
    age(new_age) {}

std::string Person::getName() const { return name; }

int Person::getAge() const { return age;}

void Person::print(){
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout << "\n";
}

Student::Student(const std::string new_name, const int new_age,
                 const std::string new_grade) 
    : Person(new_name, new_age),
    grade(new_grade){}
        /*Runner(getName() , getAge(), getTime()){
        grade = new_grade;*/

std::string Student::getGrade() const {return grade;}            // getGrade() needed for print

void Student::print() const {
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout.width(20); std::cout << std::left << grade;
    std::cout << "\n";
}

void Student::setGrade(int g){
    if (g > 100) grade = 100;
    else grade = g;
}

//-------------------------Runner::Runner(){};-----------------------------------------
Runner::Runner(const std::string new_name, const int new_age, const std::string new_grade,
       const int best)  /* const int -> int? this might be updated multiple times in run-time */
    : Student(new_name, new_age, new_grade),
    best_time(best) {}

Runner::Runner(const Runner& r){
    this->best_time = r.best_time;
    this->laps = r.laps;
}

/*
//time 
int Runner::getTime() const { return time;}

void Runner::setTime(float i ){
    time = i;
}
*/

//return best_time
float Runner::getBestTime() const{
    return best_time;
}

//sets the best total time (for all laps)
//best used by passing addLapTimes to "time"
void Runner::setBestTime(float time){
    if (time < this->getBestTime() ){
        best_time = time;
    }
}

void Runner::print() const{
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout.width(20); std::cout << std::left << getGrade();
    std::cout.width(20); std::cout << std::left << getBestTime();
    std::cout << "\n";
}

void Runner::printLaps(){
    std::cout << "Lap times for laps 1-3:" <<std::endl;
    this->laps.print_stack(true);
}

void Runner::setLapTime(float delta){ //feed Timer::GetDeltaTime()
    laps.push(delta);
} 

/*
float Runner::addLapTimes(){
    StackLL<float> temp_stack = this->laps;//working
    float total = 0.0f;
    int temp_size = this->laps.size(); //working
    std::cout << "tempsize = " << temp_size << std::endl;//working
    std::cout << "runner's n = " << this->laps.size() << std::endl;//working
    //add the lap times 
    int count = 0;
    while (count <= 2 || this->laps.size() >= 1){
        if (this->laps.size() == 1){
            total += this->laps.show_top();
            std::cout << "if: n = " << this->laps.size() << std::endl;
        }
        else{
            //add top value
            total += this->laps.show_top();
            //push to temp to not loose top of stack
            temp_stack.push(this->laps.show_top());
            //pop from current runner's stack
            this->laps.pop();

            // this->laps.n--; //size (therefore n) changes WITH push() & pop() !
            std::cout << "else: n = " << this->laps.n << std::endl;
        }
        std::cout << "count = " << count << std::endl;
        count++; 
    } 
    //add values back to runner lap stack
    while (temp_size != this->laps.size()) {
        std::cout << "Second While: n = " << this->laps.size() << std::endl;
        this->laps.push(temp_stack.show_top()); //size automatically adjusted by push()
        temp_stack.pop();
    }

    return total;
}
*/

float Runner::addLapTimes() const{
    std::cout << "\nInside addLapTimes()\n";
    StackLL<float> temp_stack(this->laps);
    StackLL<float> temp_stack_read;
    float total = 0.0f;

    int n = 1;
    std::cout << "BEFORE THE WHILE LOOPS------------------------" << std::endl; 
    std::cout << "size of temp_stack_read = " << temp_stack_read.size() << std::endl;
    std::cout << "size of temp_stack = " << temp_stack.size() << std::endl;
    std::cout << "size of this->laps = " << this->laps.size() << std::endl;
    std::cout << "----------------------------------------------" << std::endl; 
    temp_stack_read.print_stack(true);
    temp_stack.print_stack(true);
    this->laps.print_stack(true);
    

    //add the lap times to temp stack
    // std::cout << "---------------------"
    while ( ! temp_stack.empty()){
        temp_stack_read.push(temp_stack.show_top());
        std::cout << "temp_stack_read's top = " <<  temp_stack_read.show_top() << std::endl;
        temp_stack.pop();//size automatially adjusted
    }
    std::cout << "AFTER WHILE LOOP 1----------------------------" << std::endl; 
    std::cout << "size of temp_stack_read = " << temp_stack_read.size() << std::endl;
    std::cout << "size of temp_stack = " << temp_stack.size() << std::endl;
    std::cout << "size of this->laps = " << this->laps.size() << std::endl;
    std::cout << "----------------------------------------------" << std::endl; 

    std::cout << std::endl;
    while ( ! temp_stack_read.empty() ){
        std::cout << "temp_stack_read's size = " << temp_stack_read.size() << std::endl;
        std::cout << "total(before add) = " << total << " (n = " << n << ")" << std::endl;
        total += temp_stack_read.show_top();
        std::cout << "total(after add) = " << total << " (n = " << n << ")" << std::endl;
        temp_stack_read.pop();
        n++;
        std::cout << "End of total Loop!" << std::endl;
    }
    std::cout << "AFTER WHILE LOOP 2----------------------------" << std::endl; 
    std::cout << "size of temp_stack_read = " << temp_stack_read.size() << std::endl;
    std::cout << "size of temp_stack = " << temp_stack.size() << std::endl;
    std::cout << "size of this->laps = " << this->laps.size() << std::endl;
    std::cout << "----------------------------------------------" << std::endl; 
    std::cout << "End of addLapTimes()" << std::endl;
    return total;
}

/*
float Runner::addLapTimes() const{
    StackLL<float> temp_stack = this->laps;
    StackLL<float> temp_stack_read;
    float total = 0.0f;

    int n = 1;

    //add the lap times to temp stack
    temp_stack_read.push(temp_stack.show_top());
    temp_stack.pop();//size automatially adjusted
    temp_stack_read.push(temp_stack.show_top());
    temp_stack.pop();//size automatially adjusted
    temp_stack_read.push(temp_stack.show_top());
    temp_stack.pop();//size automatially adjusted
    std::cout << std::endl;

    std::cout << "temp_stack_read's size = " << temp_stack_read.size() << std::endl;
    std::cout << "total(before add) = " << total << " (n = " << n << ")" << std::endl;
    total += temp_stack_read.show_top();
    std::cout << "total(after add) = " << total << " (n = " << n << ")" << std::endl;
    temp_stack_read.pop();
    n++;

    std::cout << "temp_stack_read's size = " << temp_stack_read.size() << std::endl;
    std::cout << "total(before add) = " << total << " (n = " << n << ")" << std::endl;
    total += temp_stack_read.show_top();
    std::cout << "total(after add) = " << total << " (n = " << n << ")" << std::endl;
    temp_stack_read.pop();
    n++;

    std::cout << "temp_stack_read's size = " << temp_stack_read.size() << std::endl;
    std::cout << "total(before add) = " << total << " (n = " << n << ")" << std::endl;
    total += temp_stack_read.show_top();
    std::cout << "total(after add) = " << total << " (n = " << n << ")" << std::endl;
    temp_stack_read.pop();
    n++;
    return total;
}
*/


    

int Runner::numLaps() const{
    return this->laps.size();
}

Teacher::Teacher(const std::string new_name, const int new_age,
                 const std::string new_subject)
        : Person(new_name, new_age),
        subject(new_subject) {}

void Teacher::print() const {
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout.width(20); std::cout << std::left << subject;
    std::cout << "\n";
}
