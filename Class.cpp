//
// Created by Alexandre on 08/10/2023.
//

#include "Class.h"
Class::Class(std::string uc,std::string wd,std::string tp,double st,int dur, std::string cC){
    UC = uc;
    weekDay = wd;
    type = tp;
    startTime = st;
    duration = dur;
    classCode = cC;
}
void Class::show(){
    std::cout<<classCode<<"|"<<UC<<"|"<<weekDay<<"|"<<startTime<<"|"<<duration<<"|"<<type<<std::endl;
}
std::string Class::getUc(){return UC;}


