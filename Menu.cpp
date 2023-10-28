#include <algorithm>
#include "Menu.h"


Menu::Menu(std::vector<Turma> t,std::unordered_map<int,Student> s){
    turmas = t;
    students = s;
}
void Menu::MenuBase(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Consultar :                                                     ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      1 -> Horarios                                                ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      2 -> Estudantes                                              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      3 -> Numero de estudantes nas UCs                            ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      4 -> Ocupacao da turmas                                      ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      5 -> UCs com maior numero de estudantes                      ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      6 -> Sair                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    bool flag = true;
    while (flag){
        char k;
        std::cout<<"  Option:";
        std::cin>>k;

        switch (k){
            case '1':
                flag = false;
                Horario();
                break;
            case '2':
                flag = false;
                Estudante();
                break;
            case '3':
                flag = false;
                NEstudantes();
                break;
            case '4':
                flag = false;
                Ocupacao();
                break;
            case '5':
                flag = false;
                MaiorN();
                break;
            case '6':
                break;
        }
    }

}

void Menu::Horario(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"##############################################"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##   Horarios :                             ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      1 -> Estudante                      ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      2 -> Turma                          ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      3 -> Voltar                         ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##############################################"<<std::endl<<std::endl;

    bool flag = true;
    while (flag){
        char k;
        std::cout<<"  Option:";
        std::cin>>k;
        switch (k)
        {
            case '1':
                flag = false;
                HorarioE();
                break;
            case '2':
                flag = false;
                HorarioT();
                break;
            case '3':
                flag = false;
                MenuBase();
                break;
        }}

}
void Menu::HorarioE(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###################################################"<<std::endl;
    std::cout<<"##                                               ##"<<std::endl;
    std::cout<<"##   Horario / Estudante:                        ##"<<std::endl;
    std::cout<<"##                                               ##"<<std::endl;
    std::cout<<"##      Inserir numero Estudante:________        ##"<<std::endl;
    std::cout<<"##                                               ##"<<std::endl;
    std::cout<<"##      1 -> Voltar                              ##"<<std::endl;
    std::cout<<"##                                               ##"<<std::endl;
    std::cout<<"###################################################"<<std::endl<<std::endl;

    bool flag = true;
    while (flag){
        int k;
        std::cout<<"  Option:";
        std::cin>>k;
        switch (k)
        {
            case 1:
                flag = false;
                Horario();
                break;
            default:
                auto it = students.find((k));
                if (it != students.end()) {
                    Student student = it->second;
                    student.showSchedule();
                } else {
                    std::cout << "Number not found "<< std::endl;
                }
                flag = false;
                HorarioE();
        }}

}
void Menu::HorarioT(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Horario / Turma:                      ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir Turma:______               ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      1 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;

    bool flag = true;
    while (flag){
        std::string k;
        std::cout<<"  Option:";
        std::cin>>k;

        if (k == "1") {
            flag = false;
            Estudante();
            break;
        }
        else {
            for (auto t : turmas) {
                if (t.getClassCode() == k) {
                    t.showSchedule();
                }
            }
            flag = false;
            Estudante();
        }
    }
}

void Menu::Estudante(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###########################################"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##   Estudantes :                        ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      1 -> Turma                       ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      2 -> Curso                       ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      3 -> Ano                         ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      4 -> Voltar                      ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"###########################################"<<std::endl<<std::endl;

    bool flag = true;
    while (flag){
        char k;
        std::cout<<"  Option:";
        std::cin>>k;
        switch (k)
        {
            case '1':
                flag = false;
                EstudanteT();
                break;
                flag = false;
            case '2':
                EstudanteC();
                break;
            case '3':
                EstudanteA();
                break;
            case '4':
                flag = false;
                MenuBase();
                break;
        }}

}
void Menu::EstudanteT(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Estudantes / Turma:                   ## "<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir Turma:______               ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      1 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;

        std::string k;
        std::cout<<"  Option:";
        std::cin>>k;

            if (k == "1") Estudante();
            else {
                for (auto t : turmas) {
                    if (t.getClassCode() == k) {
                        std::set<int> numbers = t.studentsOfTurma();
                        for (int n : numbers) {
                            auto it = students.find(n);
                            Student student = it->second;
                            student.show();
                        }

                    }
                }
                EstudanteT();
        }
}
void Menu::EstudanteC(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Estudantes / Curso:                   ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir Curso:______               ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      1 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl;


    bool flag = true;
    while (flag){
        char k;
        std::cout<<"  Option:";
        std::cin>>k;
        switch (k)
        {
            case '1':
                flag = false;
                Estudante();
                break;

        }
    }
}
void Menu::EstudanteA(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###########################################"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##   Estudantes / Ano:                   ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      Inserir Ano:______               ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                      ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"###########################################"<<std::endl<<std::endl;

        int k;
        std::cout<<"  Value:";
        std::cin>>k;
        if (k == 0) Estudante();
        if (k > 3 || k < 1) EstudanteA();
        std::set<int> numbers;
        for (auto turma : turmas) {
            if (turma.getClassCode()[0] == k + '0') {
                std::set<int> temp = turma.studentsOfTurma();
                for (int n : temp) {
                    numbers.insert(n);
                }
            }
        }
        for (int n : numbers) {
            auto it = students.find(n);
            Student student = it->second;
            student.show();
        }
        EstudanteA();

}

// Número de estudantes em pelo menos n UCs
void Menu::NEstudantes(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#####################################################"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##   Numero de estudantes nas UCs:                 ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##      Inserir numero de UCs:______               ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"#####################################################"<<std::endl;

    int k;
    std::cout<<"  Value:";
    std::cin>>k;
    int count = 0;

    if (k == 0) Estudante();

    for (auto pair : students) {
        int count2 = 0;
        std::string lastUc = "";
        for (auto c : pair.second.getSchedule().getClasses()) {
            if (c.getUc() != lastUc) {
                count2++;
            }
            lastUc = c.getUc();
        }
        if (count2 >= k) {
            count++;
        }
    }
    std::cout << "O numero de estudantes e: " << count << std::endl;
    NEstudantes();
}
void Menu::Ocupacao() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Ocupacao da turmas:                   ## "<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir Ano:______                 ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir Turma:______               ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir UC:______                  ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      1 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl;

    bool flag = true;
    while (flag){
        char k;
        std::cout<<"  Option:";
        std::cin>>k;
        switch (k)
        {
            case '1':
                flag = false;
                MenuBase();
                break;

        }}

}
bool compare(std::pair<std::string, int> a, std::pair<std::string, int> b) {
    return a.second > b.second;
}
void Menu::MaiorN(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##   UCs com maior numero de estudantes:                       ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir numero de UCs:______                           ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;

    int k;
    std::cout<<"  Option:";
    std::cin>>k;

    std::map<std::string, int> ucCount;

    if (k == 0) MenuBase();
    if (k < 1) MaiorN();

    for (auto pair : students) {
        std::string lastUc = "";
        for (auto c : pair.second.getSchedule().getClasses()) {
            if (c.getUc() != lastUc) {
                ucCount[c.getUc()]++;
            }
            lastUc = c.getUc();
        }
    }
    std::vector<std::pair<std::string, int>> vetor(ucCount.begin(), ucCount.end());
    std::sort(vetor.begin(), vetor.end(), compare);


    for (int i = 0; i < std::min(k, (int)vetor.size()); i++) {
        std::cout << vetor[i].first << " tem " << vetor[i].second << " estudantes" << std::endl;
    }
    MaiorN();
}