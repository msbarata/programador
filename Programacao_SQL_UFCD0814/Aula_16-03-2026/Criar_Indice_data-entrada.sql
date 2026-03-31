CREATE INDEX idx_data_entrada
ON Reserva(Numero_Reserva, Dia_Entrada);

SELECT * FROM Reserva
WHERE Dia_Entrada > '2024-11-01';
