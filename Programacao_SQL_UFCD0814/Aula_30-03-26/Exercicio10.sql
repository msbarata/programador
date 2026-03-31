SELECT * FROM (
    SELECT 
        f.nome,
        d.nome AS departamento,
        f.salario,
        AVG(f.salario) OVER (PARTITION BY f.departamento_id) AS media_departamento
    FROM funcionarios f
    JOIN departamentos d ON f.departamento_id = d.id
) AS sub
WHERE salario > media_departamento;
