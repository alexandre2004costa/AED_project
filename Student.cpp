//
// Created by Alexandre on 08/10/2023.
//

#include "Student.h"

Student::Student(){
    name = " ";
    number = 1;
}

Student::Student(std::string name,int number): name(name), number(number){};

std::string Student::getName(){return name;}
int Student::getNumber(){return number;}

void Student::addUcs(std::pair<std::string ,Turma >t){
    turmas.push_back(t);
}

void Student::show(){
    std::cout<<name<<" and number : "<<number<<std::endl;
    for(auto k : turmas){
        std::cout<<k.first<<" : "<<k.second.getClassCode()<<std::endl;
    }
}

