/******************************************************************************
https://onlinegdb.com/X7X_vlQ5RX
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void clear(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\x1b[2J\x1b[H";
}

class Personagem{
public:
    explicit Personagem(const string nome): nome(nome), Lv(0), HP(0), ATK(0), DEF(0), XP(0) {}
    
    const string& getNome() const { return nome; }  
    int getATK() const { return ATK; }              
    int getDEF() const { return DEF; }              
    int getHP() const { return HP; }
    
    int getLv() const { return Lv; }
    void setLv(int fixo) { Lv = fixo; }
    void addLv(int add) { Lv += add; }
    void clearLv() { Lv = 0; }
    
    void setHP(int fixo) { HP = fixo; }
    void addHP(int add) { HP += add; }
    void clearHP() { HP = 0; }
    
    void setATK(int fixo) { ATK = fixo; }
    void addATK(int add) { ATK += add; }
    void clearATK() { ATK = 0; }
    
    void setDEF(int fixo) { DEF = fixo; }
    void addDEF(int add) { DEF += add; }
    void clearDEF() { DEF = 0; }
    
    int getXP() const { return XP; }
    void setXP(int fixo) { XP = fixo; }
    void addXP(int add) { XP += add; }
    void clearXP() { XP = 0; }
    
    void menuStatus() const {
        cout << "=== JOGADOR ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Lv: " << Lv << " | HP: " << HP << " | ATK: " << ATK << " | DEF: " << DEF << " | XP: " << XP << endl;
        cout << "===============" << endl;
    }
    
    void menuStatusMonstro() const {
        cout << "=== MONSTRO ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Lv: " << Lv << " | HP: " << HP << " | ATK: " << ATK << " | DEF: " << DEF << endl;
        cout << "===============" << endl;
    }
    
    void saveFile() const {
        string nomeFile = nome + ".sav";
        ofstream out(nomeFile);
        out << nome << endl
            << Lv << endl
            << HP << endl
            << ATK << endl
            << DEF << endl
            << XP << endl;
        out.close();
    }
    
    bool loadFile(){
        string nomeFile = nome + ".sav";
        ifstream in(nomeFile);
        if (!in){
            return false;
        }
        in >> nome >> Lv >> HP >> ATK >> DEF >> XP;
        in.close();
        return true;
    }

private:
    string nome;
    int Lv;
    int HP, ATK, DEF, XP;
};

void sistemaExperiencia(Personagem &j){
    int toLvUP, levelUP;
    levelUP = j.getLv() * 100;
    toLvUP = j.getXP();
    
    if (toLvUP >= levelUP){
        cout << "Parabéns subiu de nível!" << endl;
        j.addLv(1);
        j.setHP(90 + (j.getLv() * 10));
        j.addATK(2);
        j.addDEF(1);
        j.clearXP();
        j.menuStatus();
        sleep(2);
    }
}

int main()
{
    srand(time(0));
    
    string nome;
    int danoJogador = 0, danoMonstro = 0, fator = 0, rondas = 0;
    
    cout << "Bem vindo Jogador, Informe o seu nome: " << endl; 
    cin >> nome;
    
    Personagem j(nome);
    
    if(!j.loadFile()){
        cout << "Vamos criar jogador novo" << endl;
        j.setLv(1);
        j.setHP(100);
        j.setATK(10);
        j.setDEF(5);
        j.setXP(0);
        j.menuStatus();
        sleep(2);
    }
    else{
        cout << "Bem vindo de volta" << endl;
        j.menuStatus();
        sleep(2);
    }
    
    clear();
    
    cout << R"(
        Bem vindo ao mundo N.25481)" << endl;
    sleep(1);

    Personagem m("Goblin");
    m.setLv(1);
    m.setHP(50);
    m.setATK(5);
    m.setDEF(2);
    m.menuStatusMonstro();
    sleep(2);
    
    clear();
    
    while(j.getHP() > 0 && m.getHP() > 0){ 
        rondas += 1;
        
        fator = 50 + (rand() % 101);
        danoJogador = ((j.getATK() * fator) / 100) - m.getDEF();
        if(danoJogador < 0) { danoJogador = 0; }
        cout << "Atacas primeiro, e dás um golpe de " << danoJogador << endl;
        m.addHP(-danoJogador);
        
        fator = 50 + (rand() % 101);
        danoMonstro = ((m.getATK() * fator) / 100) - j.getDEF();
        if(danoMonstro < 0) { danoMonstro = 0; }
        cout << "O " << m.getNome() << " contra-ataca, e levas um dano de " << danoMonstro << endl;
        
        j.addHP(-danoMonstro);
        
        cout << endl;
        sleep(1);
    }
    
    clear();
    
    if (j.getHP() <= 0){
        cout << "Foste derrotado pelo " << m.getNome() << endl;
        j.clearHP();
    }
    else if (m.getHP() <= 0){
        int xpGanho = rondas + m.getLv();
        cout << "Ganhaste o combate contra o " << m.getNome() << "! Ganhaste " << xpGanho << " de experiência" << endl;
        j.addXP(xpGanho);
        sistemaExperiencia(j);
    }
    
    cout << "\nResultados: N. de Rondas: " << rondas << endl;
    j.menuStatus();
    m.menuStatusMonstro();
    
    j.saveFile();
    
    return 0;
}