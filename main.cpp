//
// Created by Alexandre on 09/10/2023.
//
#include <fstream>
#include "Student.h"

void loadingInfoToClasses(std::vector<Student>& students)  {
    std::ifstream in ("students_classes.csv");
    if (!in.is_open()) {  // Verifique se o arquivo foi aberto com sucesso
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }
    std::string line;
    std::string name;
    int lastNumber = 0;
    int i = 0;
    Student student = Student();
    while (std::getline(in, line)) {
        i++;
        if (i==1)continue;
        int number = std::stoi(line.substr(0, 9));
        int k = line.find_first_of(',',10);
        name = line.substr(10,k-10);
        int k2 = line.find_first_of(',',k+1);
        std::string ucCode = line.substr(k+1,k2-k-1);
        std::string turma = line.substr(k2+1);
        if (number!=lastNumber){
            Student student = Student(name,number);
            students.push_back(student);
        }
        student.addUcs({ucCode, Turma(turma)});
        lastNumber = number;


    }
    in.close();
}

int main() {
    std::vector<Student> students;
    loadingInfoToClasses(students);
    std::cout<<1;
    for(auto k : students){
        k.show();
    }
    return 0;
}