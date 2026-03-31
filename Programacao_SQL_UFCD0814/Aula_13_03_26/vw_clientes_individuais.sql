
CREATE VIEW vw_clientes_individuais AS
SELECT Numero_Cliente, Nome_Cliente, CC
FROM cliente
JOIN individual
USING (Numero_Cliente)
GROUP BY Numero_Cliente;

SELECT * FROM vw_clientes_individuais;