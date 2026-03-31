
SELECT Sigla_Hotel, Numero_Quarto, Preco, ROW_NUMBER() OVER (PARTITION BY Sigla_Hotel ORDER BY Numero_Quarto)AS Sequencia FROM Quarto;