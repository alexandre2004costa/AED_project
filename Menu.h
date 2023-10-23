#include "Student.h"


class Menu {
public:
    bool running = true;
    Menu();
    //void draw();
    void MenuBase();
    void Horario();
        void HorarioE();
        void HorarioT();
    void Estudante();
        void EstudanteT();
        void EstudanteC();
        void EstudanteA();
    void NEstudantes();
    void MaiorN();
    void Ocupacao();

};