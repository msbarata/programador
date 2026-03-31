SELECT * FROM Quarto
WHERE Preco = (SELECT MAX(Preco) FROM Quarto);