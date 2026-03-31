SELECT 
    f.nome,
    d.nome AS departamento,
    f.salario,
    SUM(f.salario) OVER (PARTITION BY f.departamento_id) AS total_departamento,
    ROUND(f.salario / SUM(f.salario) OVER (PARTITION BY f.departamento_id) * 100, 2) AS percentagem
FROM funcionarios f
JOIN departamentos d ON f.departamento_id = d.id
ORDER BY d.nome, percentagem DESC;