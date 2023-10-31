#include <algorithm>
#include "Menu.h"


Menu::Menu(std::vector<Turma> t,std::unordered_map<int,Student> s){
    turmas = t;
    students = s;
}
std::vector<Turma>& Menu::getTurmas(){
    return turmas;
}
std::unordered_map<int,Student>& Menu::getStudents(){
    return students;
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
    std::cout<<"##      3 -> Numero de estudantes nas UCs                            ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      4 -> Ocupacao da turmas                                      ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      5 -> UCs com maior numero de estudantes                      ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      6 -> Adicionar                                               ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      7 -> Remover                                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Sair                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"  Option:";
    std::cin>>k;

    switch (k){
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
        case 0:
            break;
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
    std::cout<<"##      0 -> Voltar                         ##"<<std::endl;
    std::cout<<"##                                          ##"<<std::endl;
    std::cout<<"##############################################"<<std::endl<<std::endl;


    int k;
    std::cout<<"  Option:";
    std::cin>>k;
    switch (k)
    {
        case 1:
            HorarioE();
            case 2:
                HorarioT();
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
    std::cout<<"  Option:";
    std::cin>>k;

    if (k == 0) Horario();

    auto it = students.find((k));
    if (it != students.end()) {
        Student student = it->second;
        student.showSchedule();
    } else {
        std::cout << "Number not found "<< std::endl;
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
    std::cout<<"  Option:";
    std::cin>>k;

    if (k == "0") Horario();

    for (auto t : turmas) {
        if (t.getClassCode() == k) {
            t.showSchedule();
        }
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
    std::cout<<"##      0 -> Voltar                      ##"<<std::endl;
    std::cout<<"##                                       ##"<<std::endl;
    std::cout<<"###########################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"  Option:";
    std::cin>>k;
    switch (k)
    {
        case 1:
            EstudanteT();
            case 2:
                EstudanteC();
            case 3:
                EstudanteA();
            case 0:
                MenuBase();
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
    std::cout<<"  Option:";
    std::cin>>k;

    if (k == "0") Estudante();

    for (auto t : turmas) {
        if (t.getClassCode() == k) {
            std::set<int> numbers = t.studentsOfTurma();
            for (int n : numbers) {
                auto it = students.find(n);
                Student student = it->second;
                student.show();
            }
        }
    }
    EstudanteT();

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
    std::cout<<"  Option:";
    std::cin>>k;
    if (k == "0") Estudante();

    for (auto pair : students) {
        bool flag = false;
        for (auto c : pair.second.getSchedule().getClasses()) {
            if (c.getUc() == k) flag = true;

        }
        if (flag) std::cout << pair.second.getName() << std::endl;
    }

    EstudanteC();
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
    std::cout<<"  Value:";
    std::cin>>k;

    if (k == 0) Estudante();
    if (k > 3 || k < 1) EstudanteA();

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
    EstudanteA();

}

// Número de estudantes em pelo menos n UCs
void Menu::NEstudantes(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#####################################################"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##   Numero de estudantes nas UCs:                 ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##      Inserir numero de UCs:______               ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                ##"<<std::endl;
    std::cout<<"##                                                 ##"<<std::endl;
    std::cout<<"#####################################################"<<std::endl;

    int k;
    std::cout<<"  Value:";
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
    std::cout<<"  Option:";
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
        if (turma.getClassCode()[0]-'0' == year && turma.studentsOfUC(uc) < 30) {
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
void Menu::removeUC(std::string uc, Student& student){
    //Descobrir em que turma tem aquela uc
    std::string t = "";
    for (Class k : student.getSchedule().getClasses()){
        if (k.getUc() == uc)t = k.getClassCode();
    }
    if(t == ""){
        std::cout<<"Esse estudante não tem essa Uc"<<std::endl;
        return;
    }
    //Remover o estudante da turma onde tem aquela uc
    for (Turma &turma : turmas){
        if (turma.getClassCode() == t){
            turma.removeStudent(student.getNumber(),uc);
            break;
        }
    }
    //Remover as aulas da uc do horário do estudante
    student.setSchedule(student.getSchedule().removeUcClasses(uc));
}

bool Menu::addClass(Turma turma, Student& student, std::string uc) {
    for (Turma &t : turmas) {
        if (turma.getClassCode() == t.getClassCode() && turma.studentsOfUC(uc) < 30) {
            std::vector<Class> classes = turma.classesOfUC(uc);
            if (classes.size() == 0) return false;
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
                student.showSchedule();
                return true;
            }
        }
    }
    return false;
}

void Menu::removeClass(Turma turma, Student& student, std::string uc) {
    for (Turma &t : turmas){
        if (turma.getClassCode() == t.getClassCode()){
            turma.removeStudent(student.getNumber(),uc);
            break;
        }
    }
    //Remover as aulas da uc do horário do estudante
    student.setSchedule(student.getSchedule().removeUcClasses(uc));
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
    std::cin >> turma;
    if (turma == "0") entrar();
    int numero;
    std::cin >> numero;

    std::string conjunto;
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
        if (addClass(turma, it -> second, uc)) std::cout << "Foi adicionado com sucesso." << std::endl;
        else std::cout << "Nao foi possivel adicionar." << std::endl;
    }

    entrarTurma();
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
    std::cin >> numero;
    if (numero == 0) entrar();
    std::string conjunto;
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
        if (addUC(uc, it -> second)) std::cout << "Foi adicionado com sucesso." << std::endl;
        else std::cout << "Nao foi possivel adicionar." << std::endl;
    }

    entrarUC();
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
    std::cin >> turma;
    if (turma == "0") entrar();
    int numero;
    std::cin >> numero;

    std::string conjunto;
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
        removeClass(turma, it -> second, uc);
    }

    sairTurma();
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
    std::cin >> numero;
    if (numero == 0) entrar();
    std::string conjunto;
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
        removeUC(uc, it -> second);
    }

    sairUC();
}








