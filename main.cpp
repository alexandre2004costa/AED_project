//
// Created by Alexandre on 09/10/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "Turma.h"

void loadingInfoToClasses(std::vector<Student> & students)  {
    std::ifstream arquivo("stu.txt");
    std::cout<<arquivo.is_open();
    std::string line;
    std::string name;
    int lastNumber = 0;
    int i = 0;
    Student student = Student(" ",0);
    while (std::getline(arquivo, line)) {
        std::cout<<i;
        i++;
        if (i==1)continue;
        int number = std::stoi(line.substr(0, 9));
        int k = line.find_first_of(',',10);
        name = line.substr(10,k-10);
        int k2 = line.find_first_of(',',k+1);
        std::string ucCode = line.substr(k+1,k2-k-1);
        std::string turma = line.substr(k2+1);
        if (number!=lastNumber){
            std::cout<<1;
            Student student = Student(name,number);
            students.push_back(student);
        }
        student.addUcs({ucCode, Turma(turma)});
        lastNumber = number;


    }

    arquivo.close();
}

int main() {
    std::vector<Student> students;
    loadingInfoToClasses(students);
    for(auto k : students){
        std::cout<<1;
        k.show();
    }
    return 0;
}