SELECT Numero_Quarto, Preco
FROM Quarto
WHERE Preco = (SELECT MAX(Preco) FROM Quarto);