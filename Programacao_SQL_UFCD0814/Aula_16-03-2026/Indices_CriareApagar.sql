SELECT * FROM Cliente WHERE Nome_Cliente = "CTT";
#Criar índices:

CREATE INDEX idx_nome
ON Cliente(Nome_Cliente);

CREATE INDEX idx_numero_data
ON Factura(Numero_Factura, Data_Factura);

CREATE FULLTEXT INDEX idx_pesquisa_longa
ON Hotel (Designacao);

#Mostrar índices:

SHOW INDEX FROM Cliente;
SHOW INDEX FROM Factura;
SHOW INDEX FROM Hotel;

#Apagar índices:

DROP INDEX idx_pesquisa_longa
ON Hotel;

DROP INDEX idx_nome
ON Cliente;






