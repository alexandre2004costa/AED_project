//
// Created by Alexandre on 08/10/2023.
//

#include <algorithm>
#include "Schedule.h"
void Schedule::addClasses(Class a){
    classes.push_back(a);
}
void Schedule::show(){
    for(auto k : classes){
        k.show();
    }
}
std::vector<Class>Schedule:: getClasses(){return classes;}

int Schedule::numberOfUCs() {
    int count = 0;
    std::string lastUC;
    for (auto c : classes) {
        if (c.getUc() != lastUC) count++;
        lastUC = c.getUc();
    }
    return count;
}
Schedule& Schedule::removeUcClasses(std::string uc){
    classes.erase(std::remove_if(classes.begin(), classes.end(), [uc](Class c) {
        return c.getUc() == uc;}), classes.end());
    return *this;
}

