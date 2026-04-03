Algoritmo "soma dois numeros-comparar com 500 - Uso selecao encadeada e validar resposta com Repita"
//função: demonstração uso de seleção encadeada e ciclo repita para validar resposta
Var
 a,b,c:real
 resp:caractere


Inicio
 repita
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
  repita
   escreva("Deseja introduzir novos números - Prima S/s para sim ou N/n para não: ? ")
   leia(resp)
  ate (resp="N") ou (resp="n") ou (resp="S") ou (resp="s")

 ate (resp="N")ou (resp="n")

Fimalgoritmo