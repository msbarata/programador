SELECT 
    f.nome,
    f.data_admissao,
    f.salario,
    LAG(f.salario) OVER (ORDER BY f.data_admissao) AS salario_anterior,
    f.salario - LAG(f.salario) OVER (ORDER BY f.data_admissao) AS diferenca
FROM funcionarios f;