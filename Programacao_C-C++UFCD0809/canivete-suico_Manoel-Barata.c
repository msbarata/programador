/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.
  
https://dontpad.com/25481_c/ManoelBarata/7Aula_Canivete-Suico08-10-25
*******************************************************************************/
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
                                                                                            //VARIAVEIS
double peso,altura,m,a,b,c,resultado;
int x,y,temp,opcao,numeroSecreto, palpite, tentativas;
                                                                                            //Limpar Ecra
void cls() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
                                                                                            //Boas Vindas
void boasVindas(){
    
    printf("=============================================\n");
    printf("Bem-vindo ao Canivete-suiço da 25481\n\n"
    "Selecione uma opção:                             ===\n"
    "1) Calcular o IMC                                ===\n"
    "2) Converter Milhas em KM                        ===\n"
    "3) Usar Regra três simples                       ===\n"
    "4) Jogo - Adivinha                               ===\n"
    "5) Raiz Quadrada                                 ===\n"
    "6) Média entre três números                      ===\n"
    "7) Converter Celsius para Fahrenheit             ===\n"
    "8) Calcular MDC entre dois números inteiros      ===\n"
    "0) Para sair                                     ===\n"
"=================================================\n"
    "A sua opção: "); 
  }
                                                                                            //IMC
double imc(double peso, double altura){
    cls();
    printf("Vamos calcular o seu IMC, indique o seu peso e altura:\n");
    printf("O seu peso é: "); scanf("%lf",&peso);
    printf("A sua altura é: "); scanf("%lf",&altura);
    return peso/(altura*altura);
}
                                                                                            //m>Km
double mkm(double m){
    cls();
    printf("Vamos converter milhas em kilometros:\n");
    printf("Coloque as milhas a converter: "); scanf("%lf",&m);
    return m*1.609344;
}
                                                                                            //R3s
double tres(double a,double b,double c){
    cls();
    printf("Vamos fazer uma regra de três simples de 3 valores, introduza valores A, B e C:\n");
    printf("Valor de A: "); scanf("%lf",&a);
    printf("Valor de B: "); scanf("%lf",&b);
    printf("Valor de C: "); scanf("%lf",&c);
    return (b*c)/a;
}    
    
void adivinha(){
    cls();
    srand(time(NULL));
    numeroSecreto = rand()%100+1;
    
    tentativas = 0;
    printf("Você possui sete (7) chances para acertar o número secreto entre (0-100):\n");
    
    while (tentativas < 7){
       
        printf("\nDigite o seu palpite: "); scanf("%d",&palpite);
        tentativas++;
       
        
    if (tentativas == 7){
    printf("\n** GAME OVER ** Você ultrapassou o limite de %d tentativas \n",tentativas); break;
        
    }else if (palpite == numeroSecreto){
        printf("\nParabéns você venceu!! Acertou o número secreto em %d tentativas",tentativas);
        printf("\n");
        printf("      ____________      \n");
        printf("      ==        ==      \n");
        printf("       ==      ==      \n");
        printf("        ==    ==      \n");
        printf("         ==  ==      \n");
        printf("           ==        \n");
        printf("         _______      \n"); break;
        
     
    }else if (palpite < numeroSecreto){
        printf("\nValor do palpite muito baixo!! digite um valor maior na tentativa %d: \n",tentativas+1);
    }else if (palpite > numeroSecreto){
        printf("\nValor do palpite muito alto!! digite um valor menor na tentativa %d: \n",tentativas+1);
        
    }
        
   }
    
 }
    
  double raiz(double a){
    cls();
    printf("Vamos calcular a Raiz Quadrada de um número inteiro?, introduza um número: \n");
    printf("Valor : "); scanf("%lf",&a);
    return sqrt(a);  

  }    
    
 double media (double a,double b,double c){
    cls();
    printf("Vamos fazer a média entre três valores, introduza os valores A, B e C:\n");
    printf("Valor de A: "); scanf("%lf",&a);
    printf("Valor de B: "); scanf("%lf",&b);
    printf("Valor de C: "); scanf("%lf",&c);
    return ((a+b+c)/3);   
    
 }   
 double convtemp(double a){
    cls();
    printf("Vamos converter Celsius em Fahrenheit:\n");
    printf("Digite a temperatura em Celsius: "); scanf("%lf",&a);
    return(a* 9.0 / 5.0) + 32.0;  
    
 }   
    
 int mdc (int x,int y){
    cls();
    printf("Vamos fazer o MDC para dois números inteiros, introduza os valores A e B:\n");
    printf("Valor de A: "); scanf("%d",&x);
    printf("Valor de B: "); scanf("%d",&y);  
     
    while (y != 0) {
    int temp = x % y;    
    x = y;              
    y = temp;            
}
return x;
 }
                                                                                            //INT MAIN
int main(){
    
    printf("O programa iniciará em 4 segundos...\n");
    
   while(sleep(4),cls(),boasVindas(),scanf("%d", &opcao)){
        switch(opcao){
            case 0: cls(); printf("Até breve."); return 0;
            case 1: printf("O Seu IMC é de: %.2lf\n",imc(peso,altura)); break;
            case 2: printf("A conversão de milhas em KM deu: %.2lfkm\n",mkm(m)); break;
            case 3: printf("A regra de três simples devolveu: %.0lf\n",tres(a,b,c)); break;
            case 4: printf("Jogo da Adivinha: \n");adivinha(); break;
            case 5: printf("A raiz quadra devolveu: %.0lf\n",raiz(a)); break;
            case 6: printf("Cálculo da média entre três números: %.2lf\n",media(a,b,c)); break;
            case 7: printf("A conversão de graus Celsius para Farenhight devolveu: %.2lf\n",convtemp(a)); break;
            case 8: printf("O 'Máximo Divisor Comum' entre os dois números informados devolveu: %.0d\n",mdc(x,y)); break;
            default: cls(); printf("Escolha inválida, pf repetir:\n");
        }
   }
}