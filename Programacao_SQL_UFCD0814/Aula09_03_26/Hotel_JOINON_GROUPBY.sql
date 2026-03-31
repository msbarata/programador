SELECT Numero_Cliente, Sigla_Hotel, SUM(Valor_Factura) FROM Reserva
JOIN Factura
ON Reserva.Numero_Reserva = Factura.Numero_Reserva
JOIN Reserva_Quartos
ON Reserva.Numero_Reserva = Reserva_Quartos.Numero_Reserva
GROUP BY Numero_Cliente, Sigla_Hotel;