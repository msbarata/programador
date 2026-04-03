Algoritmo "Listagem da turma - Exemplo uso Vetores"

// vamos inserir alunos através dos seus nomes e duas notas para cada aluno
// e calcular a média de cada aluno

Var

//guarda o nome dos alunos
  nome: vetor[1..4] de caractere
// guarda a 1ª nota dos alunos
  n1: vetor [1..4] de real
// guarda a 2ª nota dos alunos
  n2: vetor [1..4] de real
//guarda a média dos alunos
  media: vetor[1..4] de real
  i: inteiro


Inicio

// para cada aluno vamos inserir o seu nome e as suas duas notas
para i<-1 ate 4 faca
   escreval ("Aluno ", i)
   escreva ("Nome: ")
   leia (nome[i])
   escreva ("Primeira nota: ")
   leia (n1[i])
   escreva ("Segunda nota: ")
   leia (n2[i])
   media[i] <-(n1[i]+n2[i])/2
 fimpara
 // vamos limpar o ecrâ e gerar uma listagem de alunos    limpatela
 limpatela
 escreval("Listagem de alunos - nomes e médias")
 escreval ("---------------------------------------")
 para i<-1 ate 4 faca
 //nome[i]:15 vai escrever o nome com 15 espaços, se não forem utilizados complementa
 //com espaços em branco, media[i]:4:1 são 4 espaços ao todo e 1 casa decimal
     escreval (nome[i]:15, media[i]:4:1)
 fimpara


Fimalgoritmo