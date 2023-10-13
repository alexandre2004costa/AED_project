//
// Created by Alexandre on 08/10/2023.
//
#include <iostream>
#include <string>
#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H


class Class {
private:
    std::string UC;
    std::string weekDay;
    std::string type;
    double startTime;
    int duration;
public:
    Class(std::string uc,std::string wd,std::string tp,double st,int dur);
    void show();
    std::string getUc();
};



#endif //AED_PROJECT_CLASS_H
