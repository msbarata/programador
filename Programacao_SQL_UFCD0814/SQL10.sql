SELECT Numero_Quarto
FROM Quarto
WHERE Sigla_Hotel = 'SH' 
  AND Preco <= 200
  AND Numero_Camas >= 2;