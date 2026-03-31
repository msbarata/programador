SELECT        q.Numero_Quarto,     h.Designacao,    q.Preco
FROM Quarto q 
INNER JOIN Hotel h ON q.Sigla_Hotel = h.Sigla_Hotel 
WHERE q.Numero_Quarto = (SELECT MAX(Numero_Quarto) FROM Quarto)
ORDER BY q.Preco DESC;