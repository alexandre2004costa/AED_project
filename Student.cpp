//
// Created by Alexandre on 08/10/2023.
//

#include "Student.h"

Student::Student(){
    name = " ";
    number = 1;
}
Student::Student(std::string name,int number): name(name), number(number){};
void Student::addUcs(std::pair<std::string ,Turma >turmas){
    this->turmas.push_back(turmas);
}
void Student::show(){
    std::cout<<name<<" and number : "<<number<<std::endl;
}

