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
        if (k == ',') {// Encontrou uma vírgula, adicionar a substring à lista
            if (!substring.empty()) {
                substrings.push_back(substring);
                substring = "";//Reset
            }
        } else {// Não é uma vírgula, adicionar o caractere à substring
            substring += k;
        }
    }
    // Adicionar a última ocorrência
    if (!substring.empty()) {
        substrings.push_back(substring);
    }
    return substrings;
}

void addClassToStudent(Student &student,std::string uc,std::string classC , std::vector<Turma> &turmas){
    for (Turma &turma: turmas){
        if (classC == turma.getClassCode()){
            turma.addClassToG(std::make_pair(student.getNumber(),uc));// Adicionar o par Nºestudante:Uc à estrutura nEstudanteCadeira
            for (Class c : turma.classesOfUC(uc)){
                student.addToSchedule(c); // Adicionar as aulas ao horário do Estudante
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
        std::vector<std::string> p = strings(line);
        int number = std::stoi(p[0]);
        name = p[1];
        if (number != lastNumber) { // Se tivermos passado para um novo estudante
            if (student.getName() != " ") { // Para evitar o caso inicial
                students.insert({ lastNumber, student });
            }
            student = Student(name, number);
        }
        addClassToStudent(student,p[2],p[3],turmas); // Adicionar as aulas ao horário do Estudante e alterar a estrutura "nEstudanteCadeira" nas turmas que guarda a referencia da Uc em que aquele estudante atua naquela Turma.
        lastNumber = number;
    }
    //Adicionar a última ocorrência
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
        if (i==1)continue; // Ignorar a linha de descrição
        std::vector<std::string> p = strings(line);
        Class aula = Class(p[1],p[2],p[5],std::stod(p[3]),std::stod(p[4]),p[0]);
        std::string  classCode = p[0];
        bool isIn = false; // Esta flag confirma se a turma da aula em que estamos já exite no vetor
        for (auto &turma : turmas){
            if (turma.getClassCode()==classCode){
                isIn = true; // A turma já existe no vetor
                turma.addClassToS(aula);
            }
        }
        if (!isIn){ // Se a turma não existe no vetor nós adicionamos
            t = Turma(classCode);
            t.addClassToS(aula);
            turmas.push_back(t);
        }
    }
}
void loadWaitingList(std::queue<Request> &requests){
    std::ifstream in ("Waiting.csv");
    if (!in.is_open()) {
        std::cout << "Ainda não existe um ficheiro de lista de espera." << std::endl;
        return;
    }
    std::string line;
    int i = 0;
    Turma t;
    while (std::getline(in, line)) {
        i++;
        if (i == 1)continue;//Ignorar a linha de descrição
        std::string requestCode = line.substr(0,2);
        std::vector<std::string> p = strings(line.substr(3));
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
    loadingInfoToClasses(turmas); // Carregar a informação que está no ficheiro classes.csv e guardar no vetor de Turmas
    std::unordered_map<int,Student> students;
    loadingInfoToStudents(students,turmas);// Carregar a informação que está no ficheiro students_classes.csv e guardar no vetor de Estudantes, com a ajuda do vetor das Turmas também cria o horário dos Estudantes
    std::queue<Request> requests;
    loadWaitingList(requests);// Carregar os pedidos pendentes que estão no ficheiro Waiting.csv
    Menu menu = Menu(turmas,students,requests);//Iniciar o nosso menu passando as nossas Turmas, Estudantes e Requests
    menu.MenuBase(); // Mostrar a interface inicial do menu
    return 0;
}
