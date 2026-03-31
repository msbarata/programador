SELECT Numero_Cliente, COUNT(*) AS "Quantidade Reservas" FROM Reserva
GROUP BY Numero_Cliente;