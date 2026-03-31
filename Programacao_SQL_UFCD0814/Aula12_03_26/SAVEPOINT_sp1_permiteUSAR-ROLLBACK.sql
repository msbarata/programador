START TRANSACTION;

INSERT INTO Reserva(Numero_Reserva,Numero_Cliente,

Dia_Entrada,Dia_Saida)

VALUES (1323415,2002,"2026-03-12 17:00:00","2026-03-13 12:00:00");

INSERT INTO Reserva_Quartos(Sigla_Hotel,Numero_Quarto,Numero_Reserva,Numero_Pessoas)

VALUES ("ML",2,1323415,2);
SAVEPOINT sp1;
INSERT INTO Factura(Numero_Factura,Numero_Reserva,Data_Factura,Valor_Factura)

VALUES (0542305,1323415,"2026-03-12 17:00:00",300);
SAVEPOINT sp2;


ROLLBACK TO sp1

COMMIT;