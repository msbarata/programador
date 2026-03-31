SELECT Nome_Cliente, Numero_Cliente, COUNT(*) as "Reservas", RANK() OVER (ORDER BY Reservas DESC) FROM reserva
JOIN Cliente
Using (Numero_Cliente)
GROUP BY Numero_Cliente;