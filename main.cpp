//
// Created by Alexandre on 09/10/2023.
//
#include <fstream>
#include "Student.h"
#include "Menu.h"

void addClassToStudent(Student &student,std::string uc,std::string classC , std::vector<Turma> turmas){
    for (Turma turma: turmas){
        if (classC == turma.getClassCode()){
            for (Class c : turma.getSchedule().getClasses()){
                if (c.getUc() == uc){
                    student.addToSchedule(c);
                }
            }
        }
    }
}
void loadingInfoToStudents(std::vector<Student>& students,std::vector<Turma>turmas)  {
    std::ifstream in ("students_classes.csv");
    if (!in.is_open()) {  // Verifique se o arquivo foi aberto com sucesso
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }
    std::string line;
    std::string name;
    int lastNumber = 0;
    int i = 0;
    Student student;
    while (std::getline(in, line)) {
        i++;
        if (i==1)continue; //Ignorar a linha de descrição
        int number = std::stoi(line.substr(0, 9));
        int k = line.find_first_of(',',10);
        name = line.substr(10,k-10);
        int k2 = line.find_first_of(',',k+1);
        std::string ucCode = line.substr(k+1,k2-k-1);
        std::string classCode = line.substr(k2+1);
        if (number==lastNumber){
            addClassToStudent(student,ucCode,classCode,turmas);
        }else{
            if(student.getName()!=" "){students.push_back(student);}
            student = Student(name,number);
            addClassToStudent(student,ucCode,classCode,turmas);
        }
        lastNumber = number;
    }
    students.push_back(student);
    in.close();
}
void loadingInfoToClasses(std::vector<Turma>& turmas){
    std::ifstream in ("classes.csv");
    std::string line;
    int i = 0;
    Turma t;
    while (std::getline(in, line)) {
        i++;
        if (i==1)continue; //Ignorar a linha de descrição
        int k = line.find_first_of(',');
        std::string classCode = line.substr(0,k);
        int k2 = line.find_first_of(',',k+1);
        std::string uc = line.substr(k+1,k2-k-1);
        k = k2;
        k2 = line.find_first_of(',',k+1);
        std::string weekDay = line.substr(k+1,k2-k-1);
        k = k2;
        k2 = line.find_first_of(',',k+1);
        std::string st = line.substr(k+1,k2-k);
        double initialTime = std::stod(st); 
        k = k2;
        k2 = line.find_first_of(',',k+1);
        std::string dur = line.substr(k+1,k2-k);
        double duration = std::stod(dur);
        std::string type = line.substr(k2+1);
        Class aula = Class(uc,weekDay,type,initialTime,duration,classCode);
        bool isIn = false;
        for (auto &turma : turmas){
            if (turma.getClassCode()==classCode){
                isIn = true;
                turma.addClassToS(aula);
                }
            }
        if (!isIn){
            t = Turma(classCode);
            t.addClassToS(aula);
            turmas.push_back(t);    
        }   
    }
}



int main() {
    std::vector<Turma> turmas;
    loadingInfoToClasses(turmas);
    std::vector<Student> students;
    loadingInfoToStudents(students,turmas);
    Menu menu = Menu();
    return 0;
}
