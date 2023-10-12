//
// Created by Alexandre on 08/10/2023.
//
#include "Class.h"
#include "vector"
#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H


class Schedule {
private:
    std::vector<Class>classes;
public:
    void addClasses(Class a);
    void show();
};


#endif //AED_PROJECT_SCHEDULE_H
