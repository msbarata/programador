/******************************************************************************
https://onlinegdb.com/fPJPm1NiU
Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
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
        cout << "=== CIDADAO (Guardião da Floresta) ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Nível: " << Lv << " | Vida: " << HP << " | Ataque: " << ATK << endl;
        cout << "| Energia: " << DEF << "| Experiência: " << XP << endl;
        cout << "===============" << endl;
    }
    
    void menuStatusFogos() const {
        cout << "=== FOGOS FLORESTAIS ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Status: " << Lv << " | Força: " << HP << " | Intensidade: " << ATK << " | Energia: " << DEF << endl;
        cout << "===============" << endl;
    }
   
    void saveFile() const {
        string nomeFile = nome + ".sav";
        ofstream out(nomeFile);
        out << "Nome: " << nome << endl
            << "Nível: " << Lv << endl
            << "Vida: " << HP << endl
            << "Ataque: " << ATK << endl
            << "Energia: " << DEF << endl
            << "Experiência: " << XP << endl;
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
    
class ONG {
public:
    explicit ONG(const string nome) 
        : nomeONG(nome), palestrasRealizadas(0), arvoresPlantadas(0), bonusXP(0), bonusHP(0) {}
    
    const string& getNomeONG() const { return nomeONG; }
    int getPalestras() const { return palestrasRealizadas; }
    int getArvores() const { return arvoresPlantadas; }
    
    void setPalestras(int valor) { palestrasRealizadas = valor; }
    void addPalestras(int valor) { palestrasRealizadas += valor; }
    
    void setArvores(int valor) { arvoresPlantadas = valor; }
    void addArvores(int valor) { arvoresPlantadas += valor; }
    
    void menuStatusONG() const {
        cout << "=== ONGS (Preservacao da Floresta) ===" << endl;
        cout << "Nome: " << nomeONG << endl;
        cout << "\033[34m" << "Palestras realizadas: " << "\033[0m" << palestrasRealizadas << endl;
        cout << "\033[32m" << "Árvores plantadas: " << "\033[0m" << arvoresPlantadas << endl;
        cout << "\033[34m" << "BÔNUS - PARTILHA DO CONHECIMENTO: " << "\033[0m" <<bonusXP << endl;
        cout << "\033[32m" << "BÔNUS - VIDA NO PLANETA: " << "\033[0m" << bonusHP << endl;
        cout << "===============" << endl;
    }
    
    void realizarPalestra(Personagem &j) {
        clear();
        cout << "\n=== PALESTRA EDUCATIVA NAS JUNTAS ===" << endl;
        cout << "ONG " << nomeONG << " com a sua colaboração, está promovendo conscientização ambiental!" << endl;
        cout << "Tema: Prevenção de Incêndios e Proteção Florestal" << endl << endl;
    cout << "\033[34m" << "\n=== PALESTRAS ===" << endl;  
    cout << "              O                             \n";
    cout << "             /|\\        <- PALESTRANTE      \n";
    cout << "             / \\                            \n";
    cout << "           -------                          \n";
    cout << "\n";
    
    cout << "      VOLUNTÁRIOS ASSISTINDO PALESTRAS:\n\n";
    cout << "       O      O     O     O               \n";
    cout << "      /|\\    /|\\   /|\\   /|\\              \n";
    cout << "      / \\    / \\   / \\   / \\              \n";
    cout << "     ___    ___    ___    ___              \n";
  
    cout << "\n";
    cout << "  ============================================\n" << "\033[0m";
        
        
        sleep(1);
        
        int numPalestras = 1 + (rand() % 5);
        int participantes = 20 + (rand() % 51);
        int bonusXPLocal = participantes * 2 * numPalestras;
        
         cout << "Número de palestras realizadas: " << numPalestras << endl;
         cout << "Participantes por palestra: " << participantes << " pessoas" << endl;
         cout << "Total de participantes: " << (participantes * numPalestras) << " pessoas" << endl;
         cout << "Palestras concluídas com sucesso!" << endl << endl;
         
        palestrasRealizadas += numPalestras;
        bonusXP += bonusXPLocal;
        j.addXP(bonusXPLocal);
        j.addDEF(2 * numPalestras);
        
        cout << "Recompensas:" << endl;
        cout << "   + " << bonusXP << " de Bônus pela partilha do 'Conhecimento'" << endl;
        cout << "   + " << (2 * numPalestras) << " de Bônus pela energia da 'Conscientização'" << endl;
        cout << "   Total de palestras da ONG: " << palestrasRealizadas << endl;
        cout << "====================================================" << endl;
        cout << "**##** Parabéns você concluiu mais uma etapa!! **##**" << endl;
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
        
        sleep(4);
    }
    
    void mutiraoPlantio(Personagem &j) {
        clear();
        cout << "\n=== MUTIRÃO DE PLANTIO ===" << endl;
        cout << "ONG " << nomeONG << " com a sua colaboração, organizou reflorestamento de áreas degradadas!" << endl;
        cout << "Voluntários prontos para plantar árvores nativas portuguesas" << endl << endl;
        cout << "\033[32m" << "  Arvores ja plantadas:                         \n\n";
        cout << "      ^^^          ^^^          ^^^             \n";
        cout << "     ^^^^^        ^^^^^        ^^^^^            \n";
        cout << "    ^^^^^^^      ^^^^^^^      ^^^^^^^           \n";
        cout << "      |||          |||          |||             \n";
        cout << "      |||          |||          |||             \n";
     cout << "  ============================================== \n" <<" \033[0m" << endl;
        cout << "\n";
        
        sleep(1);
        
        int voluntarios = 10 + (rand() % 21);
        int arvores = voluntarios * (2 + (rand() % 3));
        int bonusHPLocal = arvores / 10;
     
        arvoresPlantadas += arvores;
        bonusHP += bonusHPLocal;
        j.addHP(bonusHP);
        j.addATK(2);
        
        
        cout << "Voluntários: " << voluntarios << endl;
        cout << "Árvores plantadas: " << arvores << endl;
        cout << "Bônus Vida no Planeta: " << bonusHP << endl << endl;
    
        cout << " Recompensas:" << endl;
        cout << "   + " << bonusHP << " de Bônus pela Vida no Planeta (floresta fortalecida)" << endl;
        cout << "   + " << bonusXP << " de Bônus pelo plantio de novas Árvores" << endl;
        cout << "   Total plantado pela ONG: " << arvoresPlantadas << " árvores" << endl;
        cout << "====================================================" << endl;
        cout << "**##** Parabéns você concluiu mais uma etapa!! **##**" << endl;
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
        
        
        sleep(4);
    }
  
  void salvarONG() const {
    string nomeFile = "ong_guardioesverdes.sav";
    ofstream out(nomeFile);
    out << "NomeONG: " << nomeONG << endl
        << "Palestras: " << palestrasRealizadas << endl
        << "Arvores: " << arvoresPlantadas << endl
        << "Conhecimento: " << bonusXP << endl
        << "Vida: " << bonusHP << endl;
    out.close();
}

bool carregarONG() {
    string nomeFile = "ong_guardioesverdes.sav";
    ifstream in(nomeFile);
    if (!in) {
        return false;
    }
    
      string linha;
      getline(in, linha);
    
    string rotulo;
    in >> rotulo >> palestrasRealizadas;
    in >> rotulo >> arvoresPlantadas;
    in >> rotulo >> bonusXP;
    in >> rotulo >> bonusHP;
    in.close();
    return true;
    
}
    
private:
    string nomeONG;
    int palestrasRealizadas;
    int arvoresPlantadas;
    int bonusXP;
    int bonusHP;
};

void sistemaExperiencia(Personagem &j){
    int toLvUP, levelUP;
    levelUP = (j.getLv() + 1) * 100;
    toLvUP = j.getXP();
    
    if (toLvUP >= levelUP){
        cout << "Parabéns! Você subiu para um próximo nível como Guardiao da Floresta!" << endl;
        j.addLv(1);
        j.setHP(90 + (j.getLv() * 10));
        j.addATK(2);
        j.addDEF(1);
        sleep(2);
    }
}

void fase1Combate(Personagem &j, Personagem &m, int &rondas){
    int danoJogador = 0, danoFogos = 0, fator = 0;
    
    clear();
    cout << "=== FASE 1: DETECCÃO PRECOCE ===" << endl << endl;
        cout << "\033[32m" << R"(  "Você é um 'Bombeiro Voluntário' - vigia estradas e torres de vigilância para identificar fogos nas florestas, provocados por inúmeros fatores ..."
          ___
         /   \
        | O O |
         \___/
          |||
         /|||\
        ///|||\\
      O========\\========O
        | ||| |
        | ||| |                
          | |                    
         /| |\
)" << "\033[0m" << endl;    cout << "\033[31m" << R"(
                                 )  (  )  (
                                (  )  ) (  )
                                  ) ( ) (  (
                                _____________
                               <_____________>
                               |   FOGOS    |
                               |_____________|
                               )" << "\033[0m" << endl;
   
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para INICIAR A SUA VIGILÂNCIA 👀 )===" << endl;
        cout << "====================================================" << endl;
    clear();
    
    while(j.getHP() > 0 && m.getHP() > 0){
        rondas += 1;
        
        fator = 50 + (rand() % 101);
        danoJogador = ((j.getATK() * fator) / 100) - m.getDEF();
        
        
        if(danoJogador < 0) { danoJogador = 0; }
        
        
        cout << "Rodada " << rondas << ":" << endl;
        cout << "\033[32m" << "Você em conjunto com outros 'Bombeiros Voluntários' detectam um grande foco de incêndio: " << endl;
        cout << "Você de imediato, corre a sua viatura e liga chamando por reforços (PORTUGAL CHAMA - 112) - desgaste de: " << danoJogador << "!" << "\033[0m" << endl;
        m.addHP(-danoJogador);
        cout << "Força dos Fogos: " << m.getHP() << endl << endl;
        if(m.getHP() <= 0) break;
        
        fator = 50 + (rand() % 101);
        danoFogos = ((m.getATK() * fator) / 100) - j.getDEF();
        if(danoFogos < 0) { danoFogos = 0;}
        
        cout << "\033[31m" << "O foco de fogos florestal identificado por vocês, continuam a se alastrar com fortes chamas!!" << endl;
        cout << "Apesar de seu esforço, a demora da chegada de reforços ao local está a agravar a situação - causando dano de " << danoFogos << "!" << "\033[0m" << endl;
        j.addHP(-danoFogos);
        cout << "Sua Vida Atual: " << j.getHP() << "\033[0m" << endl << endl;
       
       sleep(1);
    }
    
    if(j.getHP() <= 0){
        cout << "\033[35m" << "DERROTA NA FASE 1! Os Fogos se alastram pela floresta e os bombeiros ainda não chegaram ao local!" << endl << endl;
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
        
    }
    else{
        cout << "VITÓRIA NA FASE 1! Os Bombeiros da Capital chegam ao local rapidamente e controlam o incêndio!" << "\033[0m" << endl << endl;
    }
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
    
}

void fase2Imobilizacao(Personagem &j, Personagem &m, int &rondas){
    int danoJogador = 0, danoFogos = 0, fator = 0;
    
    m.setHP(50);
    j.setHP(100);
    
    clear();
    cout << "=== FASE 2: RECONHECIMENTO DO TERRENO ===" << endl << endl;
    cout << "\033[32m" << R"( "Você é um 'Bombeiro Voluntário' - Agora em conjunto com colegas voluntários, vocês passam a explorar locais florestais, seja a pé ou com o auxílio de drones, para mapear e registar perigos e rotas seguras..."
          ___
         /   \
        | O O |
         \___/
          |||
         /|||\
        ///|||\\
      O========\\========O
        | ||| |
        | ||| |                
          | |                    
         /| |\
)" << "\033[0m" << endl;    cout << "\033[31m" << R"(
                                 )  (  )  (
                                (  )  ) (  )
                                  ) ( ) (  (
                                _____________
                               <_____________>
                               |   FOGOS    |
                               |_____________|
                               )" << "\033[0m" << endl;
    
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para INICIAR O MAPEAMENTO DO TERRENO 🔍🗺 ) ===" << endl;
        cout << "====================================================" << endl;
    
    clear();
    
    while(j.getHP() > 0 && m.getHP() > 0){ 
        rondas += 1;
        
        fator = 50 + (rand() % 101);
        danoJogador = ((j.getATK() * fator) / 100) - m.getDEF();
        if(danoJogador < 0) { danoJogador = 0; }
        
        cout << "Rodada " << rondas << ":" << endl;
        cout << "\033[32m" << "Você em conjunto com outros 'Bombeiros Voluntários', investiram em novos recursos," << endl;
        cout << "Estão à percorrer as florestas, a pé, também a usar drones para mapear o terreno, encontraram novo foco, provocando um desgaste: " << danoJogador << "\033[0m" << endl;
        m.addHP(-danoJogador);
        cout << "Força dos Fogos: " << m.getHP() << endl << endl;
        if(m.getHP() <= 0) break;
        
        fator = 50 + (rand() % 101);
        danoFogos = ((m.getATK() * fator) / 100) - j.getDEF();
        if(danoFogos < 0) { danoFogos = 0; }
        
        cout << "\033[31m" << "Você ainda não terminou de mapear o terrreno conforme o planejado seus colegas, mas" << endl;
        cout << "os Fogos avançam com muita velocidade, aumentando assim, o dano florestal em " << "\033[0m" << danoFogos << "!" << endl;
        j.addHP(-danoFogos);
        cout << "Sua Vida Atual: " << j.getHP() << endl << endl;
        
        sleep(1);
    }
    
    if(j.getHP() <= 0){
       cout << "\033[35m" << "DERROTA NA FASE 2! Os fogos se alastram de forma descontrolada pela floresta, você e seus colegas não concluíram o mapeamento!" << endl;
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
    
        
    }
    else{
        cout << "VITÓRIA NA FASE 2! Você e seus colegas 'Bombeiros Voluntários' conseguiram mapear o local e contribuiu com o controle dos fogos!" << "\033[0m" << endl << endl;
    }
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
    
}
    
void fase3Autoridades(Personagem &j, Personagem &m, int &rondas){
    int danoJogador = 0, danoFogos = 0, fator = 0;
    
    m.setHP(50);
    j.setHP(100);
    
    clear();
    cout << "=== FASE 3: ATAQUE INICIAL RÁPIDO ===" << endl << endl;
    cout << "\033[32m" << R"( Após alguns fogos apagados, surge mais um novo foco de incêndio 'pequeno', mas que necessita de uma ação rápida por parte de você e de seus colegas 'Bombeiros Voluntários', pois o fogo já está a ameaçar 'Moradas'! iniciem imediatamente ação de combate ao fogo, com as ferramentas e recursos que tiverem disponíveis!!
           ___
         /   \
        | O O |
         \___/
          |||
         /|||\
        ///|||\\
      O========\\========O
        | ||| |
        | ||| |                
          | |                    
         /| |\
)" << "\033[0m" << endl;    cout << "\033[31m" << R"(
                                 )  (  )  (
                                (  )  ) (  )
                                  ) ( ) (  (
                                _____________
                               <_____________>
                               |   FOGOS    |
                               |_____________|
                               )" << "\033[0m" << endl;
    
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para INICIAR UM ATAQUE RÁPIDO AOS FOGOS 🚀🚒 ) ===" << endl;
        cout << "====================================================" << endl; 
    
   clear();
    
    m.addHP(-danoJogador);
    while(j.getHP() > 0 && m.getHP() > 0){ 
        rondas += 1;
        
        fator = 50 + (rand() % 101);
        danoJogador = ((j.getATK() * fator) / 100) - m.getDEF();
        if(danoJogador < 0) { danoJogador = 0; }
        
        cout << "Rodada " << rondas << ":" << endl;
        cout << "\033[32m" << "Você e colegas 'Bombeiros Voluntários', buscaram pelos meios disponíveis em suas proximidades, " << endl;
        cout << "'baldes, enchadas, pás, mangueiras de vizinhos', para bloquear o avanço das chamas " << "\033[0m" << danoJogador << "!" << endl;
        m.addHP(-danoJogador);
        cout << "Força dos FOGOS: " << m.getHP() << endl << endl;
        
        if(m.getHP() <= 0) break;
        
        fator = 50 + (rand() % 101);
        danoFogos = ((m.getATK() * fator) / 100) - j.getDEF();
        if(danoFogos < 0) { danoFogos = 0; }
        cout << "\033[31m" << "O pequeno foco de incêndio está a aumentar e se aproximar perigosamente de algumas 'Moradas'!, " << endl;
        cout << "Os'Bombeiros Voluntários' continuam a se esforçar, para evitar o mal maior ? dano provisório de " << "\033[32m"  << danoFogos << "!" << endl;
        j.addHP(-danoFogos);
        cout << "Sua Vida Atual: " << j.getHP() << endl << endl;
     
        sleep(2);
    }
    
    if(j.getHP() <= 0){
        cout << "\033[35m" << "DERROTA NA FASE 3! Apesar de todos os esforços dos 'Bombeiros Voluntários' os fogos florestais continuam a se alastrar!" << endl << endl;
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
    
    }
    else{
        cout << "VITÓRIA NA FASE 3! Você e seus colegas 'Bombeiros Voluntários' conseguiram! controlaram os fogos rapidamente por meio dos recursos limitados que possuíam!" << "\033[0m" << endl << endl;
    }
    
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
    
}
   
void fase4Aceiros(Personagem &j, Personagem &m, int &rondas){
    int danoJogador = 0, danoFogos = 0, fator = 0;
    
    m.setHP(50);
    j.setHP(100);
    
    clear();
    cout << "=== FASE 4: CONSTRUCÃO DE ACEIROS ===" << endl << endl;
   
     cout << "\033[32m" << R"( Após o devido mapeamento do terreno, realizada por você e sua dedicada equipa!, Você e os 'Bombeiros Voluntários' precisam ainda, abrir alguns ACEIROS, CAVES e VALAS corta-fogo, com o auxílio de tratores e outras ferramentas disponíveis, para fins de evitar o alastramento dos fogos.
          ___
         /   \
        | O O |
         \___/
          |||
         /|||\
        ///|||\\
      O========\\========O
        | ||| |
        | ||| |                
          | |                    
         /| |\
)" << "\033[0m" << endl;    cout << "\033[31m" << R"(
                                 )  (  )  (
                                (  )  ) (  )
                                  ) ( ) (  (
                                _____________
                               <_____________>
                               |   FOGOS    |
                               |_____________|
                               )" << "\033[0m" << endl;
    
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para INICIAR UM ATAQUE RÁPIDO AOS FOGOS ⛏️🚜🛡 ) ===" << endl;
        cout << "====================================================" << endl;
    
    
    clear();
    
    while(j.getHP() > 0 && m.getHP() > 0){ 
        rondas += 1;
        
        fator = 50 + (rand() % 101);
        danoJogador = ((j.getATK() * fator) / 100) - m.getDEF();
        if(danoJogador < 0) { danoJogador = 0; }
        
        cout << "Rodada " << rondas << ":" << endl;
        cout << "\033[32m" << "Você em conjunto com colegas 'Bombeiros Voluntários' utilizaram de todos os recursos e ferramentas disponíveis," << endl;
        cout << "para abrir aceiros, caves e valas corta-fogo, no intuito de bloquear o avanço das chamas! o desgaste foi:" << "\033[0m" << danoJogador << "!" << endl;
        m.addHP(-danoJogador);
        cout << "Força dos FOGOS: " << m.getHP() << endl << endl;
        if(m.getHP() <= 0) break;
        
        fator = 50 + (rand() % 101);
        danoFogos = ((m.getATK() * fator) / 100) - j.getDEF();
        if(danoFogos < 0) { danoFogos = 0; }
        
        cout << "\033[31m" << "Apesar de todos os aceiros construídos, os 'Fogos' continuam a se alastrar rapidamente," << endl;
        cout << "mas você em conjunto com colegas, 'Bombeiros Voluntários', continuam a trabalhar no local!: dano provisório: " << "\033[0m" << danoFogos << "!" << endl;
        cout << "Sua Vida Atual: " << j.getHP() << endl << endl;
  
        j.addHP(-danoFogos);
        sleep(1);
    }
    
    if(j.getHP() <= 0){
        cout << "DERROTA NA FASE 4! Apesar de todo o seu esforço conjunto com os bombeiros sepadores, os fogos florestais continuam a se alastrar!" << endl << endl;
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
    
    }
    else{
        cout << "VITÓRIA NA FASE 4! Você conseguiu controlar os fogos florestais!! por meio das valas corta-fogo, feitas por meio de tratores e pá !" << endl << endl;
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
    
    }
   
    sleep(1);
}

void resultFinal(Personagem &j, Personagem &m, int &rondas){
    if (j.getHP() <= 0){
        cout << "DERROTA! Você foi derrotado pelos FOGOS FLORESTAIS. A floresta agora está em risco maior... Tente novamente retornar ação!" << endl;
        j.clearHP();
    }
    else if (m.getHP() <= 0){
        int xpGanho = rondas * 10 + m.getLv() * 5;
        cout << "\033[32m" << R"( VITÓRIA!!! Finalmente, você derrotou os FOGOS FLORESTAIS e protegeu a floresta portuguesa. De acordo com as leis portuguesas contra fogos, açoes como essa salvam vidas e ecossistemas! Por isso, você ganhou pontos extras por sua coragem! 🦁 )" << "\033[0m" << endl << endl;
        j.addXP(xpGanho);
        sistemaExperiencia(j);
        
        cout << "\n========== STATUS FINAL ==========" << endl;
        cout << "\nResultados: N. de Rondas: " << rondas << endl;
        j.menuStatus();
        m.menuStatusFogos();
    }
}

void inicializarJogador(Personagem &j) {
    if(!j.loadFile()){
        cout << "Vamos criar um novo Guardião da Floresta." << endl;
        j.setLv(1);
        j.setHP(100);
        j.setATK(15);
        j.setDEF(5);
        sleep(2);
    }
    else{
        cout << "Bem-vindo de volta, Guardião da Floresta!" << endl;
        sleep(2);
    }
}

void inicializarONG(ONG &ong) {
    if(ong.carregarONG()){
        cout << "Progresso da ONG 'Guardiões Verdes' carregado com sucesso!" << endl;
        sleep(2);
    }
    else{
        cout << "Iniciando nova campanha da ONG 'Guardiões Verdes'." << endl;
        sleep(1);
    }
}


void mostrarStatusInicial(Personagem &j, ONG &ong) {
    clear();
    cout << "\033[32m" <<"\n========== STATUS INICIAL DO JOGO ==========" << "\033[0m" << endl << endl;
    j.menuStatus();
    cout << endl;
    ong.menuStatusONG();
        cout << "====================================================" << endl;
        cout << "=== DIGITE - ENTER (para continuar) ===" << endl;
        cout << "====================================================" << endl;
    clear();
}

Personagem criarInimigo() {
    Personagem m("FOGOS FLORESTAIS");
    m.setLv(1);
    m.setHP(50);
    m.setATK(20);
    m.setDEF(2);
    return m;
}

void mensagemTransicao(int numeroFase) {
    cout << "===================================================" << endl;
    cout << "**##** Voce avança para a Fase " << numeroFase << "!"<< endl;
    cout << "===================================================" << endl;
   
   
    sleep(3);
}

int exibirMenu() {
    int escolha;
    cout << "\033[32m" << "\n=== JOGO EDUCATIVO - SEJA UM GUARDIAO DA FLORESTA ===" << "\033[0m"<< endl << endl;
    cout << "\n=== ESCOLHA UMA FASE E COMBATA AOS FOGOS NAS FLORESTAS  ===" << endl;
    cout << "Escolha uma das opcões: (1, 2, 3, 4, 5, 6, 7 ou 8): " << endl;
    cout << "\n== ETAPA 1 - BOMBEIRO VOLUNTÁRIO == (Save Pessoal) " << endl;
    cout << "1. FASE 1 - Detecao precoce de Fogos (👀🔥)" << endl;
    cout << "2. FASE 2 - Reconhecimento do Terreno (🔍🗺️ )" << endl;
    cout << "3. FASE 3 - Ataque Inicial Rápido (🚀🚒 )" << endl;
    cout << "4. FASE 4 - Construcao de Aceiros (⛏️🚜🛡)" << endl << endl;
    cout << "== ETAPA 2 - COLABORADOR ONG - 'GUARDIÕES VERDES' == (Save Pessoal/ONG) "<< endl;
    cout << "5. FASE 5 - Realizar Palestra nas Juntas (🎓)" << endl;
    cout << "6. FASE 6 - Organizar Mutirão de Plantio (🌱 )" << endl << endl;
    cout << "=== JOGO COMPLETO - VOLUNTÁRIO E COLABORADOR-ONG = (Save Pessoal/ONG)" << endl;
    cout << "7. Jogar TODAS as fases na sequência" << endl;
    cout << "8. Sair do Jogo" << endl;
    cout << "Digite aqui -->";
    cin >> escolha;
    return escolha;
}


void jogarTodasFases(Personagem &j, Personagem &m, ONG &ong, int &rondas) {
    fase1Combate(j, m, rondas);
    if(j.getHP() <= 0) return;
    
    mensagemTransicao(2);
    fase2Imobilizacao(j, m, rondas);
    if(j.getHP() <= 0) return;
    
    mensagemTransicao(3);
    fase3Autoridades(j, m, rondas);
    if(j.getHP() <= 0) return;
    
    mensagemTransicao(4);
    fase4Aceiros(j, m, rondas);
    if(j.getHP() <= 0) return;
    
    mensagemTransicao(5);
    ong.realizarPalestra(j);
    if(j.getHP() <= 0) return;
    
    sleep(3);
    ong.mutiraoPlantio(j);
}

void processarEscolha(int escolha, Personagem &j, Personagem &m, ONG &ong, int &rondas) {
    switch(escolha) {
        case 1:
            fase1Combate(j, m, rondas);
            break;
        case 2:
            fase2Imobilizacao(j, m, rondas);
            break;
        case 3:
            fase3Autoridades(j, m, rondas);
            break;
        case 4:
            fase4Aceiros(j, m, rondas);
            break;
        case 5:
            ong.realizarPalestra(j);
            break;
        case 6:
            ong.mutiraoPlantio(j);
            break;
        case 7:
            jogarTodasFases(j, m, ong, rondas);
            break;
        case 8:
            cout << "Saindo do jogo..." << endl;
            sleep(1);
            break;
        default:
            cout << "Opção inválida! Saindo..." << endl;
            sleep(1);
    }
}

void finalizarJogo(Personagem &j, Personagem &m, ONG &ong, int rondas, int escolha) {
    clear();
    resultFinal(j, m, rondas);
    
    
    if(escolha == 5 || escolha == 6 || escolha == 7) {
        ong.menuStatusONG();
        ong.salvarONG();
    }
    
    j.saveFile();
}

    
    
int main(){
    srand(time(0));
    
    string nome;
    int rondas = 0;
    
    cout << "Bem-vindo, Cidadão (Guardião da Floresta)!!" << endl;
    cout << "Informe o seu nome: " << endl; 
    cout << "Digite aqui -->";
    cin >> nome;
    
    Personagem j(nome);
    ONG ong("Guardioes Verdes");
    
    inicializarJogador(j);
    inicializarONG(ong);
    mostrarStatusInicial(j, ong);
    
    Personagem m = criarInimigo();

  
   int escolha = exibirMenu();
   if(escolha == 8) {
        cout << "Saindo do jogo..." << endl;
        sleep(1);
        return 0;
    }
    
    processarEscolha(escolha, j, m, ong, rondas);
    if(escolha != 8) {
        finalizarJogo(j, m, ong, rondas, escolha);
    }
    
    return 0;
}