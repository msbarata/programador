CREATE INDEX idx_quartos_hotel
ON Quarto(Numero_Quarto, Sigla_Hotel);

SHOW INDEX FROM Quarto;

#DROP INDEX idx_quartos_hotel
#ON Quarto;



SELECT * FROM Quarto
WHERE Sigla_Hotel = 'ML'
AND Numero_Quarto = 3;

