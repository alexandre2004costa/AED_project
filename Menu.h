#include "Student.h"
#include <unordered_map>


class Menu {
private:
    std::vector<Turma> turmas;
    std::unordered_map<int,Student> students;
public:
    Menu(std::vector<Turma> t,std::unordered_map<int,Student> s);
    std::vector<Turma>& getTurmas();
    std::unordered_map<int,Student>& getStudents();
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
        void OcupacaoA();
        void OcupacaoT();
        void OcupacaoC();
    bool addUC(std::string uc, Student& student);
    void removeUC(std::string uc, Student& student);
    void addClass();
    void removeClass();
    void switchClass();

};