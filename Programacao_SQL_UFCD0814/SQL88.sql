SELECT Sigla_Hotel, COUNT(DISTINCT Numero_Reserva) as "reservas", RANK() OVER ( ORDER BY reservas DESC) FROM Reserva
JOIN Reserva_Quartos
USING (Numero_Reserva)
GROUP BY Sigla_Hotel;