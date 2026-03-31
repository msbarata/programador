SELECT    
Sigla_Hotel, Preco
FROM Quarto
GROUP BY Numero_Quarto
ORDER BY SUM(Preco ) DESC
LIMIT 1;
