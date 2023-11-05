#include "Student.h"
#include "Request.h"
#include <unordered_map>
#include <queue>
#include "stack"


class Menu {
private:
    std::vector<Turma> turmas;
    std::unordered_map<int,Student> students;
    std::queue<Request> requests;
    std::stack<std::string> registers;
public:
    Menu(std::vector<Turma> t,std::unordered_map<int,Student> s,std::queue<Request> r);
    void MenuBase();
    void schedule();
    void scheduleE();
    void scheduleT();
    void scheduleTU();


    void student();
    void showOptionE(std::vector<std::pair<int,std::string>> infos);

    void sortingOptionE(std::vector<std::pair<int,std::string>> infos);
    void sortingE(std::vector<std::pair<int,std::string>> infos,bool both);
    void sortingN(std::vector<std::pair<int,std::string>> infos,bool both);

    void studentT();
    void studentC();
    void studentA();
    void studentTC();

    void nStudents();

    void maiorN();

    void capacity();
    void capacityA();
    void capacityT();
    void capacityC();
    void capacityTC();

    void getIn();
    void getInT();
    void getInUC();

    void getOut();
    void getOutT();
    void getOutUC();

    void replace();
    void replaceT();
    void replaceU();

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
    void showRegisters();

};