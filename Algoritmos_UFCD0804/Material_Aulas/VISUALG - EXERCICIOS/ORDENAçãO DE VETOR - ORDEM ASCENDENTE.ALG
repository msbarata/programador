Algoritmo "Ordenação de vetor - ordem ascendente"

Var

  i, j, aux: inteiro
  v: vetor[1..4]de inteiro
Inicio

//inicializar o vetor
  para i<-1 ate 4 faca
     Escreva ("Digite um valor inteiro: ")
     leia (v[i])
  fimpara
//para ordenar o vetor, precisamos de um ciclo para dentro de outro para com
//índices diferentes
   para i<- 1 ate 3 faca      // 3= total de casas - 1, isto é, 4-1=3
     para j<-i+1 até 4 faca
       se (v[i]>v[j]) entao
           aux<-v[i]
           v[i]<-v[j]
           v[j]<-aux
       fimse
     
     fimpara

   fimpara
   // vamos mostrar os valores ordenados do vetor - ordem crescente
   Escreva ("O vetor ordenado é: ")
   para i<-1 ate 4 faca
     escreva (v[i], " ")
   fimpara
     
Fimalgoritmo