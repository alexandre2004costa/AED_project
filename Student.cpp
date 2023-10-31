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

void Student::show(){
    std::cout<<name<<" and number : "<<number<<std::endl;
}

void Student::addToSchedule(Class c) {
    schedule.addClasses(c);
}
void Student::showSchedule(){
    schedule.show();
}
Schedule Student::getSchedule() {
    return schedule;
}
void Student::setSchedule(Schedule &newSchedule) {
    schedule = newSchedule;
}
