CREATE VIEW vw_reservas_detalhadas AS
SELECT Numero_Reserva, Nome_Cliente, Sigla_Hotel, Numero_Quarto, Numero_Pessoas, Dia_Entrada, Dia_Saida
FROM reserva
JOIN cliente
USING (Numero_Cliente)
JOIN reserva_quartos
USING (Numero_Reserva)

GROUP BY Numero_Reserva;

SELECT * FROM vw_reservas_detalhadas;

