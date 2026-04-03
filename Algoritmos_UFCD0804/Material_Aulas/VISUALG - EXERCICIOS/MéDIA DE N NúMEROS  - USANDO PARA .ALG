algoritmo "Média de n números  - usando PARA "

var
// n é a quantidade de nºs a serem introduzidos pelo utilizador
i,n: inteiro
num, soma,media:real

inicio

soma<-0
escreva("Quantos números quer introduzir? ")
leia(n)
para i <-1 ate n faca
  escreva ("Introduza o ",i, "º número: ")
  leia(num)
  soma<- soma + num
fimpara
media<-soma/n
escreva("A soma é: ",soma, " e a média é ",media)



fimalgoritmo
