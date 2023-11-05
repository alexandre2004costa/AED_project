#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Menu.h"


// Sorting algoritmos

// Função que particiona o vetor para o algoritmo Quick Sort
int partition(std::vector<std::pair<int, std::string>> &infos, int low, int high) {
    // Escolhe o último elemento como pivô
    std::string pivot = infos[high].second;
    int i = low - 1;  // Índice do menor elemento

    // Percorre os elementos do vetor
    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (infos[j].second < pivot) {
            i++;
            // Troca os elementos com a posição do índice do menor elemento
            std::swap(infos[i], infos[j]);
        }
    }

    // Troca o pivô com o elemento após os menores
    std::swap(infos[i + 1], infos[high]);
    return i + 1;  // Retorna o índice do pivô
}

// Função de ordenação Quick Sort
void quicksort(std::vector<std::pair<int, std::string>> &infos, int low, int high) {
    if (low < high) {
        // Encontra o índice do pivô
        int pivot = partition(infos, low, high);

        // Ordena os elementos antes e depois do pivô
        quicksort(infos, low, pivot - 1);
        quicksort(infos, pivot + 1, high);
    }
}

// Função de ordenação Bubble Sort
void bubbleSort(std::vector<std::pair<int, int>> &v) {
    // Percorre o vetor de trás para frente
    for (unsigned int j = v.size() - 1; j > 0; j--) {
        bool troca = false; // Indica se houve trocas

        // Percorre o vetor
        for (unsigned int i = 0; i < j; i++) {
            // Compara o elemento atual com o próximo
            if (v[i + 1].second < v[i].second) {
                // Troca os elementos se estiverem fora de ordem
                swap(v[i], v[i + 1]);
                troca = true;
            }
        }

        // Se nenhuma troca ocorreu, o vetor está ordenado e podemos sair do loop
        if (!troca) {
            return;
        }
    }
}

// Função para transformar uma árvore em heap com raiz em i
void heapify(std::vector<std::pair<std::string, int>> &v, int n, int i) {
    int largest = i; // Inicializa o maior como o nó raiz
    int left = 2 * i + 1; // Índice do filho da esquerda
    int right = 2 * i + 2; // Índice do filho da direita

    // Se o filho da esquerda é maior que a raiz
    if (left < n && v[left].second > v[largest].second) {
        largest = left;
    }

    // Se o filho da direita é maior que o maior até agora
    if (right < n && v[right].second > v[largest].second) {
        largest = right;
    }

    // Se o maior não é mais a raiz
    if (largest != i) {
        std::swap(v[i], v[largest]); // Troca a raiz com o maior
        heapify(v, n, largest); // Chama recursivamente a função para o subárvore afetada
    }
}

// Função de ordenação Heap Sort
void heapSort(std::vector<std::pair<std::string, int>> &v) {
    int n = v.size();

    // Constrói uma heap máxima (max heap)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }

    // Extrai elementos da heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz (maior elemento) para o fim do vetor
        std::swap(v[0], v[i]);
        // Chama heapify na heap reduzida
        heapify(v, i, 0);
    }
}


Menu::Menu(std::vector<Turma> t,std::unordered_map<int,Student> s,std::queue<Request> r){
    turmas = t;
    students = s;
    requests = r;
    for (Turma &turma : turmas){
        std::vector<std::pair<int, std::string>> temp = turma.getEstudanteCadeira();
        quicksort(temp,0,temp.size()-1);
        turma.setnEstudanteCadeira(temp);
    }
}

// Métodos do Menu
void Menu::MenuBase(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Consultar :                                                     ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      1 -> Horarios                                                ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      2 -> Estudantes                                              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      3 -> Numero de estudantes em pelo menos n UCs                ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      4 -> Ocupacao                                                ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      5 -> UCs com maior numero de estudantes                      ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      6 -> Adicionar                                               ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      7 -> Remover                                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      8 -> Trocar                                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      9 -> Mostrar pedidos pendentes                               ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      10 -> Eliminar pedidos pendentes                             ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      11 -> Mostrar historico                                      ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Fechar Menu                                             ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"Opcao: ";
    std::cin>>k;

    switch (k){
        case 0:
            closeMenu();
            exit(0);
        case 1:
            schedule();
        case 2:
            student();
        case 3:
            nStudents();
        case 4:
            capacity();
        case 5:
            maiorN();
        case 6:
            getIn();
        case 7:
            getOut();
        case 8:
            replace();
        case 9:
            showWaitingList();
        case 10:
            removeFWaitingList();
        case 11:
            showRegisters();
    }
    MenuBase();

}


// Mostrar opções de horário
void Menu::schedule(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"##############################################"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##   Horarios :                             ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      1 -> Estudante                      ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      2 -> Turma                          ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      3 -> Uc duma turma                  ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                         ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##############################################"<<std::endl<<std::endl;


    int k;
    std::cout<<"Opcao: ";
    std::cin>>k;
    switch (k)
    {
        case 1:
            scheduleE();
        case 2:
            scheduleT();
        case 3:
            scheduleTU();
        case 0:
            MenuBase();
    }
    schedule();

}

// Mostrar horário de um estudante
void Menu::scheduleE(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###################################################"<<std::endl;
    std::cout<<"##                                               ##"<<std::endl;
    std::cout<<"##   Horario / Estudante:                        ##"<<std::endl;
    std::cout<<"##                                               ##"<<std::endl;
    std::cout<<"##      Inserir numero Estudante:________        ##"<<std::endl;
    std::cout<<"##                                               ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                              ##"<<std::endl;
    std::cout<<"##                                               ##"<<std::endl;
    std::cout<<"###################################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"Inserir numero Estudante: ";
    std::cin>>k;

    if (k == 0) schedule();

    auto it = students.find((k));
    if (it != students.end()) {
        Student student = it->second;
        student.showSchedule();
        registers.push("Horario do estudante "+student.getName()+ " visualizado.");  // a ação é adicionada ao histórico
    } else {
        std::cout << "Esse numero nao existe"<< std::endl;
    }
    // Chama a interface anterior
    schedule();

}

// Mostrar horário de uma turma
void Menu::scheduleT(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Horario / Turma:                      ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir Turma:______               ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;

    std::string k;
    std::cout<<"Inserir Turma: ";
    std::cin>>k;

    if (k == "0") schedule();
    bool flag = true;
    for (auto t : turmas) {
        if (t.getClassCode() == k) {  // Quando for a turma desejada
            t.showSchedule();         // Mostra o horário
            flag = false;
        }
    }
    if (flag) {
        std::cout << "Essa turma não existe" << std::endl;
        // Se a turma não existe, pede uma nova turma
        scheduleT();
    }else registers.push("Horario da turma "+k+ " visualizado.");   // a ação é adicionada ao histórico

    // Chama a interface anterior
    schedule();

}

// Mostrar o horário de uma turma numa UC
void Menu::scheduleTU(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Horario / Uc duma Turma:              ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir Turma:______               ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir Uc:______                  ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;

    std::string turma;
    std::cout<<"Inserir Turma: ";
    std::cin>>turma;
    if (turma == "0") schedule();
    std::string uc;
    std::cout<<"Inserir Uc: ";
    std::cin>>uc;

    bool flag = true;
    for (auto t : turmas) {
        if (t.getClassCode() == turma) {              // Quando for a turma desejada
            flag = false;
            for (auto k : t.classesOfUC(uc)){
                k.show();                             // Mostra as aulas desse horário
            }
        }
    }
    if (flag) {
        std::cout << "Essa turma não existe" << std::endl;
        // Se a turma não existe, pede uma nova turma
        scheduleTU();
    }else registers.push("Horario da turma "+turma+"e Uc "+uc +" visualizado.");  // a ação é adicionada ao histórico
    schedule();
}

// Interface do estudante
void Menu::student(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###########################################"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##   Estudantes :                        ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      1 -> Turma                       ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      2 -> UC                          ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      3 -> Ano                         ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      4 -> Turma e Uc                  ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                      ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"###########################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"Opcao: ";
    std::cin>>k;
    switch (k)
    {
        // Adicionar ao histórico o que foi visualizado:
        case 1:
            studentT();
            registers.push("Ocupacao das turmas visualizada");
        case 2:
            studentC();
            registers.push("Ocupacao das UCs visualizada");
        case 3:
            studentA();
            registers.push("Ocupacao dos anos visualizada");
        case 4:
            studentC();
            registers.push("Ocupacao das turmas/Ucs visualizada");
        case 0:
            MenuBase();
    }
    student();

}

// Mostrar opções de visualização
void Menu::showOptionE(std::vector<std::pair<int,std::string>> infos){
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   O que quer printar:                   ## "<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      1 -> Estudante                     ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      2 -> Numero                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      3 -> Estudante e numero            ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;
    int k;
    std::cout <<" Opcao: ";
    std::cin >> k;
    switch (k) {
        // Chamar funções necessárias:
        case 0:
            studentT();
        case 1:
            sortingE(infos,false);
        case 2:
            sortingN(infos,false);
        case 3:
            sortingOptionE(infos);
    }
    showOptionE(infos);
}

// Mostrar opções de ordenação
void Menu::sortingOptionE(std::vector<std::pair<int,std::string>> infos){ // Apenas usado em estudante e número
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Por que parametro quer ordenar:       ## "<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      1 -> Estudante                     ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      2 -> Numero                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;
    int k;
    std::cout <<" Opcao: ";
    std::cin >> k;
    switch (k) {
        // Chamar funções de ordenação necessárias
        case 0:
            showOptionE(infos);
        case 1:
            sortingE(infos,true);
        case 2:
            sortingN(infos,true);
    }
    sortingOptionE(infos);
}

// Ordenar por ordem alfabética
void Menu::sortingE(std::vector<std::pair<int,std::string>> infos,bool both){
    quicksort(infos,0,infos.size()-1);  // função de ordenação
    if (both){   // Caso se queira mostrar o objeto Estudante e o número correspondente
        for (auto k : infos){
            std::cout<< k.second << " : "<<k.first<<std::endl;
        }
    }else{  // Caso contrário, apenas o objeto é mostrado
        for (auto k : infos){
            std::cout<< k.second << std::endl;
        }
    }
    // Voltar para a interface geral do estudante
    student();
}

// Algoritmo de ordenação
void selectionSort(std::vector<std::pair<int,std::string>> &infos) {
    for (unsigned i = 0; i < infos.size()-1; i++) {
        unsigned k = i;
        for (unsigned j = i+1; j < infos.size(); j++)
            if (infos[j].first < infos[k].first)
                k = j;
        swap(infos[i], infos[k]);
    }
}

// Ordenar por ordem crescente dos números de estudante
void Menu::sortingN(std::vector<std::pair<int,std::string>> infos,bool both){
    selectionSort(infos);
    if (both){   // Caso se queira mostrar o objeto Estudante e o número correspondente
        for (auto k : infos){
            std::cout<< k.second << " : "<<k.first<<std::endl;
        }
    }else{       // Caso contrário, apenas o objeto é mostrado
        for (auto k : infos){
            std::cout<< k.second << std::endl;
        }
    }
    student();
}

// Interface de estudantes numa turma
void Menu::studentT(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Estudantes / Turma:                   ## "<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir Turma:______               ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;

    std::string k;
    std::cout<<"Inserir Turma: ";
    std::cin>>k;

    std::vector<std::pair<int,std::string>> infos;
    if (k == "0") student();
    bool flag = true;
    for (auto t : turmas) {
        if (t.getClassCode() == k) {                                                  // Quando for a turma desejada
            flag = false;
            std::set<int> numbers = t.studentsOfTurma();
            for (int n : numbers) {
                auto it = students.find(n);                              // Encontrar o estudante
                infos.push_back({it->second.getNumber(),it->second.getName()}); // Mostrar os estudantes segundo uma certa ordem
            }                                                                         // (o vetor "infos" será usado nas ordenações)
        }
    }
    if (flag) {
        std::cout << "Essa turma não existe" << std::endl;
        // Se a turma não existe, pede uma de novo
        studentT();
    }
    // Redireciona para as opções de visualização
    showOptionE(infos);
}

// Interface de estudantes numa UC
void Menu::studentC(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Estudantes / UC:                      ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      Inserir UC:______                  ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl;


    std::string k;
    std::cout<<"Inserir UC: ";
    std::cin>>k;
    std::vector<std::pair<int,std::string>> infos;
    if (k == "0") student();
    bool flag2 = true;
    for (auto pair : students) {
        bool flag = false;
        for (auto c : pair.second.getSchedule().getClasses()) {   // Por cada aula nas aulas no horário desse estudante
            if (c.getUc() == k) flag = true;                            // Quando for a UC desejada
        }
        if (flag){
            flag2 = false;
            infos.push_back({pair.second.getNumber(),pair.second.getName()});  // Mostrar os estudantes segundo uma certa ordem
        }                                                                            // (o vetor "infos" será usado nas ordenações)
    }
    if (flag2) {
        std::cout << "Essa Uc não existe" << std::endl;
        // Se a UC não existe, pede uma de novo
        studentC();
    }
    // Redireciona para as opções de visualização
    showOptionE(infos);
}

// Interface de estudantes num ano letivo
void Menu::studentA(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###########################################"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##   Estudantes / Ano:                   ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      Inserir Ano:______               ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                      ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"###########################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"Inserir Ano: ";
    std::cin>>k;

    if (k == 0) student();
    if (k > 3 || k < 1){
        std::cout<<"Insere um ano entre 1 e 3"<<std::endl;
        studentA();   // O ano tem de estar entre 1 e 3, caso contrário é pedido de novo
    }
    std::vector<std::pair<int,std::string>> infos;
    std::set<int> numbers;
    for (auto turma : turmas) {
        if (turma.getClassCode()[0] == k + '0') {            // Quando o primeiro caracter da turma corresponder ao ano desejado
            std::set<int> temp = turma.studentsOfTurma();
            for (int n : temp) {
                numbers.insert(n);
            }
        }
    }
    // São usados dois sets para prevenir a repetição de elementos
    for (int n : numbers) {
        auto it = students.find(n);
        infos.push_back({it->second.getNumber(),it->second.getName()});   // Mostrar os estudantes segundo uma certa ordem
    }                                                                           // (o vetor "infos" será usado nas ordenações)
    // Redireciona para as opções de visualização
    showOptionE(infos);
}

// Interface de estudantes numa turma e numa UC
void Menu::studentTC(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###########################################"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##   Estudantes -> Turma e Uc:           ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      Inserir Turma:______             ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      Inserir Uc:______                ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                      ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"###########################################"<<std::endl<<std::endl;
    std::string turma;
    std::cout<<"Inserir Turma: ";
    std::cin>>turma;
    if (turma == "0")student();
    std::string uc;
    std::cout<<"Inserir Uc: ";
    std::cin>>uc;
    std::vector<std::pair<int,std::string>> infos;
    bool flag = true;
    for (Turma t : turmas){
        if (t.getClassCode() == turma){                                               // Turma desejada
            if (t.studentsOfUC(uc) > 0)flag = false;                                  // Não pode estar vazia
            for (auto k : t.studentsOfTurmaUc(uc)){                               // Percorrer o número dos estudantes nessa turma na UC pretendida
                auto it = students.find(k);
                infos.push_back({it->second.getNumber(),it->second.getName()});  // Mostrar os estudantes segundo uma certa ordem
            }                                                                          // (o vetor "infos" será usado nas ordenações)
            break;
        }
    }
    if (flag){
        std::cout<<"Insere inputs válidos."<<std::endl;
        // No caso de entradas inexistentes, novas serão pedidas
        studentTC();
    }
    // Redireciona para as opções de visualização
    showOptionE(infos);
}
// Número de estudantes num número mínimo de UCs
void Menu::nStudents(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#####################################################"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##   Numero de estudantes em pelo menos n UCs:     ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##      Inserir numero de UCs:______               ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"#####################################################"<<std::endl;

    int k;
    std::cout<<"Inserir numero de UCs: ";
    std::cin>>k;
    int count = 0;

    if (k == 0) MenuBase();
    for (auto pair : students) {
        int count2 = 0;
        std::string lastUc = "";
        for (auto c : pair.second.getSchedule().getClasses()) {    // Por cada aula nas aulas no horário desse estudante
            if (c.getUc() != lastUc) {                                   // Se for diferente da UC anterior
                count2++;                                                // Um contador é aumentado
            }
            lastUc = c.getUc();
        }
        if (count2 >= k) {                                               // Caso seja no mínimo igual ao valor inserido
            count++;                                                     // A contagem pretendida é aumentada
        }
    }
    std::cout << "O numero de estudantes e: " << count << std::endl;
    registers.push("Numero de estudantes em pelo menos k UCs visualizado");  // a ação é adicionada ao histórico
    // Volta ao início
    MenuBase();
}

// Mostrar lotação
void Menu::capacity() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Ocupacao do/a:                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      1 -> Ano                           ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      2 -> Turma                         ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      3 -> UC                            ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      4 -> Turma e Uc                    ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl;


    int k;
    std::cout<<"  Option:";
    std::cin>>k;
    switch (k) {
        // Adicionar ao histórico as ações realizadas
        case 0:
            MenuBase();
            break;
        case 1:
            capacityA();
            registers.push("Ocupação de cada ano visualizada");
            break;
        case 2:
            capacityT();
            registers.push("Ocupação de cada turma visualizada");
            break;
        case 3:
            capacityC();
            registers.push("Ocupação de cada Uc visualizada");
            break;
        case 4:
            capacityTC();
            registers.push("Ocupação de cada Turma/Uc visualizada");
    }
    capacity();

}


// Lotação de um ano letivo
void Menu::capacityA() {
    // Para armazenar a lotação de cada ano
    std::unordered_map<int, int> anos;

    for (auto pair : students) {
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;
        for (auto c : pair.second.getSchedule().getClasses()) {   // Por cada aula nas aulas no horário desse estudante
            // Para saber em qual ano aumentar contagem:
            if (c.getClassCode()[0] == '1') flag1 = true;
            else if (c.getClassCode()[0] == '2') flag2 = true;
            else if (c.getClassCode()[0] == '3') flag3 = true;
        }
        // Incrementar contagens:
        if (flag1) anos[1]++;
        if (flag2) anos[2]++;
        if (flag3) anos[3]++;
    }
    std::vector<std::pair<int, int>> vetor(anos.begin(), anos.end());  // Transformar em vetor
    bubbleSort(vetor);                                                       // Ordenar

    for (int i = 0; i < (int)vetor.size(); i++) {
        std::cout << "0 ano " << vetor[i].first << " tem " << vetor[i].second << " estudantes" << std::endl;
    }
}

// Lotação de uma turma
void Menu::capacityT() {
    std::unordered_map<std::string, int> t;
    for (Turma turma : turmas) {
        t[turma.getClassCode()] = turma.numberOfStudents();   // Armazenar quantos alunos tem cada turma
    }
    std::vector<std::pair<std::string, int>> v(t.begin(), t.end());  // Transformar em vetor
    heapSort(v);                                                           // Ordenar

    for (int i = 0; i < (int)v.size(); i++) {
        std::cout << "A turma " << v[i].first << " tem " << v[i].second << " estudantes" << std::endl;
    }
}

void Menu::capacityC() {
    std::unordered_map<std::string, int> ucs;
    for (auto pair : students) {
        std::string lastUc = "";
        for (auto c : pair.second.getSchedule().getClasses()) {  // Por cada aula nas aulas no horário desse estudante
            if (c.getUc() != lastUc) {
                // Se a UC for diferente da última, aumentar a sua contagem
                ucs[c.getUc()]++;
            }
            lastUc = c.getUc();
        }
    }
    std::vector<std::pair<std::string, int>> vetor(ucs.begin(), ucs.end());  // Transformar em vetor
    heapSort(vetor);                                                               // Ordenar

    for (int i = 0; i < (int)vetor.size(); i++) {
        std::cout << vetor[i].first << " tem " << vetor[i].second << " estudantes" << std::endl;
    }
}
void Menu::capacityTC(){
    std::unordered_map<std::string, int> t;
    for (Turma turma : turmas) {
        for (auto k : turma.getSchedule().getClasses()){                         // Por cada aula nas aulas do horário de cada turma
            t[turma.getClassCode()+","+k.getUc()] = turma.studentsOfUC(k.getUc()); // Armazenar esse número
        }
    }
    std::vector<std::pair<std::string, int>> v(t.begin(), t.end());   // Transformar em vetor
    heapSort(v);                                                            // Ordenar

    for (int i = 0; i < (int)v.size(); i++) {
        std::cout << "A turma/Uc " << v[i].first << " tem " << v[i].second << " estudantes" << std::endl;
    }
}

// Mostrar as UCs com o maior número de estudantes
void Menu::maiorN(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##   UCs com maior numero de estudantes:                       ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir numero de UCs:______                           ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;

    int k;
    std::cout<<"Inserir numero de UCs: ";
    std::cin>>k;

    std::map<std::string, int> ucCount;

    if (k == 0) MenuBase();
    if (k < 1) maiorN();

    for (auto pair : students) {
        std::string lastUc = "";
        for (auto c : pair.second.getSchedule().getClasses()) {   // Por cada aula nas aulas no horário desse estudante
            if (c.getUc() != lastUc) {
                // Incrementar a contagem de estudantes
                ucCount[c.getUc()]++;
            }
            lastUc = c.getUc();
        }
    }
    std::vector<std::pair<std::string, int>> vetor(ucCount.begin(), ucCount.end());  // Transformar em vetor
    heapSort(vetor);                                                                       // Ordenar


    for (int i = 0; i < std::min(k, (int)vetor.size()); i++) {
        std::cout << vetor[i].first << " tem " << vetor[i].second << " estudantes" << std::endl;
    }
    registers.push(std::to_string(k)+" UCs com maior numero de estudantes visualizadas");  // guardar ação no histórico
    // Voltar ao início
    MenuBase();
}

// Adicionar um estudante a uma UC
bool Menu::addUC(std::string uc, Student& student) {
    if (student.getSchedule().numberOfUCs() >= 7) return false;
    int n = stoi(uc.substr(uc.length() - 2, 2));
    int year;
    // Descobrir o ano sabendo a UC
    if (n >= 1 && n <= 5) year = 1;
    else if (n >= 11 && n <= 15) year = 2;
    else if (n >= 21 && n<= 25) year = 3;

    for (Turma &turma : turmas) {
        if (turma.getClassCode()[0]-'0' == year && turma.studentsOfUC(uc) < 30 && testBalance("entrar",turma.getClassCode(),uc)) {
            // Se a turma for do ano pretendido, tiver menos de 30 estudantes e a troca não provocar mais desiquilíbrios:
            std::vector<Class> classes = turma.classesOfUC(uc);
            bool c = true;
            for (auto c1 : classes) {
                for (auto c2 : student.getSchedule().getClasses()) {
                    if (c1.overlaps(c2)) c = false;                       // Comparar todas as aulas e verificar se se sobrepõem
                }
            }
            if (c) {
                turma.addClassToG({student.getNumber(), uc});          // Adiciona estudante à turma
                for (auto cl : classes) student.addToSchedule(cl);  // Adicionar as aulas ao horário do aluno
                return true;
            }
        }
    }
    return false;
}

// Remover um estudante de uma UC
bool Menu::removeUC(std::string uc, Student& student){
    //Descobrir em que turma tem aquela uc
    std::string t = "";
    for (Class k : student.getSchedule().getClasses()){
        if (k.getUc() == uc)t = k.getClassCode();
    }
    if(t == ""){
        return false;
    }
    //Remover o estudante da turma onde tem aquela uc
    for (Turma &turma : turmas){
        if (turma.getClassCode() == t){
            if(testBalance("sair",turma.getClassCode(),uc)){
                turma.removeStudent(student.getNumber(),uc);
                break;
            }
            return false;
        }
    }
    //Remover as aulas da uc do horário do estudante
    student.setSchedule(student.getSchedule().removeUcClasses(uc));
    return true;
}

// Adicionar estudante a uma turma numa dada UC
bool Menu::addClass(std::string turma, Student& student, std::string uc) {
    for (Turma &t : turmas) {
        if (turma == t.getClassCode() && t.studentsOfUC(uc) < 30 && testBalance("entrar",t.getClassCode(),uc)) {
            // Se for a turma pretendida, tiver menos de 30 estudantes e a troca não provocar mais desiquilíbrios:
            std::vector<Class> classes = t.classesOfUC(uc);
            if (classes.size() == 0) return false;  // Turma está vazia
            bool c = true;
            for (auto c1 : classes) {
                for (auto c2 : student.getSchedule().getClasses()) {
                    if (c1.overlaps(c2)) c = false;                     // Comparar todas as aulas e verificar se se sobrepõem
                }
            }
            if (c) {
                t.addClassToG({student.getNumber(), uc});             // Adiciona estudante à turma
                for (auto cl : classes) student.addToSchedule(cl); // Adicionar as aulas ao horário do aluno
                return true;
            }
        }
    }
    return false;
}

// Remover um estudante de uma turma numa dada UC
bool Menu::removeClass(std::string turma, Student& student, std::string uc) {
    for (Turma &t : turmas){
        if (turma == t.getClassCode()){
            if (testBalance("sair",t.getClassCode(),uc)){  // Se não provocar mais desiquilíbrios
                t.removeStudent(student.getNumber(),uc);
                break;
            }
            return false;
        }
    }
    //Remover as aulas da uc do horário do estudante
    student.setSchedule(student.getSchedule().removeUcClasses(uc));
    return true;
}

// Interface para adições
void Menu::getIn() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###########################################"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##   Adicionar a :                       ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      1 -> Turma                       ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      2 -> UC                          ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                      ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"###########################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"Opcao: ";
    std::cin >> k;

    switch (k) {
        case 1:
            getInT();
        case 2:
            getInUC();
        case 0:
            MenuBase();
    }
    getIn();
}

// Adicionar a turma
void Menu::getInT() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir Turma:______                                   ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir numero de estudante:______                     ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir UCs (separadas por virgulas):______            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;

    std::string turma;
    std::cout << "Inserir Turma: ";
    std::cin >> turma;
    if (turma == "0") getIn();
    int numero;
    std::cout << "Inserir numero de estudante: ";
    std::cin >> numero;
    std::string conjunto;
    std::cout << "Inserir UCs (separadas por virgulas): ";
    std::cin >> conjunto;
    std::set<std::string> ucs;
    int lastPos = -1;
    for (int i = 0; i < conjunto.length(); i++) {
        // Separar cada palavra:
        if (conjunto[i] == ',') {
            ucs.insert(conjunto.substr(lastPos + 1, i - lastPos - 1));
            lastPos = i;
        }
    }
    ucs.insert(conjunto.substr(lastPos + 1));

    auto it = students.find(numero);
    for (std::string uc : ucs) {
        if (addClass(turma, it -> second, uc)){
            std::cout << "Foi adicionado com sucesso." << std::endl;  // Adição bem sucedida
            registers.push(it->second.getName()+" foi adicionado à turma "+turma+" na Uc "+uc); // Ação guardada no histórico
            waitingList();  // Função dos pedidos pendentes
        }else {
            std::cout << "Nao foi possivel adicionar de momento, o seu pedido esta registado." << std::endl; // Adição não realizada
            requests.push(Request("ac",numero,uc,turma));           // Pedido registado
        }
    }
    getIn();
}

// Adicionar a UC
void Menu::getInUC() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir numero de estudante:______                     ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir UCs (separadas por virgulas):______            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;

    int numero;
    std::cout<<"Inserir numero de estudante: ";
    std::cin >> numero;
    if (numero == 0) getIn();
    std::string conjunto;
    std::cout<<"Inserir UCs (separadas por virgulas): ";
    std::cin >> conjunto;
    std::set<std::string> ucs;
    int lastPos = -1;
    for (int i = 0; i < conjunto.length(); i++) {
        // Separar cada palavra:
        if (conjunto[i] == ',') {
            ucs.insert(conjunto.substr(lastPos + 1, i - lastPos - 1));
            lastPos = i;
        }
    }
    ucs.insert(conjunto.substr(lastPos + 1));

    auto it = students.find(numero);
    for (std::string uc : ucs) {
        std::cout << uc;
        if (addUC(uc, it -> second)){
            std::cout << "Foi adicionado com sucesso." << std::endl;     // Adição bem sucedida
            registers.push(it->second.getName()+" entrou na Uc "+uc); // Ação guardada no histórico
            waitingList();  // Função dos pedidos pendentes
        }else{
            std::cout << "Nao foi possivel adicionar de momento, o seu pedido esta registado." << std::endl; // Adição não realizada
            requests.push(Request("au",numero,uc));                             // Pedido registado
        }
    }
    getIn();
}

// Remover
void Menu::getOut() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###########################################"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##   Remover de :                       ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      1 -> Turma                       ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      2 -> UC                          ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                      ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"###########################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"Opcao: ";
    std::cin >> k;

    switch (k) {
        case 1:
            getOutT();
        case 2:
            getOutUC();
        case 0:
            MenuBase();
    }
    getOut();
}

// Remover de turma
void Menu::getOutT() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir Turma:______                                   ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir numero de estudante:______                     ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir UCs (separadas por virgulas):______            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;

    std::string turma;
    std::cout<<"Inserir Turma:";
    std::cin >> turma;
    if (turma == "0") getIn();
    int numero;
    std::cout<<"Inserir numero de estudante: ";
    std::cin >> numero;
    std::string conjunto;
    std::cout<<"Inserir UCs (separadas por virgulas): ";
    std::cin >> conjunto;
    std::set<std::string> ucs;
    int lastPos = -1;
    for (int i = 0; i < conjunto.length(); i++) {
        // Separar cada UC
        if (conjunto[i] == ',') {
            ucs.insert(conjunto.substr(lastPos + 1, i - lastPos - 1));
            lastPos = i;
        }
    }
    ucs.insert(conjunto.substr(lastPos + 1));

    auto it = students.find(numero);
    for (std::string uc : ucs) {
        if (removeClass(turma, it -> second, uc)){
            std::cout<<"Saida da turma "<<turma<< " com sucesso"<<std::endl;  // Remoção bem sucedida
            registers.push(it->second.getName()+" saiu da turma "+turma);  // Ação guardada no histórico
            waitingList();  // Função dos pedidos pendentes
        }else{
            std::cout<<"Saida da turma "<<turma<< " recusada"<<std::endl;                          //Remoção não realizada
            requests.push(Request("rc",numero,uc,turma)); // Pedido registado
        }
    }

    getOut();
}

// Remover de UC
void Menu::getOutUC() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir numero de estudante:______                     ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir UCs (separadas por virgulas):______            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;

    int numero;
    std::cout<<"Inserir numero de estudante: ";
    std::cin >> numero;
    if (numero == 0) getIn();
    std::string conjunto;
    std::cout<<"Inserir UCs (separadas por virgulas): ";
    std::cin >> conjunto;
    std::set<std::string> ucs;
    int lastPos = -1;
    for (int i = 0; i < conjunto.length(); i++) {
        // Separar cada UC
        if (conjunto[i] == ',') {
            ucs.insert(conjunto.substr(lastPos + 1, i - lastPos - 1));
            lastPos = i;
        }
    }
    ucs.insert(conjunto.substr(lastPos + 1));

    auto it = students.find(numero);
    for (std::string uc : ucs) {
        if (removeUC(uc, it -> second)){
            std::cout<<"Saida da Uc "<<uc<< " com sucesso"<<std::endl;   // Remoção bem sucedida
            registers.push(it->second.getName()+" saiu da Uc "+uc);   // Ação guardada no histórico
            waitingList();  // Função dos pedidos pendentes
        }else{
            std::cout<<"Saida da Uc "<<uc<< " recusada"<<std::endl;               // Remoção não realizada
            requests.push(Request("ru",numero,uc));  // Pedido registado
        }
    }

    getOut();
}

// Trocas
void Menu::replace(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"###########################################"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##   Trocar de :                         ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      1 -> Turma                       ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      2 -> UC                          ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                      ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"###########################################"<<std::endl<<std::endl;
    int k;
    std::cout<<"Opcao: ";
    std::cin>>k;
    if (k == 0)MenuBase();
    switch (k) {
        case 1:
            replaceT();
        case 2:
            replaceU();
    }
    replace();
}

// Trocar de turma numa UC
void Menu::replaceT() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir turma atual:______                             ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir numero de estudante:______                     ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir nova turma:______                              ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir UC:______                                      ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::string tInicial;
    std::cout << "Inserir turma atual: ";
    std::cin>>tInicial;
    if (tInicial == "0")replace();
    int numero;
    std::cout << "Inserir numero de estudante: ";
    std::cin>>numero;
    std::string tFinal;
    std::cout << "Inserir nova turma: ";
    std::cin>>tFinal;
    std::string uc;
    std::cout << "Inserir UC: ";
    std::cin>>uc;

    auto it = students.find(numero);
    if (switchClass(it->second,tInicial,tFinal,uc)){
        std::cout<<"Troca realizada com sucesso"<<std::endl;   // Troca bem sucedida
        registers.push(it->second.getName()+" trocou da turma "+tInicial+" para a turma "+tFinal+" na Uc "+uc);  // Ação guardada no histórico
        waitingList();  // Função dos pedidos pendentes
    }else{
        std::cout<<"Nao foi possivel realizar a troca"<<std::endl;   // Troca não realizada
        requests.push(Request("sc",numero,uc,tInicial,tFinal)); // Pedido registado
    }
    replace();
}

// Trocar de UC
void Menu::replaceU() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir Uc atual:______                                ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir numero de estudante:______                     ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      Inserir nova Uc:______                                 ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                            ##"<<std::endl;
    std::cout<<"##                                                             ##"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::string uInicial;
    std::cout << "Inserir Uc atual: ";
    std::cin>>uInicial;
    if (uInicial == "0")replace();
    int numero;
    std::cout << "Inserir numero de estudante: ";
    std::cin>>numero;
    std::string uFinal;
    std::cout << "Inserir nova Uc: ";
    std::cin>>uFinal;
    auto it = students.find(numero);
    if (switchUC(it->second,uInicial,uFinal)){
        std::cout<<"Troca realizada com sucesso"<<std::endl;   // Troca bem sucedida
        registers.push(it->second.getName()+" trocou da Uc "+uInicial+" para a Uc "+uFinal);  // Ação guardada no histórico
        waitingList();   // Função dos pedidos pendentes
    }else{
        std::cout<<"Nao foi possivel realizar a troca"<<std::endl;  // Troca não realizada
        requests.push(Request("su",numero,uInicial,"","",uFinal)); // Pedido registado
    }
    replace();
}

int biggestDiff(std::vector<std::pair<int,std::string>>a){
    int maxDiff = 0;
    int minValue = INT_MAX;
    int maxValue = 0;
    for (auto pair : a) {
        minValue = std::min(minValue,pair.first);      // Valor mínimo atual
        maxValue = std::max(maxValue,pair.first);      // Valor máximo atual
        maxDiff = std::max(maxValue-minValue,maxDiff); // Maior diferença atual
    }
    return maxDiff;
}


bool Menu::testBalance(std::string pedido,std::string turma,std::string uc){
    std::vector<std::pair<int,std::string>>alunosT;
    for (Turma t : turmas){
        if (t.haveUc(uc)){  // Se a turma tiver a UC pretendida
            // Se a turma não estiver vazia, armazena o número de alunos nessa turma dessa UC
            if (t.studentsOfUC(uc) != 0)alunosT.push_back({t.studentsOfUC(uc),t.getClassCode()});
        }
    }
    int bdiff = biggestDiff(alunosT);
    //Alterar a contagem de alunos na turma q pretendemos entrar/sair
    for(auto &pair : alunosT){
        if (pair.second == turma){
            if (pedido == "entrar"){
                pair.first++;
            }else{//Sair
                pair.first--;
            }
        }
    }
    int bdiff2 = biggestDiff(alunosT);
    return (bdiff <= 4 && bdiff2 <= 4) || (bdiff > 4 && bdiff2 <= bdiff);
}

// Trocar um estudante de UC
bool Menu::switchUC(Student& student,std::string ucInicial,std::string ucFinal){
    if (removeUC(ucInicial,student)){  // Remover da UC inicial
        if(addUC(ucFinal,student)){    // Adicionar à UC pretendida
            return true;
        }else{
            addUC(ucInicial,student);  //Repor o estudante na uc inicial
        }
    }
    return false;
}

// Trocar um estudante de turma
bool Menu::switchClass(Student& student,std::string tInicial,std::string tFinal,std::string uc){
    if (removeClass(tInicial,student,uc)){   // Remover da turma inicial
        if(addClass(tFinal,student,uc)){     // Adicionar à turma pretendida
            return true;
        }else{
            addClass(tFinal,student,uc);     //Repor o estudante na turma inicial
        }
    }
    return false;
}

// Lista de pedidos
void Menu::waitingList(){
    std::queue<Request> nova; // Fila temporária para guardar pedidos não aceites
    bool flag = false;        // Controla se algum pedido foi aceite
    while (requests.size() > 0){
        Request request = requests.front();   // Pedido mais antigo
        requests.pop();                       // É removido da fila
        std::string rc = request.requestCode;
        auto it = students.find(request.studentNumber);
        if (!flag){
            if (rc == "ac"){
                if(addClass(request.OptionalClassI,it->second,request.Uc)){
                    flag = true;
                    std::cout<<"Uma vaga na lista de espera foi colocada com sucesso"<<std::endl;
                }else{
                    nova.push(request);
                }
            }else if(rc == "au"){
                if(addUC(request.Uc,it->second)){
                    flag = true;
                    std::cout<<"Uma vaga na lista de espera foi colocada com sucesso"<<std::endl;
                }else{
                    nova.push(request);
                }
            }else if (rc == "rc"){
                if(removeClass(request.OptionalClassI,it->second,request.Uc)){
                    flag = true;
                    std::cout<<"Uma vaga na lista de espera foi colocada com sucesso"<<std::endl;
                }else{
                    nova.push(request);
                }
            }else if (rc == "ru"){
                if (removeUC(request.Uc,it->second)){
                    flag = true;
                    std::cout<<"Uma vaga na lista de espera foi colocada com sucesso"<<std::endl;
                }else{
                    nova.push(request);
                }
            }else if (rc == "sc"){
                if(switchClass(it->second,request.OptionalClassI,request.OptionalClassF,request.Uc)){
                    flag = true;
                    std::cout<<"Uma vaga na lista de espera foi colocada com sucesso"<<std::endl;
                }else{
                    nova.push(request);
                }
            }else if (rc == "su"){
                if(switchUC(it->second,request.Uc,request.UcFinal)){
                    flag = true;
                    std::cout<<"Uma vaga na lista de espera foi colocada com sucesso"<<std::endl;
                }else{
                    nova.push(request);
                }
            }
        }else{
            nova.push(request);
        }
    }
    requests = nova;  // Pedidos não aceites são colocados de novo na fila
}

// Mostrar pedidos na lista de espera
void Menu::showWaitingList(){
    std::queue<Request> nova;  // Fila temporária para guardar pedidos
    int i = 1;
    while (!requests.empty()) {
        std::cout << i <<" -> ";
        requests.front().show();
        nova.push(requests.front());
        requests.pop();
        i++;
    }
    std::cout<<"Temos um total de "<<nova.size()<<" pedidos pendentes"<<std::endl;
    requests = nova;
    MenuBase();
}

// Guardar alterações nos ficheiros
void Menu::closeMenu(){
    std::ofstream out("classes.csv", std::ofstream::out | std::ofstream::trunc); // ficheiro agora vazio
    out << "ClassCode,UcCode,Weekday,StartHour,Duration,Type"<<std::endl;
    for(Turma turma : turmas){
        for(auto k : turma.getSchedule().getClasses()){
            out << k.transformToFileFormat() << std::endl;     // Colocar informações no ficheiro
        }
    }
    out.close();
    std::string lastTurma = "";
    std::string lastUc = "";
    std::ofstream out2("students_classes.csv", std::ofstream::out | std::ofstream::trunc); // ficheiro agora vazio
    out2 << "StudentCode,StudentName,UcCode,ClassCode"<<std::endl;
    for (auto pair : students){
        for (auto k : pair.second.getSchedule().getClasses()){
            std::string turma = k.getClassCode();
            std::string uc = k.getUc();
            if (lastTurma != turma || lastUc != uc){
                out2 <<pair.first <<","<<pair.second.getName()<<","<<uc<<","<<turma<<std::endl; // Colocar informações no ficheiro
            }
            lastUc = uc;
            lastTurma = turma;
        }
    }
    out2.close();
    std::ofstream out3("Waiting.csv", std::ofstream::out | std::ofstream::trunc);  // ficheiro agora vazio
    out3 <<"RequestCode,StudentNumber,Uc1,Turma1,Turma2,Uc2"<<std::endl;
    while (!requests.empty()) {
        out3 << requests.front().toFileFormat() <<std::endl; // Colocar informações no ficheiro
        requests.pop();
    }
    out3.close();
}

// Remover pedidos pendentes
void Menu::removeFWaitingList(){
    std::queue<Request> nova;  // Fila temporária para guardar pedidos
    int i = 1;
    while (!requests.empty()) {
        std::cout << i <<" -> ";
        requests.front().show();
        nova.push(requests.front());
        requests.pop();
        i++;
    }
    requests = nova;
    int k;
    std::cout<<std::endl;
    std::cout <<" Qual o pedido que pretende remover? ";
    std::cin >> k;
    std::queue<Request> nova2;
    i = 1;
    while (!requests.empty()) {
        if (i != k)nova2.push(requests.front()); // Se não for o pedido por eliminar
        requests.pop();
        i++;
    }
    requests = nova2;
    std::cout<<std::endl;
    std::cout <<"O seu pedido foi removido."<<std::endl;
    MenuBase();
}

// Mostrar histórico
void Menu::showRegisters(){
    std::stack<std::string> novo;
    while(!registers.empty()){
        std::cout<<registers.top()<<std::endl;
        novo.push(registers.top());
        registers.pop();
    }
    novo = registers;
}









