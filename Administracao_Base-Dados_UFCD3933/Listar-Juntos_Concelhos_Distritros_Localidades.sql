SELECT   d.DESIG  AS "Distrito", c.DESIG  AS "Concelho",  cp.LOCALIDADE AS "Localidade"
FROM codigopostal cp
JOIN distritos d  ON cp.DD = d.DD
JOIN concelhos c  ON cp.CC = c.CC AND cp.DD = c.DD