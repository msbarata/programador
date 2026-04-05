--  importa os dados do ficheiro concelhos.txt para a tabela concelhos
USE codigopostal_manoelbarata;
LOAD DATA INFILE 'c:\\sql\\concelhos.txt'
INTO TABLE concelhos
FIELDS TERMINATED BY ';'
LINES TERMINATED BY '\r\n'
(DD, CC, DESIG);


SELECT * FROM concelhos;