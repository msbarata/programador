SELECT   c.DESIG  AS "Concelho de Abrantes", cp.LOCALIDADE AS "Localidade", CONCAT(cp.CP4, '-', cp.CP3) AS "Código Postal"
FROM codigopostal cp
JOIN concelhos c  ON cp.CC = c.CC
WHERE c.DESIG IN ('Abrantes')
ORDER BY cp.LOCALIDADE;