SELECT   d.DESIG  AS "Distrito", c.DESIG  AS "Concelho",  CONCAT(cp.CP4, '-', cp.CP3) AS "Código Postal"
FROM codigopostal cp
JOIN distritos d  ON cp.DD = d.DD
JOIN concelhos c  ON cp.CC = c.CC AND cp.DD = c.DD
WHERE d.DESIG IN ('Lisboa', 'Porto', 'Braga')
ORDER BY d.DESIG, c.DESIG, cp.LOCALIDADE;