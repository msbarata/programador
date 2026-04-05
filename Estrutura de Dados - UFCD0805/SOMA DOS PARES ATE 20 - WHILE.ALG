Algoritmo "soma dos pares ate 100 - para"
// Disciplina   : [Linguagem e Lógica de Programação] 
// Professor   : Antonio Carlos Nicolodi 

Var
// Seção de Declarações das variáveis 
     contador, soma: inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
contador<-2
soma<-0
enquanto contador<=20 faça
              soma<- soma + contador
              contador<- contador+2
fimenquanto
escreva("A soma dos pares é " , soma)

Fimalgoritmo