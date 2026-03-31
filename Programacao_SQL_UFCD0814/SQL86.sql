SELECT DISTINCT Nome_Cliente FROM Cliente
JOIN reserva
USING (Numero_Cliente);
