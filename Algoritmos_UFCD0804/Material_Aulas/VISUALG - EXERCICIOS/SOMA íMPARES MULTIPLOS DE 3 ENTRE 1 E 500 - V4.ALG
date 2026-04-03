Algoritmo "Soma ímpares multiplos de 3 entre 1 e 500 - V4"

Var

  i,soma:inteiro

Inicio

  soma<-0
  i<-1
  enquanto (i<=500) faca
   //verificação se o número é múltiplo de 3 e ímpar

   se(i mod 3 = 0) entao
    soma<-soma + i
    // caso queiram ver os números
    escreva(i, " ")
   fimse
   i<-i+2
  fimenquanto
  escreval("")
  escreva("A soma de todos os números ímpares múltiplos de 3 entre 1 e 500 é: ",soma)
Fimalgoritmo

