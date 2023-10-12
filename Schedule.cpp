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
