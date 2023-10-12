//
// Created by Alexandre on 08/10/2023.
//

#include "Class.h"
Class::Class(std::string uc,std::string wd,std::string tp,double st,int dur){
    UC = uc;
    weekDay = wd;
    type = tp;
    startTime = st;
    duration = dur;
}
void Class::show(){
    std::cout<<UC<<"|"<<weekDay<<"|"<<startTime<<"|"<<duration<<"|"<<type<<std::endl;
}

