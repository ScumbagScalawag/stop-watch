#ifndef MY_RUNNER
#define MY_RUNNER
#include <string>
#include <iostream>

//made runner & student a type of person (common attributes) 
class Person{
private: 
    std::string name;
    int age;
public:
    Person(){};
    Person(const std::string new_name, const int new_age)
        : name(new_name),
        age(new_age) {}
    std::string getName() const{ return name;}
    int getAge() const { return age;}
    virtual const void print(){
        std::cout.width(20); std::cout << std::left << getName();
        std::cout.width(20); std::cout << std::left << getAge();
        std::cout << "\n";
    }

};


class Runner : public Person{
private:
    double time;
public:
    Runner(){};
    Runner(const std::string new_name, const int new_age, 
           const int new_time)  /* const int -> int? this might be updated multiple times in run-time */
        : time(new_time) {}
    int getTime() const { return time;}
    virtual void print() const = 0;
    const void print(){
        std::cout.width(20); std::cout << std::left << getName();
        std::cout.width(20); std::cout << std::left << getAge();
        std::cout.width(20); std::cout << std::left << getTime();
        std::cout << "\n";
    }
};

class Student : public Person{
private:
    std::string grade;
public:
    Student(const std::string new_name, const int new_age,
            const std::string new_grade) 
    : Person(new_name, new_age) {}
        /*Runner(getName() , getAge(), getTime()){
        grade = new_grade;*/
    virtual  void print(){
        std::cout.width(20); std::cout << std::left << getName();
        std::cout.width(20); std::cout << std::left << getAge();
        std::cout.width(20); std::cout << std::left << grade;
        std::cout << "\n";
    }

};

class Teacher : public Runner{
private:
    std::string subject;
public:
    Teacher(const std::string new_subject, const std::string new_name, const int new_age ) : Runner(getName() , getAge(), getTime()){
        subject = new_subject;
    }
    const void print(){
        std::cout.width(20); std::cout << std::left << getName();
        std::cout.width(20); std::cout << std::left << getAge();
        std::cout.width(20); std::cout << std::left << getTime();
        std::cout.width(20); std::cout << std::left << subject;
        std::cout << "\n";
    }

};

#endif
