//
// Created by Alexandre on 01/11/2023.
//

#ifndef P_AED_REQUEST_H
#define P_AED_REQUEST_H


#include <string>

class Request {
private:
    int studentNumber;
    std::string Uc;
    std::string OptionalClass;//Turma desejada
public:
    Request(int studentNumber,std::string Uc);
    Request(int studentNumber,std::string Uc, std::string OptionalClass);
};


#endif //P_AED_REQUEST_H
