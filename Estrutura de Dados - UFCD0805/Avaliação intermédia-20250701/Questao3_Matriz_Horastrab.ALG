Algoritmo "Matriz-Horas_Trabalhadas"
// Disciplina   : Estrutura de Dados
// Professor   : Antonio Pedro
// Autor(a)    : Manoel Silva Barata
// Data atual  : 04/07/2025

Var

horastrab: vetor [0..2, 0..3] de real
coluna:vetor [0..3] de caracter
linha:vetor [0..2] de caracter
total_ht: vetor [0..2] de real
total_hd: vetor [0..3] de real
i,j: inteiro


Inicio


  para i de 0 até 2 faça
        para j de 0 até 3 faça
            escreva("Digite o total de horas trabalhadas hoje [", i, ",", j, "]: ")
            leia(horastrab[i, j])
        fimpara
    fimpara


total_ht[0]<-(horastrab[0,0]+horastrab[0,1]+horastrab[0,2]+horastrab[0,3])
total_ht[1]<-(horastrab[1,0]+horastrab[1,1]+horastrab[1,2]+horastrab[1,3])
total_ht[2]<-(horastrab[2,0]+horastrab[2,1]+horastrab[2,2]+horastrab[2,3])



total_hd[0]<-(horastrab[0,0]+horastrab[1,0]+horastrab[2,0])
total_hd[1]<-(horastrab[0,1]+horastrab[1,1]+horastrab[2,1])
total_hd[2]<-(horastrab[0,2]+horastrab[1,2]+horastrab[2,2])
total_hd[3]<-(horastrab[0,3]+horastrab[1,3]+horastrab[2,3])


coluna[0]<-"Segunda"
coluna[1]<-"Terça"
coluna[2]<-"Quarta"
coluna[3]<-"Quinta"

linha[0]<-"Funcionário 1"
linha[1]<-"Funcionário 2"
linha[2]<-"Funcionário 3"

escreval("              ",coluna[0],"    ",coluna[1],"   ",coluna[2],"    ",coluna[3],"    Total")
escreval(linha[0],"    ",horastrab[0,0],"h     ",horastrab[0,1],"h      ",horastrab[0,2],"h    ",horastrab[0,3],"h     ",total_ht[0],"h")
escreval(linha[1],"    ",horastrab[1,0],"h      ",horastrab[1,1],"h     ",horastrab[1,2],"h     ",horastrab[1,3],"h     ",total_ht[1],"h")
escreval(linha[2],"    ",horastrab[2,0],"h     ",horastrab[2,1],"h     ",horastrab[2,2],"h     ",horastrab[2,3],"h       ",total_ht[2],"h")

escreval("Total de horas trabalhadas por dia:  ")
escreval(coluna[0],": ",total_hd[0],"h; ")
escreval(coluna[1],": ",total_hd[1],"h; ")
escreval(coluna[2],": ",total_hd[2],"h; ")
escreval(coluna[3],": ",total_hd[3],"h. ")


      se (total_ht[0] > total_ht[1]) e (total_ht[0] > total_ht[2]) então
    escreval("Funcionário 1 trabalhou mais horas")
       senão
        se (total_ht[1] > total_ht[0]) e (total_ht[1] > total_ht[2])   então
        escreva ("Funcionário 2 trabalhou mais horas")
        senão
            se (total_ht[2] > total_ht[0]) e (total_ht[2] > total_ht[1])   então
             escreva ("Funcionário 3 trabalhou mais horas")
             fimse
        fimse
    fimse
       

Fimalgoritmo