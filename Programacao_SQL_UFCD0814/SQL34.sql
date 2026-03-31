SELECT    
    q.Numero_Quarto, 
    h.Designacao,
    h.Sigla_Hotel
FROM Quarto q
INNER JOIN Hotel h ON q.Sigla_Hotel = h.Sigla_Hotel
WHERE h.Designacao LIKE '% Sheraton %'
