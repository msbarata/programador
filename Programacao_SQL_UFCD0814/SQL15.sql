SELECT 
    Numero_Camas,
    COUNT(*) AS Quantidade_Quartos,
    SUM(Preco) AS Faturacao_Noite
FROM Quarto
WHERE Sigla_Hotel = 'SH'