//
// Created by Alexandre on 08/10/2023.
//
#include <algorithm>
#include "Schedule.h"

void Schedule::show(){// Mostra as aulas do horário
    for(auto k : classes){
        k.show();
    }
}
//Get
std::vector<Class>Schedule:: getClasses(){return classes;}

void Schedule::addClasses(Class a){classes.push_back(a);}// Adiciona uma aula ao horário

int Schedule::numberOfUCs() {// Retorna o nºde ucs no horário
    int count = 0;
    std::string lastUC;
    for (auto c : classes) {
        if (c.getUc() != lastUC) count++; // Se a uc for diferente da anterior adicionamos um à contagem
        lastUC = c.getUc();
    }
    return count;
}

Schedule& Schedule::removeUcClasses(std::string uc){// Retorna uma referência de um horário sem as aulas de uma certa uc
    classes.erase(std::remove_if(classes.begin(), classes.end(), [uc](Class c) {
        return c.getUc() == uc;}), classes.end()); // Filtrar o horário ao eliminar as ucs que são iguais à uc passada por parâmetro
    return *this;
}

