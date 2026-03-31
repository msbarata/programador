SELECT Sigla_Hotel, Numero_Camas, Preco
FROM quarto
WHERE Numero_Camas >=2 AND Preco < 150
ORDER BY Sigla_Hotel;