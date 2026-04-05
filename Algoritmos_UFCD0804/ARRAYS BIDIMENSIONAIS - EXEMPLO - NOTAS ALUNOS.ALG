Algoritmo "Arrays bidimensionais - exemplo - NOTAS ALUNOS"


// Descrição   : Neste exercício VAMOS CONSIDERAR UMA TURMA DE 5 ALUNOS,
// OS QUAIS FIZERAM TRÊS EXAMES CADA UM. PODEMOS DEFINIR NESTE CASO
// UM ARRAY DE DUAS DIMENSÕES, PARA GUARDAR AS NOTAS DOS ALUNOS NOS RESPETIVOS
//EXAMES e vamos CALCULAR A MÉDIA DO ALUNO (média dos três exames do aluno) e a
//MÉDIA DE CADA EXAME

Var

// notas é o array de notas para guardar as notas dos alunos nos respetivos exames

    notas: vetor [1..5,1..3] de real
    i,j: inteiro
    soma,media: real

Inicio
//introdução das notas dos alunos nos três exames
para i<-1 ate 5 faca
  escreval("-----------------------------------------------------------")
  para j<-1 ate 3 faca
       Escreva ("Introduza a nota do aluno ",i," no exame ", j, ": ")
       leia (notas[i,j])
  fimpara

fimpara
// cálculo da média de cada aluno  e mostrar a mesma
limpatela
para  i<-1 ate 5 faca
     soma<-0
     para  j<-1 ate 3 faca
         soma<-soma + notas[i,j]]
     fimpara
     media<-soma/3
     Escreval ("A média do aluno ",i," é ",media:4:1)

fimpara
 escreval("-----------------------------------------------------------")
 //cálculo da média de cada exame - relembrar: temos 5 alunos em que cada um
 //realizou três exames
 para  j<-1 ate 3 faca
   soma<-0
   para i<-1 ate 5 faca
     soma<-soma+ notas[i,j]
   fimpara
   media<-soma/5
   escreval ("A média do exame nº ",j, " é ",  media:4:1)
 fimpara
 

Fimalgoritmo