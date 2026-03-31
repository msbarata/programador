SELECT DISTINCT
    c.Nome_Cliente,
    r.Numero_Reserva
FROM Cliente c
INNER JOIN Reserva r ON c.Numero_Cliente = r.Numero_Cliente
Group BY c.Numero_Cliente
ORDER BY SUM(r.Numero_Reserva ) DESC