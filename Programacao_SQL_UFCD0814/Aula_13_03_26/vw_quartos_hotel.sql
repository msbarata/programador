#CREATE VIEW vw_quartos_hotel AS

SELECT Sigla_Hotel, Designacao, Numero_Quarto, Numero_Camas, Preco
FROM hotel
JOIN quarto
USING (Sigla_Hotel)
GROUP BY Sigla_Hotel;

SELECT * FROM vw_quartos_hotel;