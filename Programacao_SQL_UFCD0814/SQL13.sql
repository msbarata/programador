SELECT AVG(Preco) AS Media_Preco
FROM Quarto
WHERE Sigla_Hotel = 'SH' 
  AND Numero_Camas >= 2;