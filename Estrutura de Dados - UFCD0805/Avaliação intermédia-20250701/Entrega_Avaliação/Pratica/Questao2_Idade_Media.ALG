Algoritmo "ARRAY_VETOR_IDADE-MEDIA"
// Disciplina   : [Estrutura de Dados]
// Professor   : Antonio Pedro
// Autor(a)    : Manoel Barata
// Data atual  : 03/07/2025
Var
  idade: vetor[0..4] de inteiro
   contador: inteiro
   posicaomaior, maioridade, idademaior: inteiro
   soma, media: real


Inicio
soma <-0
media <-0
idademaior <-0
maioridade <-0
posicaomaior <-0

   para contador de 0 até 4 faça
      escreva("Digite a sua idade-", contador, ": ")
      leia(idade[contador])
      soma <- soma + idade[contador]
      

      se idade[contador]>= 18 então
      idademaior <- idademaior + 1
      fimse
   fimpara
   
   para contador de 0 ate 4 faca
      se idade[contador] > maioridade então
         maioridade <- idade[contador]
         posicaomaior <- contador
      fimse
   fimpara
            media <- (soma/5)

     escreval("A idade média = ", media," anos")
     escreval("Maiores de idade = ", idademaior," pessoas. ")
     escreval("A maior idade é: ", maioridade," anos")
     escreval("Ela está na posição: ", posicaomaior)

Fimalgoritmo
