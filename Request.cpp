//
// Created by Alexandre on 01/11/2023.
//

#include <iostream>
#include "Request.h"

Request::Request(std::string requestCode, int studentNumber, std::string Uc, std::string OptionalClassI, std::string OptionalClassF, std::string UcFinal)// Construtor com parâmetros opcionais tendo em conta o tipo de pedido
        : requestCode(requestCode),
          studentNumber(studentNumber),
          Uc(Uc),
          OptionalClassI(OptionalClassI),
          OptionalClassF(OptionalClassF),
          UcFinal(UcFinal) {}

void Request::show(){// Mostra o pedido e os seus parâmetros
    if (requestCode == "ac")std::cout << "O aluno numero "<<studentNumber<<" quer entrar na turma "<<OptionalClassI<<" na cadeira "<<Uc<<std::endl;
    else if(requestCode == "au")std::cout << "O aluno numero "<<studentNumber<<" quer entrar na cadeira "<<Uc<<std::endl;
    else if (requestCode == "rc")std::cout << "O aluno numero "<<studentNumber<<" quer sair da turma "<<OptionalClassI<<" na cadeira "<<Uc<<std::endl;
    else if (requestCode == "ru")std::cout << "O aluno numero "<<studentNumber<<" quer sair da cadeira "<<Uc<<std::endl;
    else if (requestCode == "sc")std::cout << "O aluno numero "<<studentNumber<<" quer trocar da turma "<<OptionalClassI<<" para a "<<OptionalClassF<<std::endl;
    else if (requestCode == "su")std::cout << "O aluno numero "<<studentNumber<<" quer trocar da Uc "<<OptionalClassI<<" para a "<<OptionalClassF<<std::endl;
}
std::string Request::toFileFormat(){// Retorna o pedido numa string no formato de ficheiro
    if (requestCode == "ac")return requestCode + ","+std::to_string(studentNumber) +","+Uc+","+OptionalClassI;
    else if(requestCode == "au")return requestCode + ","+std::to_string(studentNumber) +","+Uc;
    else if (requestCode == "rc")return requestCode + ","+std::to_string(studentNumber) +","+Uc+","+OptionalClassI;
    else if (requestCode == "ru")return requestCode + ","+std::to_string(studentNumber) +","+Uc;
    else if (requestCode == "sc")return requestCode + ","+std::to_string(studentNumber) +","+Uc+","+OptionalClassI+","+OptionalClassF;
    else if (requestCode == "su")return requestCode + ","+std::to_string(studentNumber) +","+Uc+","+OptionalClassI+","+OptionalClassF+","+UcFinal;
}
