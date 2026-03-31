START TRANSACTION;

INSERT INTO Reserva(Numero_Reserva,Numero_Cliente,

Dia_Entrada,Dia_Saida)

VALUES (1323480,2004,"2026-03-16 17:00:00","2026-03-18 12:00:00");

INSERT INTO Reserva_Quartos(Sigla_Hotel,Numero_Quarto,Numero_Reserva,Numero_Pessoas)

VALUES ("IB",2,1323480,2);

INSERT INTO Factura(Numero_Factura,Numero_Reserva,Data_Factura,Valor_Factura)

VALUES (0542380,1323480,"2026-03-16 17:00:00",600);

COMMIT;

SELECT * FROM Reserva;