SELECT * FROM (
    SELECT 
        f.projeto_id,
        p.nome AS nome_projeto,
        sum(f.horas) AS horas_projeto
    FROM funcionario_projeto f
    JOIN projetos p ON f.projeto_id = p.id
	GROUP BY f.projeto_id, p.nome
) AS sub
ORDER BY horas_projeto DESC
Limit 1;