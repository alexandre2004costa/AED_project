//
// Created by Alexandre on 08/10/2023.
//
#include "Schedule.h"

#include <map>
#include <set>
#include <list>
#ifndef AED_PROJECT_TURMA_H
#define AED_PROJECT_TURMA_H

class Turma {
private:
    std::string classCode;
    Schedule schedule;
    std::vector<std::pair<int, std::string>>EstudanteCadeira; // Estrutura q guarda a que Uc o Nºestudante está associado dentro desta Turma

public:
    Turma(); // Construtor default
    Turma(std::string classCode); // Construtor com o classCode

    void showSchedule(); // Mostra o horário

    //Gets
    std::string getClassCode();
    Schedule getSchedule();
    std::vector<std::pair<int, std::string>> getEstudanteCadeira();

    //Sets
    void setnEstudanteCadeira(std::vector<std::pair<int, std::string>> a);

    void addClassToS(Class c); // Adiciona uma aula ao schedule
    void addClassToG(std::pair< int , std::string>); // // Adiciona um aluno à turma numa determinada uc

    int numberOfStudents(); // Retorna o nº total de estudantes na turma
    std::set<int> studentsOfTurma(); // Retorna um set com todos os nº de estudantes da turma

    int studentsOfUC(std::string uc); // Retorna o nº total de estudantes da turma naquela uc
    std::set<int> studentsOfTurmaUc(std::string uc); // Retorna um set com todos os nº de estudantes da turma naquela uc

    std::vector<Class> classesOfUC(std::string uc); // Retorna um vetor com as aulas daquela uc nesta turma
    void removeStudent(int n, std::string uc); // Retira um estudante da turma a uma certa uc

    bool haveUc(std::string uc); // Confirma se existe uma certa uc na turma
    bool operator==(Turma turma); // Operador que confirma a igualdade entre turmas tendo em conta o classCode
};


#endif //AED_PROJECT_TURMA_H
