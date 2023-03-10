#ifndef MY_RUNNER
#define MY_RUNNER
#include <string>
#include <iostream>
#include "customStack.h"

class Person{
private: 
    std::string name;
    int age;
public:
    Person(){};
    Person(const std::string new_name, const int new_age);
    std::string getName() const; 
    int getAge() const; 
    virtual void print();
};

class Student : public Person{
private:
    float grade = 0.0f; 
public:
    Student(){};
    Student(const std::string new_name, const int new_age,
            const float new_grade);
    float getGrade() const;
    void setGrade(float g);
    void print() const;
};

class Runner : public Student{
private:
    //float time;
    float best_time;
    StackLL<float> laps;
public:
    Runner(){};
    Runner(const std::string new_name, const int new_age, const float new_grade,
           const float best = 0.0f);  /* const int -> int? this might be updated multiple times in run-time */
    Runner(const Runner& r);
    /*
    ~Runner(){
        this->laps.~StackLL();
    };
    */
    //int getTime() const; // potentially not needed
    //void setTime(float i); // potentially not needed
    float getBestTime() const;
    void setBestTime(float i);
    void printLaps();
    void setLapTime(float delta); //feed Timer::GetDeltaTime()
    void print() const;
    float addLapTimes();
    int numLaps() const;
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
