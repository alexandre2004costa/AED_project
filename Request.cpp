//
// Created by Alexandre on 01/11/2023.
//

#include "Request.h"

Request::Request(int studentNumber, std::string requestCode, std::string Uc, std::string UcFinal, std::string OptionalClassI, std::string OptionalClassF)
        : studentNumber(studentNumber), requestCode(requestCode), Uc(Uc), UcFinal(UcFinal), OptionalClassI(OptionalClassI), OptionalClassF(OptionalClassF) {}