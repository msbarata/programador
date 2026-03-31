USE empresa_db;

SELECT f.projeto_id, p.nome, COUNT(f.horas) AS total_horas_trabalhadas
FROM funcionario_projeto f
JOIN projetos p ON p.id = f.projeto_id
GROUP BY p.id, p.nome;




