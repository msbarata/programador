#CREATE VIEW vw_facturas_clientes AS
SELECT Numero_Factura, Nome_Cliente, Numero_Reserva, Data_Factura, Valor_Factura
FROM factura
JOIN reserva
USING (Numero_Reserva)
JOIN cliente
USING (Numero_Cliente)
GROUP BY Numero_Cliente
ORDER BY Numero_Factura ASC;

SELECT * FROM vw_facturas_clientes; 