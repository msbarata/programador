Algoritmo "Notas de 20 alunos - Vetores - calculomeida"

Var
// Seção de Declarações das variáveis 
  //posicao  /indice
  
  contador: inteiro
  nota: vetor[1..20] de real
  soma: real
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 

soma<-0

// algoritmo de inserção
para contador de 1 ate 20 passo 1 faça
     escreva("introduza a ",contador," nota: ")
     leia (nota[contador])
     soma<- soma + nota[contador]
fimpara

escreval ("--------------------------------------------------")

para contador de 1 ate 20 passo 1 faça
     escreval("A ",contador, " nota introduzida foi: ",nota[contador])
fimpara
escreva("A média das 20 notas é ", soma/20)



Fimalgoritmo