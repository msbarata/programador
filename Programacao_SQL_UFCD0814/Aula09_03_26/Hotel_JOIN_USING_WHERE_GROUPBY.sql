SELECT * FROM hotel
JOIN Quarto
USING (Sigla_Hotel)
WHERE Numero_Camas >= 2
GROUP BY Designacao;