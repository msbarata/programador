algoritmo "INTRODUÇAO NOTA VALIDA ENTRE 0 e 20 com repita - V2"

var
nota: real

inicio

 repita

   Escreva ("Introduza uma nota:")
   leia(nota)
   se (nota<0) ou (nota>20)  entao
     escreval ("Nota inválida")
    //escreval escreve e muda de linha
   senao
     escreva("A nota introduzida foi ", nota)
   fimse
 ate (nota>=0) e (nota <=20)




fimalgoritmo
