--  importa os dados do ficheiro distritos.txt para a tabela distritos
USE codigopostal_manoelbarata;
LOAD DATA INFILE 'c:\\sql\\distritos.txt'
INTO TABLE distritos
FIELDS TERMINATED BY ';'
LINES TERMINATED BY '\r\n'
(DD, DESIG);

SELECT * FROM distritos;