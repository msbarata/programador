Algoritmo "Soma ímpares multiplos de 3 entre 1 e 500 - V2"

Var

  i,soma:inteiro

Inicio

  soma<-0
  para i<-1 ate 500 passo 2 faca   // deste modo, vamos tendo os ímpares
   //vamos verificar agora se o número é múltiplo de 3

   se(i mod 3 = 0) entao
    soma<-soma + i
    // caso queiram ver os números
    escreva(i, " ")
   fimse
  fimpara
  escreval("")
  escreva("A soma de todos os números ímpares múltiplos de 3 entre 1 e 500 é: ",soma)
Fimalgoritmo

