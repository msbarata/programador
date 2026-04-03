algoritmo "SOMA NUMEROS 1 ATE 50 - USANDO REPITA ...ATÉ - V3"

// Função :    Demonstrar o uso da estrutura de repetição Repita ...Até
var
soma,contador: inteiro

inicio

 soma<-0
 contador <- 0
 repita
     soma<- soma + contador
     contador <- contador + 1
     //escreval(soma)                //ciclo feito 51 vezes
 ate contador >50

 escreva("A soma é: ",soma)
fimalgoritmo
