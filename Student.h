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
    std::vector<std::pair<std::string ,Turma >> turmas;
    int number;
public:
    Student();
    Student(std::string name,int number);
    void addUcs(std::pair<std::string ,Turma >turmas);
    void show();
};


#endif //AED_PROJECT_STUDENT_H
