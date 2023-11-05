//
// Created by Alexandre on 08/10/2023.
//
#include "Class.h"
#include "vector"
#include <set>
#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H


/// Classe que declara um horário
///
/// É a classe usada para declarar um horário, realizar alterações e ver atributos do mesmo
///@param classes : Conjunto de aulas
///@see Class()
class Schedule {
private:
    std::vector<Class>classes; // Vetor que guarda as aulas do horário
public:

    /// Mostra as aulas do horário
    void show();

    //Get
    /// Obter as aulas do horário
    /// @return conjunto de aulas
    std::vector<Class> getClasses();

    /// Adiciona uma aula ao horário
    ///@param a : aula a adicionar ao horário
    void addClasses(Class a);

    /// Retorna o nºde ucs no horário
    /// @return número de ucs
    int numberOfUCs();

    /// Retorna uma referência de um horário sem as aulas de uma certa uc
    ///@return referência de um horário
    Schedule& removeUcClasses(std::string uc);
};


#endif //AED_PROJECT_SCHEDULE_H
