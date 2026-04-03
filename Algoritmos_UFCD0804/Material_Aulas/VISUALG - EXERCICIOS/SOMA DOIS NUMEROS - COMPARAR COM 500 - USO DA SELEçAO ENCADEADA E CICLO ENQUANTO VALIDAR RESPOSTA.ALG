Algoritmo "soma dois numeros - Comparar com 500 - uso da seleçao encadeada e ciclo Enquanto validar resposta"
// função: demonstração uso seleção encadeada e ciclo enquanto validar resposta
Var
 a,b,c:real
 resp:caractere


Inicio

  resp <-"s"  // um exemplo para poder entrar no ciclo enquanto
  enquanto (resp="s") ou (resp="S")  faca
    escreva ("Introduza o primeiro número: ")
    leia(a)
    escreva ("Introduza o segundo número: ")
    leia(b)
    c <- a+b

    escreval("A soma dos dois números é: ",c)
    se c<500 entao
      escreval("A soma dos dois números é menor do que 500")
    senão
     se c=500 entao
        escreval("A soma dos dois números é igual a 500")
     senao
         escreval("A soma dos dois números é maior do que 500")
     fimse
    fimse

    escreva("Deseja introduzir novos números - Prima S/s para sim ou N/n para não: ? ")
    leia(resp)
     // se a resposta não for válida, isto é se não for
     // S ou s ou N ou n  , vai entrar no ciclo enquanto
     // que se segue
    enquanto (resp<>"S") e (resp<>"s") e (resp<>"N") e (resp<>"n") faca
        Escreval ("Resposta inválida. A sua resposta só pode ser S/s/N/n")
        escreva("Deseja introduzir novos números? ")
        leia(resp)
    fimenquanto

   fimenquanto

Fimalgoritmo