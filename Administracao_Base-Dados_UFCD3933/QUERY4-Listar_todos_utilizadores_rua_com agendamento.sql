-- Listar todos utilizadores e sua Morada, com agendamento e ID_empresa
SELECT DISTINCT
    u.Nome,
    u.Morada,
    a.ID_empresa
FROM dadosutilizadores u
JOIN agendamento a ON u.NISS = a.NISS_utilizador
WHERE u.Morada LIKE '%Rua%'
ORDER BY u.Nome;