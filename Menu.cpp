#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Menu.h"


Menu::Menu(std::vector<Turma> t,std::unordered_map<int,Student> s,std::queue<Request> r){
    turmas = t;
    students = s;
    requests = r;
}
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
    std::cout<<"##      4 -> Ocupacao da turmas                                      ##"<<std::endl;
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
    }
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
    }
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
        case 2:
            EstudanteC();
        case 3:
            EstudanteA();
        case 4:
            EstudanteTC();
        case 0:
            MenuBase();
    }
    Estudante();

}
int Menu::SortingOpctionE(){
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Tipos:                                ## "<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      1 -> Estudante                     ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      2 -> Numero                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      3 -> Estudante e numero            ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      4 -> Estudante e Uc                ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      5 -> Numero e Uc                   ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      6 -> Estudante e turma             ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      4 -> Numero e turma                ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                        ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"#############################################"<<std::endl<<std::endl;

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

    if (k == "0") Estudante();
    bool flag = true;
    for (auto t : turmas) {
        if (t.getClassCode() == k) {
            flag = false;
            std::set<int> numbers = t.studentsOfTurma();
            for (int n : numbers) {
                auto it = students.find(n);
                Student student = it->second;
                student.show();
            }
        }
    }
    if (flag) {
        std::cout << "Essa turma não existe" << std::endl;
        EstudanteT();
    }
    Estudante();

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
    if (k == "0") Estudante();
    bool flag2 = true;
    for (auto pair : students) {
        bool flag = false;
        for (auto c : pair.second.getSchedule().getClasses()) {
            if (c.getUc() == k) flag = true;
        }
        if (flag){
            flag2 = false;
            std::cout << pair.second.getName() << std::endl;
        }
    }
    if (flag2) {
        std::cout << "Essa Uc não existe" << std::endl;
        EstudanteC();
    }
    Estudante();
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
        Student student = it->second;
        student.show();
    }
    Estudante();

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
    bool flag = true;
    for (Turma t : turmas){
        if (t.getClassCode() == turma){
            if (t.studentsOfUC(uc) > 0)flag = false;
            for (auto k : t.studentsOfTurmaUc(uc)){
                auto it = students.find(k);
                it->second.show();
            }
            break;
        }
    }
    if (flag){
        std::cout<<"Insere inputs válidos."<<std::endl;
        EstudanteTC();
    }
    Estudante();
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

    if (k == 0) Estudante();

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
    NEstudantes();
}

bool compareInts(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second > b.second;
}
bool compare(std::pair<std::string, int> a, std::pair<std::string, int> b) {
    return a.second > b.second;
}
void Menu::Ocupacao() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#############################################"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##   Ocupacao da turmas:                   ## "<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      1 -> Ano                           ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      2 -> Turma                         ##"<<std::endl;
    std::cout<<"##                                         ##"<<std::endl;
    std::cout<<"##      3 -> UC                            ##"<<std::endl;
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
                break;
            case 2:
                OcupacaoT();
                break;
            case 3:
                OcupacaoC();
                break;
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
    std::sort(vetor.begin(), vetor.end(), compareInts);


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
    std::sort(v.begin(), v.end(), compare);


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
    std::sort(vetor.begin(), vetor.end(), compare);


    for (int i = 0; i < (int)vetor.size(); i++) {
        std::cout << vetor[i].first << " tem " << vetor[i].second << " estudantes" << std::endl;
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
    std::sort(vetor.begin(), vetor.end(), compare);


    for (int i = 0; i < std::min(k, (int)vetor.size()); i++) {
        std::cout << vetor[i].first << " tem " << vetor[i].second << " estudantes" << std::endl;
    }
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
    while (!requests.empty()) {
        requests.front().show();
        nova.push(requests.front());
        requests.pop();
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









