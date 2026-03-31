START TRANSACTION;

INSERT INTO Reserva(Numero_Reserva,Numero_Cliente,

Dia_Entrada,Dia_Saida)

VALUES (1323481,2004,"2026-03-17 17:00:00","2026-03-18 12:00:00");

INSERT INTO Reserva_Quartos(Sigla_Hotel,Numero_Quarto,Numero_Reserva,Numero_Pessoas)

VALUES ("IB",2,1323481,2);

INSERT INTO Factura(Numero_Factura,Numero_Reserva,Data_Factura,Valor_Factura)

VALUES (0542381,1323481,"2026-03-17 17:00:00",300);

ROLLBACK;

SELECT * FROM Reserva;

