https://www.onlinegdb.com/Nq6bBiRf-

/******************************************************************************

LINK: 

*******************************************************************************/
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime> // srand(time(0));
#include <fstream> // save/load
#include <iomanip>
#include <cmath>
#include <chrono>
#include <thread>
#include <sstream>
#include <vector>
#include <cctype> 
#include <random>
#include <SnakeGame.h>
using namespace std;
                                                                                //VOID
void clear(int segundos){
    sleep(segundos);
    cout << "\x1b[2J\x1b[H";
}
                                                                                //CLASS
class Jogador{
public:
    explicit Jogador(const string& nome): nome(nome), A(0), B(0), C(0) {}
    
    void setA(int fixo) {A = fixo;}
    void addA(int add) {A += add;} 
    void subA(int sub) {A -= sub;}
    
    void setB(int fixo) {B = fixo;}
    void addB(int add) {B += add;}
    void subB(int sub) {B -= sub;}
    
    void setC(int fixo) {C = fixo;}
    void addC(int add) {C += add;}
    void subC(int sub) {C -= sub;}
    
    void menuStatus(){
        clear(2);
        cout << "Jogador:     " << nome << endl;
        cout << "HP/ATK/DEF:  " << A << "/" << B << "/" << C << endl << endl;
    }
    
    void saveFile() const {
        string nomeFile = nome + ".sav";
        ofstream out(nomeFile);
        out << nome << endl
            << A << endl
            << B << endl
            << C << endl;
    }
    
    bool loadFile() {
        string nomeFile = nome + ".sav";
        ifstream in(nomeFile);
        if (!in){
            return false;
        }
        in  >> nome 
            >> A 
            >> B 
            >> C;
            
        return true;
    }
    
    
private:
    string nome;
    int A,B,C;
};
                                                                                //1 - JOAO SILVA
int joaoSilva() {
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
    int opcao;

    do {
        cout << CYAN << "\n===== MENU PRINCIPAL =====" << RESET << endl;
        cout << YELLOW << "1. Calcular prestacao e tabela" << RESET << endl;
        cout << YELLOW << "2. Sobre o programa" << RESET << endl;
        cout << YELLOW << "0. Sair" << RESET << endl;

        cout << MAGENTA << "Escolha uma opcao: " << RESET;
        cin >> opcao;

        if (opcao == 1) {

            double montante, taxaAnual, taxaMensal, prestacao;
            int meses;

            cout << CYAN << "\n===== CALCULO DE PRESTACAO DE EMPRESTIMO =====" << RESET << endl;

            cout << YELLOW << "Montante do emprestimo (€): " << RESET;
            cin >> montante;

            cout << YELLOW << "Taxa de juro anual (%): " << RESET;
            cin >> taxaAnual;

            cout << YELLOW << "Numero de meses: " << RESET;
            cin >> meses;

            taxaMensal = (taxaAnual / 100.0) / 12.0;

            // Fórmula da prestação mensal
            prestacao = montante * taxaMensal / (1 - pow(1 + taxaMensal, -meses));

            cout << "\n" << GREEN << "Prestacao mensal: "
                 << fixed << setprecision(2) << prestacao << " €" << RESET << "\n\n";

            cout << MAGENTA << "===== TABELA DE AMORTIZACAO =====" << RESET << endl;

            cout << CYAN
                 << left << setw(10) << "Mes"
                 << setw(15) << "Prestacao"
                 << setw(15) << "Juros"
                 << setw(15) << "Amortiz."
                 << setw(15) << "Saldo" << RESET << endl;

            double saldo = montante;

            for (int i = 1; i <= meses; i++) {
                double juros = saldo * taxaMensal;
                double amortizacao = prestacao - juros;
                saldo -= amortizacao;

                if (saldo < 0) saldo = 0;

                cout << left << setw(10) << i
                     << setw(15) << prestacao << "€"
                     << setw(15) << juros << "€"
                     << setw(15) << amortizacao << "€"
                     << setw(15) << saldo << "€" << endl;
            }

            cout << GREEN << "\nTabela concluida!" << RESET << endl;

        } 
        else if (opcao == 2) {
            cout << GREEN
                 << "\nPrograma desenvolvido para calculo de emprestimos,"
                 << "\ncom tabela de amortizacao e interface em menu."
                 << "\nAutor: Joao Silva\n"
                 << RESET;
        } 
        else if (opcao == 0) {
            cout << RED << "\nA sair do programa..." << RESET << endl;
        } 
        else {
            cout << RED << "Opcao invalida! Tente novamente." << RESET << endl;
        }

    } while (opcao != 0);

    return 0;
}
                                                                                //2 - Sandra Mota
void sandraMota() {
    srand(time(0));
    string simbolos[] = {"🍒", "🔔", "💎", "🍋", "⭐"};
    string nome;
    int creditos;
    int aposta = 10;
    char jogar;

    cout << "Bem-vindo(a)! Qual é o teu nome? ";
    cin >> nome;
    
    // Load File
    string nomeFile = nome + ".sav";
    ifstream in(nomeFile);
    if (in) {
        in >> creditos;
        cout << endl<<"Olá novamente, " << nome << "! Créditos disponíveis: " << creditos << "€"<< endl;
        in.close();
        sleep(2);
    } else {
        creditos = 50;
        cout << endl<< "Novo jogador criado: " << nome << " com " << creditos << "€ de créditos."<< endl;
        sleep(2);
    }

    do {
        clear(1);
        cout << "\033[38;5;208m*****************************************\033[0m\n";
        cout << "\033[38;5;208m*    \033[0m 🎰 \033[1;35mSANDRA'S SLOT MACHINE\033[0m 🎰 \033[38;5;208m        *\033[0m\n";
        cout << "\033[38;5;208m*****************************************\033[0m\n";

        cout << "Jogador: \033[1;36m" << nome << "\033[0m" << endl;
        cout << "Créditos: \033[1;32m" << creditos << "€\033[0m | Aposta: \033[4m" << aposta << "€\033[0m" << endl << endl;
        cout << "Desejas jogar? (s/n): " << endl;
        cin >> jogar;

        if (jogar == 's' || jogar == 'S') {
            if (creditos < aposta) {
                cout << "\033[1;31mCréditos insuficientes!\033[0m" << endl;
                break;
            }

            creditos -= aposta;
            clear(2);
            cout << "\n         A girar..." << endl;
            clear(2);

            string s1 = simbolos[rand() % 5];
            string s2 = simbolos[rand() % 5];
            string s3 = simbolos[rand() % 5];
            
            cout << endl << "         \033[1;33m[ " << s1 << "  ] [ " << s2 << "  ] [ " << s3 << "  ]\033[0m" << endl;

            if (s1 == s2 && s2 == s3) {
                cout << endl<< "            \033[1;32mJACKPOT! +50€\033[0m" << endl;
                creditos += 50;
            } else if (s1 == s2 || s2 == s3 || s1 == s3) {
                cout << endl<< "         \033[1;34mDois iguais! +20€\033[0m" << endl;
                creditos += 20;
            } else {
                cout << endl<< "     \033[1;31mNada feito... tenta outra vez!\033[0m" << endl;
            }

            cout << endl<< "Clica ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            clear(0);
        }

    } while ((jogar == 's' || jogar == 'S') && creditos >= aposta);

    // Save FIle
    ofstream out(nomeFile);
    out << creditos;
    out.close();

    cout << "\n\033[1;36mJogo terminado. Créditos finais guardados: " << creditos << "€\033[0m" << endl;
}
                                                                                //3 - Tatiana tatianaNascimento
void tatianaNascimento() {
    clear(1);
    string nome;
    Jogador j(nome);
    cout << "****Jogo Menu Saudavel Da Semana da Tatiana do Nascimento****\n\n";

    for (int dia = 1; dia <= 7; dia++) {
        clear(1);
        cout << "------- DIA " << dia << "\n\n";

        int escolha;

        cout << "Pequeno-almoço:\n";
        cout << "1 - Iogurte com frutas\n";
        cout << "2 - Tosta mista\n";
        cout << "3 - Fast food\n";
        cout << "Escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1: j.addA(10); break;
            case 2: j.addB(3); break;
            case 3: j.subC(10); break;
        }

        cout << "\nAlmoço:\n";
        cout << "1 - Frango grelhado com salada\n";
        cout << "2 - Massa à bolonhesa\n";
        cout << "3 - Hambúrguer industrial\n";
        cout << "Escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1: j.addA(10); break;
            case 2: j.addB(5); break;
            case 3: j.addC(-10); break;
        }

        cout << "\nJantar:\n";
        cout << "1 - Sopa de legumes\n";
        cout << "2 - Omelete\n";
        cout << "3 - Pizza congelada\n";
        cout << "Escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1: j.addA(5); break;
            case 2: j.addB(3); break;
            case 3: j.addC(-5); break;
        }

        cout << "\nResumo do dia " << dia << ":\n";
        j.menuStatus();
        sleep(2);
    }

    cout << "\n===== FIM DA SEMANA =====\n";
    j.menuStatus();
    cout << "Boa semana saudável!\n";
}
                                                                                //4 - Marcos Araujo
void marcosAraujo() {

    // ------------------- Ler ano do utilizador -----------------------
    int ano_alvo;
    cout << "Digite o ano de destino: ";
    cin >> ano_alvo;

    if (ano_alvo <= 1900) {
        cout << "Ano inválido! Encerrando programa.\n";
    }

    ofstream file("resultado.txt");

    // --------------------- Data atual -------------------------------
    time_t now = time(nullptr);
    tm *now_tm = localtime(&now);

    // --------------------- Data alvo --------------------------------
    tm target_tm = {};
    target_tm.tm_year = ano_alvo - 1900;
    target_tm.tm_mon  = 0;   // Janeiro
    target_tm.tm_mday = 1;   // Dia 1
    target_tm.tm_hour = 0;
    target_tm.tm_min  = 0;
    target_tm.tm_sec  = 0;

    time_t target_time = mktime(&target_tm);

    auto printSave = [&](const string &t){
        cout << t << endl;
        file << t << endl;
    };

    if (now >= target_time) {
        printSave("Esse ano já começou!");
        file.close();
    }

    // --------------------- Diferença total ---------------------------
    long long diff = difftime(target_time, now);
    long long seconds = diff;
    long long minutes = seconds / 60;
    long long hours   = minutes / 60;
    long long days    = hours / 24;
    long long weeks   = days / 7;

    // ---------------- Cálculo exato Y/M/D ----------------------------
    int y = now_tm->tm_year + 1900;
    int m = now_tm->tm_mon + 1;
    int d = now_tm->tm_mday;

    int anos, meses, dias;

    int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    auto isLeap = [&](int year){
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    };

    if (isLeap(y)) mdays[1] = 29;

    anos  = ano_alvo - y;
    meses = 1 - m;   // janeiro → mês 1
    dias  = 1 - d;

    if (dias < 0) {
        int idx = (m - 2 + 12) % 12;
        dias += mdays[idx];
        meses--;
    }

    if (meses < 0) {
        meses += 12;
        anos--;
    }

    // --------------------- Saída ------------------------------------
    printSave("Tempo até 1 de janeiro de " + to_string(ano_alvo) + ":\n");

    printSave("Anos:    " + to_string(anos));
    printSave("Meses:   " + to_string(meses));
    printSave("Dias:    " + to_string(dias));
    printSave("");

    printSave("Dias totais:    " + to_string(days));
    printSave("Semanas totais: " + to_string(weeks));
    printSave("Horas totais:   " + to_string(hours));
    printSave("Minutos totais: " + to_string(minutes));
    printSave("Segundos:       " + to_string(seconds));
    clear(10);
}
                                                                                //5 - Ricardo Branco
void ricardoBranco() {
    double depositoMensal, taxaAnual, taxaMensal;
    int anos;
    
    cout << "==== CALCULO DE INVESTIMENTO ====" << endl;
    
    cout << "Quanto vais depositar mensalmente (€): ";
    cin >> depositoMensal;
    
    cout << "Duracao (anos): ";
    cin >> anos;
    
    cout << "Taxa de juro anual (%): ";
    cin >> taxaAnual;
    
    // Conversão
    taxaMensal = (taxaAnual / 100.0) / 12.0;
    
    double saldo = 0;
    double totalDepositado = 0;
    
    cout << "\n===== EVOLUCAO DO INVESTIMENTO =====" << endl;
    cout << left << setw(8) << "Ano"
         << right << setw(20) << "Total Investido"
         << setw(20) << "Juros Ganhos"
         << setw(20) << "Saldo Total" << endl;
    
    // Calcular mês a mês, mas mostrar anualmente
    for (int ano = 1; ano <= anos; ano++) {
        for (int mes = 1; mes <= 12; mes++) {
            // Adicionar juros ao saldo atual
            saldo += saldo * taxaMensal;
            
            // Adicionar depósito mensal
            saldo += depositoMensal;
            totalDepositado += depositoMensal;
        }
        
        double jurosGanhos = saldo - totalDepositado;
        
        cout << left << setw(8) << ano
             << right << setw(17) << fixed << setprecision(2) << totalDepositado << " €"
             << setw(17) << jurosGanhos << " €"
             << setw(17) << saldo << " €" << endl;
    }
    
    double jurosTotal = saldo - totalDepositado;
    
    cout << "\n===== RESUMO FINAL =====" << endl;
    cout << "Total investido: " << fixed << setprecision(2) << totalDepositado << " €" << endl;
    cout << "Juros ganhos: " << jurosTotal << " €" << endl;
    cout << "Saldo final: " << saldo << " €\n" << endl;
    
    clear(5);
}
                                                                                //6 - Goncalo Lionco
void goncaloLionco() {
    srand(time(0));

    cout << "🔪 Jogo da Lâmina - Corte os objetos antes que caiam!\n";
    cout << "Pressione a tecla correta o mais rápido possivel.\n";
    cout << "---------------------------------------------------\n";

    int score = 0;
    int rounds = 5; // número de objetos que vão cair

    for (int i = 1; i <= rounds; i++) {
        char objeto = 'A' + rand() % 26; // objeto aleatório (letra)
        cout << "\nObjeto #" << i << " está a cair: [" << objeto << "]\n";

        // tempo inicial
        auto start = chrono::steady_clock::now();

        char resposta;
        cout << "Digite a letra para cortar: ";
        cin >> resposta;

        // tempo final
        auto end = chrono::steady_clock::now();
        auto duracao = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        if (resposta == objeto && duracao <= 2000) { // 2 segundos para reagir
            cout << "✅ Cortou a tempo! (" << duracao << " ms)\n";
            score++;
        } else if (resposta == objeto) {
            cout << "⏱ Cortou, mas demasiado lento (" << duracao << " ms)\n";
        } else {
            cout << "❌ Errou o corte!\n";
        }
    }

    cout << "\nFim do jogo! Pontuacao final: " << score << " / " << rounds << "\n";
    if (score == rounds) cout << "🥇 Mestre da Lâmina!\n";
    else if (score >= rounds/2) cout << "👍 Bom desempenho!\n";
    else cout << "😅 Precisa de treinar mais...\n";
}
                                                                                //7 - Helga Martins!!!
void helgaMartins(){
#define COR_RESET   "\x1b[0m"
#define COR_VERMELHO "\x1b[31m"
#define COR_VERDE   "\x1b[32m"
#define COR_AMARELO "\x1b[33m"
#define COR_AZUL    "\x1b[34m"
#define COR_ROXO    "\x1b[35m"
#define COR_CIANO   "\x1b[36m"
#define COR_LARANJA "\x1b[38;5;208m"
    int posicaoMacaco, atirar, tentativas, pontos = 0, nivel = 1;
    int maxPosicoes = 5;
    bool usouBinoculo = false, usouBananaDupla = false;
    char jogarNovamente;
    
    //  INTRODUÇÃO 
    clear(0);
    cout << COR_AMARELO << "\n";
    cout << "    ███████████████████████████████████\n";
    cout << "    █                                  █\n";
    cout << "    █   🍌  ACERTA NO MACACO!  🐵        █\n";
    cout << "    █                                  █\n";
    cout << "    ███████████████████████████████████\n";
    cout << COR_RESET << "\n";
    sleep(1);
    
    cout << COR_CIANO << "📖 HISTÓRIA:\n" << COR_RESET;
    cout << "   O macaco KoméPah roubou TODAS as tuas bananas! 😱\n";
    sleep(2);
    cout << "   Agora ele está a gozar contigo escondido\n";
    cout << "   entre as palmeiras...\n";
    sleep(2);
    cout << COR_VERDE << "\n   🎯 A TUA MISSÃO: \n" << COR_RESET;
    cout << "   Recupera as bananas atirando-as no macaco!\n";
    sleep(2);
    cout << COR_AMARELO << "\n   ⚠️  MAS CUIDADO: " << COR_RESET;
    cout << "Ele é MUITO esperto! 🧠\n";
    sleep(2);
    
    cout << COR_ROXO << "\n\n   [ENTER para começar a aventura]" << COR_RESET;
    cin.ignore();
    cin.get();
    
    //  ESCOLHA DE DIFICULDADE
    clear(0);
    cout << COR_CIANO << "╔═══════════════════════════════════════╗\n";
    cout << "║     🎚️  ESCOLHE A DIFICULDADE 🎚️        ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║                                       ║\n";
    cout << "║  1) 😊 FÁCIL                           ║\n";
    cout << "║     • 5 posições                      ║\n";
    cout << "║     • 5 tentativas                    ║\n";
    cout << "║     • Dicas precisas                  ║\n";
    cout << "║                                       ║\n";
    cout << "║  2) 😐 MÉDIO                           ║\n";
    cout << "║     • 7 posições                      ║\n";
    cout << "║     • 3 tentativas                    ║\n";
    cout << "║     • Dicas normais                   ║\n";
    cout << "║                                       ║\n";
    cout << "║  3) 😰 DIFÍCIL                         ║\n";
    cout << "║     • 10 posições                     ║\n";
    cout << "║     • 2 tentativas                    ║\n";
    cout << "║     • Poucas dicas                    ║\n";
    cout << "║                                       ║\n";
    cout << "╚═══════════════════════════════════════╝\n" << COR_RESET;
    
    int dificuldade;
    cout << "\n🎯 Tua escolha: ";
    cin >> dificuldade;
    
    if(dificuldade == 1){
        tentativas = 5;
        maxPosicoes = 5;
    }
    else if(dificuldade == 2){
        tentativas = 3;
        maxPosicoes = 7;
    }
    else{
        tentativas = 2;
        maxPosicoes = 10;
    }
    
    //  LOOP principal do jogo
    srand(time(0));
    
    while(tentativas > 0){
        clear(1);
        
        // Gera posição do macaco
        posicaoMacaco = (rand() % maxPosicoes) + 1;
        
        //  CABEÇALHO
        cout << COR_LARANJA << "╔══════════════════════════════════════════════════╗\n";
        cout << "║       🍌 ACERTA NO MACACO KoméPah! 🐵                 ║\n";
        cout << "╠═══════════════════════════════════════════════════╣\n" << COR_RESET;
        
        //  ESTATÍSTICAS
        cout << "║  " << COR_VERDE << "💚 Vidas: " << COR_RESET;
        for(int i = 0; i < tentativas; i++) cout << "❤️ ";
        for(int i = tentativas; i < 5; i++) cout << "🖤 ";
        cout << "                               ║\n";
        
        cout << "║  " << COR_AMARELO << "⭐ Pontos: " << pontos << COR_RESET;
        if(pontos < 10) cout << "                                       ║\n";
        else if(pontos < 100) cout << "                                 ║\n";
        else cout << "                                           ║\n";
        
        cout << "║  " << COR_AZUL << "📈 Nível: " << nivel << COR_RESET;
        cout << "                                        ║\n";
        
        cout << COR_LARANJA << "╠═══════════════════════════════════════════════════╣\n" << COR_RESET;
        
        // 🌴 Palmeiras (esconde o macaco)
        cout <<                                                                                      "║  ";
        for(int i = 1; i <= maxPosicoes; i++){
            if(i < 10) cout << " [" << i << "] ";
            else cout << "[" << i << "] ";
        }
        cout << "║\n";
        
        cout <<                                                                              "║  ";
        for(int i = 1; i <= maxPosicoes; i++){
            cout << " 🌴  ";
        }
        cout << "                             ║\n";
        
        cout << COR_LARANJA << "╠═══════════════════════════════════════════════════╣\n";
        
        // 💪 POWER-UPS
        cout << "║  " << COR_ROXO << "🎁 POWER-UPS:" << COR_RESET << "                                  ║\n";
        cout << "║  ";
        if(!usouBinoculo) cout << COR_CIANO << "[B]" << COR_RESET << " 🔭 Binóculos (revela zona)       ";
        else cout << COR_VERMELHO << "[X]" << COR_RESET << " 🔭 Binóculos (usado)             ";
        cout << "║\n";
        
        cout << "║  ";
        if(!usouBananaDupla) cout << COR_AMARELO << "[D]" << COR_RESET << " 🍌🍌 Banana Dupla (2 tiros)      ";
        else cout << COR_VERMELHO << "[X]" << COR_RESET << " 🍌🍌 Banana Dupla (usado)        ";
        cout << "║\n";
        
        cout << COR_LARANJA << "╚══════════════════════════════════════════════════╝\n" << COR_RESET;
        
        // Input do Jogador
        cout << "\n" << COR_VERDE << "🎯 Atira a banana (1-" << maxPosicoes << ") ou usa power-up: " << COR_RESET;
        string input;
        cin >> input;
        
        // Verifica power-ups
        if((input == "B" || input == "b") && !usouBinoculo){
            clear(0);
            cout << COR_CIANO << "\n🔭 A USAR BINÓCULOS...\n" << COR_RESET;
            sleep(1);
            
            if(posicaoMacaco <= maxPosicoes/2){
                cout << COR_AMARELO << "   💡 O macaco está na PRIMEIRA METADE!\n" << COR_RESET;
            }
            else{
                cout << COR_AMARELO << "   💡 O macaco está na SEGUNDA METADE!\n" << COR_RESET;
            }
            
            usouBinoculo = true;
            sleep(2);
            continue;
        }
        else if((input == "D" || input == "d") && !usouBananaDupla){
            clear(0);
            cout << COR_AMARELO << "\n🍌🍌 BANANA DUPLA ATIVADA!\n" << COR_RESET;
            cout << "   Atira duas vezes seguidas!\n\n";
            sleep(1);
            
            int tiro1, tiro2;
            cout << "🎯 Primeiro tiro (1-" << maxPosicoes << "): ";
            cin >> tiro1;
            cout << "🎯 Segundo tiro (1-" << maxPosicoes << "): ";
            cin >> tiro2;
            
            if(tiro1 == posicaoMacaco || tiro2 == posicaoMacaco){
                clear(0);
                cout << COR_VERDE << "\n🎉🎉🎉 ACERTASTE COM BANANA DUPLA! 🎉🎉🎉\n" << COR_RESET;
                cout << "         🐵" << COR_AMARELO << "💥" << COR_RESET << "🍌🍌\n";
                cout << COR_AMARELO << "\n   +20 PONTOS BÓNUS!\n" << COR_RESET;
                pontos += 20;
                nivel++;
                sleep(3);
            }
            else{
                cout << COR_VERMELHO << "\n❌ FALHASTE AMBOS OS TIROS!\n" << COR_RESET;
                cout << "   O macaco estava na posição " << posicaoMacaco << "!\n";
                tentativas--;
                sleep(2);
            }
            
            usouBananaDupla = true;
            continue;
        }
        
        // Converte input para número
        atirar = atoi(input.c_str());
        
        if(atirar < 1 || atirar > maxPosicoes){
            cout << COR_VERMELHO << "\n⚠️  Posição inválida!\n" << COR_RESET;
            sleep(1);
            continue;
        }
        
        // Verificar se acertou
        clear(0);
        
        // Animação do tiro
        cout << "\n🍌 Banana a voar";
        for(int i = 0; i < 3; i++){
            cout << ".";
            cout.flush();
            usleep(300000);
        }
        cout << "\n\n";
        
        if(atirar == posicaoMacaco){
            // 🎉 ACERTOU!
            cout << COR_VERDE << "   ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
            cout << "   █                           █\n";
            cout << "   █  🎉 ACERTASTE! 🎉         █\n";
            cout << "   █                           █\n";
            cout << "   █        🐵" << COR_AMARELO << "💥" << COR_VERDE << "🍌              █\n";
            cout << "   █                           █\n";
            cout << "   ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n" << COR_RESET;
            
            cout << "\n" << COR_AMARELO << "   🐵: 'AUU! Apanhaste-me!' \n" << COR_RESET;
            
            int pontosGanhos = 10 * nivel;
            pontos += pontosGanhos;
            nivel++;
            
            cout << COR_VERDE << "\n   +" << pontosGanhos << " PONTOS!\n" << COR_RESET;
            
            // Reset power-ups no próximo nível
            usouBinoculo = false;
            usouBananaDupla = false;
            
            sleep(3);
        }
        else{
            // ❌ ERROU!
            cout << COR_VERMELHO << "   ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
            cout << "   █                           █\n";
            cout << "   █    ❌ FALHASTE! ❌        █\n";
            cout << "   █                           █\n";
            cout << "   █         🍌   💨   🐵      █\n";
            cout << "   █                           █\n";
            cout << "   ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n" << COR_RESET;
            
            tentativas--;
            
            cout << "\n" << COR_AMARELO << "   🐵: 'Haha! Falhaste!' \n" << COR_RESET;
            cout << COR_AZUL << "   O macaco estava na posição " << posicaoMacaco << "!\n" << COR_RESET;
            
            // dicas
            int distancia = abs(atirar - posicaoMacaco);
            
            if(distancia == 1){
                cout << COR_LARANJA << "\n   🔥 MUITO PERTO! Quase lá!\n" << COR_RESET;
            }
            else if(distancia == 2){
                cout << COR_AMARELO << "\n   ♨️  PERTO! Estás quente!\n" << COR_RESET;
            }
            else if(distancia <= 4){
                cout << COR_AZUL << "\n   🧊 LONGE... Está frio!\n" << COR_RESET;
            }
            else{
                cout << COR_ROXO << "\n   ❄️  MUITO LONGE! Gélido!\n" << COR_RESET;
            }
            
            sleep(3);
        }
    }
    
    //  GAME OVER
    clear(0);
    
    cout << COR_VERMELHO << "\n";
    cout << "   ███████████████████████████████████\n";
    cout << "   █                                 █\n";
    cout << "   █      💀 GAME OVER! 💀             █\n";
    cout << "   █                                  █\n";
    cout << "   ███████████████████████████████████\n";
    cout << COR_RESET << "\n";
    
    sleep(1);
    
    cout << COR_CIANO << "╔═══════════════════════════════════════╗\n";
    cout << "║                                       ║\n";
    cout << "║  🏆 PONTUAÇÃO FINAL: " << pontos;
    if(pontos < 10) cout << "                 ║\n";
    else if(pontos < 100) cout << "                ║\n";
    else if(pontos < 1000) cout << "               ║\n";
    else cout << "              ║\n";
    
    cout << "║  📊 Níveis alcançados: " << (nivel - 1) << "               ║\n";
    cout << "║                                       ║\n";
    
    // RANKING
    if(pontos >= 100){
        cout << "║  " << COR_AMARELO << "🏆 RANK: MESTRE DOS MACACOS!" << COR_RESET << "        ║\n";
        cout << "║  " << COR_VERDE << "Incrível! És um verdadeiro expert!" << COR_RESET << "  ║\n";
    }
    else if(pontos >= 50){
        cout << "║  " << COR_VERDE << "⭐ RANK: ATIRADOR EXPERT!" << COR_RESET << "           ║\n";
        cout << "║  " << COR_AMARELO << "Muito bom! Continua assim!" << COR_RESET << "         ║\n";
    }
    else if(pontos >= 20){
        cout << "║  " << COR_AZUL << "✨ RANK: BOM ATIRADOR!" << COR_RESET << "              ║\n";
        cout << "║  " << COR_CIANO << "Nada mau! Estás a melhorar!" << COR_RESET << "        ║\n";
    }
    else if(pontos >= 10){
        cout << "║  " << COR_ROXO << "🌟 RANK: PRINCIPIANTE!" << COR_RESET << "              ║\n";
        cout << "║  " << COR_AMARELO << "Bom começo! Treina mais!" << COR_RESET << "          ║\n";
    }
    else{
        cout << "║  " << COR_VERMELHO << "💩 RANK: PRECISA TREINAR!" << COR_RESET << "          ║\n";
        cout << "║  " << COR_AZUL << "Não desistas! Tenta outra vez!" << COR_RESET << "         ║\n";
    }
    
    cout << "║                                       ║\n";
    cout << "╚═══════════════════════════════════════╝\n" << COR_RESET;
    
    // Frase do macaco
    cout << "\n" << COR_AMARELO << "🐵 KoméPah: ";
    if(pontos >= 50){
        cout << "'Uau! És bom mesmo! 😮'";
    }
    else if(pontos >= 20){
        cout << "'Não és mau... mas eu sou melhor! 😏'";
    }
    else{
        cout << "'Haha! As bananas são MINHAS! 😂'";
    }
    cout << COR_RESET << "\n\n";
    
    sleep(2);
    
    // Créditos
    cout << COR_CIANO << "═══════════════════════════════════════\n";
    cout << "  🎮 Jogo criado por: Helga 25481 🎮\n";
    cout << "  🍌 Obrigada por jogares! 🐵\n";
    cout << "═══════════════════════════════════════\n" << COR_RESET;
}
                                                                                //8 - Marco Iça 
void marcoIca() {
    srand(time(0));

    char jogarNovamente;

    do {
        string jogador;
        cout << "Como te chamas, guerreiro? ";
        getline(cin, jogador);
        clear(1);

        int vitoriasJogador = 0;
        int vitoriasInimigo = 0;

        string opcoes[4] = {"ataque", "defesa", "magia", "ataque especial"};
        int ronda = 1;

        while (vitoriasJogador < 3 && vitoriasInimigo < 3) {
           
            int escolhaNum = 0;
            cout << "========= ROUND " << ronda << " =========\n\n";
            cout << jogador << ", escolhe uma opção: \n\n";
            cout << "1 - Ataque\n";
            cout << "2 - Defesa\n";
            cout << "3 - Magia\n";
            cout << "4 - Ataque Especial\n";
            cout << "\nEscolhe (1-4): ";
            cin >> escolhaNum;
            cin.ignore();
            sleep(2);
            clear(0);

            while (escolhaNum < 1 || escolhaNum > 4) {
                cout << "Opção inválida! Escolhe entre 1 e 4: ";
                cin >> escolhaNum;
                cin.ignore();
            }

            string escolhaJogador = opcoes[escolhaNum - 1];
            string escolhaPC = opcoes[rand() % 4];

            cout << "\n" << jogador << " escolheu: " << escolhaJogador << "\n";
            cout << "O inimigo escolheu: " << escolhaPC << "\n\n";
            sleep(3);
            clear(0);

            int pontosJogador = 0;
            int pontosInimigo = 0;

            if (escolhaJogador == "ataque" && escolhaPC == "defesa") {
                cout << "\nO inimigo bloqueou o teu ataque, mas escorregou numa casca de banana e ficou sem sapatos!\n";
                pontosJogador = 1;
            } else if (escolhaJogador == "defesa" && escolhaPC == "ataque") {
                cout << "\nDefendeste o ataque, o inimigo ficou sem calças e fugiu!\n";
                pontosJogador = 1;
            } else if (escolhaJogador == "magia" && escolhaPC == "ataque especial") {
                cout << "\nTentaste uma magia, mas o ataque especial do inimigo surpreendeu-te e transformou-te em sapo!\n";
                pontosInimigo = 1;
            } else if (escolhaJogador == "ataque especial" && escolhaPC == "magia") {
                cout << "\nO teu ataque especial fez ricochete na magia inimiga e cortou-lhe o bigode!\n";
                pontosJogador = 1;
            } else if (escolhaJogador == "magia" && escolhaPC == "defesa") {
                cout << "\nA magia fez ricochete na defesa do inimigo e transformou-o num André Ventura!\n";
                pontosJogador = 1;
            } else if (escolhaJogador == "ataque" && escolhaPC == "magia") {
                cout << "\nO teu ataque foi interrompido por um feitiço de invisibilidade do inimigo! Acertaste na parede\n";
                pontosInimigo = 1;
            } else if (escolhaJogador == "ataque especial" && escolhaPC == "ataque especial") {
                cout << "\nAmbos lançaram ataques especiais e criaram uma explosão de arco-íris com a música do Y.M.C.M!\n";
            } else if (escolhaJogador == "defesa" && escolhaPC == "defesa") {
                cout << "\nAmbos tentaram defender e acabaram a fazer uma guerra de palavras feias!\n";
            } else if (escolhaJogador == escolhaPC) {
                cout << "\nEmpataram e jogaram pedra, papel ou tesoura!\n";
            } else {
                cout << "\nA batalha foi caótica e ninguém sabe o que aconteceu!\n";
            }

            int bonus = rand() % 7;
            string efeitosBonus[7] = {
                "Um dragão obeso passou perto de voces!",
                "Chuva de confetes mágicos celebra o combate!",
                "Um mago desdentado começa a rir-se da situação!",
                "A arena tremeu por um segundo e cairam almondegas!️",
                "Um coelho gigante cruzou o campo de batalha a comer doritos!",
                "Um gnomo surgiu do nada e começou a dançar breakdance ao som de Britney Spears!",
                "O chão transformou-se em gelatina, ambos pararam o combate e começaram a comer!"
            };
            cout << "\nEFEITO BONUS: " << efeitosBonus[bonus] << "\n";
            sleep(6);
            clear(0);

            if (pontosJogador > pontosInimigo) {
                cout << "\n" << jogador << " venceu a ronda!\n\n";
                vitoriasJogador++;
            } else if (pontosJogador < pontosInimigo) {
                cout << "\nO inimigo venceu a ronda!\n\n";
                vitoriasInimigo++;
            } else {
                cout << "\nA ronda ficou empatada!\n\n";
            }
            sleep(3);
            clear(0);

            cout << "\nTOTAL ATUAL DE PONTOS:\n";
            cout << jogador << ": " << vitoriasJogador << " pontos\n";
            cout << "Inimigo: " << vitoriasInimigo << " pontos\n";
            sleep(3);
            clear(0);

            ronda++;
        }

        cout << "\n===== RESULTADO FINAL =====\n\n";
        cout << jogador << ": " << vitoriasJogador << " pontos\n";
        cout << "Inimigo: " << vitoriasInimigo << " pontos\n\n";

        if (vitoriasJogador > vitoriasInimigo)
            cout << "GRANDE VITÓRIA, " << jogador << "! O CPU torna-se assim no teu escravo!\n";
        else
            cout << "Foste derrotado! Tens de limpar as placas do CPU durante uma semana...\n";

        cout << "\nQueres jogar outra vez? (s/n): ";
        cin >> jogarNovamente;
        cin.ignore();
        clear(1);

    } while (jogarNovamente == 's' || jogarNovamente == 'S');
}
                                                                                //9 - Amanda Bordalo
void amandaBordalo() {
string nome;
char resposta;
int positivos=0;

cout<<"Olá,Tiago foi assassinado e você é suspeito.\nPor favor responda nossas perguntas:"<<endl;
clear(4);
cout<<"Nome:"<<endl;
cin>>nome;
clear(1);
cout<<"Você entregou o trabalho?(S ou N)"<<endl;
cin>>resposta;
if (resposta=='N' || resposta=='n')
positivos+=1;
clear(1);
cout<<"Você é profundo conhecedor de DeepWeb?(S ou N)"<<endl;
cin>>resposta;
if (resposta=='S' || resposta=='s')
positivos+=1;
clear(1);
cout<<"Seu saldo bancário é positivo?(S ou N)"<<endl;
cin>>resposta;
if (resposta=='S' || resposta=='s')
positivos+=1;
clear(1);
if(positivos<=1){
cout<<"Inocente. Te odeio!!"<<endl;
}else if (positivos>=2){
cout<<"Deveria ter me chamado para ajudar!!!"<<endl;
} clear (5);
}
                                                                                //10 - Gerson Moises
void gersonMoises() {


    vector<string> historico;
    int opcao;
    double a, b;

    cout << fixed << setprecision(2);

    while (true) {
        cout << "\n=== Calculadora Científica (Gerson) ===" << endl;
        cout << "1. Soma" << endl;
        cout << "2. Subtracao" << endl;
        cout << "3. Multiplicacao" << endl;
        cout << "4. Divisao" << endl;
        cout << "5. Potencia" << endl;
        cout << "6. Raiz" << endl;
        cout << "7. Ver Historico" << endl;
        cout << "8. Salvar Historico" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma operacao: ";
        cin >> opcao;

        if (opcao == 0) {
            // Não chama clear(4) aqui antes de sair do loop
            break; // Sai do loop, o programa volta para main e termina
        }

        switch (opcao) {
            case 1: {
                cout << "Digite dois numeros: ";
                cin >> a >> b;
                double resultado = a + b;
                stringstream ss;
                ss << fixed << setprecision(2);
                ss << "Soma(" << a << ", " << b << ") = " << resultado;
                historico.push_back(ss.str());
                cout << "Resultado: " << resultado << endl;
                clear(4);
                break;
            }
            case 2: {
                cout << "Digite dois numeros: ";
                cin >> a >> b;
                double resultado = a - b;
                stringstream ss;
                ss << fixed << setprecision(2);
                ss << "Subtracao(" << a << ", " << b << ") = " << resultado;
                historico.push_back(ss.str());
                cout << "Resultado: " << resultado << endl;
                clear(4);
                break;
            }
            case 3: {
                cout << "Digite dois numeros: ";
                cin >> a >> b;
                double resultado = a * b;
                stringstream ss;
                ss << fixed << setprecision(2);
                ss << "Multiplicacao(" << a << ", " << b << ") = " << resultado;
                historico.push_back(ss.str());
                cout << "Resultado: " << resultado << endl;
                clear(4);
                break;
            }
            case 4: {
                cout << "Digite dois numeros: ";
                cin >> a >> b;
                if (b == 0) {
                    cout << "Erro: divisao por zero!" << endl;
                } else {
                    double resultado = a / b;
                    stringstream ss;
                    ss << fixed << setprecision(2);
                    ss << "Divisao(" << a << ", " << b << ") = " << resultado;
                    historico.push_back(ss.str());
                    cout << "Resultado: " << resultado << endl;
                }
                clear(4);
                break;
            }
            case 5: {
                cout << "Digite base e expoente: ";
                cin >> a >> b;
                double resultado = pow(a, b);
                stringstream ss;
                ss << fixed << setprecision(2);
                ss << "Potencia(" << a << ", " << b << ") = " << resultado;
                historico.push_back(ss.str());
                cout << "Resultado: " << resultado << endl;
                clear(4);
                break;
            }
            case 6: {
                cout << "Digite um numero: ";
                cin >> a;
                if (a < 0) {
                    cout << "Erro: raiz de numero negativo!" << endl;
                } else {
                    double resultado = sqrt(a);
                    stringstream ss;
                    ss << fixed << setprecision(2);
                    ss << "Raiz(" << a << ") = " << resultado;
                    historico.push_back(ss.str());
                    cout << "Resultado: " << resultado << endl;
                }
                clear(4);
                break;
            }
            case 7:
                cout << "\n=== Historico ===" << endl;
                if (historico.empty()) {
                    cout << "Nenhuma operacao registrada." << endl;
                } else {
                    for (const auto& linha : historico) {
                        cout << linha << endl;
                    }
                }
                cout << "\nPressione Enter para continuar...";
                cin.ignore();
                cin.get();
                clear(0);
                break;
            case 8:
                {
                    ofstream arquivo("historico.txt");
                    for (const auto& linha : historico) {
                        arquivo << linha << endl;
                    }
                    arquivo.close();
                    cout << "Historico salvo em historico.txt" << endl;
                    clear(4);
                }
                break;
            default:
                cout << "Opcao invalida!" << endl;
                clear(4);
        }
    }
    // Opcional: forçar a atualização do buffer de saída antes de terminar
    cout.flush();
}
                                                                                //11 - Midia Brandao
void midiaBrandao() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int tamanhoPista = 50;
    const int numCarros = 4;
    const char carros[numCarros] = { 'A', 'B', 'C', 'D' };
    int pos[numCarros] = { 0 };

    // --- Início da interação ---
    cout << "🏎️  === CORRIDA DE CARACTERES === 🏁" << endl;
    cout << "Carros participantes: ";
    for (int i = 0; i < numCarros; i++) cout << carros[i] << " ";
    cout << "\n-----------------------------------\n";

    char aposta;
    cout << "Em qual carro voce aposta? ";
    cin >> aposta;
    aposta = toupper(aposta);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nPreparar... ";
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << "Apontar... ";
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << "Já!\n";
    this_thread::sleep_for(chrono::milliseconds(800));

    bool vencedor = false;
    int ganhador = -1;

    // --- Loop da corrida ---
    while (!vencedor) {

        // limpar a tela usando a função clear (sem delay aqui, apenas limpar)
        cout << "\x1b[2J\x1b[H";

        // atualizar posições
        for (int i = 0; i < numCarros; i++) {
            int avanco = rand() % 3;
            pos[i] += avanco;

            if (pos[i] >= tamanhoPista - 1) {
                pos[i] = tamanhoPista - 1;
                vencedor = true;
                ganhador = i;
            }
        }

        // mostrar corrida
        for (int i = 0; i < numCarros; i++) {
            for (int j = 0; j < tamanhoPista; j++) {
                if (j == pos[i])
                    cout << carros[i];
                else if (j == tamanhoPista - 1)
                    cout << '|';
                else
                    cout << '-';
            }
            cout << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(150 + rand() % 100));
    }

    // --- Resultado ---
    cout << "\n🏁 O carro " << carros[ganhador] << " venceu!" << endl;

    if (aposta == carros[ganhador])
        cout << "🎉 Parabens! Voce acertou sua aposta!" << endl;
    else
        cout << "😅 Que pena! Voce perdeu a aposta." << endl;

    cout << "\nFim da corrida. Obrigado por jogar!\n";
clear(10); } 
                                                                                //12 - Alexandre Rolim
void alexandreRolim() {
    const int Limite_chances = 10;
    const int Menor_num = 1;
    const int Maior_num = 50;

    srand((unsigned) time(nullptr));

    int numeroSecreto = Menor_num + rand() % (Maior_num - Menor_num + 1);

    int palpites[Limite_chances];
    int tentativasFeitas = 0;

    while (tentativasFeitas < Limite_chances) {
        clear(1);
        cout << "Tentativa " << (tentativasFeitas + 1) << " de " << Limite_chances << "\n";
        cout << "Digite seu palpite entre " << Menor_num << " e " << Maior_num << ": ";
        int palpite;
        cin >> palpite;

        palpites[tentativasFeitas] = palpite;
        tentativasFeitas++;

        if (palpite == numeroSecreto) {
            cout << "Parabéns! é isso mesmo! O número era " << numeroSecreto << ".\n";
            return;
        } else if (palpite < numeroSecreto) {
            cout << "QUASE! O número é maior que " << palpite << ".\n";
        } else {
            cout << "QUASE! O número é menor que " << palpite << ".\n";
        }

        //  os palpites anteriores
        cout << "Você já tentou: ";
        for (int i = 0; i < tentativasFeitas; i++) {
            cout << palpites[i];
            if (i < tentativasFeitas - 1) cout << ", ";
        }
        cout << "\n";

        cout << "Tentativas restantes: " << (Limite_chances - tentativasFeitas) << "\n";

        clear(3);
    }

    // caso ele perca o jogo
    clear(1);
    cout << "Suas tentativas acabaram! O número era: " << numeroSecreto << ".\n";
clear(5);}
                                                                                //13 - Tatiana Anaclelio
void tatianaAnaclelio(){
    string nome;
    int fome = 50, felicidade = 50, energia = 50;
    int opcao;

    cout << "Digite o nome do seu PET: ";
    cin >> nome;


    do {
                                                                                // Mostrar status
        cout << "_____________________________"<< endl;
        cout << "           MEU PET           "<< endl;
        cout << "    Nome: " << nome << endl; 
        cout << "    Fome: " << fome << endl;
        cout << "    Felicidade: " << felicidade << endl;
        cout << "    Energia: " << energia <<  endl;
        cout << "_____________________________" << endl;

                                                                                // Menu
        cout << R"(
    Escolha sua opção:
    1) Alimentar
    2) Brincar
    3) Dormir
    0) Sair 
    )";
        cin >> opcao;   

                                                                                // Ações
        if (opcao == 1) {
            fome += 20; if (fome > 100) fome = 100;
            energia += 10; if (energia > 100) energia = 100;
            cout << nome << " foi alimentado!"<< endl;
            clear(4);
        } else if (opcao == 2) {
            felicidade += 20; if (felicidade > 100) felicidade = 100;
            energia -= 15; fome -= 10;
            cout << nome << " brincou e está feliz!"<< endl;
            clear(4);
        } else if (opcao == 3) {
            energia += 30; if (energia > 100) energia = 100;
            fome -= 15;
            cout << nome << " dormiu e recuperou energia!"<< endl;
            clear(5);
        } else if (opcao == 0) {
            cout << "Você escolheu sair!  :(  " << endl;
            cout << "Até a próxima ...  " << endl;
            break;
        } else {
            cout << "Ops! Aldo deu errado. Escolha novamente!"<< endl;
        }

                                                                                // Atualizar estado geral
        fome -= 5; felicidade -= 5; energia -= 5;

                                                                                // Verificar se morreu
        if (fome <= 0 || felicidade <= 0 || energia <= 0) {
            cout << "O seu PET morreu! :( " << endl;
            break;
        }

    } while (opcao != 4);

    cout << "       Fim do jogo!"<< endl;
clear(5);}
                                                                                //14 - Rosiane  Mazim
void rosianeMazim() {
    #define SLEEP(x) sleep(x)
    srand(time(0));

    string nome;
    cout << "Bem-vindo ao Quiz Inteligente! Qual é seu nome? ";
    cin >> nome;

    int HP = 100, ATK = 5, DEF = 3;
    string arq = nome + ".sav";

    ifstream in(arq);
    if (in >> nome >> HP >> ATK >> DEF) {
    cout << "Bem-vindo de volta ao Quiz dos Inteligentes!\n";
    }
    in.close();

    cout << "STATUS: HP=" << HP << " | ATK=" << ATK << " | DEF=" << DEF << "\n";

    char op;
    cout << "Deseja iniciar o QUIZ RPG? (s/n): ";
    cin >> op;

    if (op == 's' || op == 'S') {
    vector<string> perguntas = {
    "1) Qual palavra-chave define uma funcao em C++?\nA) def B) function C) void D) fn",
    "2) O que significa RPG?\nA) Real Programmer Guide B) Role Playing Game C) Random Program Generator D) Rapid Power Guide",
    "3) Qual símbolo inicia um comentario de linha em C++?\nA) ## B) // C) || D) **",
    "4) Qual tipo de dado armazena numeros inteiros?\nA) float B) char C) int D) string",
    "5) O que uma funcao retorna quando seu tipo é void?\nA) 0 B) nada C) true D) erro"
    };
    vector<char> respostas = {'C', 'B', 'B', 'C', 'B'};
    int pontos = 0;

    for (int i = 0; i < perguntas.size(); i++) {
    cout << perguntas[i] << "\nSua resposta: ";
    char r;
    cin >> r;
    r = toupper(r);
    if (r == respostas[i]) {
    cout << "✔ Correto! +1 ATK\n";
    ATK++;
    pontos++;
    } else {
    cout << "✘ Errado! +1 DEF\n";
    DEF++;
}
    SLEEP(1);
    cout << "\x1b[2J\x1b[H"; // Limpa a tela
    }

    cout << "Voce acertou " << pontos << " de " << perguntas.size() << " perguntas.\n";
    cout << "STATUS FINAL: HP=" << HP << " | ATK=" << ATK << " | DEF=" << DEF << "\n";
}

    ofstream out(arq);
    out << nome << "\n" << HP << "\n" << ATK << "\n" << DEF;
    out.close();
    cout << "Progresso salvo. Ate a proxima aventura!\n";
clear(5);}
                                                                                //15 - Charliane Silva
void charlianeSilva() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    int gridOriginal[4][4] = {
        {1, 0, 3, 4},
        {3, 4, 0, 2},
        {2, 3, 4, 0},
        {4, 0, 2, 3}
    };

    int solution[4][4] = {
        {1, 2, 3, 4},
        {3, 4, 1, 2},
        {2, 3, 4, 1},
        {4, 1, 2, 3}
    };

    int continuar = 1;

    while (continuar == 1) {

        int grid[4][4];
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                grid[i][j] = gridOriginal[i][j];

        bool cheio = false;

        while (!cheio) {

            cout << "\nMini jogo SUDOKU 4x4\n";
            cout << "Complete com números de 1 a 4\n";
            cout << "(0 = vazio)\n\n";

            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    if (gridOriginal[i][j] != 0) {
                        cout << grid[i][j] << " ";
                    } else {
                        if (grid[i][j] == 0) {
                            cout << "0 ";
                        }
                        else if (grid[i][j] == solution[i][j]) {
                            cout << GREEN << grid[i][j] << RESET << " ";
                        } else {
                            cout << RED << grid[i][j] << RESET << " ";
                        }
                    }
                }
                cout << endl;
            }

            int linha, col, num;
            cout << "\nDigite linha (1-4): ";
            cin >> linha;
            cout << "Digite coluna (1-4): ";
            cin >> col;
            cout << "Digite número (1-4): ";
            cin >> num;

            if (linha < 1 || linha > 4 || col < 1 || col > 4 || num < 1 || num > 4) {
                cout << "\nNúmero inserido é errado!\n";
                continue;
            }

            linha--; 
            col--;

            if(gridOriginal[linha][col] == 0) {
                grid[linha][col] = num;
                cout << "\nNúmero inserido!\n";
            } else {
                cout << "\nPosição já preenchida!\n";
            }

            cheio = true;
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    if (grid[i][j] == 0) {
                        cheio = false;
                        break;
                    }
                }
                if (!cheio) break;
            }
        }

        cout << "\n Valores Inseridos\n";
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\n Jogo correto\n";
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nDigite 1 para jogar novamente ou 0 para sair: ";
        cin >> continuar;

        if (continuar == 1) {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
        }
    } clear(6);
}
                                                                                //16 - Hector Silva
void hectorSilva() {

    int face = rand() % 6 + 1;

    cout << "Voce tirou: " << face << endl;

    switch(face) {

        case 1:
            cout << R"(
        
                   .---------.
                  /         /|   
                 /    o    / |   
                /_________/  | 
                | o       |  / 
                |         | / 
                |       o |/   
                '---------'     
        
            )";
        break;

        case 2:
            cout << R"(
        
                   .---------.
                  /  o      /|   
                 /       o / |   
                /________ /  | 
                | o       |  / 
                |    o    | / 
                |       o |/   
                '---------'     
        
            )";
        break;

        case 3:
            cout << R"(
        
                   .---------.
                  / o       /|   
                 /    o    / |   
                /_______o_/  | 
                | o     o |  / 
                |         | / 
                | o      o|/   
                '---------'     
        
            )";
        break;

        case 4:
            cout << R"(
        
                   .---------.
                  / o    o  /|   
                 /         / |   
                /__o____o_/  | 
                |         |  / 
                |    o    | / 
                |         |/   
                '---------'     
        
            )";
        break;

        case 5:
            cout << R"(
        
                   .---------.
                  / o    o  /|   
                 /    o    / |   
                /__o____o_/ 5| 
                | o       |  / 
                |    o    | / 
                |       o |/   
                '---------'     
        
            )";
        break;

        case 6:
            cout << R"(
        
                   .---------.
                  / o     o /|   
                 / o     o / |   
                /_o ____o_/  | 
                |         |  / 
                |    o    | / 
                |         |/   
                '---------'      
        
            )";
        break;
    } clear(5);
}
                                                                                //17 - Getulio Brito
void getulioBrito() {
    random_device rd;
    mt19937 gen(rd()); // Gerador de números pseudoaleatórios
    uniform_int_distribution<int> fuse_dist(50, 70); // Tempo da bomba aleatório entre 50 e 70 segundos
    int fuse_seconds = fuse_dist(gen);

    clear(3); // espera 3 segundo antes de limpar
    cout << "=== JOGO DA BOMBA ===\n";
    cout << "Tens " << fuse_seconds << " segundos e 3 tentativas.\n";
    cout << "Tens coragem?\n\n";

    auto start = chrono::steady_clock::now();
    int tentativas = 0;
    const int max_tentativas = 3;

    while (tentativas < max_tentativas) {
        auto now = chrono::steady_clock::now();
        int elapsed = chrono::duration_cast<chrono::seconds>(now - start).count();
        int remaining = fuse_seconds - elapsed;

        if (remaining <= 0) {
            cout << "\nTempo esgotado!\n";
            break;
        }

        cout << "Tempo restante: " << remaining << "s\n";
        cout << "Tentativa " << (tentativas + 1) << "/" << max_tentativas << "\n";
        cout << "Insira 3 dígitos: ";

        string tentativa;
        if (!getline(cin, tentativa)) break; // Sai se input falhar

        // Remove espaços iniciais e finais
        while (!tentativa.empty() && isspace(tentativa.back())) tentativa.pop_back();
        while (!tentativa.empty() && isspace(tentativa.front())) tentativa.erase(tentativa.begin());

        // Verifica se tem exatamente 3 dígitos
        if (tentativa.size() != 3 || !isdigit(tentativa[0]) || !isdigit(tentativa[1]) || !isdigit(tentativa[2])) {
            cout << "Erro: tens que inserir exatamente 3 dígitos!\n\n";
            continue; // Não conta como tentativa
        }

        tentativas++;
        clear(3); // espera 3 segundo antes de limpar
    }

    cout << "\nBOOM!\nGAME OVER\n"; clear(5);
}
                                                                                //18 - Manoel Barata
void manoelBarata(){
    string nome, recurso, endereco;

    cout << "Bem vindo Estudante! Informe o seu nome: " << endl;
    cin >> nome;

    cout << "Informe o assunto do seu recurso educacional: " << endl;
    cin >> recurso;

    cout << "Informe o endereço eletrônico de seu recurso educacional: " << endl;
    cin >> endereco;
    clear(2);

    string nomeFile = nome + ".sav";
    ofstream out(nomeFile, ios::app);

    if (!out) {
        cout << "Erro ao criar o arquivo!" << endl;
       return;
    }

    out << nome << endl;
    out << recurso << endl;
    out << endereco << endl;
    out.close();

    cout << "\nArquivo salvo com sucesso!" << endl;
    clear(2);
   
    string nomeLido, assuntoLido, enderecoLido;
    ifstream in(nomeFile);

    if (!in) {
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
       return;
    }
    
    while (true) {

    getline(in, nomeLido);
    getline(in, assuntoLido);
    getline(in, enderecoLido);
   
    if (!in) break;
    
cout << "| Assunto              | " << setw(27) << left << assuntoLido   << "|" << endl;
cout << "| URL                  | " << setw(27) << left << enderecoLido  << "|" << endl;

cout << "+----------------------+-----------------------------+" << endl;
    
        
    }
     in.close();
     cout << "\n**|| Catálogo Científico de " << nome << ": |**" << endl;
     clear(5);
    }                                                                                
                                                                                //19 - Gabriel Morais
void gabrielMorais(){
    srand(time(0));                                                             // VARIAVEIS
    int mod, prof, AC, acerto, ataques, dadoAtaque, dado, dano=0;
    int escolha, escolha2, escolha3;
    int aleatorio1, aleatorio2;
 
comeco1:
    cout<<"___________________________________________________\n"<<endl;
    cout<<"Quer rodar para o ataque ou só ver o dano?"<<endl;
    cout<<"1- Rodar para o ataque         2- Ver o dano"<<endl;
    cin>>escolha2;
    clear(1);
    
    cout<<"___________________________________________________\n"<<endl;
    switch(escolha2){
        case 1: cout<<"Quantos ataques quer realizar?  ";
                cin>>ataques;
                
                cout<<"Qual o modificador de ataque?  ";
                cin>>mod;
  
                cout<<"Qual a sua proeficiencia?   ";
                cin>>prof;
    
                cout<<"Qual o AC do alvo?   ";
                cin>>AC; 
                break;
        case 2: cout<<"Qual o modificador de ataque?  ";
                cin>>mod;
                ataques = 1;
                break;
        default:  clear(1); goto comeco1; break;
    }
    clear(1);
    
comeco2:
    cout<<"___________________________________________________\n"<<endl;
    cout<<"\nEscolha o dado para o dano: "<<endl;
    cout << R"(
1- d4   2- d6   3- d8
    4- d10  5- d12
)";
    cin>>escolha;
    cout<<"\n___________________________________________________\n"<<endl;
    switch(escolha){
        case 1: cout<<"- Quantos dados quer rodar para o ataque?  ";
                cin>>dadoAtaque; dado=4; break;
        case 2: cout<<"- Quantos dados quer rodar para o ataque?  ";
                cin>>dadoAtaque; dado=6; break;
        case 3: cout<<"- Quantos dados quer rodar para o ataque?  ";
                cin>>dadoAtaque; dado=8; break;
        case 4: cout<<"- Quantos dados quer rodar para o ataque?  ";
                cin>>dadoAtaque; dado=10; break;
        case 5: cout<<"- Quantos dados quer rodar para o ataque?  ";
                cin>>dadoAtaque; dado=12; break;
        default: cout<<"opção invalida"<<endl; clear(1); goto comeco2; break;
    }
    cout<<"\n\nEscolheu "<<dadoAtaque<<"d"<<dado<<endl;
    clear(1);
    
    cout<<"___________________________________________________\n"<<endl;
    
    if (escolha2==2){
        cout<<"Dado: "<<dadoAtaque<<"d"<<dado<<"   Modificador de dano: "<<mod<<endl<<endl;
    }else if (escolha2==1){
        cout<<"Ataques: "<<ataques<<"   Proeficiencia: "<<prof<<"   AC do alvo: "<<AC<<endl;
        cout<<"Dado: "<<dadoAtaque<<"d"<<dado<<"   Modificador de dano: "<<mod<<endl<<endl;
    }
    cout<<"___________________________________________________\n"<<endl;
    
    
    for(int i=0; i<ataques; i++){
        aleatorio1 = (rand() % 20) + 1;
        acerto = aleatorio1 + mod + prof;
        
        if(escolha2 == 2){                                                      // PULAR PARA DANO
            for(int o=0; o<dadoAtaque; o++){
                aleatorio2 = (rand() % dado) + 1;
                dano+= aleatorio2 + mod;}
            cout<<"Deu "<<dano<<" de dano!"<<endl;
            aleatorio2 = (rand() % dado) + 1;
            dano+= aleatorio2;
            cout<<"\nDeu "<<dano<<" de dano Critico!"<<endl;
            cout<<"___________________________________________________"<<endl;
            
        }else if(aleatorio1 == 20){                                             // DANO CRITICO
            cout<<"\nCritico!! Tirou 20 no dado!!"<<endl;
            for(int o=0; o<(dadoAtaque+1); o++){
                aleatorio2 = (rand() % dado) + 1;
                dano+= aleatorio2 + mod;}
            dano-=mod;
            cout<<"\nDeu "<<dano<<" de dano critico!"<<endl;
            cout<<"___________________________________________________"<<endl;
            
        }else if(acerto>= AC){                                                  // DANO
            cout<<"\nTirou "<<aleatorio1<<" no dado."<<endl;
            cout<<"O seu attack roll foi "<<acerto<<". Acertou!"<<endl;
            for(int o=0; o<dadoAtaque; o++){
                aleatorio2 = (rand() % dado) + 1;
                dano+= aleatorio2 + mod;}
            cout<<"Deu "<<dano<<" de dano!"<<endl;
            cout<<"___________________________________________________"<<endl;
                        
        }else if(aleatorio1 == 1){                                              // FALHA CRITICA
            cout<<"\nFalha critica! Tirou 1 no dado..."<<endl;
        }else if(acerto< AC){                                                   // FALHA
            cout<<"\nTirou "<<aleatorio1<<" no dado."<<endl;
            cout<<"O seu attack roll foi "<<acerto<<"."<<endl;
            cout<<"\nErrou o ataque."<<endl;
            cout<<"___________________________________________________"<<endl;
        }
    }
    
    cout<<"1- Tentar novamente"<<endl;
    cin>>escolha3;
    clear(3);
    if(escolha3==1){goto comeco1;}
}
                                                                                //20 - Sabrina Gomes
void sabrinaGomes() {
    SabrinaYukkiGomes();
    clear(5);
}
                                                                                //INT MAIN
int main()
{
    string nome;
    int escolha;
    
    cout << R"(
           _____                              
          |   __|_ _ ___ ___ ___              
          |__   | | | . | -_|  _|             
          |_____|___|  _|___|_|               
                    |_|                       
                                              
       _____         _         _              
      |     |___ ___|_|_ _ ___| |_ ___        
      |   --| .'|   | | | | -_|  _| -_|       
      |_____|__,|_|_|_|\_/|___|_| |___|       
                                              
                                              
 _____     _            ___ ___ ___ ___ ___   
|   __|_ _|_|___ ___   |_  |  _| | | . |_  |  
|__   | | | |  _| . |  |  _|_  |_  | . |_| |_ 
|_____|___|_|___|___|  |___|___| |_|___|_____|
                                                                                                                                    
        )"<<endl;

   // cout << "Bem-Vindo Jogador, qual é o seu nome? "; cin >> nome;
    Jogador j(nome);
    if (!j.loadFile()){
        cout <<"Vamos Criar jogador Novo" << endl;
            j.setA(0); 
            j.setB(0); 
            j.setC(0);
    } else {
        cout << "Bem-Vindo de volta!" << endl;
    }
    
    do {
        clear(2);
        cout << R"(
                 +-+ +-+ +-+ +-+ +-+ +-+ +-+ 
                 |E| |s| |c| |o| |l| |h| |a| 
                 +-+ +-+-+-+-+-+-+-+ +-+ +-+ 
                         |u| |m| |a|           
                   +-+ +-+-+-+-+-+-+-+ +-+     
                   |O| |p| |c| |a| |o| |:|     
                   +-+ +-+ +-+ +-+ +-+ +-+ 
 
1 - Calculador Emprestimos         2 - Slot Machine
3 - Uma Semana Saudavel            4 - Calcular tempo até
5 - Calculador de Investimento     6 - Jogo Reflexos
7 - Monkey Business                8 - Mini Arena  
9 - Detetive                       10 - Calculadora  
11 - Corrida de Caracter           12 - Adivinha de Numeros  
13 - Meu Pet                       14 - Quiz Inteligente  
15 - Sudoku                        16 - Jogo dos Dados
17 - Jogo da Bomba                 18 - Catalogo Científico
19 - Dungeons and Dragons          20 - Snake Game
21 - (Nerias Coming Soon...)        0 - Sair
    
                 A sua Escolha: )"; cin >> escolha; clear(2);
    
    switch (escolha) {
        
        case 1:
        joaoSilva();
        break;
        case 2:
        sandraMota();
        break;        
        case 3:
        tatianaNascimento();
        break;
        case 4:
        marcosAraujo();
        break;        
        case 5:
        ricardoBranco();
        break;        
        case 6:
        goncaloLionco();
        break;
        case 7:
        helgaMartins();
        break;        
        case 8:
        marcoIca();
        break;
        case 9:
        amandaBordalo();
        break;        
        case 10:
        gersonMoises();
        break;        
        case 11:
        midiaBrandao();
        break;
        case 12:
        alexandreRolim();
        break;        
        case 13:
        tatianaAnaclelio();
        break;
        case 14:
        rosianeMazim();
        break;        
        case 15:
        charlianeSilva();
        break;        
        case 16:
        hectorSilva();
        break;
        case 17:
        getulioBrito();
        break;        
        case 18:
        manoelBarata();
        break;
        case 19:
        gabrielMorais();
        break;        
        case 20:
        sabrinaGomes();
        break;        
        case 21:
        //();
        break;        
        case 0:
            cout << "       Decidiu Sair, Até breve!";
        break;         
        default:
            cout << "Opção Inválida. Repetir Pf.";
        break; 
        }
        
    } while (escolha !=0);
    

    // j.saveFile();
    
    return 0;
}