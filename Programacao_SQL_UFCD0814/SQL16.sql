SELECT COUNT(DISTINCT Numero_Cliente)
FROM Reserva
WHERE Numero_Cliente IN (SELECT Numero_Cliente FROM Individual);