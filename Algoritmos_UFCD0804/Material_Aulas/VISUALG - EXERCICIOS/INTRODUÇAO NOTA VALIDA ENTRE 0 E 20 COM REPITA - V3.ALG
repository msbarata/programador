algoritmo "INTRODUÇAO NOTA VALIDA ENTRE 0 e 20 com repita - V3"

var
nota: real

inicio

 repita

   Escreva ("Introduza uma nota:")
   leia(nota)
   se (nota>=0) e (nota<=20)  entao
     escreva("A nota introduzida foi ", nota)
   senao
      escreval ("Nota inválida")
    //escreval escreve e muda de linha
   fimse
 ate (nota>=0) e (nota <=20)


fimalgoritmo
