use hotel_5086;

CREATE VIEW Reservas_Organizacoes AS
SELECT * FROM Reserva
WHERE Numero_Cliente IN (SELECT Numero_Cliente FROM Organizacao);

SELECT * FROM Reservas_Organizacoes;
