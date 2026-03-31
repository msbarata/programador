SELECT 
    f.nome,
    d.nome AS departamento,
    f.salario,
    RANK() OVER (PARTITION BY f.departamento_id ORDER BY f.salario DESC) AS ranking
FROM funcionarios f
JOIN departamentos d ON f.departamento_id = d.id;