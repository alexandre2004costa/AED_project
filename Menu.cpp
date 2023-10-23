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
void Menu::menuBase(){
    std::cout<<std::endl;
    std::cout<<" Consultar : "<<std::endl<<std::endl;
    std::cout<<"    1 -> Horarios"<<std::endl<<std::endl;
    std::cout<<"    2 -> Estudantes"<<std::endl<<std::endl;
    std::cout<<"    3 -> Numero de estudantes nas UCs"<<std::endl<<std::endl;
    std::cout<<"    4 -> Ocupacao das turmas"<<std::endl<<std::endl;
    std::cout<<"    5 -> UCs com maior numero de estudantes"<<std::endl<<std::endl;
    std::cout<<"    6 -> Exit"<<std::endl<<std::endl;
}
void Menu::manage(char k){
    
}
