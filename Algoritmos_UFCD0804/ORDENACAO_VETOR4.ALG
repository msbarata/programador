Algoritmo "Ordenacao_Vetor4"

Var

  i, j, aux: inteiro               // aux é do mesmo tipo que v
  v: vetor[1..4]de inteiro
Inicio

//inicializar o vetor
  para i<-1 ate 4 faca
     escreva ("Digite o",i,"º valor: ")
     leia (v[i])
  fimpara
//para ordenar os vetores, precisamos de um ciclo para dentro de outro para com
//índices diferentes
   para i<- 1 ate 3 faca      // 3= comprimento - 1, isto é, 4-1=3
     para j<-i+1 até 4 faca
       se (v[i]>v[j]) entao
           aux<-v[i]
           v[i]<-v[j]
           v[j]<-aux
       fimse
     fimpara

   fimpara
   // vamos mostrar os valores ordenados do vetor
   escreva ("O vetor ordenado é: ")
   para i<-1 ate 4 faca
     escreva (v[i], " ")
   fimpara
Fimalgoritmo