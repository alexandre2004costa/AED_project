//
// Created by Alexandre on 08/10/2023.
//

#include "Class.h"
Class::Class(std::string uc,std::string wd,std::string tp,double st,double dur, std::string cC){
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

std::string Class::getClassCode() {
    return classCode;
}

bool Class::overlaps(Class c) {
    if (weekDay == c.weekDay) {
        double end1 = startTime + duration;
        double end2 = c.startTime + c.duration;

        if ((startTime <= end2 && end1 >= c.startTime) || (c.startTime <= end1 && end2 >= startTime)) return true;
    }
    return false;
}
std::string Class::transformToFileFormat(){
    return classCode+","+UC+","+weekDay+","+ std::to_string(startTime)+","+ std::to_string(duration)+","+type;
}



