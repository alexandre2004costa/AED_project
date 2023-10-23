#include "Menu.h"


Menu::Menu(){
        std::cout<<20*"#"<<std::endl;
        for (int i = 0 ; i < 30 ; i++){
            std::cout<<"#"<<std::endl;
            for (int j = 0 ; j < 18 ; j++)std::cout<<"#"<<std::endl;
            std::cout<<"#"<<std::endl;
        }
        std::cout<<20*"#"<<std::endl;
    }