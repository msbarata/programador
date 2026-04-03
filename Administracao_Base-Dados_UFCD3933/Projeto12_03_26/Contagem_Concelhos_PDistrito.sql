SELECT d. DESIG as "Distrito", COUNT(DISTINCT CC) as "Contagem de Concelhos" FROM concelhos c
JOIN distritos d
USING (DD)
GROUP BY d.DD, d.DESIG
ORDER BY d.DESIG ASC;
