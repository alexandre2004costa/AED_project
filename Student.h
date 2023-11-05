//
// Created by Alexandre on 08/10/2023.
//
#include "Turma.h"
#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

/// Classe que declara um estudante
///
/// É a classe usada para declarar um estudante, e realizar alterações no seu horário
///@param name : Nome do estudante
///@param schedule : Horário do estudante
///@see Schedule()
///@param number : Número de estudante do aluno
class Student {
private:
    std::string name; // Nome
    Schedule schedule; // Horário do estudante
    int number; // Nº de estudante
public:
    /// Cria um estudante com atributos nulos
    Student();

    /// Cria um estudante com nome e número
    ///@param name : Nome do estudante
    ///@param number : Número de estudante do aluno
    Student(std::string name,int number);

    //Gets
    /// Obter o nome do estudante
    /// @return nome
    std::string getName();

    /// Obter o número do estudante
    /// @return número
    int getNumber();

    /// Obter o horário do estudante
    /// @return horário
    ///@see Schedule()
    Schedule getSchedule();

    //Set
    /// Altera o horário atual por um novo
    ///@see Schedule()
    void setSchedule(Schedule &newSchedule);

    /// Adiciona uma aula ao horário do estudante
    /// @param c : aula a adicionar ao horário
    void addToSchedule(Class c);

    ///Mostra as aulas do horário
    ///@see Class()
    void showSchedule();


};


#endif //AED_PROJECT_STUDENT_H
