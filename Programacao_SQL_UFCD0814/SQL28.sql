SELECT 
    q.Numero_Quarto, 
    h.Designacao
FROM Quarto q
INNER JOIN Hotel h ON q.Sigla_Hotel = h.Sigla_Hotel
WHERE q.Numero_Quarto = (SELECT MAX(Numero_Quarto) FROM Quarto);