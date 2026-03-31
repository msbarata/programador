CREATE VIEW vw_facturas_detalhadas AS
SELECT Numero_Factura, Nome_Cliente, Numero_Reserva, Valor_Factura, Data_Factura
FROM factura
JOIN reserva
USING (Numero_Reserva)
JOIN cliente
USING (Numero_Cliente)
GROUP BY Numero_Cliente
ORDER BY Numero_Factura ASC;

SELECT * FROM vw_facturas_detalhadas; 