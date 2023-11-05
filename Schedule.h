//
// Created by Alexandre on 08/10/2023.
//
#include "Class.h"
#include "vector"
#include <set>
#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H


class Schedule {
private:
    std::vector<Class>classes; // Vetor que guarda as aulas do horário
public:
    void show(); // Mostra as aulas do horário
    //Get
    std::vector<Class> getClasses();

    void addClasses(Class a); // Adiciona uma aula ao horário

    int numberOfUCs(); // Retorna o nºde ucs no horário

    Schedule& removeUcClasses(std::string uc); // Retorna uma referência de um horário sem as aulas de uma certa uc
};


#endif //AED_PROJECT_SCHEDULE_H
