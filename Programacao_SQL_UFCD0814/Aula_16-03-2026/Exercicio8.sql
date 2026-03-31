CREATE VIEW vw_reservas_clientes  AS
SELECT Numero_Reserva, Nome_Cliente, Dia_Entrada, Dia_Saida
FROM reserva
JOIN cliente
USING (Numero_Cliente)
GROUP BY Numero_Cliente;
