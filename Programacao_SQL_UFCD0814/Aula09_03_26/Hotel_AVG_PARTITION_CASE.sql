SELECT Sigla_Hotel, Numero_Quarto, Preco, AVG(Preco) OVER (PARTITION BY Sigla_Hotel) as media, 
CASE 
	WHEN Preco >  AVG(Preco) OVER (PARTITION BY Sigla_Hotel) THEN "Acima da média"
    WHEN Preco <  AVG(Preco) OVER (PARTITION BY Sigla_Hotel) THEN "Abaixo da média"
    ELSE "Igual à média"
END as Comparacao
FROM Quarto;