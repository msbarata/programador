SELECT Sigla_Hotel, COUNT(*) Numero_Quarto
FROM Quarto
GROUP BY Sigla_Hotel
HAVING COUNT(*) > 4