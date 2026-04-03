Algoritmo "ARRAY/VETOR-CONTADOR_INTEIROS"
// Disciplina   : [Estrutura de Dados]
// Professor   : Antonio Pedro
// Autor(a)    : Manoel Barata
// Data atual  : 03/07/2025

Var
  numeros: vetor[0..5] de inteiro
   contador: inteiro
   positivos: inteiro
   negativos: inteiro
   zero: inteiro

Inicio

 positivos <- 0
 negativos <- 0
 zero <- 0

   para contador de 0 até 5 faça
      escreva("Digite um número inteiro:", contador, ": ")
      leia(numeros[contador])
   fimpara

     para contador de 0 até 5 faca
          se numeros[contador] = 0 então
             zero <- zero + 1
          senão
          se numeros[contador] < 0 então
          negativos <- negativos + 1
          senão
          positivos <- positivos + 1
       fimse
      fimse
   fimpara
   
     escreval("Numeros inteiros: ", numeros[0], numeros[1], numeros[2],numeros[3],numeros[4],numeros[5], " ")
     escreval("Quantidades de numeros positivos = ", positivos," ")
     escreval("Quantidade de zeros = ", zero," ")
     escreval("Quantidades de numeros negativos = ", negativos," ")
     
  se (positivos > negativos) e (positivos > zero) então
   escreval("Quantidade de números positivos é maior")
 senão
   se (negativos > positivos) e (negativos > zero) então
      escreval("Quantidade de números negativos é maior")
   senão
      se (zero > positivos) e (zero > negativos) então
         escreval("Quantidade de zeros é maior")
      senão
         escreval("Existe empate entre as categorias")
      fimse
   fimse
fimse
Fimalgoritmo