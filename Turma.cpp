//
// Created by Alexandre on 08/10/2023.
//

#include "Turma.h"

Turma::Turma(std::string classCode):classCode(classCode){};
std::string Turma::show(){
    return classCode;
}
