//
// Created by Alexandre on 08/10/2023.
//
#include "Schedule.h"

#include <map>
#include <set>
#include <list>
#ifndef AED_PROJECT_TURMA_H
#define AED_PROJECT_TURMA_H

/// Classe que declara uma turma
///
/// É a classe usada para declarar uma turma, mostrar e modificar os alunos e o horário da mesma
///@param classCode : Código da turma
///@param schedule : Horário da turma
///@see Schedule()
///@param EstudanteCadeira : Conjunto de estudantes com a respetiva uc da turma
class Turma {
private:
    std::string classCode;
    Schedule schedule;
    std::vector<std::pair<int, std::string>>EstudanteCadeira;

public:
    /// Cria uma turma com atributos nulos
    Turma(); // Construtor default

    /// Cria uma turma com um classCode
    ///@param classCode : Código da turma
    Turma(std::string classCode);

    ///Mostra o hórario da turma
    ///@see Schedule()
    void showSchedule();

    //Gets
    /// Obter o classCode da turma
    /// @return classCode
    std::string getClassCode();

    /// Obter o horário da turma
    /// @return horário
    Schedule getSchedule();

    /// Obter um estudante
    /// @return estudantes com a respetiva uc da turma
    std::vector<std::pair<int, std::string>> getEstudanteCadeira();

    //Set
    /// Altera o vetor de estudantes atual por um novo
    /// @param a
    void setnEstudanteCadeira(std::vector<std::pair<int, std::string>> a);

    /// Adicionar a aula ao horário
    /// @param c
    /// @see Class()
    void addClassToS(Class c); // Adiciona uma aula ao schedule
/// Adicionar um par estudante ao vetor de pares de estudantes
    /// @param par
    void addClassToG(std::pair< int , std::string> par); // // Adiciona um aluno à turma numa determinada uc

    /// Obter o número de estudantes numa turma
    /// @return número de estudantes da turma
    int numberOfStudents(); // Retorna o nº total de estudantes na turma

    /// Armazenar os números dos estudantes da turma
    /// @return set com os seus números
    std::set<int> studentsOfTurma(); // Retorna um set com todos os nº de estudantes da turma

    /// Obter o número de estudantes numa turma numa dada uc
    /// @return número de estudantes
    int studentsOfUC(std::string uc); // Retorna o nº total de estudantes da turma numa determinada uc

    /// Obter os números de cada estudante numa turma numa dad uc
    /// @return set desses números,
    /// Complexidade : O(log n) - > binary search
    std::set<int> studentsOfTurmaUc(std::string uc); // Retorna um set com todos os nº de estudantes da turma naquela uc

    /// Obter as aulas de uma das ucs na turma
    /// @return vetor das aulas
    std::vector<Class> classesOfUC(std::string uc); // Retorna um vetor com as aulas numa determinada uc na turma

    /// Remover um estudante da turma numa dada uc
    void removeStudent(int n, std::string uc); // Retira um estudante da turma a uma certa uc

    /// Verificar se uma determinada uc existe na turma
    /// @return true caso exista
    bool haveUc(std::string uc); // Confirma se existe uma determminada uc na turma

    /// Verificar se os classCodes de duas turmas são iguais
    /// @return true caso sejam
    bool operator==(Turma turma); // Operador que confirma a igualdade entre turmas tendo em conta o classCode
};


#endif //AED_PROJECT_TURMA_H