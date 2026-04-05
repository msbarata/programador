Algoritmo "ARRAY/VETOR"

Var
   aluno: vetor[1..5] de inteiro
   nome:  vetor[1..5] de caractere
   contador: inteiro

Inicio
   para contador de 1 até 5 faça
      escreva("Digite a nota do aluno ", contador, ": ")
      leia(aluno[contador])
      escreva("Digite o nome do aluno ", contador, ": ")
      leia(nome[contador])
      
   fimpara

   escreva("Notas dos alunos: ")
   para contador de 1 até 5 faca
      escreva(aluno[contador], " ")
      escreva(nome[contador], " ")
   fimpara
Fimalgoritmo