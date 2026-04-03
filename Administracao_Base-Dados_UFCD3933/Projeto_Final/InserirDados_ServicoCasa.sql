use servico_casa;
-- dadosutilizadores
INSERT INTO dadosutilizadores (NISS, Nome, Morada) VALUES
(1001, 'Ana Silva', 'Rua A, Lisboa'),
(1002, 'Bruno Costa', 'Rua B, Porto'),
(1003, 'Carla Mendes', 'Rua C, Braga'),
(1004, 'Daniel Rocha', 'Rua D, Coimbra'),
(1005, 'Eva Santos', 'Rua E, Faro');

-- tiposservicos
INSERT INTO tiposservicos (Nome) VALUES
('Limpeza'),
('Canalização'),
('Eletricidade'),
('Jardinagem'),
('Pintura');

-- dadosempresa
INSERT INTO dadosempresa (Nome, Tiposservico, Localidade) VALUES
('LimpaTudo', 'Limpeza', 'Lisboa'),
('CanosFix', 'Limpeza', 'Porto'),
('LuzCerta', 'Eletricidade', 'Porto'),
('VerdeVivo', 'Jardinagem', 'Coimbra'),
('PintaBem', 'Pintura', 'Lisboa');

-- agendamento
INSERT INTO agendamento (NISS_utilizador, ID_empresa) VALUES
(1001, 1),
(1002, 2),
(1003, 3),
(1004, 4),
(1005, 5);