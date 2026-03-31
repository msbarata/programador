SELECT Sigla_Hotel, Numero_Quarto, Preco, SUM(Preco) OVER (PARTITION BY Sigla_Hotel)AS Soma_Preco_Hotel FROM Quarto;
