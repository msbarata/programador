SELECT 
    r.Numero_Cliente,
    COUNT(*) AS Total_Reservas
FROM reserva r
GROUP BY r.Numero_Cliente;