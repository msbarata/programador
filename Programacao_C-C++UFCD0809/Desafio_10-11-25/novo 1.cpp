https://onlinegdb.com/Yfle_AN4C

#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int pontosJogador=0, pontosCPU=0;  

void clear(int segundos){
    sleep(segundos);
    cout << "\x1b[2J\x1b[H";
}

string apresentacao(){
    string nome;
    cout<<"Bemvindo ao Jogo - Pedra, Papel, Tesoura! Escreva seu nome: "<<endl;
    cin>>nome;
    cout<<"Olá "<<nome<<" !"<<endl; 
    return(nome);}

void menuInicial(){
     cout<< R"(
Jogo do Pedra, Papel, Tesoura
1) Pedra
2) Papel
3) Tesoura
0) Sair: )";}


int menuIfPedra(){
  int aleatorio;
  
 aleatorio = rand() % 3;
 if (aleatorio == 0){
        cout << "CPU escolheu Pedra - Empatou!" << endl;
    }else if (aleatorio == 1){
        cout << "CPU escolheu Papel - Você Perdeu!" << endl;
        pontosCPU += 1;
    }else if (aleatorio == 2){
        cout << "CPU escolheu Tesoura - Você Ganhou!" << endl;
        pontosJogador += 1;
    }else{
        cout << "Erro" << endl;
    }
     return pontosJogador, pontosCPU;
}
int menuIfPapel(){
    int aleatorio;
 aleatorio = rand() % 3;
 if (aleatorio == 0){
        cout << "CPU escolheu Pedra - Você Ganhou!" << endl;
         pontosJogador += 1;
    }else if (aleatorio == 1){
        cout << "CPU escolheu Papel - Empatou!" << endl;
       
    }else if (aleatorio == 2){
        cout << "CPU escolheu Tesoura - Você Perdeu!" << endl;
        pontosCPU += 1;
    }else{
        cout << "Erro" << endl;
    }
     return pontosJogador, pontosCPU;
}

    int menuIfTesoura(){
    int aleatorio;  
 aleatorio = rand() % 3;
 
 if (aleatorio == 0){
        cout << "CPU escolheu Pedra - Você Perdeu!" << endl;
        pontosCPU += 1;
    }else if (aleatorio == 1){
        cout << "CPU escolheu Papel - Você Ganhou!" << endl;
       pontosJogador += 1;
    }else if (aleatorio == 2){
        cout << "CPU escolheu Tesoura - Empatou!" << endl;
    }else{
        cout << "Erro" << endl;  
}
 return pontosJogador, pontosCPU;
}
    void menuSwitchCase(){
    int escolha;
    cin >> escolha;
    switch (escolha){
        case 1: cout << "Escolheu Pedra" << endl; menuIfPedra(); break;
           
        case 2: cout << "Escolheu Papel" << endl; menuIfPapel(); break;
          
        case 3: cout << "Escolheu Tesoura" << endl; menuIfTesoura(); break;
        
        case 0: cout << "Sair! Até Breve!" << endl; break;    
        } 
    
    }
    
    void pontuacao (){
         cout << "Pontuações! Jogador: " << pontosJogador << " pontos e CPU " << pontosCPU << " pontos" << endl;
        
    }
    
    
     void vencedor (){
        
        if (pontosCPU == 3){
                cout << "CPU ganhou com " << pontosCPU << " pontos e Jogador perdeu com " << pontosJogador << " pontos" << endl;
                
        }else if (pontosJogador == 3){
                 cout<< R"(
                 /=======\
                   /   \
                   /   \
                  =======
                  ======= - Você Venceu !!)";
                cout <<" Jogador ganhou com " << pontosJogador << " pontos e CPU perdeu com " << pontosCPU << " pontos" << endl;
        }else{
                cout << "Ninguém ganhou, porque o Jogador desitiu! " <<endl;
    }
}
    int main(){
    srand(time(0));
    
    int escolha=-1;
    string nomeJogador;
    
    nomeJogador=apresentacao();
    
    do{
        clear(3);
        
       for (; pontosJogador <3 && pontosCPU <3 && escolha !=0;){
        
       pontuacao();
       menuInicial();
       menuSwitchCase();
            
        clear(3);
            
            } if (pontosCPU == 3 || pontosJogador == 3) {escolha=0;}
            
        }while (escolha !=0);
     
        sleep(3);
        
          vencedor();
    
        return 0;
}