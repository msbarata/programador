Algoritmo "Exercicio"

Var

vendas: vetor [0..2, 0..3] de real
t:vetor [0..3] de caracter
v:vetor [0..2] de caracter
total_v: vetor [0..2] de real

Inicio

vendas[0,0]<-1200.50
vendas[0,1]<-1350.00
vendas[0,2]<-1180.75
vendas[0,3]<-1420.30
vendas[1,0]<-980.20
vendas[1,1]<-1150.40
vendas[1,2]<-1300.60
vendas[1,3]<-1250.10
vendas[2,0]<-1400.80
vendas[2,1]<-1100.20
vendas[2,2]<-1380.90
vendas[2,3]<-1500.00

total_v[0]<-(vendas[0,0]+vendas[0,1]+vendas[0,2]+vendas[0,3])
total_v[1]<-(vendas[1,0]+vendas[1,1]+vendas[1,2]+vendas[1,3])
total_v[2]<-(vendas[2,0]+vendas[2,1]+vendas[2,2]+vendas[2,3])


t[0]<-"1º Trimestre"
t[1]<-"2º Trimestre"
t[2]<-"3º Trimestre"
t[3]<-"4º Trimestre"

v[0]<-"Ana"
v[1]<-"Bruno"
v[2]<-"Carlos"

escreval("        ",t[0]," ",t[1]," ",t[2]," ",t[3]," Total")
escreval(v[0],"    ",vendas[0,0],"€     ",vendas[0,1],"€       ",vendas[0,2],"€    ",vendas[0,3],"€     ",total_v[0],"€")
escreval(v[1],"  ",vendas[1,0],"€      ",vendas[1,1],"€     ",vendas[1,2],"€     ",vendas[1,3],"€     ",total_v[1],"€")
escreval(v[2]," ",vendas[2,0],"€     ",vendas[2,1],"€     ",vendas[2,2],"€     ",vendas[2,3],"€       ",total_v[2],"€")



Fimalgoritmo