//
// Created by Alexandre on 08/10/2023.
//
#include "Schedule.h"
#include <map>
#include <set>
#ifndef AED_PROJECT_TURMA_H
#define AED_PROJECT_TURMA_H


class Turma {
private:
    std::string classCode;
    Schedule schedule;
    std::set<std::pair<int, std::string>>nEstudanteCadeira;

public:
    Turma();
    Turma(std::string classCode);
    void show();
    void showSchedule();
    std::string getClassCode();
    void addClassToS(Class c);
    Schedule getSchedule();
    void addClassToG(std::pair< int , std::string>);
    int numberOfStudents();
    std::set<int> studentsOfTurma();
    bool operator==(Turma turma);
};


#endif //AED_PROJECT_TURMA_H
