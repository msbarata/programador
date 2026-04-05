-- Todos os Serviços Agendados com utilizador, empresa e localidade.
SELECT 
    a.numero_entrada,
    u.Nome AS Utilizador,
    e.Nome AS Empresa,
	e.Localidade,
    e.Tiposservico AS 'Serviço Agendado'  
FROM agendamento a
JOIN dadosutilizadores u ON a.NISS_utilizador = u.NISS
JOIN dadosempresa e ON a.ID_empresa = e.ID
ORDER BY a.numero_entrada;