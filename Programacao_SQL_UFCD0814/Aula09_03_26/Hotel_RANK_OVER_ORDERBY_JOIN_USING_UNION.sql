SELECT Nome_Cliente,Reservas,RANK() OVER (ORDER BY Reservas DESC) FROM (
SELECT Nome_Cliente,COUNT(*) as "reservas" FROM Reserva
JOIN Cliente
USING (Numero_Cliente)
GROUP BY Numero_Cliente

UNION 

SELECT Nome_Cliente, 0 as "reservas" FROM Cliente
WHERE Numero_Cliente NOT IN (SELECT Numero_Cliente FROM Reserva)) tb1
 