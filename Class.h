//
// Created by Alexandre on 08/10/2023.
//
#include <iostream>
#include <string>
#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H


class Class {
private:
    std::string UC;
    std::string weekDay;
    std::string type;
    std::string classCode;
    double startTime;
    double duration;
public:
    Class(std::string uc,std::string wd,std::string tp,double st,double dur, std::string cC);

    void show();// Mostar a aula

    //Gets
    std::string getUc();
    std::string getClassCode();

    bool overlaps(Class c); // Verifica se existe sobreposição entre duas aulas

    std::string transformToFileFormat();//Retorna a aula em formato ficheiro a aula
};



#endif //AED_PROJECT_CLASS_H
