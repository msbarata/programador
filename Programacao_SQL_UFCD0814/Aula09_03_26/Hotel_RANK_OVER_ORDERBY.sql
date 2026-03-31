SELECT Sigla_Hotel, Numero_Quarto, Preco, RANK() OVER (ORDER BY Preco DESC) FROM Quarto

