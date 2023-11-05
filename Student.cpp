//
// Created by Alexandre on 08/10/2023.
//

#include "Student.h"

Student::Student(){// Construtor default
    name = " ";
    number = 1;
}

Student::Student(std::string name,int number): name(name), number(number){};// Construtor com nome e nº

//Gets
std::string Student::getName(){return name;}
int Student::getNumber(){return number;}
Schedule Student::getSchedule() {return schedule;}

//Set
void Student::setSchedule(Schedule &newSchedule) {
    schedule = newSchedule;
}

void Student::addToSchedule(Class c) {// Adiciona uma aula ao horário do estudante
    schedule.addClasses(c);
}
void Student::showSchedule(){// Mostra o horário do estudante
    schedule.show();
}


