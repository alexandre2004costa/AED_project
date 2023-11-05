//
// Created by Alexandre on 01/11/2023.
//

#ifndef P_AED_REQUEST_H
#define P_AED_REQUEST_H


#include <string>

/// Classe que declara um pedido, este guarda informação de pedidos que não foram aceites à primeira tentativa e esperam aprovação
///
/// É a classe usada para declarar, mostrar e transformar em formato ficheiro um pedido.
///@param studentNumber : Número do estudante que efetuou o pedido
///@param requestCode : Tipo de pedido efetuado
///@param Uc : Uc a que foi efetuado o pedido, ou Uc da qual o estudante pretende sair
///@param UcFinal : Uc em que o estudante pretende entrar (parâmetro pode ser opcional dependendo do tipo de pedido)
///@param OptionalClassI :  Turma a que foi efetuado o pedido, ou Turma da qual o estudante pretende sair
///@param OptionalClassF : Turma em que o estudante pretende entrar (parâmetro pode ser opcional dependendo do tipo de pedido)
class Request {
public:
    /// Cria um pedido com requestCode, número de estudante, uc, e parâmetros opcionais : turma inicial, turma final e uc final
    ///@param studentNumber : Número do estudante que efetuou o pedido
    ///@param requestCode : Tipo de pedido efetuado
    ///@param Uc : Uc a que foi efetuado o pedido, ou Uc da qual o estudante pretende sair
    ///@param UcFinal : Uc em que o estudante pretende entrar (parâmetro pode ser opcional dependendo do tipo de pedido)
    ///@param OptionalClassI :  Turma a que foi efetuado o pedido, ou Turma da qual o estudante pretende sair
    ///@param OptionalClassF : Turma em que o estudante pretende entrar (parâmetro pode ser opcional dependendo do tipo de pedido)
    Request(std::string requestCode,int studentNumber,std::string Uc,std::string OptionalClassI = "", std::string OptionalClassF = "", std::string UcFinal = "");

    /// Mostra o contéudo do pedido
    void show();

    /// Transforma o pedido em formato ficheiro,
    /// formato ficheiro : requestCode,studentNumber,Uc,OptionalClassI,OptionalClassF,UcFinal;
    /// @return parâmetros no formato ficheiro
    std::string toFileFormat();

    // Parâmetros públicos da classe
    int studentNumber;
    std::string requestCode;
    std::string Uc;
    std::string UcFinal;
    std::string OptionalClassI;
    std::string OptionalClassF;
};


#endif //P_AED_REQUEST_H
