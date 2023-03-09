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

//Runner::Runner(){};
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

//best_time
float Runner::getBestTime() const{
    return best_time;
}

void Runner::setBestTime(float i){
    //iterate through stack objects (timestamps) and add them up
    //SNode<* ptr;
    //for (Stack)
    /*
    if (delta < this->getBestTime() ){
        this->setBestTime(delta);
    }
    */
    best_time = i;
}

void Runner::print() const{
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout.width(20); std::cout << std::left << getGrade();
    std::cout.width(20); std::cout << std::left << getBestTime();
    std::cout << "\n";
}

void Runner::getLaps(){
    //SNode<double>* ptr;
    //print the "laps" stack:
    this->laps.print_stack(true);
    //for (ptr = this->laps.top; this->laps.top != NULL; )
}

void Runner::setLaps(float delta){ //feed Timer::GetDeltaTime()
    laps.push(delta);
} 

void Runner::endAttempt(int lap_no, float delta){ //finds best time
    if (delta < this->getBestTime() ){
        this->setBestTime(delta);
    }
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
