
-- Apagando antigos utilizadores para evitar conflito
-- DROP USER IF EXISTS 'gestor'@'localhost';
-- DROP USER IF EXISTS 'administrador'@'localhost';
-- DROP USER IF EXISTS 'consulta'@'localhost';
-- FLUSH PRIVILEGES;

-- Criando utilizadores com password

-- CREATE USER 'administrador'@'localhost' IDENTIFIED BY 'administrador123';
-- CREATE USER 'gestor'@'localhost' IDENTIFIED BY 'gestor123';
-- CREATE USER 'consulta'@'localhost' IDENTIFIED BY 'consulta123';

-- Criando permissões para os respetivos utilizadores

-- Fornecer privilégios diferentes para cada utilizador e aplicar ao final

GRANT ALL PRIVILEGES ON servico_casa.* TO 'administrador'@'localhost';
GRANT SELECT, INSERT, UPDATE ON servico_casa.* TO 'gestor'@'localhost';
GRANT SELECT ON servico_casa.* TO 'consulta'@'localhost';
FLUSH PRIVILEGES;










