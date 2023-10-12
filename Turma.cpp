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

