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
    Menu(std::vector<Turma> t,std::unordered_map<int,Student> s,std::queue<Request> r);
    void MenuBase();
    void Horario();
        void HorarioE();
        void HorarioT();
        void HorarioTU();
    void Estudante();
        void ShowOptionE(std::vector<std::pair<int,std::string>> infos);
        void SortingOptionE(std::vector<std::pair<int,std::string>> infos);
        void SortingE(std::vector<std::pair<int,std::string>> infos,bool both);
        void SortingN(std::vector<std::pair<int,std::string>> infos,bool both);
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
        void OcupationTC();
    void entrar();
        void entrarTurma();
        void entrarUC();
    void sair();
        void sairTurma();
        void sairUC();
    void trocar();
        void trocarT();
        void trocarU();
    void closeMenu();
    bool testBalance(std::string pedido,std::string turma,std::string uc);
    bool addUC(std::string uc, Student& student);
    bool removeUC(std::string uc, Student& student);
    bool addClass(std::string turma, Student& student, std::string uc);
    bool removeClass(std::string turma, Student& student, std::string uc);
    bool switchClass(Student& student,std::string tInicial,std::string tFinal,std::string uc);
    bool switchUC(Student& student,std::string ucInicial,std::string ucFinal);
    void waitingList();
    void showWaitingList();
    void removeFWaitingList();

};