#include "Student.h"
#include <unordered_map>


class Menu {
private:
    std::vector<Turma> turmas;
    std::unordered_map<int,Student> students;
public:
    Menu(std::vector<Turma> t,std::unordered_map<int,Student> s);
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