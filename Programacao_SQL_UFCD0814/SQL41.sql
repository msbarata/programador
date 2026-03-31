SELECT    
h.Designacao,
rq.Sigla_Hotel, 
rq.Numero_Reserva
FROM Hotel h 
INNER JOIN Reserva_Quartos rq ON rq.Sigla_Hotel = h.Sigla_Hotel
GROUP BY Numero_Reserva
ORDER BY SUM(Numero_Reserva) DESC
LIMIT 1;