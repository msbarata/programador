Algoritmo "Matriz-Media_Disciplinas"
// Disciplina   : Estrutura de Dados
// Professor   : Antonio Pedro
// Autor(a)    : Manoel Silva Barata
// Data atual  : 04/07/2025

Var
// coluna - disciplinas
//linha - aluno

notas: vetor [1..4, 1..3] de real
aluno: vetor [1..4] de inteiro
medialuno: vetor [1..4] de real
aprovaluno: vetor [1..4] de caracter
mediamat: real
mediaport: real
mediaing: real
melhordisc: caracter
mediamaior: real
somatotnotas: real
mediatotnotas: real
totalap,totalnotas,i,j: inteiro


Inicio

 totalap <- 0
 somatotnotas <- 0
 totalnotas <- 0

  para i de 1 até 4 faça
        para j de 1 até 3 faça
            escreva("Digite a nota do aluno [", i, ", para a disciplina", j, "]: ")
            leia(notas[i, j])
        fimpara
    fimpara
    
    
    
    para i de 1 até 4 faça
        para j de 1 até 3 faça

       somatotnotas<- (somatotnotas + (notas[i, j]))

        fimpara
    fimpara
    
    
     mediatotnotas<-  (somatotnotas/12)
    
    
    
    
  para i de 1 até 4 faça
  
     aluno[i]<- i
     
  fimpara

medialuno[1]<-(notas[1,1]+ notas[1,2]+ notas[1,3])/3
medialuno[2]<-(notas[2,1]+ notas[2,2]+ notas[2,3])/3
medialuno[3]<-(notas[3,1]+ notas[3,2]+ notas[3,3])/3
medialuno[4]<-(notas[4,1]+ notas[4,2]+ notas[4,3])/3

   se medialuno[1]>=10 então
       aprovaluno[1] <- ("Aprovado")
       senao
       aprovaluno[1] <- ("Reprovado")
   fimse
   
   se medialuno[2]>=10 então
       aprovaluno[2] <- ("Aprovado")
       senao
       aprovaluno[2] <- ("Reprovado")
   fimse
   
   se medialuno[3]>=10 então
       aprovaluno[3] <- ("Aprovado")
       senao
       aprovaluno[3] <- ("Reprovado")
   fimse
   
    se medialuno[4]>=10 então
       aprovaluno[4] <- ("Aprovado")
       senao
       aprovaluno[4] <- ("Reprovado")
   fimse
   
   
   para i de 1 até 4 faça

      se  aprovaluno[i] = ("Aprovado") entao
      totalap<- totalap+1
      fimse
  fimpara
   
mediamat<-((notas[1,1]+ notas[2,1]+ notas[3,1])+ notas[4,1])/4)
mediaport<-((notas[1,2]+ notas[2,2]+ notas[3,2])+ notas[4,2])/4)
mediaing<-((notas[1,2]+ notas[2,2]+ notas[3,2])+ notas[4,2])/4)


   se  ((mediamat > mediaport) e (mediamat > mediaing))  então
        melhordisc <- ("Matemática")
        mediamaior <- mediamat

      senão
           se  ((mediaport > mediamat) e (mediaport > mediaing)) então
           melhordisc <- ("Português")
            mediamaior <- mediaport
                 senão
                 
            se ((mediaing > mediamat) e (mediaing > mediaport)) então
                 melhordisc <- ("Inglês")
                  mediamaior <- mediaing
       senão
              se ((mediamat = mediaport) e (mediamat = mediaing)) então
                     melhordisc <- ("As disciplinas apresentam médias iguais")
                     mediamaior <- mediamat
              senão
              
              se   ((mediamat = mediaport) e (mediamat <> mediaing))  então
              
                     melhordisc <- ("Matemática e Português apresentam médias iguais")
                     mediamaior <- mediamat
              senão
              
              se    ((mediaport = mediaing) e (mediaport <> mediamat))  então

                     melhordisc <- ("Português e Inglês apresentam médias iguais")
                     mediamaior <- mediaport

                  fimse
               fimse
            fimse
          fimse
      fimse
fimse

   

escreval ("                  ","=== RELATÓRIO DA TURMA===")
escreval("Aluno"," Mat.","     Port.","   Ing.","    Média","   Situação")
escreval(aluno[1],"    ",notas[1,1],"     ",notas[1,2],"      ",notas[1,3],"    ",medialuno[1],"     ",aprovaluno[1])
escreval(aluno[2],"    ",notas[2,1],"     ",notas[2,2],"      ",notas[2,3],"    ",medialuno[2],"     ",aprovaluno[2])
escreval(aluno[3],"    ",notas[3,1],"     ",notas[3,2],"      ",notas[3,3],"    ",medialuno[3],"     ",aprovaluno[3])
escreval(aluno[4],"     ",notas[4,1],"     ",notas[4,2],"      ",notas[4,3],"    ",medialuno[4],"     ",aprovaluno[4])
escreval("Alunos aprovados: ", totalap, " de 4")
escreval("Melhor disciplina: ", melhordisc, " (Média :", mediamaior,")")
escreval("Média geral da turma ", mediatotnotas)








Fimalgoritmo