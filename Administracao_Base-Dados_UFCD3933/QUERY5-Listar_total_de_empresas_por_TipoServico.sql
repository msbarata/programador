-- Listar o total de empresas agrupadas pelo tipo de serviço que oferecem
SELECT 
    Tiposservico,
    COUNT(*) AS Total_Empresas
FROM dadosempresa
GROUP BY Tiposservico
ORDER BY Total_Empresas DESC;