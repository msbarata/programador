-- Listar empresas de uma localidade específica que forneça um tipo de serviço específico:
SELECT Nome, Tiposservico, Localidade
FROM dadosempresa
WHERE Localidade = 'Lisboa'
  AND Tiposservico = 'Limpeza'
ORDER BY Nome;