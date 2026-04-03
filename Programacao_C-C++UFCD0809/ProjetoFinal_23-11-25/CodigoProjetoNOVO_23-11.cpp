/******************************************************************************
https://onlinegdb.com/Xrol6BbmuA
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
        cout << "=== CIDADÃO (Guardião da Floresta) ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Lv: " << Lv << " | HP: " << HP << " | ATK: " << ATK << " | DEF: " << DEF << " | XP: " << XP << endl;
        cout << "===============" << endl;
    }
    
    void menuStatusMonstro() const {
        cout << "=== PIRODUENTE (Incendiário Irresponsável) ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Lv: " << Lv << " | HP: " << HP << " | ATK: " << ATK << " | DEF: " << DEF << endl;
        cout << "===============" << endl;
    }
    
    void saveFile() const {
        string nomeFile = nome + ".sav";
        ofstream out(nomeFile);
        out << "Nome: " << nome << endl
            << "Nível: " << Lv << endl
            << "Vida: " << HP << endl
            << "Ataque: " << ATK << endl
            << "Defesa: " << DEF << endl
            << "Experiência :" << XP << endl;
        out.close();
    }
    
    bool loadFile(){
        string nomeFile = nome + ".sav";
        ifstream in(nomeFile);
        if (!in){
            return false;
        }
        string rotulo;
        in >> rotulo >> nome;        
        in >> rotulo >> Lv;          
        in >> rotulo >> HP;          
        in >> rotulo >> ATK;         
        in >> rotulo >> DEF;         
        in >> rotulo >> XP; 
       
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
        cout << "Parabéns! Você subiu de nível como Guardião da Floresta!" << endl;
        j.addLv(1);
        j.setHP(90 + (j.getLv() * 10));
        j.addATK(2);
        j.addDEF(1);
        j.clearXP();
        j.menuStatus();
        sleep(2);
    }
    }

    void fase1Combate(Personagem &j, Personagem &m, int &rondas){
    int danoJogador = 0, danoMonstro = 0, fator = 0;
    
    clear();
    cout << "=== FASE 1: CONFRONTO NA RODOVIA ===" << endl;
    cout << "Você Visualizou na rodovia alguém atear fogo na Floresta..." << endl << endl;
    cout << "Reage e ataca primeiro, usando sua coragem de cidadão para 'extinguir' a ameaça!" << endl;
    sleep(3);
    
    while(j.getHP() > 0 && m.getHP() > 0){
        rondas += 1;
        
        fator = 50 + (rand() % 101);
        danoJogador = ((j.getATK() * fator) / 100) - m.getDEF();
        if(danoJogador < 0) { danoJogador = 0; }
        
        cout << "Rodada " << rondas << ":" << endl;
        cout << "Você ataca com coragem: dano de " << danoJogador << "!" << endl;
        m.addHP(-danoJogador);
        cout << "HP do Piroduente: " << m.getHP() << endl << endl;
        
        if(m.getHP() <= 0) break;
        
        fator = 50 + (rand() % 101);
        danoMonstro = ((m.getATK() * fator) / 100) - j.getDEF();
        if(danoMonstro < 0) { danoMonstro = 0;}
        cout << "O Piroduente contra-ataca com chamas ilegais: dano de " << danoMonstro << "!" << endl;
        cout << "Seu HP: " << j.getHP() << endl << endl;
        
        j.addHP(-danoMonstro);
        sleep(2);
    }
    
 
    if(j.getHP() <= 0){
        cout << "DERROTA NA FASE 1! O Piroduente te derrotou com suas chamas!" << endl;
    }
    else{
        cout << "VITÓRIA NA FASE 1! Você venceu o primeiro confronto!" << endl;
    }
    
    sleep(2);
    }

    void fase2Imobilizacao(Personagem &j, Personagem &m, int &rondas){
    int danoJogador = 0, danoMonstro = 0, fator = 0;
    
    // Resetar HP para segunda fase
    m.setHP(50);
    j.setHP(100);
    
    clear();
    cout << "=== FASE 2: IMOBILIZAÇÃO NA MATA ===" << endl;
    cout << "Agora você se aproximou do Piroduente e tentou imobilizá-lo com uma chave de braço," << endl;
    cout << "dispensando toda sua força por cerca de 15 minutos!" << endl << endl;
    sleep(3);
    
    while(j.getHP() > 0 && m.getHP() > 0){ 
        rondas += 1;
        
        fator = 50 + (rand() % 101);
        danoJogador = ((j.getATK() * fator) / 100) - m.getDEF();
        if(danoJogador < 0) { danoJogador = 0; }
        
        cout << "Rodada " << rondas << ":" << endl;
        cout << "Você tenta imobilizar: dano de " << danoJogador << "!" << endl;
        m.addHP(-danoJogador);
        cout << "HP do Piroduente: " << m.getHP() << endl << endl;
        
        if(m.getHP() <= 0) break;
        
        fator = 50 + (rand() % 101);
        danoMonstro = ((m.getATK() * fator) / 100) - j.getDEF();
        if(danoMonstro < 0) { danoMonstro = 0; }
        
        cout << "O Piroduente usa de toda sua malícia e força-física, empurrando-o: dano de " << danoMonstro << "!" << endl;
        cout << "Seu HP: " << j.getHP() << endl << endl;
        
        j.addHP(-danoMonstro);
        sleep(1);
    }
    
    // Resultado da Fase 2
    if(j.getHP() <= 0){
        cout << "DERROTA NA FASE 2! O Piroduente conseguiu fugir pela mata!" << endl;
    }
    else{
        cout << "VITÓRIA NA FASE 2! Você conseguiu imobilizar o Piroduente!" << endl;
    }
    
    sleep(2);
    }
    
    void fase3Autoridades(Personagem &j, Personagem &m, int &rondas){
    int danoJogador = 0, danoMonstro = 0, fator = 0;
    
    m.setHP(50);
    j.setHP(100);
    
    clear();
    cout << "=== FASE 3: Ligar para PORTUGAL CHAMA ===" << endl;
    cout << "Agora você muito cansado, retornou a sua viatura, pegou seu telemóvel e ligou para PORTUGAL CHAMA !!," << endl;
    cout << "Eles ficaram de enviar o mais rápido possível efetivos para o local" << endl << endl;
    sleep(3);
    
    while(j.getHP() > 0 && m.getHP() > 0){ 
        rondas += 1;
        
        fator = 50 + (rand() % 101);
        danoJogador = ((j.getATK() * fator) / 100) - m.getDEF();
        if(danoJogador < 0) { danoJogador = 0; }
        
        cout << "Rodada " << rondas << ":" << endl;
        cout << "Você mesmo cansado, ainda deu mais um pique até sua viatura, para comunicar o ocorrido as autoridades compententes " << danoJogador << "!" << endl;
        m.addHP(-danoJogador);
        cout << "HP do Piroduente: " << m.getHP() << endl << endl;
        
        if(m.getHP() <= 0) break;
        
        fator = 50 + (rand() % 101);
        danoMonstro = ((m.getATK() * fator) / 100) - j.getDEF();
        if(danoMonstro < 0) { danoMonstro = 0; }
        
        cout << "O PIRODUENTE fugiu pela mata a dentro, será que ele conseguirá escapar e a floresta continuará a queimar sem controle? : dano de " << danoMonstro << "!" << endl;
        cout << "Seu HP: " << j.getHP() << endl << endl;
        
        j.addHP(-danoMonstro);
        sleep(1);
    }
    
    if(j.getHP() <= 0){
        cout << "DERROTA NA FASE 3! Apesar da denúncia realizada ao 112 - (PORTUGAL CHAMA) o PIRODUENTE escapou e a Floresta continua a arder em chmas!" << endl;
    }
    else{
        cout << "VITÓRIA NA FASE 3! Você conseguiu !! O PIRODUENTE foi detido e o incêndio florestal foi apagado por completo!" << endl;
    }
    
    sleep(3);
    }
   
int main(){
    srand(time(0));
    
    string nome;
    int escolha = 0;
    int rondas = 0;
    
    cout << "Bem-vindo, Cidadão! Informe o seu nome: " << endl; 
    cin >> nome;
    
    Personagem j(nome);
    
    if(!j.loadFile()){
        cout << "Vamos criar um novo Guardião da Floresta." << endl;
        j.setLv(1);
        j.setHP(100);
        j.setATK(10);
        j.setDEF(5);
        j.setXP(0);
        j.menuStatus();
        sleep(2);
    }
    else{
        cout << "Bem-vindo de volta, Guardião!" << endl;
        j.menuStatus();
        sleep(2);
    }
    
    clear();
    
    cout << R"(
    Bem-vindo à Floresta Protegida de Portugal, um mundo onde as leis contra incêndios florestais (como o Decreto-Lei 124/2006) protegem a natureza. Você é um cidadão comum, mas corajoso, que patrulha as matas para impedir violações. Os piroduentes são criaturas maliciosas que iniciam fogos ilegalmente, ignorando as regras de prevencão e limpeza de terrenos. Sua missão: confrontar uma dessas criaturas para defender a floresta e aplicar a justiça ambiental!
    )" << endl;
    sleep(4);

    Personagem m("PIRODUENTE");
    m.setLv(1);
    m.setHP(50);
    m.setATK(10);
    m.setDEF(2);
    m.menuStatusMonstro();
    sleep(2);
    
    // MENU DE ESCOLHA
    clear();
    cout << "\n=== ESCOLHA UMA FASE PARA JOGAR E PROTEGER AS FLORESTAS ===" << endl;
    cout << "1. FASE 1 - Confronto na Rodovia (com chamas 🔥 )" << endl;
    cout << "2. FASE 2 - Imobilização na Mata (corpo a corpo 💪 )" << endl;
    cout << "3. FASE 3 - Ligar Portugal Chama (112 - Incêndios 🚒 )" << endl;
    cout << "4. Jogar AMBAS as fases" << endl;
    cout << "5. Sair do Jogo" << endl;
    cout << "Escolha (1, 2, 3, 4 ou 5): ";
    cin >> escolha;
    
    if(escolha == 1){
        fase1Combate(j, m, rondas);
    }
    else if(escolha == 2){
        fase2Imobilizacao(j, m, rondas);
    }    
    else if(escolha == 3){
        fase3Autoridades(j, m, rondas);    
    }
    else if(escolha == 4){
        fase1Combate(j, m, rondas);
        if(j.getHP() > 0){
            cout << "**##** Você avança para a Fase 2! **##**" << endl;
            sleep(3);
            fase2Imobilizacao(j, m, rondas);
         if(j.getHP() > 0){
            cout << "**##** Você avança para a Fase 3! **##**" << endl;
            sleep(3);
            fase3Autoridades(j, m, rondas);   
            
        }
    }
    else{
        cout << "Opção inválida! Saindo..." << endl;
    }
    }
   
    clear();
    if (j.getHP() <= 0){
        cout << "DERROTA! Você foi derrotado pelo Piroduente. A floresta está em risco maior agora... Tente novamente para aplicar a lei!" << endl;
        j.clearHP();
    }
    else if (m.getHP() <= 0){
        int xpGanho = rondas * 10 + m.getLv() * 5;
        cout << "VITÓRIA! Você derrotou o Piroduente e preveniu um incêndio ilegal. De acordo com as leis portuguesas contra fogos, ações como essa salvam vidas e ecossistemas, E Ganhou " << xpGanho << " de experiência!" << endl;
        j.addXP(xpGanho);
        sistemaExperiencia(j);
    }
    clear();
    cout << "\nResultados: N. de Rondas: " << rondas << endl;
    j.menuStatus();
    m.menuStatusMonstro();
    j.saveFile();
  
    return 0;
}