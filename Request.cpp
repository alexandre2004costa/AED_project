//
// Created by Alexandre on 01/11/2023.
//

#include "Request.h"

Request::Request(int studentNumber, std::string Uc){
    this->studentNumber = studentNumber;
    this->Uc = Uc;
    this->OptionalClass = "";
}
Request::Request(int studentNumber, std::string Uc, std::string OptionalClass) {
    this->studentNumber = studentNumber;
    this->Uc = Uc;
    this->OptionalClass = OptionalClass;
}