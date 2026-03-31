/* =====================================================
   BASE DE DADOS HOTEL_5086 — Versão Melhorada
   ===================================================== */
 
DROP DATABASE IF EXISTS `Hotel_5086`;
CREATE DATABASE `Hotel_5086`;
USE `Hotel_5086`;
 
/* =====================================================
   TABELAS PRINCIPAIS
   ===================================================== */
 
CREATE TABLE `Cliente` (
    Numero_Cliente INT PRIMARY KEY AUTO_INCREMENT,
    Nome_Cliente VARCHAR(199) NOT NULL
);
 
CREATE TABLE `Organizacao` (
    Numero_Cliente INT PRIMARY KEY,
    Ramo_Actividade VARCHAR(100),
    Nome_Contacto VARCHAR(100) UNIQUE,
    FOREIGN KEY (Numero_Cliente) REFERENCES Cliente(Numero_Cliente)
);
 
CREATE TABLE `Individual` (
    Numero_Cliente INT PRIMARY KEY,
    CC INT UNIQUE,
    FOREIGN KEY (Numero_Cliente) REFERENCES Cliente(Numero_Cliente)
);
 
CREATE TABLE `Hotel` (
    Sigla_Hotel VARCHAR(10) PRIMARY KEY,
    Designacao VARCHAR(100) NOT NULL
);
 
CREATE TABLE `Quarto` (
    Sigla_Hotel VARCHAR(10),
    Numero_Quarto INT,
    Numero_Camas INT,
    Preco DECIMAL(6,2),
    PRIMARY KEY (Sigla_Hotel, Numero_Quarto),
    FOREIGN KEY (Sigla_Hotel) REFERENCES Hotel(Sigla_Hotel)
);
 
CREATE TABLE `Reserva` (
    Numero_Reserva INT PRIMARY KEY AUTO_INCREMENT,
    Numero_Cliente INT NOT NULL,
    Dia_Entrada DATETIME NOT NULL,
    Dia_Saida DATETIME,
    FOREIGN KEY (Numero_Cliente) REFERENCES Cliente(Numero_Cliente)
);
 
CREATE TABLE `Reserva_Quartos` (
    Sigla_Hotel VARCHAR(10),
    Numero_Quarto INT,
    Numero_Reserva INT,
    Cama_Extra INT DEFAULT 0,
    Numero_Pessoas INT NOT NULL,
    PRIMARY KEY (Sigla_Hotel, Numero_Quarto, Numero_Reserva),
    FOREIGN KEY (Sigla_Hotel, Numero_Quarto) REFERENCES Quarto(Sigla_Hotel, Numero_Quarto),
    FOREIGN KEY (Numero_Reserva) REFERENCES Reserva(Numero_Reserva)
);
 
CREATE TABLE `Factura` (
    Numero_Factura INT PRIMARY KEY AUTO_INCREMENT,
    Numero_Reserva INT,
    Data_Factura TIMESTAMP,
    Valor_Factura DECIMAL(8,2),
    FOREIGN KEY (Numero_Reserva) REFERENCES Reserva(Numero_Reserva)
);
 
/* =====================================================
   DADOS DE EXEMPLO
   ===================================================== */
 
/* HOTEIS */
INSERT INTO Hotel VALUES 
('ML', 'Marriott Lisboa'),
('IB', 'Ibis Chiado'),
('HL', 'Hilton Lisboa'),
('SH', 'Sheraton Lisboa'),
('HT', 'Hotel Tivoli');
 
/* CLIENTES ORGANIZAÇÕES */
INSERT INTO Cliente (Numero_Cliente, Nome_Cliente) VALUES
(1001, 'Caixa Geral de Depósitos'),
(1002, 'CTT'),
(1003, 'Supermercado Compre Aqui'),
(1004, 'Europcar'),
(1005, 'Cinemas NOS');
 
INSERT INTO Organizacao VALUES
(1001, 'Banca', 'Manuel Sousa'),
(1002, 'Entregas e Logística', 'Luís Amaral'),
(1003, 'Retalho Alimentar', 'Maria Pinto'),
(1004, 'Aluguer de Automóveis', 'Rui Almeida'),
(1005, 'Entretenimento', 'Pedro Lopes');
 
/* CLIENTES INDIVIDUAIS */
INSERT INTO Cliente (Numero_Cliente, Nome_Cliente) VALUES
(2001, 'João Pedro'),
(2002, 'Luís Nunes'),
(2003, 'Maria Ribeiro'),
(2004, 'Rui Paulo'),
(2005, 'Afonso Oliveira');
 
INSERT INTO Individual VALUES
(2001, 122340543),
(2002, 122341253),
(2003, 155120543),
(2004, 221340553),
(2005, 422390533);
 
/* QUARTOS — exemplo com diferentes preços */
INSERT INTO Quarto VALUES
('ML',1,2,180),('ML',2,2,180),('ML',3,1,150),('ML',4,3,210),('ML',5,1,130),
('HT',1,1,80),('HT',2,2,100),('HT',3,1,90),('HT',4,2,110),('HT',5,1,85),
('SH',1,2,140),('SH',2,2,145),('SH',3,3,160),('SH',4,1,120),('SH',5,1,120),
('IB',1,1,75),('IB',2,1,75),('IB',3,1,75),('IB',4,2,95),('IB',5,2,95),
('HL',1,2,220),('HL',2,2,230),('HL',3,1,200),('HL',4,3,250),('HL',5,1,190);
 
/* =====================================================
   RESERVAS DE EXEMPLO
   ===================================================== */
 
/* João Pedro — reserva 2 quartos no Sheraton */
INSERT INTO Reserva (Numero_Cliente, Dia_Entrada, Dia_Saida)
VALUES (2001, NOW() + INTERVAL 2 DAY, NOW() + INTERVAL 5 DAY);
INSERT INTO Reserva_Quartos VALUES ('SH',4,1,0,2), ('SH',5,1,0,1);
INSERT INTO Factura (Numero_Reserva, Data_Factura, Valor_Factura)
VALUES (1, '2024-11-08 12:00:00', 340.00);
 
/* Luís Nunes — reserva 1 quarto no Hilton */
INSERT INTO Reserva (Numero_Cliente, Dia_Entrada, Dia_Saida)
VALUES (2002, NOW() + INTERVAL 10 DAY, NOW() + INTERVAL 12 DAY);
INSERT INTO Reserva_Quartos VALUES ('HL',3,2,1,2);
INSERT INTO Factura VALUES (NULL, 2, '2024-11-15 09:00:00', 400.00);
 
/* CTT — reserva corporativa de 3 quartos no Marriott */
INSERT INTO Reserva (Numero_Cliente, Dia_Entrada, Dia_Saida)
VALUES (1002, '2024-12-01 15:00:00', '2024-12-05 11:00:00');
INSERT INTO Reserva_Quartos VALUES 
('ML',1,3,0,2), ('ML',2,3,0,1), ('ML',3,3,1,3);
INSERT INTO Factura VALUES (NULL, 3, '2024-12-05 12:00:00', 1550.00);
 
/* Europcar — reserva curta no Ibis */
INSERT INTO Reserva (Numero_Cliente, Dia_Entrada, Dia_Saida)
VALUES (1004, NOW() + INTERVAL 1 DAY, NOW() + INTERVAL 2 DAY);
INSERT INTO Reserva_Quartos VALUES ('IB',1,4,0,1);
INSERT INTO Factura VALUES (NULL, 4, NOW(), 75.00);
 
/* Maria Ribeiro — fim-de-semana no Tivoli */
INSERT INTO Reserva (Numero_Cliente, Dia_Entrada, Dia_Saida)
VALUES (2003, NOW() + INTERVAL 5 DAY, NOW() + INTERVAL 7 DAY);
INSERT INTO Reserva_Quartos VALUES ('HT',2,5,0,2);
INSERT INTO Factura VALUES (NULL, 5, NOW(), 200.00);