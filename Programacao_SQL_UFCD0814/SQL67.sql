SELECT Sigla_Hotel, SUM(Numero_Camas) FROM Quarto
GROUP BY Sigla_Hotel;
