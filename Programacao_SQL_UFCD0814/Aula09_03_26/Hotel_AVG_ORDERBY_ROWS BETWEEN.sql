SELECT data_venda, valor, AVG(valor) OVER 
(ORDER BY valor ROWS BETWEEN 2 PRECEDING AND CURRENT ROW) FROM Vendas_Diarias;