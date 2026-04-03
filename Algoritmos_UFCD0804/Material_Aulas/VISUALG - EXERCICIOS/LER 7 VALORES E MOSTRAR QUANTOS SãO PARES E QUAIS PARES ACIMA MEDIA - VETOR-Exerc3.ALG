Algoritmo "Ler 7 valores e mostrar quantos são pares e quais pares acima media - vetor"

//Função:Exemplificar uso vetores - ver quantos são pares e quais são os pares acima média

Var

  i,n_pares, soma: inteiro
  media:real
  v:vetor[1..7] de inteiro

Inicio

  n_pares <- 0
  soma <- 0
  para i<- 1 ate 7 faca
   escreva("Introduza o ",i,"º valor inteiro: ")
   leia(v[i])
   soma <- soma + v[i]
  fimpara
  media <- soma / 7
 escreval("---------------------------------------------------------------------------------------------------------------------")
  escreval("A média dos 7 números é: ",media:4:1)
  escreval("---------------------------------------------------------------------------------------------------------------------")
  para i<- 1 ate 7 faca
  
    se (v[i] mod 2 = 0) entao
     n_pares <- n_pares +1
     escreva("O valor ",v[i], " é par e foi introduzido na posição ",i)
     se(v[i]> media) entao
      escreva(". Este valor está acima da média.")
     fimse
     escreval("")
    fimse
    
  fimpara
  escreval("---------------------------------------------------------------------------------------------------------------------")
  escreva("O número de pares introduzidos é: ",n_pares)
Fimalgoritmo
