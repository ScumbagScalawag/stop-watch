#ifndef MY_RUNNER
#define MY_RUNNER
#include <string>

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
    std::string grade; // (optional) maybe make this float towards the end? 
public:
    Student(){};
    Student(const std::string new_name, const int new_age,
            const std::string new_grade);
    std::string getGrade() const;
    void print() const;
    void setGrade(int g);
};

class Runner : public Student{
private:
    float time;
    float best_time;
public:
    Runner(){};
    Runner(const std::string new_name, const int new_age, const std::string new_grade,
           const int new_time);  /* const int -> int? this might be updated multiple times in run-time */
    int getTime() const;
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
