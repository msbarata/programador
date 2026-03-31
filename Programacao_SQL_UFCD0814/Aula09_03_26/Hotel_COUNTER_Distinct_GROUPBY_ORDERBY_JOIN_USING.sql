SELECT Sigla_Hotel, Count(Distinct Numero_Reserva) FROM Reserva 
JOIN Reserva_Quartos
USING (Numero_Reserva)
GROUP BY Sigla_Hotel
HAVING Count(Distinct Numero_Reserva)  >= ALL (SELECT Count(Distinct Numero_Reserva) FROM Reserva 
JOIN Reserva_Quartos
USING (Numero_Reserva)
GROUP BY Sigla_Hotel);