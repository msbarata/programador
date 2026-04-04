
https://onlinegdb.com/GMQvOeCSF

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char n[] = "0123456789";
char nLimpo[] = "0123456789";
char jogador = 'X',recomecar;
char nomeJogador[51];
char ficheiro[100];
int jogada,vitoria=0,empate=0,i,pontosX=0;
int V[8][3] = { {1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{7,5,3},{9,5,1} };

void cls() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void boasVindas(){
    cls();
    printf("\n    Bem-vindo ao Jogo do Galo 🐔\n\n");
}

void areaJogo(char n[]){
    printf("       ------+-----+------\n"
    "       |  %c  |  %c  |  %c  |\n"
    "       ------+-----+------\n"
    "       |  %c  |  %c  |  %c  |\n"
    "       ------+-----+------\n"
    "       |  %c  |  %c  |  %c  |\n"
    "       ------+-----+------\n",
    n[7],n[8],n[9],
    n[4],n[5],n[6],
    n[1],n[2],n[3]
    );
}

void verificarVitoria(int V[8][3], char jogador){
    vitoria=0;
    for(i=0;i<8;i++){
        if(n[V[i][0]]==n[V[i][1]] && n[V[i][1]]==n[V[i][2]]){
            vitoria=1;
            
        if(jogador == 'X')  {
            pontosX+=100;
            printf("\n\n Jogador %c - %s  GANHOU +100 pontos! Total atualizado: %d pontos.\e \n", jogador, nomeJogador, pontosX);
        }else{
            pontosX-=100;
            printf("\n\n Jogador %c - %s PERDEU 100 pontos! Total atualizado: %d pontos.\e \n", jogador, nomeJogador, pontosX);
            
        }  
            
        }
    }
}
void guardarPontos(){
    printf("Introduza o nome do jogador: ");
    scanf("%50[^\n]", nomeJogador);
    
    snprintf(ficheiro, sizeof(ficheiro), "%s.sav", nomeJogador);
    FILE *f = fopen(ficheiro, "r");
    
    if (f && fscanf(f, "%*[^@]@%d", &pontosX) == 1){
        fclose(f);
        printf("\n\e[32mSave carregado! Bem-vindo %s! Pontos: %d\e[0m\n", nomeJogador, pontosX);
        sleep(4);
    } else {
        if (f) fclose(f);
        printf("\n\e[33mJogador novo detectado! Começando do zero.\e[0m\n");
        pontosX = 0;
        sleep(4);
    }
}

void gravarFicheiro(){
    snprintf(ficheiro, sizeof ficheiro,"%s.sav", nomeJogador);
	FILE *f = fopen(ficheiro, "w");
	fprintf(f, "%s@%d\n",nomeJogador,pontosX);
	fclose(f);
}


void recomecarJogo(){
    for(i=0;i<10;i++){
        n[i] = nLimpo[i];
    }
}

int main()
{
    guardarPontos();
jogo:    
    while(vitoria==!1 && empate!=9){
        boasVindas();
        areaJogo(n);
        if(jogador == 'X')  {
        printf("\n        Jogador %c - %s (1-9): ",jogador, nomeJogador);
        }else{
        printf("\n        Jogador %c (1-9): ",jogador);
        
        }
        if (scanf("%d", &jogada)!=1) return 0;
        if (jogada<1 || jogada >9 || n[jogada]=='X' || n[jogada]=='O'){
            printf("\n\n  \e[31m    !!! Jogada Inválida !!! \e[0m \n");
            sleep(2);
            continue;
        }
        n[jogada] = jogador;
        empate+=1;
        
        verificarVitoria(V, jogador);
        
        jogador = (jogador=='X') ? 'O' : 'X' ;
        }
        
    if (empate==9 && vitoria==0){
        
        pontosX += 300;
        
        printf("\n\n \e[1m\e[33m       Acabou em Empate! Jogador: %s com %d", nomeJogador, pontosX);}
         sleep(4);
    printf("\n \e[34m     Digite r para recomecar o Jogo; s para sair e salvar \e[0m");
    while (getchar() != '\n'); scanf("%c",&recomecar);
        if (recomecar == 'r') {
            recomecarJogo();
            empate=0;
            vitoria=0;
            goto jogo;
        }
        
      gravarFicheiro();
    
    return 0;
}