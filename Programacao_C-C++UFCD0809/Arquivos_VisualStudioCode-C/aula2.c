/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>    // Biblioteca para comandos do C
#include <locale.h>  // Biblioteca para alterar idiomas, como o português.
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// area reservada para declaração de variaveis:


char nome[10], nomeCompleto[50];
int ano;
float variavel2;

int main()
{
    setlocale(LC_ALL, "");   //Forçar que o dicionário
    
    printf("Hello World\n");
    sleep(2);
    system("clear");
    printf("Olá 25481!");
    printf("como se chama?");
    scanf("%s",nome);
    printf("Prazer em conhecê-lo %s, que nome bonito, por favor informe seu nome completo: ", nome);
    
    getchar();fgets(nomeCompleto, sizeof(nomeCompleto), stdin);
    printf("Pf introduza o ano corrente: ");
    scanf("%d",&ano);
    
    
    ano=2030;
    char nome[15]=("Baratinha");
    
    printf("\n\nA ultima variavel guardou: %s %d \n\n",nome, ano);
    
    
    printf("A variavel nome guardou: %s",nomeCompleto);
       
    sleep(2);
    printf("Pf introduza o valor 3.141:\n");
    scanf("%f",&variavel2);
    printf("O valor reduziu para %.2f:",variavel2);
    
   
    return 0;
}
