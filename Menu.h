#include "Student.h"
#include "Request.h"
#include <unordered_map>
#include <queue>
#include "stack"

/// Classe que declara um menu
///
/// É a classe usada para criar uma interface onde podemos visualizar e modificar informações acerca dos estudantes, turmas e pedidos.
///@param turmas : Conjunto de todas as turmas
///@param students : Conjunto de todos os estudantes
///@param requests : Conjunto dos pedidos pendentes
///@param registers : Conjunto de registos de ações neste mesmo menu

class Menu {
private:
    std::vector<Turma> turmas;
    std::unordered_map<int,Student> students;
    std::queue<Request> requests;
    std::stack<std::string> registers;
public:
    /// Cria um menu  tendo em conta as turmas, os estudantes e os pedidos
    ///@param t : Conjunto de todas as turmas
    ///@param s : Conjunto de todos os estudantes
    ///@param r : Conjunto dos pedidos pendentes
    ///@see Turma()
    ///@see Student()
    ///@see Request()
    Menu(std::vector<Turma> t,std::unordered_map<int,Student> s,std::queue<Request> r);

    /// Interface inicial do menu onde podemos escolher que ação queremos realizar
    void MenuBase();

    /// Interface do horário onde podemos escolher entre ver o horário do estudante, turma ou turma/uc
    void schedule();

    /// Interface para ver o horário de um estudante ao receber o número deste por input
    void scheduleE();

    /// Interface para ver o horário de uma turma ao receber o classcode desta por input
    void scheduleT();

    /// Interface para ver o horário de uma turma/uc ao receber o classcode e a uc por input
    void scheduleTU();

    /// Interface de estudantes onde podemos escolher entre ver os estudantes duma turma, uc, ano ou turma/uc
    void student();
    void studentT();
    void studentC();
    void studentA();
    void studentTC();

    /// Interface que apresenta diferentes opções de print do vetor que recebe, o utilizador pode escolher entre printar :
    /// Estudante, Número, Estudante e número. Este método é chamado depois dos métodos studentT(), studentC(), studentA() e studentTC();
    /// O objetivo deste método é dar a opção ao utilizador de escolher o que quer ver na tela,
    /// Tendo em conta as escolhas do utilizador este método vai chamar sortingOptionE() ou sortingE() ou sortingN()
    ///@param infos : conjunto de pares (nºde estudante, nome de estudante)
    void showOptionE(std::vector<std::pair<int,std::string>> infos);

    /// Interface que apresenta diferentes opções de ordenação para as informações do vetor recebido,
    /// este método é chamado depois do utilizador ter escolhido printar o estudante e o número juntamente em showOptionE(),
    /// este método chama ainda sortingE() ou sortingN() tendo em conta o input do utilizador
    ///@param infos : conjunto de pares (nºde estudante, nome de estudante)
    void sortingOptionE(std::vector<std::pair<int,std::string>> infos);

    /// Printa de forma oredenada os estudantes ou os estudantes:números tendo em conta o parâmetro both,
    /// para ordenar de forma alfabética (pelo nome do estudante) é usado o algoritmo de sort quicksort
    ///@param infos : conjunto de pares (nºde estudante, nome de estudante)
    ///@param both : booleano que indica se é para printar apenas o estudante ou o estudante e o número
    void sortingE(std::vector<std::pair<int,std::string>> infos,bool both);

    /// Printa de forma oredenada os números ou os estudantes:números tendo em conta o parâmetro both,
    /// para ordenar de forma numérica (pelo número do estudante) é usado o algoritmo de sort selectionsort
    ///@param infos : conjunto de pares (nºde estudante, nome de estudante)
    ///@param both : booleano que indica se é para printar apenas o número ou o estudante e o número
    void sortingN(std::vector<std::pair<int,std::string>> infos,bool both);



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