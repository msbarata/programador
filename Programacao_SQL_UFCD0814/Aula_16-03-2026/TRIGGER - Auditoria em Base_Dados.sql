SELECT * FROM Hotel;

UPDATE Hotel SET Designacao = "Hilton Lisboa" WHERE Sigla_Hotel = "HL";

CREATE TABLE Hotel_Audit (
id int primary key auto_increment,
old_sigla_hotel varchar(100),
old_designacao varchar(100),
new_sigla_hotel varchar(100),
new_designacao varchar(100),
createdAt datetime default now()

);

DELIMITER //
 
CREATE TRIGGER hotel_history
AFTER UPDATE
ON Hotel
FOR EACH ROW
BEGIN
	INSERT INTO Hotel_Audit(
    old_sigla_hotel,old_designacao,new_sigla_hotel,new_designacao)
    VALUES (OLD.Sigla_Hotel,OLD.Designacao,NEW.Sigla_Hotel,NEW.Designacao);
END//
 
DELIMITER ;
 
UPDATE HOTEL SET Designacao = "Hilton Lisboa" WHERE Sigla_Hotel = "HL";
SELECT * FROM Hotel_Audit;
 
SELECT * FROM Reserva;
 
DELIMITER //
 
CREATE TRIGGER check_reserva_data
BEFORE INSERT 
ON Reserva
FOR EACH ROW
BEGIN
	IF NEW.Dia_Saida < NEW.Dia_Entrada THEN
		SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = "Campo dia saida anterior ao dia entrada";
	END IF;
END//
 
DELIMITER ;
 
SELECT * FROM Reserva;
INSERT INTO Reserva(Numero_Cliente,Dia_Entrada,Dia_Saida) VALUES (3001,NOW(),NOW() - INTERVAL 2 DAY);
 
 
DELIMITER //
 
CREATE TRIGGER trg_disallow_negative_roomprice
BEFORE INSERT 
ON Quarto
FOR EACH ROW
BEGIN 
	    IF NEW.Preco <= 0 THEN
			SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Quarto não pode ter preco negativo.';
		END IF;
END//
 
DELIMITER ;
 
DELIMITER //
 
CREATE TRIGGER trg_disallow_upt_negative_roomprice
BEFORE UPDATE 
ON Quarto
FOR EACH ROW
BEGIN 
	    IF NEW.Preco <= 0 THEN
			SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Quarto não pode ter preco negativo.';
		END IF;
END//
 
DELIMITER ;
 
INSERT INTO Quarto (Sigla_Hotel,Numero_Quarto,Preco) VALUES ("HL",1234567,-55);
UPDATE Quarto SET Preco = -55 WHERE Numero_Quarto = 123456;
 
INSERT INTO FACTURA(Numero_Reserva,Valor_Factura) VALUES (1,100);
SELECT * FROM Factura;
 
DELIMITER //
 
CREATE TRIGGER auto_n_camas
BEFORE INSERT
ON Quarto
FOR EACH ROW
BEGIN
	IF NEW.Numero_Camas IS NULL THEN
		SET NEW.Numero_Camas = 0;
	END IF;
END//
DELIMITER ;
 
INSERT INTO Quarto (Sigla_Hotel,Numero_Quarto,Preco) VALUES ("HL",43214546,200);
SELECT * FROM Quarto;

-- Crie um TRIGGER que impeça inserir
-- em Reserva_Quartos um registro com Numero_Pessoas inferior a 1.

DELIMITER //

CREATE TRIGGER trg_block_insert_resquartos
BEFORE INSERT
ON Reserva_Quartos
FOR EACH ROW
	BEGIN
		if NEW.Numero_Pessoas < 1 THEN
			SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = "Erro - Numero de pessoas tem que ser maior que 0.";
		END IF;
END//

DELIMITER ;

INSERT INTO Reserva_Quartos(Sigla_Hotel,Numero_Quarto,Numero_Reserva,Numero_Pessoas)
VALUES ("HL",1,1,-10);


-- Crie um trigger que corrige inserir 
-- em Reserva_Quartos um registo com Numero_Pessoas inferior a 1 para 1.
DROP TRIGGER trg_block_insert_resquartos;
DELIMITER // 
CREATE TRIGGER trg_fix_insert_resquartos
BEFORE INSERT
ON Reserva_Quartos
FOR EACH ROW
	BEGIN
		if NEW.Numero_Pessoas < 1 THEN
			SET NEW.Numero_Pessoas = 1;
		END IF;
END//
DELIMITER ;
INSERT INTO Reserva_Quartos(Sigla_Hotel,Numero_Quarto,Numero_Reserva,Numero_Pessoas) 
VALUES ("HL",1,1,-10);
SELECT * FROM Reserva_Quartos;


-- Crie um trigger que preencha automaticamente Data_Fatura com a data/hora atual quando o valor vier nulo.

DELIMITER // 
CREATE TRIGGER trg_ex2
BEFORE INSERT
ON Factura
FOR EACH ROW
	BEGIN
		if NEW.Data_Factura is NULL THEN
			SET NEW.Data_Factura = now();
		END IF;
END//
DELIMITER ;

INSERT INTO FACTURA(Numero_Reserva,Valor_Factura) VALUES (2,750);
SELECT * FROM Factura;


-- Crie um trigger que impeça apagar um cliente que tenha reservas associadas.
DELIMITER //
CREATE TRIGGER avoid_delete
BEFORE DELETE
ON Cliente
FOR EACH ROW
BEGIN
	IF EXISTS(
		SELECT 1 FROM Reserva WHERE Numero_Cliente = OLD.Numero_Cliente
    ) THEN 
		SIGNAL SQLSTATE "45000"
        SET MESSAGE_TEXT = "Cliente têm reservas";
    END IF;
END//
DELIMITER ;
 
DELETE FROM Cliente WHERE Numero_Cliente = 2001;

-- Crie um trigger que impeça criar uma reserva de um quarto já reservado
DELIMITER //

CREATE TRIGGER trg_duplicate_booking
BEFORE INSERT ON Reserva_Quartos
FOR EACH ROW
BEGIN
    IF EXISTS (
        SELECT 1
        FROM Reserva_Quartos rq
        JOIN Reserva r 
            ON rq.Numero_Reserva = r.Numero_Reserva
        JOIN Reserva r_new 
            ON r_new.Numero_Reserva = NEW.Numero_Reserva
        WHERE rq.Sigla_Hotel = NEW.Sigla_Hotel
          AND rq.Numero_Quarto = NEW.Numero_Quarto
          AND (
                r_new.Dia_Entrada < r.Dia_Saida
                AND r_new.Dia_Saida > r.Dia_Entrada
          )
    ) THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Reserva de quarto já existente!';
    END IF;
END//
 
DELIMITER ;


-- Crie um Trigger que impeça de reservar
-- mas do que 3 quartos na mesma reserva 

DELIMITER //
CREATE TRIGGER trg_ex6
BEFORE INSERT ON Reserva_Quartos
FOR EACH ROW
BEGIN
    IF 3 >= (SELECT COUNT(*) FROM Reserva_Quartos WHERE Numero_Reserva = New.Numero_Reserva)
    THEN
        SIGNAL SQLSTATE "45000"
        SET MESSAGE_TEXT="Já existem 3 quartos";
	END IF;
END//
DELIMITER ;

