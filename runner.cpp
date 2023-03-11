#include "runner.h"
#include<iostream>

//Person::Person(){};
Person::Person(const std::string new_name, const int new_age)
    : name(new_name),
    age(new_age) {}

//Returns name
std::string Person::getName() const { return name; }

//Returns age
int Person::getAge() const { return age;}

//Prints Person-specific information
void Person::print(){
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout << "\n";
}

//Student: inherets "Person" information
Student::Student(const std::string new_name, const int new_age,
                 const float new_grade) 
    : Person(new_name, new_age),
    grade(new_grade){}

//Returns Student's grade
float Student::getGrade() const {return grade;}

//Prints Student-specific information
void Student::print() const {
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout.width(20); std::cout << std::left << getGrade();
    std::cout << std::endl;
}

//Sets grade (no more than 100)
void Student::setGrade(float g){
    if (g > 100.0f) grade = 100.0f;
    else grade = g;
}

//Runner: inherets "Student" information
Runner::Runner(const std::string new_name, const int new_age, const float new_grade,
       const float best)  /* const int -> int? this might be updated multiple times in run-time */
    : Student(new_name, new_age, new_grade),
    best_time(best) {}

//Creates a new runner ONLY with same properties for laps and best_time
//Used ONLY for copying runner's time-based information 
Runner::Runner(const Runner& r){
    this->best_time = r.best_time;
    this->laps = r.laps;
}

//return best_time
float Runner::getBestTime() const{
    return best_time;
}

//Sets the best total time (for all laps combined).
//Best used by passing addLapTimes to "time"
void Runner::setBestTime(float time){
    best_time = time;
    if(best_time == 0.0f){
        best_time = time;
    }
    else{
        if (time < best_time){
            best_time = time;
        }
    }
}

//Prints Runner-specific information
void Runner::print() const{
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout.width(20); std::cout << std::left << getGrade();
    std::cout.width(20); std::cout << std::left << getBestTime();
    std::cout << "\n";
}

//Prints the times for each lap ran
void Runner::printLaps(){
    std::cout << "Lap times for laps 1-3:" <<std::endl;
    this->laps.print_stack(true);
}

//Add(push) a lap time to the stack of lap times
void Runner::setLapTime(float delta){ //feed Timer::GetDeltaTime()
    laps.push(delta);
} 

//Adds all the lap times together
float Runner::addLapTimes(){
    StackLL<float> temp;
    float total = 0.0f;
    while ( ! this->laps.empty()){
        temp.push(this->laps.show_top());
        this->laps.pop();//size automatially adjusted
    }
    while ( ! temp.empty() ){
        total += temp.show_top();
        this->laps.push(temp.show_top());
        temp.pop();
    }
    return total;
}

//Returns the number of laps ran (size of laps stack)
int Runner::numLaps() const{
    return this->laps.size();
}

//Teacher: inherets "Person" information
Teacher::Teacher(const std::string new_name, const int new_age,
                 const std::string new_subject)
        : Person(new_name, new_age),
        subject(new_subject) {}

//Prints Teacher-specific information
void Teacher::print() const {
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout.width(20); std::cout << std::left << subject;
    std::cout << "\n";
}
