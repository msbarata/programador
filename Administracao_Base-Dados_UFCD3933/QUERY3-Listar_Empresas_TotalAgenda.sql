-- Listar empresas com suas localidades, com ordenação descendente pelo total de agendamentos
SELECT 
    e.Nome AS Empresa,
    e.Localidade,
    COUNT(a.numero_entrada) AS Total_Agendamentos
FROM dadosempresa e
LEFT JOIN agendamento a ON e.ID = a.ID_empresa
GROUP BY e.Nome
ORDER BY Total_Agendamentos DESC;