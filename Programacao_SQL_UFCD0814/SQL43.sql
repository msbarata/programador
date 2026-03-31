SELECT DISTINCT
    c.Nome_Cliente,
    o.Numero_Cliente,
    r.Numero_Reserva
FROM Cliente c
INNER JOIN Organizacao o ON c.Numero_Cliente = o.Numero_Cliente
INNER JOIN Reserva r ON r.Numero_Cliente = o.Numero_Cliente
Group BY o.Numero_Cliente
ORDER BY SUM(o.Numero_Cliente ) DESC
