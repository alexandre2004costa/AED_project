//
// Created by Alexandre on 08/10/2023.
//
#include "Turma.h"
#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H


class Student {
private:
    std::string name; // Nome
    Schedule schedule; // Horário do estudante
    int number; // Nº de estudante
public:
    Student(); // Construtor default
    Student(std::string name,int number); // Construtor com nome e nº

    //Gets
    std::string getName();
    int getNumber();
    Schedule getSchedule();

    //Set
    void setSchedule(Schedule &newSchedule);

    void addToSchedule(Class c); // Adiciona uma aula ao horário do estudante
    void showSchedule(); // Mostra o horário do estudante


};


#endif //AED_PROJECT_STUDENT_H
