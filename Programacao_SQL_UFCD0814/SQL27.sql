SELECT Sigla_Hotel, Numero_Quarto 
FROM Quarto
WHERE Numero_Quarto = (SELECT MAX(Numero_Quarto) FROM Quarto);