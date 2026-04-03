Algoritmo "Vetores"
// Função: ilustrar o uso de vetores
Var

    i: inteiro
    v: vetor [1..3] de real
    soma: real
    
Inicio

        soma<- 0
        para i<- 1 ate 3 faca
          escreva ("Digite a ",i,"ª nota: ")
          leia (v[i])
          soma<- soma + v[i]
        fimpara
        para i<-1 ate 3 faca
           Escreval ("A ",i,"ª nota introduzida foi: ", v[i])
        fimpara
        escreva ("A média das 3 notas é: ", soma/3)
        // observação: melhorem o exercício para validar as notas, como
        // já sabem fazer...


Fimalgoritmo