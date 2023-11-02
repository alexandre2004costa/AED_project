//
// Created by Alexandre on 01/11/2023.
//

#ifndef P_AED_REQUEST_H
#define P_AED_REQUEST_H


#include <string>

class Request {
public:
    Request(int studentNumber, std::string requestCode, std::string Uc, std::string UcFinal = "", std::string OptionalClassI = "", std::string OptionalClassF = "");
    int studentNumber;
    std::string requestCode;
    std::string Uc;
    std::string UcFinal;
    std::string OptionalClassI;
    std::string OptionalClassF;
};


#endif //P_AED_REQUEST_H
