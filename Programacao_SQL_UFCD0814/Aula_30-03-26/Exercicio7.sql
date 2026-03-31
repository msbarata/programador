USE empresa_db;

SELECT f.departamento_id, d.nome, sum(f.salario) AS salario_acumulado
FROM funcionarios f
JOIN departamentos d ON f.departamento_id = d.id
GROUP BY f.departamento_id, d.nome

