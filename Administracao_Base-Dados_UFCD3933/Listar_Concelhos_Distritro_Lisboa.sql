SELECT c.DESIG AS Concelhos_Lisboa
FROM concelhos c
JOIN distritos d USING(DD)
WHERE d.DESIG = 'Lisboa';
