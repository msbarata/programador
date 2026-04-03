#include <stdio.h>    // Biblioteca para comandos do C
#include <locale.h>  // Biblioteca para alterar idiomas, como o português.
#include <stdlib.h>
#include <string.h>

// area reservada para declaração de variaveis:


char nome[10], nomeCompleto[50], variavel1[50], variavel2[50], variavel3[50], variavel4[50], variavel5[50], variavel6[50];
int idade;

int main()
{
    setlocale(LC_ALL, "");   //Forçar que o dicionário
    
  
    printf("como se chama? ");
    scanf("%s",nome);
    printf("Prazer em conhecê-lo %s, por favor informe seu nome completo: ", nome);
    getchar();fgets(nomeCompleto, sizeof(nomeCompleto), stdin);
    printf("Qual a sua idade? (em anos): "); 
    scanf("%d",&idade);
    
    printf("Prezado %s, com %d anos de idade, agradecemos por sua candidatura. Vamos iniciar nossa entrevista? ", nome, idade);
   
    system("clear");
    printf("\n\n-->>Possui experiência no desenvolvimento de aplicativos para telemóveis? (Sim ou Não): ");
    scanf("%s",variavel1); 
    
    if (strcmp(variavel1, "sim") == 0 || strcmp(variavel1, "Sim") == 0 || strcmp(variavel1, "SIM") == 0) {
    
    printf("\nMuito bem, %s siga em frente na sua entrevista", nome);
    system("clear");
    }else{
        printf("Término da entrevista, %s infelizmente não é o perfil do candidato que procuramos", nome);
     return 0;
     
     system("clear");
    
    }
    printf("\n\n-->>Você usaria Auth ou Firebase Auth na autenticação da base de dados Firebase? (Sim ou Não): ");
    scanf("%s",variavel2); 
    
    if (strcmp(variavel2, "sim") == 0 || strcmp(variavel2, "Sim") == 0 || strcmp(variavel2, "SIM") == 0) {
    
    printf("\nMuito bem, %s siga em frente na sua entrevista", nome);
    system("clear");
    }else{
        printf("Término da entrevista, %s infelizmente não é o perfil do candidato que procuramos", nome);
     return 0;
     
     system("clear");
        
    }  
        
    printf("\n\n-->>Na base de dados Firebase, os dados em tempo real são salvos em Firestone / Realfile? (Sim ou Não): ");
    scanf("%s",variavel3); 
    
    if (strcmp(variavel3, "não") == 0 || strcmp(variavel3, "Não") == 0 || strcmp(variavel3, "NÃO") == 0) {
    
    printf("\nMuito bem, %s siga em frente na sua entrevista", nome);
    system("clear");
    }else{
        printf("Término da entrevista, %s infelizmente não é o perfil do candidato que procuramos", nome);
     return 0;
   
     system("clear");
    } 
        
    printf("\n\n-->>Dart é a linguagem de programação principal que o framework Flutter utiliza? (Sim ou Não): ");
    scanf("%s",variavel4); 
    
    if (strcmp(variavel4, "sim") == 0 || strcmp(variavel4, "Sim") == 0 || strcmp(variavel4, "SIM") == 0) {
    
    printf("\nMuito bem, %s siga em frente na sua entrevista", nome);
    system("clear");
    }else{
        printf("Término da entrevista, %s infelizmente não é o perfil do candidato que procuramos", nome);
     return 0;
   
     system("clear");
    }     
        
        printf("\n\n-->>Scaffold é o nome do widget base que compõe a maioria das telas o framework Flutter? (Sim ou Não): ");
    scanf("%s",variavel5); 
    
    if (strcmp(variavel5, "sim") == 0 || strcmp(variavel5, "Sim") == 0 || strcmp(variavel5, "SIM") == 0) {
    
    printf("\nMuito bem, %s siga em frente na sua entrevista", nome);
    system("clear");
    }else{
        printf("Término da entrevista, %s infelizmente não é o perfil do candidato que procuramos", nome);
     return 0;
  
     system("clear");
    }     
    
    printf("\n\n-->>Navigator / Routes é o elemento utilizado para desenvolver a navegação entre telas?: ");
    scanf("%s",variavel6); 
    
    if (strcmp(variavel6, "sim") == 0 || strcmp(variavel6, "Sim") == 0 || strcmp(variavel6, "SIM") == 0) {
    printf("\nParabéns %s !!  Você foi selecionado para a fase final do processo seletivo. ", nome);
    system("clear");
    }else{
        printf("Término da entrevista, %s infelizmente você ficou no cadastro para uma próxima oportunidade", nome);
     return 0;
   
     system("clear");
    }     
        
       return 0;
}
