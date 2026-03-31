SELECT Sigla_Hotel, SUM(Preco) FROM Quarto
GROUP BY Sigla_Hotel
ORDER BY SUM(Preco) DESC
LIMIT 1;