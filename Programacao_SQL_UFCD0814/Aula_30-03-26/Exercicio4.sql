USE empresa_db;

SELECT f.departamento_id, d.nome, AVG(f.salario) AS media_salario
FROM funcionarios f
JOIN departamentos d ON f.departamento_id = d.id
GROUP BY f.departamento_id, d.nome
HAVING AVG(f.salario) > 2200;
