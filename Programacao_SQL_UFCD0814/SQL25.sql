SELECT 
    Sigla_Hotel,
    COUNT(*) AS Numero_Quartos
FROM Quarto
GROUP BY Sigla_Hotel
ORDER BY Sigla_Hotel;