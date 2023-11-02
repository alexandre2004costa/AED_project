//
// Created by Alexandre on 01/11/2023.
//

#include <iostream>
#include "Request.h"

Request::Request(int studentNumber, std::string requestCode, std::string Uc, std::string UcFinal, std::string OptionalClassI, std::string OptionalClassF)
        : studentNumber(studentNumber), requestCode(requestCode), Uc(Uc), UcFinal(UcFinal), OptionalClassI(OptionalClassI), OptionalClassF(OptionalClassF){}

void Request::show(){
    if (requestCode == "ac")std::cout << "O aluno numero "<<studentNumber<<" quer entrar na turma "<<OptionalClassI<<" na cadeira "<<Uc<<std::endl;
    else if(requestCode == "au")std::cout << "O aluno numero "<<studentNumber<<" quer entrar na cadeira "<<Uc<<std::endl;
    else if (requestCode == "rc")std::cout << "O aluno numero "<<studentNumber<<" quer sair da turma "<<OptionalClassI<<" na cadeira "<<Uc<<std::endl;
    else if (requestCode == "ru")std::cout << "O aluno numero "<<studentNumber<<" quer sair da cadeira "<<Uc<<std::endl;
    else if (requestCode == "sc")std::cout << "O aluno numero "<<studentNumber<<" quer trocar da turma "<<OptionalClassI<<" para a "<<OptionalClassF<<std::endl;
    else if (requestCode == "su")std::cout << "O aluno numero "<<studentNumber<<" quer trocar da Uc "<<OptionalClassI<<" para a "<<OptionalClassF<<std::endl;
}
std::string Request::ToFileFormat(){
    if (requestCode == "ac")return "O aluno numero "+ std::to_string(studentNumber) +" quer entrar na turma "+OptionalClassI+" na cadeira "+Uc;
    else if(requestCode == "au")return "O aluno numero "+std::to_string(studentNumber)+" quer entrar na cadeira "+Uc;
    else if (requestCode == "rc")return "O aluno numero "+std::to_string(studentNumber)+" quer sair da turma "+OptionalClassI+" na cadeira "+Uc;
    else if (requestCode == "ru")return "O aluno numero "+std::to_string(studentNumber)+" quer sair da cadeira "+Uc;
    else if (requestCode == "sc")return "O aluno numero "+std::to_string(studentNumber)+" quer trocar da turma "+OptionalClassI+" para a "+OptionalClassF;
    else if (requestCode == "su")return "O aluno numero "+std::to_string(studentNumber)+" quer trocar da Uc "+OptionalClassI+" para a "+OptionalClassF;
}
