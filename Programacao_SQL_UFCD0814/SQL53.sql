SELECT * FROM Reserva r
LEFT JOIN Factura f
ON f.Numero_Reserva = r.Numero_Reserva
WHERE Numero_Factura IS NULL;