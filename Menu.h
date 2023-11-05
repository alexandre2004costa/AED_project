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

    /// Interface para ver os estudantes de uma turma ao receber o classcode desta por input
    void studentT();

    /// Interface para ver os estudantes de uma uc ao receber a uc por input
    void studentC();

    /// Interface para ver os estudantes de um ano ao receber o ano por input
    void studentA();

    /// Interface para ver os estudantes de uma turma/uc ao receber o classcode desta e a uc por input
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

    /// Interface para ver o número de estudantes num número mínimo n de UCs passadas por input,
    /// Complexidade : O(n**2)
    void nStudents();

    /// Interface que mostra as n UCs com o maior número de estudantes, esse n é um valor passado por input
    void maiorN();

    /// Interface da ocupação onde podemos escolher entre ver a ocupação dos anos, turmas, ucs ou turmas/ucs
    void capacity();

    /// Printa a ocupação de todos os anos por ordem crescente
    void capacityA();

    /// Printa a ocupação de todas as turmas por ordem crescente,
    /// Complexidade : O(n log(n)) - > heap sort
    void capacityT();

    /// Printa a ocupação de todas as ucs por ordem crescente
    void capacityC();

    /// Printa a ocupação de todas as turmas/ucs por ordem crescente
    void capacityTC();

    /// Interface para efetuar adições de estudantes a turmas e ucs
    void getIn();

    /// Interface que verifica se é possível adicionar um estudante a uma turma numa dada uc
    /// Essa confirmação é feita em addClass()
    void getInT();

    /// Interface que verifica se é possível adicionar um estudante a uma uc
    /// Essa confirmação é feita em addUC()
    void getInUC();

    /// Interface para efetuar remoções de estudantes de turmas e ucs
    void getOut();

    /// Interface que verifica se é possível remover um estudante de uma turma numa dada uc
    /// Essa confirmação é feita em removeClass()
    void getOutT();

    /// Interface que verifica se é possível remover um estudante de uma uc
    /// Essa confirmação é feita em removeUC()
    void getOutUC();

    /// Interface para efetuar trocas de estudantes entre turmas e ucs
    void replace();

    /// Interface que verifica se é possível trocar um estudante de turma numa dada uc
    /// Essa confirmação é feita em switchClass()
    void replaceT();

    /// Interface que verifica se é possível trocar um estudante de uc
    /// Essa confirmação é feita em switchUC()
    void replaceU();

    /// Transferir informação das estruturas para os ficheiros
    void closeMenu();

    /// Verificar se os desiquilíbrios entre número de estudantes de cada turma não pioram
    /// @param pedido, turma, uc
    /// @return true caso seja possível
    bool testBalance(std::string pedido,std::string turma,std::string uc);

    /// Adicionar um estudante a uma uc
    /// @param uc, student
    /// @return true caso seja possível
    bool addUC(std::string uc, Student& student);

    /// Remover um estudante de uma uc
    /// @param uc, student
    /// @return true caso seja possível
    bool removeUC(std::string uc, Student& student);

    /// Adicionar um estudante a uma turma numa determinada uc
    /// @param turma, student, uc
    /// @return true caso seja possível,
    ///Complexidade : n**5
    bool addClass(std::string turma, Student& student, std::string uc);

    /// Remover um estudante de uma turma numa determinada uc
    /// @param turma, student, uc
    /// @return true caso seja possível
    bool removeClass(std::string turma, Student& student, std::string uc);

    /// Trocar um estudante de turma numa determinada uc
    /// @param student, tInicial, tFinal, uc
    /// @return true caso seja possível
    bool switchClass(Student& student,std::string tInicial,std::string tFinal,std::string uc);

    /// Trocar um estudante de uc
    /// @param student, ucInicial, ucFinal
    /// @return true caso seja possível
    bool switchUC(Student& student,std::string ucInicial,std::string ucFinal);

    /// Tratar dos pedidos na lista de espera,
    /// Complexidade : O(n**6)
    void waitingList();

    /// Mostrar lista de espera,
    /// Complexidade : O(n)
    void showWaitingList();

    /// Remover pedidos da lista de espera,
    /// Complexidade : O(n)
    void removeFWaitingList();

    /// Mostrar o histórico de ações efetuadas,
    /// Complexidade : O(n)
    void showRegisters();

};