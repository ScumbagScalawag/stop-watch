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
    //SNode<double>* ptr;
    //print the "laps" stack:
    //for (ptr = this->laps.top; this->laps.top != NULL; )
}

void Runner::setLapTime(float delta){ //feed Timer::GetDeltaTime()
    laps.push(delta);
} 

void Runner::endAttempt(int lap_no, float delta){ //finds best time
    if (delta < this->getBestTime() ){
        this->setBestTime(delta);
    }
}

float Runner::addLapTimes(){
    StackLL<float> temp = this->laps;
    float total;
    int temp_size = this->laps.n;
    std::cout << "tempsize = " << temp_size << std::endl;
    std::cout << "runner's n = " << this->laps.n << std::endl;

    
    //add the lap times 
    do {
        if (this->laps.n == 1){
            total += this->laps.show_top();
            std::cout << "if: n = " << this->laps.n << std::endl;

        }
        else{
            //add top value
            total += this->laps.show_top();
            //push to temp to not loose top of stack
            temp.push(this->laps.show_top());
            //pop from current runner's stack
            this->laps.pop();

            /*
            this->laps.show_top();
            */
            this->laps.n--;
            std::cout << "else: n = " << this->laps.n << std::endl;
        }
    } while (this->laps.n >= 1);

    //add values back to runner lap stack
    while (temp_size != this->laps.n) {
        std::cout << "Second While: n = " << this->laps.n << std::endl;
        this->laps.push(temp.show_top());
        temp.pop();
        this->laps.n++;
    }

    return total;
}

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
