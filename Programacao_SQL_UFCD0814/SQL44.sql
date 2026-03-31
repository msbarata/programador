SELECT 
    AVG(q.Preco) AS Preco_Medio,
    h.Sigla_Hotel
FROM Quarto q
INNER JOIN Hotel h ON q.Sigla_Hotel = h.Sigla_Hotel
WHERE h.Sigla_Hotel LIKE '%SH%'
GROUP BY h.Sigla_Hotel;