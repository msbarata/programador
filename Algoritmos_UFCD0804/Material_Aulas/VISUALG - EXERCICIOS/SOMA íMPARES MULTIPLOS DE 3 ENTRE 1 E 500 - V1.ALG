Algoritmo "Soma ímpares multiplos de 3 entre 1 e 500 - V1"

Var

  i,soma:inteiro

Inicio

  soma<-0
  para i<-1 ate 500 faca
   //vamos verificar agora se o número é múltiplo de 3 e ímpar

   se(i mod 3 = 0) e (i mod 2 <>0) entao
    soma<-soma + i
    // caso queiram ver os números
    escreva(i, " ")
   fimse
  fimpara
  escreval("")
  escreva("A soma de todos os números ímpares múltiplos de 3 entre 1 e 500 é: ",soma)
Fimalgoritmo