SELECT 
    c.Nome_Cliente
FROM Cliente c
INNER JOIN Organizacao o ON c.Numero_Cliente = o.Numero_Cliente
INNER JOIN Reserva r ON c.Numero_Cliente = r.Numero_Cliente
INNER JOIN Reserva_Quartos rq ON r.Numero_Reserva = rq.Numero_Reserva
GROUP BY c.Numero_Cliente, c.Nome_Cliente
HAVING COUNT(DISTINCT rq.Sigla_Hotel) > 1;