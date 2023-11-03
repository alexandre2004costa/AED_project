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
    std::set<std::pair<int, std::string>>nEstudanteCadeira; // Estrutura q guarda a que Uc o Nºestudante está associado dentro desta Turma

public:
    Turma(); // Construtor default
    Turma(std::string classCode);
    void showEstudanteUc();
    void showSchedule();
    std::string getClassCode();
    void addClassToS(Class c);
    Schedule getSchedule();
    void addClassToG(std::pair< int , std::string>);
    int numberOfStudents();
    std::set<int> studentsOfTurma();
    bool operator==(Turma turma);
    int studentsOfUC(std::string uc);
    std::set<int> studentsOfTurmaUc(std::string uc);
    std::vector<Class> classesOfUC(std::string uc);
    void removeStudent(int n, std::string uc);
    bool haveUc(std::string uc);
};


#endif //AED_PROJECT_TURMA_H
