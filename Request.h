//
// Created by Alexandre on 01/11/2023.
//

#ifndef P_AED_REQUEST_H
#define P_AED_REQUEST_H


#include <string>

class Request {
public:
    Request(std::string requestCode,int studentNumber,std::string Uc,std::string OptionalClassI = "", std::string OptionalClassF = "", std::string UcFinal = "");
    void show();
    std::string ToFileFormat();
    int studentNumber;
    std::string requestCode;
    std::string Uc;
    std::string UcFinal;
    std::string OptionalClassI;
    std::string OptionalClassF;
};


#endif //P_AED_REQUEST_H
