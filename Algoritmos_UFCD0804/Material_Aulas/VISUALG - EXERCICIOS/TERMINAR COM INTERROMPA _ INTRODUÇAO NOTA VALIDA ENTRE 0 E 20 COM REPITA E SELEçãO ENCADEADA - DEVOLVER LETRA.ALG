algoritmo "INTRODUÇAO NOTA VALIDA ENTRE 0 e 20 com repita e seleção encadeada - Devolver letra"

var
nota: real
inicio


enquanto verdadeiro faca

 escreva("*** Introduza uma nota:(999 - para terminar) *** ")
 leia(nota)
 se nota=999 entao
    escreva ("***** Programa Terminado. Digitou 999 ******")
    interrompa
 senao
  se (nota<0) ou (nota>20) entao
   escreval ("Nota Inválida")
  senao
   se nota <=9.4 entao
    escreval ("A nota introduzida foi ", nota," e corresponde à letra D")
   senao
     se nota <=14.9 entao
     escreval ("A nota introduzida foi ", nota," e corresponde à letra C")
     senao
       se nota<=17.9 entao
       escreval ("A nota introduzida foi ", nota," e corresponde à letra B")
      senao
        escreval ("A nota introduzida foi ", nota," e corresponde à letra A")
       fimse
     fimse
   fimse
  fimse
 fimse
 escreval()
 fimenquanto



fimalgoritmo
