#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Menu.h"


// Search e sorting algoritmos
int partition(std::vector<std::pair<int, std::string>> &infos, int low, int high) {
    std::string pivot = infos[high].second;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (infos[j].second < pivot) {
            i++;
            std::swap(infos[i], infos[j]);
        }
    }
    std::swap(infos[i + 1], infos[high]);
    return i + 1;
}

void quicksort(std::vector<std::pair<int, std::string>> &infos, int low, int high) { // Quick sorting algoritmo
    if (low < high) {
        int pivot = partition(infos, low, high);
        quicksort(infos, low, pivot - 1);
        quicksort(infos, pivot + 1, high);
    }
}
void bubbleSort(std::vector<std::pair<int,int>> &v) {
    for(unsigned int j = v.size()-1; j > 0; j--) {
        bool troca = false;
        for(unsigned int i = 0; i < j; i++)
            if(v[i+1].second < v[i].second) {
                swap(v[i],v[i+1]);
                troca = true;
            }
        if (!troca) return;
    }
}
void heapify(std::vector<std::pair<std::string, int>> &v, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && v[left].second > v[largest].second) {
        largest = left;
    }
    if (right < n && v[right].second > v[largest].second) {
        largest = right;
    }
    if (largest != i) {
        std::swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}
void heapSort(std::vector<std::pair<std::string, int>> &v) {
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

Menu::Menu(std::vector<Turma> t,std::unordered_map<int,Student> s,std::queue<Request> r){
    turmas = t;
    students = s;
    requests = r;
    for (Turma &turma : turmas){
        std::list<std::pair<int, std::string>> temp = turma.getnEstudanteCadeira();
        temp.sort([](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {return a.second < b.second;});
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
    std::cout<<"##      0 -> Sair                                                    ##"<<std::endl;
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
            Horario();
        case 2:
            Estudante();
        case 3:
            NEstudantes();
        case 4:
            Ocupacao();
        case 5:
            MaiorN();
        case 6:
            entrar();
        case 7:
            sair();
        case 8:
            trocar();
        case 9:
            showWaitingList();
        case 10:
            removeFWaitingList();
        case 11:
            showRegisters();
    }
    MenuBase();

}

void Menu::Horario(){
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
            HorarioE();
        case 2:
            HorarioT();
        case 3:
            HorarioTU();
        case 0:
            MenuBase();
    }
    Horario();

}
void Menu::HorarioE(){
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

    if (k == 0) Horario();

    auto it = students.find((k));
    if (it != students.end()) {
        Student student = it->second;
        student.showSchedule();
        registers.push("Horario do estudante "+student.getName()+ " visualizado.");
    } else {
        std::cout << "Esse numero nao existe"<< std::endl;
    }

    HorarioE();

}
void Menu::HorarioT(){
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

    if (k == "0") Horario();
    bool flag = true;
    for (auto t : turmas) {
        if (t.getClassCode() == k) {
            t.showSchedule();
            flag = false;
        }
    }
    if (flag) {
        std::cout << "Essa turma não existe" << std::endl;
        HorarioT();
    }else registers.push("Horario da turma "+k+ " visualizado.");

    Horario();

}
void Menu::HorarioTU(){
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
    if (turma == "0") Horario();
    std::string uc;
    std::cout<<"Inserir Uc: ";
    std::cin>>uc;

    bool flag = true;
    for (auto t : turmas) {
        if (t.getClassCode() == turma) {
            flag = false;
            for (auto k : t.classesOfUC(uc)){
                k.show();
            }
        }
    }
    if (flag) {
        std::cout << "Essa turma não existe" << std::endl;
        HorarioTU();
    }else registers.push("Horario da turma "+turma+"e Uc "+uc +" visualizado.");
    Horario();
}

void Menu::Estudante(){
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
        case 1:
            EstudanteT();
            registers.push("Ocupacao das turmas visualizada");
        case 2:
            EstudanteC();
            registers.push("Ocupacao das UCs visualizada");
        case 3:
            EstudanteA();
            registers.push("Ocupacao dos anos visualizada");
        case 4:
            EstudanteTC();
            registers.push("Ocupacao das turmas/Ucs visualizada");
        case 0:
            MenuBase();
    }
    Estudante();

}
void Menu::ShowOptionE(std::vector<std::pair<int,std::string>> infos){
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
        case 0:
            EstudanteT();
        case 1:
            SortingE(infos,false);
        case 2:
            SortingN(infos,false);
        case 3:
            SortingOptionE(infos);
    }
    ShowOptionE(infos);
}
void Menu::SortingOptionE(std::vector<std::pair<int,std::string>> infos){ // Apenas usado em estudante e número.
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
        case 0:
            SortingOptionE(infos);
        case 1:
            SortingE(infos,true);
        case 2:
            SortingN(infos,true);
    }
    SortingOptionE(infos);
}

void Menu::SortingE(std::vector<std::pair<int,std::string>> infos,bool both){
    quicksort(infos,0,infos.size()-1);
    if (both){
        for (auto k : infos){
            std::cout<< k.second << " : "<<k.first<<std::endl;
        }
    }else{
        for (auto k : infos){
            std::cout<< k.second << std::endl;
        }
    }

    Estudante();
}
void selectionSort(std::vector<std::pair<int,std::string>> &infos) {
    for (unsigned i = 0; i < infos.size()-1; i++) {
        unsigned k = i;
        for (unsigned j = i+1; j < infos.size(); j++)
            if (infos[j].first < infos[k].first)
                k = j;
        swap(infos[i], infos[k]);
    }
}
void Menu::SortingN(std::vector<std::pair<int,std::string>> infos,bool both){
    selectionSort(infos);
    if (both){
        for (auto k : infos){
            std::cout<< k.second << " : "<<k.first<<std::endl;
        }
    }else{
        for (auto k : infos){
            std::cout<< k.second << std::endl;
        }
    }
    Estudante();
}
void Menu::EstudanteT(){
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
    if (k == "0") Estudante();
    bool flag = true;
    for (auto t : turmas) {
        if (t.getClassCode() == k) {
            flag = false;
            std::set<int> numbers = t.studentsOfTurma();
            for (int n : numbers) {
                auto it = students.find(n);
                infos.push_back({it->second.getNumber(),it->second.getName()});
            }
        }
    }
    if (flag) {
        std::cout << "Essa turma não existe" << std::endl;
        EstudanteT();
    }
    ShowOptionE(infos);
}
void Menu::EstudanteC(){
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
    if (k == "0") Estudante();
    bool flag2 = true;
    for (auto pair : students) {
        bool flag = false;
        for (auto c : pair.second.getSchedule().getClasses()) {
            if (c.getUc() == k) flag = true;
        }
        if (flag){
            flag2 = false;
            infos.push_back({pair.second.getNumber(),pair.second.getName()});
        }
    }
    if (flag2) {
        std::cout << "Essa Uc não existe" << std::endl;
        EstudanteC();
    }
    ShowOptionE(infos);
}
void Menu::EstudanteA(){
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

    if (k == 0) Estudante();
    if (k > 3 || k < 1){
        std::cout<<"Insere um ano entre 1 e 3"<<std::endl;
        EstudanteA();
    }
    std::vector<std::pair<int,std::string>> infos;
    std::set<int> numbers;
    for (auto turma : turmas) {
        if (turma.getClassCode()[0] == k + '0') {
            std::set<int> temp = turma.studentsOfTurma();
            for (int n : temp) {
                numbers.insert(n);
            }
        }
    }
    for (int n : numbers) {
        auto it = students.find(n);
        infos.push_back({it->second.getNumber(),it->second.getName()});
    }
    ShowOptionE(infos);
}

void Menu::EstudanteTC(){
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
    if (turma == "0")Estudante();
    std::string uc;
    std::cout<<"Inserir Uc: ";
    std::cin>>uc;
    std::vector<std::pair<int,std::string>> infos;
    bool flag = true;
    for (Turma t : turmas){
        if (t.getClassCode() == turma){
            if (t.studentsOfUC(uc) > 0)flag = false;
            for (auto k : t.studentsOfTurmaUc(uc)){
                auto it = students.find(k);
                infos.push_back({it->second.getNumber(),it->second.getName()});
            }
            break;
        }
    }
    if (flag){
        std::cout<<"Insere inputs válidos."<<std::endl;
        EstudanteTC();
    }
    ShowOptionE(infos);
}
// Número de estudantes em pelo menos n UCs
void Menu::NEstudantes(){
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
        for (auto c : pair.second.getSchedule().getClasses()) {
            if (c.getUc() != lastUc) {
                count2++;
            }
            lastUc = c.getUc();
        }
        if (count2 >= k) {
            count++;
        }
    }
    std::cout << "O numero de estudantes e: " << count << std::endl;
    registers.push("Numero de estudantes em pelo menos k UCs visualizado");
    MenuBase();
}

void Menu::Ocupacao() {
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
            case 0:
                MenuBase();
                break;
            case 1:
                OcupacaoA();
                registers.push("Ocupação de cada ano visualizada");
                break;
            case 2:
                OcupacaoT();
                registers.push("Ocupação de cada turma visualizada");
                break;
            case 3:
                OcupacaoC();
                registers.push("Ocupação de cada Uc visualizada");
                break;
            case 4:
                OcupationTC();
                registers.push("Ocupação de cada Turma/Uc visualizada");
        }
        Ocupacao();

}



void Menu::OcupacaoA() {
    std::unordered_map<int, int> anos;

    for (auto pair : students) {
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;
        for (auto c : pair.second.getSchedule().getClasses()) {
            if (c.getClassCode()[0] == '1') flag1 = true;
            else if (c.getClassCode()[0] == '2') flag2 = true;
            else if (c.getClassCode()[0] == '3') flag3 = true;
        }
        if (flag1) anos[1]++;
        if (flag2) anos[2]++;
        if (flag3) anos[3]++;
    }
    std::vector<std::pair<int, int>> vetor(anos.begin(), anos.end());
    bubbleSort(vetor);

    for (int i = 0; i < (int)vetor.size(); i++) {
        std::cout << "0 ano " << vetor[i].first << " tem " << vetor[i].second << " estudantes" << std::endl;
    }
}

void Menu::OcupacaoT() {
    std::unordered_map<std::string, int> t;
    for (Turma turma : turmas) {
        t[turma.getClassCode()] = turma.numberOfStudents();
    }
    std::vector<std::pair<std::string, int>> v(t.begin(), t.end());
    heapSort(v);
    for (int i = 0; i < (int)v.size(); i++) {
        std::cout << "A turma " << v[i].first << " tem " << v[i].second << " estudantes" << std::endl;
    }
}

void Menu::OcupacaoC() {
    std::unordered_map<std::string, int> ucs;
    for (auto pair : students) {
        std::string lastUc = "";
        for (auto c : pair.second.getSchedule().getClasses()) {
            if (c.getUc() != lastUc) {
                ucs[c.getUc()]++;
            }
            lastUc = c.getUc();
        }
    }
    std::vector<std::pair<std::string, int>> vetor(ucs.begin(), ucs.end());
    heapSort(vetor);
    for (int i = 0; i < (int)vetor.size(); i++) {
        std::cout << vetor[i].first << " tem " << vetor[i].second << " estudantes" << std::endl;
    }
}
void Menu::OcupationTC(){
    std::unordered_map<std::string, int> t;
    for (Turma turma : turmas) {
        for (auto k : turma.getSchedule().getClasses()){
            t[turma.getClassCode()+","+k.getUc()] = turma.studentsOfUC(k.getUc());
        }
    }
    std::vector<std::pair<std::string, int>> v(t.begin(), t.end());
    heapSort(v);
    for (int i = 0; i < (int)v.size(); i++) {
        std::cout << "A turma/Uc " << v[i].first << " tem " << v[i].second << " estudantes" << std::endl;
    }
}

void Menu::MaiorN(){
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
    if (k < 1) MaiorN();

    for (auto pair : students) {
        std::string lastUc = "";
        for (auto c : pair.second.getSchedule().getClasses()) {
            if (c.getUc() != lastUc) {
                ucCount[c.getUc()]++;
            }
            lastUc = c.getUc();
        }
    }
    std::vector<std::pair<std::string, int>> vetor(ucCount.begin(), ucCount.end());
    heapSort(vetor);


    for (int i = 0; i < std::min(k, (int)vetor.size()); i++) {
        std::cout << vetor[i].first << " tem " << vetor[i].second << " estudantes" << std::endl;
    }
    registers.push(k+" UCs com maior numero de estudantes visualizadas");
    MaiorN();
}

bool Menu::addUC(std::string uc, Student& student) {
   if (student.getSchedule().numberOfUCs() >= 7) return false;
   int n = stoi(uc.substr(uc.length() - 2, 2));
   int year;
   if (n >= 1 && n <= 5) year = 1;
   else if (n >= 11 && n <= 15) year = 2;
   else if (n >= 21 && n<= 25) year = 3;
    for (Turma &turma : turmas) {
        if (turma.getClassCode()[0]-'0' == year && turma.studentsOfUC(uc) < 30 && testBalance("entrar",turma.getClassCode(),uc)) {
            std::vector<Class> classes = turma.classesOfUC(uc);
            bool c = true;
            for (auto c1 : classes) {
                for (auto c2 : student.getSchedule().getClasses()) {
                    if (c1.overlaps(c2)) c = false;
                }
            }
            if (c) {
                turma.addClassToG({student.getNumber(), uc});
                for (auto cl : classes) student.addToSchedule(cl);
                turma.addClassToG({student.getNumber(),uc});
                return true;
            }
        }
    }
    return false;
}
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

bool Menu::addClass(std::string turma, Student& student, std::string uc) {
    for (Turma &t : turmas) {
        if (turma == t.getClassCode() && t.studentsOfUC(uc) < 30 && testBalance("entrar",t.getClassCode(),uc)) {
            std::vector<Class> classes = t.classesOfUC(uc);
            if (classes.size() == 0) return false;
            bool c = true;
            for (auto c1 : classes) {
                for (auto c2 : student.getSchedule().getClasses()) {
                    if (c1.overlaps(c2)) c = false;
                }
            }
            if (c) {
                t.addClassToG({student.getNumber(), uc});
                for (auto cl : classes) student.addToSchedule(cl);
                t.addClassToG({student.getNumber(),uc});
                return true;
            }
        }
    }
    return false;
}

bool Menu::removeClass(std::string turma, Student& student, std::string uc) {
    for (Turma &t : turmas){
        if (turma == t.getClassCode()){
            if (testBalance("sair",t.getClassCode(),uc)){
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

void Menu::entrar() {
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
            entrarTurma();
        case 2:
            entrarUC();
        case 0:
            MenuBase();
    }
    entrar();
}

void Menu::entrarTurma() {
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
    if (turma == "0") entrar();
    int numero;
    std::cout << "Inserir numero de estudante: ";
    std::cin >> numero;
    std::string conjunto;
    std::cout << "Inserir UCs (separadas por virgulas): ";
    std::cin >> conjunto;
    std::set<std::string> ucs;
    int lastPos = -1;
    for (int i = 0; i < conjunto.length(); i++) {
        if (conjunto[i] == ',') {
            ucs.insert(conjunto.substr(lastPos + 1, i - lastPos - 1));
            lastPos = i;
        }
    }
    ucs.insert(conjunto.substr(lastPos + 1));
    auto it = students.find(numero);
    for (std::string uc : ucs) {
        if (addClass(turma, it -> second, uc)){
            std::cout << "Foi adicionado com sucesso." << std::endl;
            registers.push(it->second.getName()+" foi adicionado à turma "+turma+" na Uc "+uc);
            waitingList();
        }else {
            std::cout << "Nao foi possivel adicionar de momento, o seu pedido esta registado." << std::endl;
            requests.push(Request("ac",numero,uc,turma));
        }
    }
    entrar();
}

void Menu::entrarUC() {
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
    if (numero == 0) entrar();
    std::string conjunto;
    std::cout<<"Inserir UCs (separadas por virgulas): ";
    std::cin >> conjunto;
    std::set<std::string> ucs;
    int lastPos = -1;
    for (int i = 0; i < conjunto.length(); i++) {
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
            std::cout << "Foi adicionado com sucesso." << std::endl;
            registers.push(it->second.getName()+" entrou na Uc "+uc);
            waitingList();
        }else{
            std::cout << "Nao foi possivel adicionar de momento, o seu pedido esta registado." << std::endl;
            requests.push(Request("au",numero,uc));
        }
    }
    entrar();
}

void Menu::sair() {
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
            sairTurma();
        case 2:
            sairUC();
        case 0:
            MenuBase();
    }
    sair();
}

void Menu::sairTurma() {
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
    if (turma == "0") entrar();
    int numero;
    std::cout<<"Inserir numero de estudante: ";
    std::cin >> numero;
    std::string conjunto;
    std::cout<<"Inserir UCs (separadas por virgulas): ";
    std::cin >> conjunto;
    std::set<std::string> ucs;
    int lastPos = -1;
    for (int i = 0; i < conjunto.length(); i++) {
        if (conjunto[i] == ',') {
            ucs.insert(conjunto.substr(lastPos + 1, i - lastPos - 1));
            lastPos = i;
        }
    }
    ucs.insert(conjunto.substr(lastPos + 1));
    auto it = students.find(numero);
    for (std::string uc : ucs) {
        if (removeClass(turma, it -> second, uc)){
            std::cout<<"Saida da turma "<<turma<< " com sucesso"<<std::endl;
            registers.push(it->second.getName()+" saiu da turma "+turma);
            waitingList();
        }else{
            std::cout<<"Saida da turma "<<turma<< " recusada"<<std::endl;
            requests.push(Request("rc",numero,uc,turma));
        }
    }

    sair();
}

void Menu::sairUC() {
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
    if (numero == 0) entrar();
    std::string conjunto;
    std::cout<<"Inserir UCs (separadas por virgulas): ";
    std::cin >> conjunto;
    std::set<std::string> ucs;
    int lastPos = -1;
    for (int i = 0; i < conjunto.length(); i++) {
        if (conjunto[i] == ',') {
            ucs.insert(conjunto.substr(lastPos + 1, i - lastPos - 1));
            lastPos = i;
        }
    }
    ucs.insert(conjunto.substr(lastPos + 1));
    auto it = students.find(numero);
    for (std::string uc : ucs) {
        if (removeUC(uc, it -> second)){
            std::cout<<"Saida da Uc "<<uc<< " com sucesso"<<std::endl;
            registers.push(it->second.getName()+" saiu da Uc "+uc);
            waitingList();
        }else{
            std::cout<<"Saida da Uc "<<uc<< " recusada"<<std::endl;
            requests.push(Request("ru",numero,uc));
        }
    }

    sair();
}
void Menu::trocar(){
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
            trocarT();
        case 2:
            trocarU();
    }
    trocar();
}
void Menu::trocarT() {
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
    if (tInicial == "0")trocar();
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
        std::cout<<"Troca realizada com sucesso"<<std::endl;
        registers.push(it->second.getName()+" trocou da turma "+tInicial+" para a turma "+tFinal+" na Uc "+uc);
        waitingList();
    }else{
        std::cout<<"Nao foi possivel realizar a troca"<<std::endl;
        requests.push(Request("sc",numero,uc,tInicial,tFinal));
    }
    trocar();
}
void Menu::trocarU() {
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
    if (uInicial == "0")trocar();
    int numero;
    std::cout << "Inserir numero de estudante: ";
    std::cin>>numero;
    std::string uFinal;
    std::cout << "Inserir nova Uc: ";
    std::cin>>uFinal;
    auto it = students.find(numero);
    if (switchUC(it->second,uInicial,uFinal)){
        std::cout<<"Troca realizada com sucesso"<<std::endl;
        registers.push(it->second.getName()+" trocou da Uc "+uInicial+" para a Uc "+uFinal);
        waitingList();
    }else{
        std::cout<<"Nao foi possivel realizar a troca"<<std::endl;
        requests.push(Request("su",numero,uInicial,"","",uFinal));
    }
    trocar();
}
int biggestDiff(std::vector<std::pair<int,std::string>>a){
    int maxDiff = 0;
    int minValue = INT_MAX;
    int maxValue = 0;
    for (auto pair : a) {
        minValue = std::min(minValue,pair.first);
        maxValue = std::max(maxValue,pair.first);
        maxDiff = std::max(maxValue-minValue,maxDiff);
    }
    return maxDiff;
}
bool Menu::testBalance(std::string pedido,std::string turma,std::string uc){
    std::vector<std::pair<int,std::string>>alunosT;
    for (Turma t : turmas){
        if (t.haveUc(uc)){
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
bool Menu::switchUC(Student& student,std::string ucInicial,std::string ucFinal){
    if (removeUC(ucInicial,student)){
        if(addUC(ucFinal,student)){
            return true;
        }else{
            addUC(ucInicial,student);//Repor o estudante na uc inicial
        }}
    return false;
}
bool Menu::switchClass(Student& student,std::string tInicial,std::string tFinal,std::string uc){
    if (removeClass(tInicial,student,uc)){

        if(addClass(tFinal,student,uc)){
            return true;
        }else{
            addClass(tFinal,student,uc);//Repor o estudante na turma inicial
        }}
    return false;
}
void Menu::waitingList(){
    std::queue<Request> nova;
    bool flag = false;
    while (requests.size() > 0){
        Request request = requests.front();
        requests.pop();
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
    requests = nova;
}
void Menu::showWaitingList(){
    std::queue<Request> nova;
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
void Menu::closeMenu(){
    std::ofstream out("classes.csv", std::ofstream::out | std::ofstream::trunc);
    out << "ClassCode,UcCode,Weekday,StartHour,Duration,Type"<<std::endl;
    for(Turma turma : turmas){
        for(auto k : turma.getSchedule().getClasses()){
            out << k.transformToFileFormat() << std::endl;
        }
    }
    out.close();
    std::string lastTurma = "";
    std::string lastUc = "";
    std::ofstream out2("students_classes.csv", std::ofstream::out | std::ofstream::trunc);
    out2 << "StudentCode,StudentName,UcCode,ClassCode"<<std::endl;
    for (auto pair : students){
        for (auto k : pair.second.getSchedule().getClasses()){
            std::string turma = k.getClassCode();
            std::string uc = k.getUc();
            if (lastTurma != turma || lastUc != uc){
                out2 <<pair.first <<","<<pair.second.getName()<<","<<uc<<","<<turma<<std::endl;
            }
            lastUc = uc;
            lastTurma = turma;
        }
    }
    out2.close();
    std::ofstream out3("Waiting.csv", std::ofstream::out | std::ofstream::trunc);
    out3 <<"RequestCode,StudentNumber,Uc1,Turma1,Turma2,Uc2"<<std::endl;
    while (!requests.empty()) {
        out3 << requests.front().ToFileFormat() <<std::endl;
        requests.pop();
    }
    out3.close();
}
void Menu::removeFWaitingList(){
    std::queue<Request> nova;
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
        if (i != k)nova2.push(requests.front());
        requests.pop();
        i++;
    }
    requests = nova2;
    std::cout<<std::endl;
    std::cout <<"O seu pedido foi removido."<<std::endl;
    MenuBase();
}
void Menu::showRegisters(){
    std::stack<std::string> novo;
    while(!registers.empty()){
        std::cout<<registers.top()<<std::endl;
        novo.push(registers.top());
        registers.pop();
    }
    novo = registers;
}









