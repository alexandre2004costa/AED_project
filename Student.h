//
// Created by Alexandre on 08/10/2023.
//
#include "Turma.h"
#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H


class Student {
private:
    std::string name;
    Schedule schedule;
    int number;
public:
    Student();
    Student(std::string name,int number);
    std::string getName();
    int getNumber();
    void show();
    void addToSchedule(Class c);
    void showSchedule();
    Schedule getSchedule();
    void setSchedule(Schedule &newSchedule);
};


#endif //AED_PROJECT_STUDENT_H
