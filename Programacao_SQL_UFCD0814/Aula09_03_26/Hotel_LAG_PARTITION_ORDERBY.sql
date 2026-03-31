SELECT Numero_Cliente,Numero_Reserva, Dia_Entrada, LAG(Dia_Entrada) OVER (PARTITION BY Numero_Cliente ORDER BY Dia_Entrada ) FROM Reserva;
