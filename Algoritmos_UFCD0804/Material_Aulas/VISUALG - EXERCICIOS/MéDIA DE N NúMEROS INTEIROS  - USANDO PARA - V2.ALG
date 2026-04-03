algoritmo "Média de n números inteiros  - usando PARA - V2"

var
// n é a quantidade de nºs a serem introduzidos pelo utilizador
i,n, num, soma: inteiro

inicio

soma<-0
escreva("Quantos números inteiros quer introduzir? ")
leia(n)
para i <-1 ate n faca
  escreva ("Introduza o ",i, "º número inteiro: ")
  leia(num)
  soma<- soma + num
fimpara

escreva("A soma é: ",soma, " e a média é ",soma/n)



fimalgoritmo
