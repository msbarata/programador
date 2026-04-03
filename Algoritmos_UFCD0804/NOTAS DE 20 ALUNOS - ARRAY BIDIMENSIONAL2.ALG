Algoritmo "Notas de 20 alunos - Array Bidimensional"
/
Var
// Seção de Declarações das variáveis
  //posicao  /indice

  linha, coluna: inteiro
  nota: vetor[1..20, 1..3] de real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...

// algoritmo de inserção

para linha de 1 ate 20 passo 1 faça
     para coluna de 1 ate 3 passo 1 faça
          escreva("introduza a nota ",linha," no teste ",coluna,"  :")
           leia (nota[linha,coluna])
    fimpara
fimpara

para linha de 1 ate 20 passo 1 faça
     para coluna de 1 ate 3 passo 1 faça
     
     escreval("A nota do",linha, "aluno ao teste: ",coluna, "foi", nota[linha,coluna])
     fimpara
fimpara


Fimalgoritmo