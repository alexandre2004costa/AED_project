//
// Created by Alexandre on 01/11/2023.
//

#ifndef P_AED_REQUEST_H
#define P_AED_REQUEST_H


#include <string>


class Request {
public:
    Request(std::string requestCode,int studentNumber,std::string Uc,std::string OptionalClassI = "", std::string OptionalClassF = "", std::string UcFinal = ""); // Construtor com parâmetros opcionais tendo em conta o tipo de pedido
    void show(); // Mostra o pedido e os seus parâmetros
    std::string toFileFormat(); // Retorna o pedido numa string no formato de ficheiro
    // Parâmetros públicos da classe
    int studentNumber;
    std::string requestCode;
    std::string Uc;
    std::string UcFinal;
    std::string OptionalClassI;
    std::string OptionalClassF;
};


#endif //P_AED_REQUEST_H
