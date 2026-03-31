CREATE DATABASE `0814_FuncoesAnaliticas`;
USE `0814_FuncoesAnaliticas`;
CREATE TABLE vendas_diarias (
    id INT AUTO_INCREMENT PRIMARY KEY,
    data_venda DATE,
    valor DECIMAL(10,2)
);
 
INSERT INTO vendas_diarias (data_venda, valor) VALUES
('2025-01-01', 120.50),
('2025-01-02', 98.30),
('2025-01-03', 110.00),
('2025-01-04', 150.20),
('2025-01-05', 130.75),
('2025-01-06', 170.40),
('2025-01-07', 160.10),
('2025-01-08', 180.00),
('2025-01-09', 175.50),
('2025-01-10', 190.00),
('2025-01-11', 210.25),
('2025-01-12', 205.10),
('2025-01-13', 220.00),
('2025-01-14', 215.60);