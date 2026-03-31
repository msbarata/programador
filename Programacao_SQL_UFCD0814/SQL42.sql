SELECT DISTINCT
    c.Nome_Cliente AS Nome_Cliente
FROM Cliente c
INNER JOIN Reserva r ON c.Numero_Cliente = r.Numero_Cliente
ORDER BY c.Nome_Cliente;