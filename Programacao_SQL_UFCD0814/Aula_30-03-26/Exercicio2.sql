USE empresa_db;

SELECT f.id, d.nome, COUNT(f.id) AS Numero_Funcionarios
FROM funcionarios f
JOIN departamentos d ON f.id = d.id
GROUP BY f.departamento_id, d.nome;




