SELECT 
    c.Nome_Cliente AS Nome_Organizacao,
    COUNT(r.Numero_Reserva) AS Total_Reservas
FROM Cliente c
INNER JOIN Organizacao o ON c.Numero_Cliente = o.Numero_Cliente
LEFT JOIN Reserva r ON c.Numero_Cliente = r.Numero_Cliente
GROUP BY c.Numero_Cliente, c.Nome_Cliente
ORDER BY Total_Reservas DESC;