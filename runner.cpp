#include <iostream>
#include <string>

#include "runner.h"

//Person
// I've added a line on the remote version! How ever will I resolve this?
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

//Student
Student::Student(const std::string new_name, const int new_age,
                 const std::string new_grade) 
    : Person(new_name, new_age),
    grade(new_grade){}
        /*Runner(getName() , getAge(), getTime()){
        grade = new_grade;*/

void Student::print() const {
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout.width(20); std::cout << std::left << grade;
    std::cout << "\n";
}

//Runner
//Runner::Runner(){};
Runner::Runner(const std::string new_name, const int new_age, const std::string new_grade,
       const int new_time)  /* const int -> int? this might be updated multiple times in run-time */
    : Student(new_name, new_age, new_grade),
    time(new_time) {}
int Runner::getTime() const { return time;}

void Runner::print() const{
    std::cout.width(20); std::cout << std::left << getName();
    std::cout.width(20); std::cout << std::left << getAge();
    std::cout.width(20); std::cout << std::left << getTime();
    std::cout << "\n";
}

//Teacher
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
