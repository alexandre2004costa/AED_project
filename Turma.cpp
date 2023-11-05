//
// Created by Alexandre on 08/10/2023.
//

#include "Turma.h"

// Algoritmo de searching , binary search
int binarySearch(std::vector<std::pair<int, std::string>> temp, std::string target) {
    int low = 0; // Limite inferior
    int high = temp.size() - 1; // Limite superior
    while (low <= high) {
        int mid = low + (high - low) / 2; // Elemento do meio
        if (temp[mid].second == target) { return mid;}  // Caso este seja o elemento certo
        else if (temp[mid].second < target) {low = mid + 1;} // O valor está para cima do meio
        else {high = mid - 1;} // O valor está para baixo do meio
    }
    return -1;
}
// Metodos da classe
Turma::Turma(){classCode=" ";}// Construtor default

Turma::Turma(std::string classCode):classCode(classCode){};// Construtor com o classCode

void Turma::showSchedule() {schedule.show();}// Mostra o horário

//Gets
std::string Turma::getClassCode(){return classCode;}

Schedule Turma::getSchedule(){return schedule;}

std::vector<std::pair<int, std::string>> Turma::getEstudanteCadeira(){return EstudanteCadeira;}

//Sets
void Turma::setnEstudanteCadeira(std::vector<std::pair<int, std::string>> a){EstudanteCadeira = a;}


void Turma::addClassToS(Class c){schedule.addClasses(c);}// Adiciona uma aula ao schedule

void Turma::addClassToG(std::pair<int, std::string> par){EstudanteCadeira.push_back(par);}// Adiciona um aluno à turma numa determinada uc

int Turma::numberOfStudents(){// Retorna o nº total de estudantes na turma
    int c = 0;
    int lastN = 0;
    for (auto k : EstudanteCadeira){
        if (k.first != lastN)c++; //Se o nº for diferente do anterior adicionamos um à contagem de alunos
        lastN = k.first;
    }
    return c;
}
std::set<int> Turma::studentsOfTurma(){// Retorna um set com todos os nº de estudantes da turma
    std::set<int> numbers;
    for (auto k : EstudanteCadeira){
        numbers.insert(k.first); // Adicionar o nº ao set
    }
    return numbers;
}

int Turma::studentsOfUC(std::string uc) {// Retorna o nº total de estudantes da turma naquela uc
    int count = 0;
    for (auto pair : EstudanteCadeira) {
        if (pair.second == uc) count++; //Se a uc for igual adicionamos um à contagem de alunos
    }
    return count;
}

std::set<int> Turma::studentsOfTurmaUc(std::string uc){// Retorna um set com todos os nº de estudantes da turma naquela uc
    std::set<int> res;
    int k = binarySearch(EstudanteCadeira,uc); // Encontramos um indíce da ocorrência daquela uc no vetor EstudanteCadeira
    res.insert(EstudanteCadeira[k].first);
    int i = 0;
    while(EstudanteCadeira[k-i].second == uc){ // Andar para trás enquanto estivermos na mesma uc
        res.insert(EstudanteCadeira[k-i].first);
        i++;
    }
    i = 0;
    while(EstudanteCadeira[k-i].second == uc){// Andar para a frente enquanto estivermos na mesma uc
        res.insert(EstudanteCadeira[k-i].first);
        i++;
    }
    return res;
}

std::vector<Class> Turma::classesOfUC(std::string uc) {// Retorna um vetor com as aulas daquela uc nesta turma
    std::vector<Class> classes;
    for (auto c : schedule.getClasses()) {
        if (c.getUc() == uc) classes.push_back(c); // Caso estejamos numa aula daquela uc
    }
    return classes;
}

void Turma::removeStudent(int n ,std::string uc){// Retira um estudante da turma a uma certa uc
    for (auto it = EstudanteCadeira.begin(); it != EstudanteCadeira.end(); ++it) {
        if (it->first == n && it->second == uc) { // Se estivermos no par que estamos à procura
            EstudanteCadeira.erase(it); // Eliminamos aquela ocurrência na estrutura EstudanteCadeira
            break;
        }
    }
}

bool Turma::haveUc(std::string uc){// Confirma se existe uma certa uc na turma
    int year = classCode[0] - '0'; // Extrai o ano através do primeiro dígito do classCode
    int n =  stoi(uc.substr(uc.length()-2,2)); // Extrai os dois últimos dígitos da uc
    switch (year) {
        case 1:
            return n >= 1 && n <= 5;
        case 2:
            return n >= 11 && n <= 15;
        case 3:
            return n >= 21 && n<= 25;
    }
    return false;
}

bool Turma::operator==(Turma turma) {// Operador que confirma a igualdade entre turmas tendo em conta o classCode
    return turma.getClassCode() == classCode;
}


