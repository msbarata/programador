DELIMITER $$

CREATE TRIGGER impedir_reducao_salario
BEFORE UPDATE ON funcionarios
FOR EACH ROW
BEGIN
    IF NEW.salario < OLD.salario THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Erro: Não é permitido reduzir o salário de um funcionário!';
    END IF;
END$$

DELIMITER ;