SELECT * FROM Reserva 
WHERE Numero_Cliente IN (SELECT Numero_Cliente FROM Individual);

SELECT * FROM Reserva 
WHERE Numero_Cliente NOT IN (SELECT Numero_Cliente FROM Individual);