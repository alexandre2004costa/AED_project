//
// Created by Alexandre on 08/10/2023.
//

#include "Turma.h"
Turma::Turma(){classCode=" ";}
Turma::Turma(std::string classCode):classCode(classCode){};
void Turma::show(){
    std::cout<<classCode<<" And : "<<std::endl;
    schedule.show();
}
std::string Turma::getClassCode(){return classCode;}
void Turma::addClassToS(Class c){
    schedule.addClasses(c);
}
Schedule Turma::getSchedule(){
    return schedule;
}
void Turma::addClassToG(std::pair<int, std::string> par){
    nEstudanteCadeira.insert(par);
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
