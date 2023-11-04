//
// Created by Alexandre on 08/10/2023.
//

#include "Turma.h"

int binarySearch(std::vector<std::pair<int, std::string>> temp, std::string target) {
    int low = 0;
    int high = temp.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (temp[mid].second == target) {
            return mid;
        } else if (temp[mid].second < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
Turma::Turma(){classCode=" ";}
Turma::Turma(std::string classCode):classCode(classCode){};
std::string Turma::getClassCode(){return classCode;}
std::vector<std::pair<int, std::string>> Turma::getnEstudanteCadeira(){return nEstudanteCadeira;}
void Turma::setnEstudanteCadeira(std::vector<std::pair<int, std::string>> a){
    nEstudanteCadeira = a;
}
void Turma::showEstudanteUc(){
    for (auto k : nEstudanteCadeira){
        std::cout << k.first << " in "<<k.second<<std::endl;
    }
}
void Turma::addClassToS(Class c){
    schedule.addClasses(c);
}
Schedule Turma::getSchedule(){
    return schedule;
}
void Turma::addClassToG(std::pair<int, std::string> par){
    nEstudanteCadeira.push_back(par);
}
int Turma::numberOfStudents(){
    int c = 0;
    int lastN = 0;
    for (auto k : nEstudanteCadeira){
        if (k.first != lastN)c++;
        lastN = k.first;
    }
    return c;
}
std::set<int> Turma::studentsOfTurma(){
    std::set<int> numbers;
    for (auto k : nEstudanteCadeira){
        numbers.insert(k.first);
    }
    return numbers;
}

bool Turma::operator==(Turma turma) {
    return turma.getClassCode() == classCode;
}
void Turma::showSchedule() {
    schedule.show();
}

int Turma::studentsOfUC(std::string uc) {
    int count = 0;
    for (auto pair : nEstudanteCadeira) {
        if (pair.second == uc) count++;
    }
    return count;
}
std::set<int> Turma::studentsOfTurmaUc(std::string uc){
    std::set<int> res;
    int k = binarySearch(nEstudanteCadeira,uc);
    res.insert(nEstudanteCadeira[k].first);
    int i = 0;
    while(nEstudanteCadeira[k-i].second == uc){
        res.insert(nEstudanteCadeira[k-i].first);
        i++;
    }
    i = 0;
    while(nEstudanteCadeira[k-i].second == uc){
        res.insert(nEstudanteCadeira[k-i].first);
        i++;
    }
    return res;
}

std::vector<Class> Turma::classesOfUC(std::string uc) {
    std::vector<Class> classes;
    for (auto c : schedule.getClasses()) {
        if (c.getUc() == uc) classes.push_back(c);
    }
    return classes;
}
void Turma::removeStudent(int n ,std::string uc){
    for (auto it = nEstudanteCadeira.begin(); it != nEstudanteCadeira.end(); ++it) {
        if (it->first == n && it->second == uc) {
            nEstudanteCadeira.erase(it);
            break;
        }
    }
}
bool Turma::haveUc(std::string uc){
    int year = classCode[0] - '0';
    int n =  stoi(uc.substr(uc.length()-2,2));
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
