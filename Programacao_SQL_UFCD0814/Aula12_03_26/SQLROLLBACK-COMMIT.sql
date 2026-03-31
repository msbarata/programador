USE hotel_5086;
START transaction;
INSERT INTO Cliente(Nome_Cliente,Numero_Cliente)
VALUES ("TESTE",1562405);
COMMIT;
ROLLBACK;

SELECT * FROM Cliente;
