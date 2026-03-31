SELECT 
    f.nome,
    f.data_admissao,
    f.salario,
    AVG(f.salario) OVER (
        ORDER BY f.data_admissao
        ROWS BETWEEN 2 PRECEDING AND CURRENT ROW
    ) AS media_movel
FROM funcionarios f
ORDER BY f.data_admissao;