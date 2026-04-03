algoritmo "PRODUTO DOS NUMEROS Inteiros positivos DE 1 ATE 10 - usando PARA"

var
prod,contador: inteiro

inicio

 prod<-1
 para contador <-1 ate 10 faca
   prod<- prod * contador
   escreval(prod)
 fimpara
 escreva("O produto é: ",prod)

// observação: apesar de o resultado da multiplicaçao de inteiros positivos
//dar um inteiro positivo, este resultado deve ser declarado como real
//porque se forem muitos numeros a serem multiplicados
// é excedida a capacidade de memória para os inteiros. Por exemplo,
// imagine multiplicar todos os números até ao 50. E depois experimente
//declarando como real
fimalgoritmo
