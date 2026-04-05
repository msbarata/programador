-- Criar base de dados
CREATE DATABASE servico_casa;
USE servico_casa;

-- Tabela: dadosutilizadores
CREATE TABLE dadosutilizadores (
    NISS INT PRIMARY KEY,
    Nome VARCHAR(100) NOT NULL,
    Morada VARCHAR(255)
);

-- Tabela: dadosempresa
CREATE TABLE dadosempresa (
    ID INT PRIMARY KEY AUTO_INCREMENT,
    Nome VARCHAR(100) NOT NULL,
    Tiposservico VARCHAR(100),
    Localidade VARCHAR(100)
);

-- Tabela: tiposservicos
CREATE TABLE tiposservicos (
    Nome VARCHAR(100) PRIMARY KEY
);

-- Tabela: agendamento
CREATE TABLE agendamento (
    numero_entrada INT PRIMARY KEY AUTO_INCREMENT,
    NISS_utilizador INT,
    ID_empresa INT,
    
    -- Foreign Keys
    CONSTRAINT fk_utilizador
        FOREIGN KEY (NISS_utilizador)
        REFERENCES dadosutilizadores(NISS)
        ON DELETE CASCADE
        ON UPDATE CASCADE,

    CONSTRAINT fk_empresa
        FOREIGN KEY (ID_empresa)
        REFERENCES dadosempresa(ID)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);