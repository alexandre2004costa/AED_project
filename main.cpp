//
// Created by Alexandre on 09/10/2023.
//
#include <fstream>
#include "Student.h"
#include "Menu.h"
#include <unordered_map>

// Função para extrair substrings entre vírgulas
std::vector<std::string> strings(std::string input) {
    std::vector<std::string> substrings;
    std::string substring;
    for (char k : input) {
        if (k == ',') {
            // Encontrou uma vírgula, adicionar a substring à lista
            if (!substring.empty()) {
                substrings.push_back(substring);
                substring = "";//Reset
            }
        } else {
            // Não é uma vírgula, adicionar o caractere à substring
            substring += k;
        }
    }
    // Último caso
    if (!substring.empty()) {
        substrings.push_back(substring);
    }
    return substrings;
}


void addClassToStudent(Student &student,std::string uc,std::string classC , std::vector<Turma> &turmas){
    for (Turma &turma: turmas){
        if (classC == turma.getClassCode()){
            turma.addClassToG(std::make_pair(student.getNumber(),uc));
            for (Class c : turma.getSchedule().getClasses()){
                if (c.getUc() == uc){
                    student.addToSchedule(c);
                }
            }
        }

    }
}
void loadingInfoToStudents(std::unordered_map<int,Student>& students,std::vector<Turma> & turmas)  {
    std::ifstream in ("students_classes.csv");
    if (!in.is_open()) {
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
        if (number != lastNumber) {
            if (student.getName() != " ") {
                students.insert({ lastNumber, student });
            }
            student = Student(name, number);
        }
        addClassToStudent(student,ucCode,classCode,turmas);
        lastNumber = number;
    }

    students.insert({student.getNumber(),student});
    in.close();
}
void loadingInfoToClasses(std::vector<Turma>& turmas){
    std::ifstream in ("classes.csv");
    if (!in.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }
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
void loadWaitingList(std::queue<Request> &requests){
    std::ifstream in ("Waiting.csv");
    if (!in.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }
    std::string line;
    int i = 0;
    Turma t;
    while (std::getline(in, line)) {
        i++;
        if (i == 1)continue;
        std::string requestCode = line.substr(0,2);
        std::vector<std::string> p = strings(line.substr(3));
        for(auto k : p)std::cout<<" : "<<k;
        if (requestCode == "ac")requests.push(Request("ac",std::stoi(p[0]),p[1],p[2]));
        else if(requestCode == "au")requests.push(Request("au",std::stoi(p[0]),p[1]));
        else if (requestCode == "rc")requests.push(Request("rc",std::stoi(p[0]),p[1],p[2]));
        else if (requestCode == "ru")requests.push(Request("ru",std::stoi(p[0]),p[1]));
        else if (requestCode == "sc")requests.push(Request("sc",std::stoi(p[0]),p[1],p[2],p[3]));
        else if (requestCode == "su")requests.push(Request("su",std::stoi(p[0]),p[1],"","",p[2]));
    }
}



int main() {
    std::vector<Turma> turmas;
    loadingInfoToClasses(turmas);
    std::unordered_map<int,Student> students;
    loadingInfoToStudents(students,turmas);
    std::queue<Request> requests;
    loadWaitingList(requests);
    Menu menu = Menu(turmas,students,requests);
    menu.MenuBase();
    return 0;
}
