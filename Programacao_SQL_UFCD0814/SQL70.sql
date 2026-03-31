SELECT "Individual" AS tipo, COUNT(*) AS "N.Clientes", SUM(Valor_Factura) AS "Total Facturado", SUM(Valor_Factura)/COUNT(*) AS "Média"
FROM Individual i,Reserva r, Factura f
WHERE i.Numero_Cliente = r.Numero_Cliente AND r.Numero_Reserva = f.Numero_Reserva
UNION
SELECT "Organizacao" AS tipo, COUNT(*) As "N.Clientes", SUM(Valor_Factura) As "Total Facturado", SUM(Valor_Factura)/COUNT(*) AS "Média"
FROM Organizacao o, Reserva r, Factura f
WHERE o.Numero_Cliente = r.Numero_Cliente AND r.Numero_Reserva = f.Numero_Reserva
