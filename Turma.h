//
// Created by Alexandre on 08/10/2023.
//
#include "Schedule.h"
#ifndef AED_PROJECT_TURMA_H
#define AED_PROJECT_TURMA_H


class Turma {
private:
    std::string classCode;
    Schedule schedule;
public:
    Turma(std::string classCode);
};


#endif //AED_PROJECT_TURMA_H
