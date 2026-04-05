algoritmo "Média de n números  - usando PARA - V2 "

var
// n é a quantidade de nºs a serem introduzidos pelo utilizador
i,n: inteiro
num, soma:real

inicio

soma<-0
escreva("Quantos números quer introduzir? ")
leia(n)
para i <-1 ate n faca
  escreva ("Introduza o ",i, "º número: ")
  leia(num)
  soma<- soma + num
fimpara

escreva("A soma é: ",soma, " e a média é ",soma/n)



fimalgoritmo
