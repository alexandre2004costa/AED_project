//
// Created by Alexandre on 08/10/2023.
//

#include "Schedule.h"
void Schedule::addClasses(Class a){
    classes.push_back(a);
}
void Schedule::show(){
    for(auto k : classes){
        k.show();
    }
    //std::cout<<std::endl;
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

