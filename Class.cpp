//
// Created by Alexandre on 08/10/2023.
//

#include <iomanip>
#include "Class.h"
Class::Class(std::string uc,std::string wd,std::string tp,double st,double dur, std::string cC){// Cria uma aula dado uma uc, dia da semana, tipo de aula, hora de início, duração e uma turma
    uc = uc;
    weekDay = wd;
    type = tp;
    startTime = st;
    duration = dur;
    classCode = cC;
}
void Class::show(){
    std::cout<<classCode<<"|"<<uc<<"|"<<weekDay<<"|"<<startTime<<"|"<<duration<<"|"<<type<<std::endl;
}

//Gets
std::string Class::getUc(){return uc;}

std::string Class::getClassCode() {return classCode;}

bool Class::overlaps(Class c) {// Verifica se existe sobreposição entre duas aulas
    if (weekDay == c.weekDay) { // Caso as aulas sejam no mesmo dia
        double end1 = startTime + duration;
        double end2 = c.startTime + c.duration;
        if ((startTime <= end2 && end1 >= c.startTime) || (c.startTime <= end1 && end2 >= startTime)) return true;
    }
    return false;
}
std::string Class::transformToFileFormat(){ // Retorna a aula em formato ficheiro a aula
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1); // Definir 1 case decimal para os double values
    ss << classCode << "," << uc << "," << weekDay << "," << startTime << "," << duration << "," << type;
    return ss.str();
}



