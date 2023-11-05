//
// Created by Alexandre on 08/10/2023.
//
#include <iostream>
#include <string>
#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H

/// Classe que declara uma aula
///
/// É a classe usada para declarar as aulas e mostrar os seus atributos, bem como confirmar se existe sobreposição entre aulas
///@param uc : Refere a uc que está a ser lecionada na aula
///@param weekDay : Dia da semana da aula
///@param type : Distingue a aula entre prática, teórico-prática e teórica
///@param classCode : ClassCode da turma da aula
///@param startTime : Hora de início da aula
///@param duration : Tempo de duração da aula
class Class {
private:
    std::string uc;
    std::string weekDay;
    std::string type;
    std::string classCode;
    double startTime;
    double duration;
public:
    /// Cria uma aula dado uma uc, dia da semana, tipo de aula, hora de início, duração e uma turma
    ///@param uc : Unidade curricular que está a ser lecionada na aula
    ///@param wd : Dia da semana da aula
    ///@param tp : Distingue a aula entre prática, teórico-prática e teórica
    ///@param cC : ClassCode da turma da aula
    ///@param st : Hora de início da aula
    ///@param dur : Tempo de duração da aula
    Class(std::string uc,std::string wd,std::string tp,double st,double dur, std::string cC);

    ///Mostra os diferentes atríbutos da aula
    void show();

    //Gets
    /// Obter a uc da aula
    /// @return uc
    std::string getUc();

    /// Obter o classcode da turma da aula
    /// @return classcode
    std::string getClassCode();

    /// Verifica se existe sobreposição no horário de duas aulas
    /// @param c : aula com que queremos fazer a comparação
    /// @return bool : indica se existe ou não sobreposição
    bool overlaps(Class c);

    /// Transforma a aula em formato ficheiro,
    /// formato ficheiro : classCode,uc,weekDay,startTime,duration,type;
    /// @return parâmetros no formato ficheiro
    std::string transformToFileFormat();//

};



#endif //AED_PROJECT_CLASS_H
