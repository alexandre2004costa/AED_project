#include "Menu.h"


Menu::Menu(){}
/*void Menu::draw(){
            std::cout<<"########################################"<<std::endl;
        for (int i = 0 ; i < 20 ; i++){
            std::cout<<"#";
            for (int j = 0 ; j < 38 ; j++)std::cout<<" ";
            std::cout<<"#"<<std::endl;
        }
        std::cout<<"########################################"<<std::endl;
}*/
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
    std::cout<<"##      6 -> Exit                                                    ##"<<std::endl;
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
        flag = false;
        break;
    }
    }

}

void Menu::Horario(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"########################################"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##   Horarios :                             ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      1 -> Estudante                      ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      2 -> Turma                          ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      3 -> Exit                           ##"<<std::endl;
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
    std::cout<<"##      1 -> Exit                                ##"<<std::endl;
    std::cout<<"##                                               ##"<<std::endl;
    std::cout<<"###################################################"<<std::endl<<std::endl;

    bool flag = true;
    while (flag){
        char k;
        std::cout<<"  Option:";
        std::cin>>k;
        switch (k)
        {
            case '1':
                flag = false;
                Horario();
                break;
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
    std::cout<<"##      1 -> Exit                          ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;

    bool flag = true;
    while (flag){
        char k;
        std::cout<<"  Option:";
        std::cin>>k;
        switch (k)
        {
            case '1':
                flag = false;
                Horario();
                break;
        }}
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
    std::cout<<"##      4 -> Exit                        ##"<<std::endl;
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
    std::cout<<"##      1 -> Exit                          ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;

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
        }}
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
    std::cout<<"##      1 -> Exit                          ##"<<std::endl;
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

        }}
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
    std::cout<<"##      1 -> Exit                        ##"<<std::endl;
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
                Estudante();
                break;

        }}
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
    std::cout<<"##      Inserir UCs:______                         ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##      1 -> Exit                                  ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"#####################################################"<<std::endl;


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
    std::cout<<"##      1 -> Exit                          ##"<<std::endl;
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
void Menu::MaiorN(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##   UCs com maior numero de estudantes:                       ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      1 -> Exit                                              ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;

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
