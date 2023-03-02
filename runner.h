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
    Person(const std::string new_name, const int new_age);
    std::string getName() const; 
    int getAge() const; 
    virtual void print() = 0;
};


class Runner : public Person{
private:
    double time;
public:
    Runner(){};
    Runner(const std::string new_name, const int new_age, 
           const int new_time);  /* const int -> int? this might be updated multiple times in run-time */
    int getTime() const;
    void print() const;
};

class Student : public Person{
private:
    std::string grade;
public:
    Student(const std::string new_name, const int new_age,
            const std::string new_grade);
        /*Runner(getName() , getAge(), getTime()){
        grade = new_grade;*/
    void print() const;
};

class Teacher : public Person{
private:
    std::string subject;
public:
    Teacher(){};
    Teacher(const std::string new_name, const int new_age,
            const std::string new_subject);
    void print() const;
};

#endif
