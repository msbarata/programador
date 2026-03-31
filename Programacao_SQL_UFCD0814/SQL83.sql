SELECT     c.Nome_Cliente,    i.Numero_Cliente
FROM Cliente c
INNER JOIN Individual i ON c.Numero_Cliente = i.Numero_Cliente