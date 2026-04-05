--  importa os dados do ficheiro todos_cp.txt para a tabela codigopostal
USE codigopostal_manoelbarata;
LOAD DATA INFILE 'c:\\sql\\todos_cp.txt'
INTO TABLE codigopostal
FIELDS TERMINATED BY ';'
LINES TERMINATED BY '\r\n'
(DD, CC, LLLL, LOCALIDADE, ART_COD, ART_TIPO, PRI_PREP, ART_TITULO, SEG_PREP, ART_DESIG, ART_LOCAL, TROÇO, PORTA, CLIENTE, CP4, CP3, CPALF);