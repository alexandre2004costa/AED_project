#include "Student.h"
#include "Request.h"
#include <unordered_map>
#include <queue>


class Menu {
private:
    std::vector<Turma> turmas;
    std::unordered_map<int,Student> students;
    std::queue<Request> requests;
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
        void EstudanteTC();
    void NEstudantes();
    void MaiorN();
    void Ocupacao();
        void OcupacaoA();
        void OcupacaoT();
        void OcupacaoC();
    void entrar();
        void entrarTurma();
        void entrarUC();
    void sair();
        void sairTurma();
        void sairUC();

    void trocar();
        void trocarT();
        void trocarU();
    bool testBalance(std::string pedido,std::string turma,std::string uc);
    bool addUC(std::string uc, Student& student);
    bool removeUC(std::string uc, Student& student);
    bool addClass(Turma turma, Student& student, std::string uc);
    bool removeClass(Turma turma, Student& student, std::string uc);
    bool switchClass(Student& student,Turma tInicial,Turma tFinal,std::string uc);
    bool switchUC(Student& student,std::string ucInicial,std::string ucFinal);

};