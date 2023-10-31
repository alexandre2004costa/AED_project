//
// Created by Alexandre on 08/10/2023.
//
#include "Class.h"
#include "vector"
#include <set>
#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H


class Schedule {
private:
    std::vector<Class>classes;
public:
    void addClasses(Class a);
    void show();
    std::vector<Class> getClasses();
    int numberOfUCs();
    Schedule& removeUcClasses(std::string uc);
};


#endif //AED_PROJECT_SCHEDULE_H
