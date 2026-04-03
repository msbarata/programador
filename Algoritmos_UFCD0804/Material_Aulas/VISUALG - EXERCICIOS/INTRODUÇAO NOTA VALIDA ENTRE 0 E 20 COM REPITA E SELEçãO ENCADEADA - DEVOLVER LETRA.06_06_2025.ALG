algoritmo "INTRODUÇAO NOTA VALIDA ENTRE 0 e 20 com repita e seleção encadeada - Devolver letra"

var
nota: real
resposta: caractere

inicio


repita
 escreva ("Introduza uma nota:")
 leia(nota)

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
 repita
   escreva ("Quer continuar (S/s/N/n)?  ")
   leia (resposta)
 ate (resposta="S") ou (resposta="s") ou (resposta="N") ou (resposta="n")
ate (resposta="N") ou (resposta="n")



fimalgoritmo
