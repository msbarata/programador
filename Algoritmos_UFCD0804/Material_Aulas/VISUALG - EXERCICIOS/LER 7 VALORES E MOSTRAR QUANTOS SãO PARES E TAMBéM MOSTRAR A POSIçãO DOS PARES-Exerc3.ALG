Algoritmo "Ler 7 valores e mostrar quantos são pares e também mostrar a posição dos pares"

Var

    i, cont: inteiro
    // cont vai contar o número de pares
    v: vetor[1..7] de inteiro

Inicio

     cont<-0
     para i<-1 ate 7 faca
       escreva ("Digite o ",i,"º valor inteiro: ")
       leia (v[i])
     fimpara
     para i<-1 ate 7 faca
       se (v[i] mod 2=0) entao
         cont<-cont + 1
         escreval ("Valor par na posição ",i)
       fimse
     fimpara
     escreva ("O total de pares foi ", cont)

Fimalgoritmo