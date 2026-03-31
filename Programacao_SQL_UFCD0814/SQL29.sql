SELECT 
    h.Designacao
FROM Hotel h
INNER JOIN reserva_quartos rq ON h.Sigla_Hotel = rq.Sigla_Hotel
INNER JOIN reserva r ON rq.Numero_Reserva = r.Numero_Reserva
INNER JOIN organizacao o ON r.Numero_Cliente = o.Numero_Cliente
GROUP BY h.Designacao, h.Sigla_Hotel
HAVING COUNT(DISTINCT r.Numero_Cliente) = 1;