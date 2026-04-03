<?php

include 'config.php';

//criar base de dados

$ligacao = new PDO("mysql:host=$host", $user, $db_password);
$motor = $ligacao->prepare(
		"CREATE DATABASE IF NOT EXISTS $base_dados
		DEFAULT CHARACTER SET utf8"
);
$motor->execute();
$ligacao = null;

echo '<p>Base de dados criada com sucesso</p><hr>';

//Criar as tabelas

$ligacao = new PDO("mysql:dbname=$base_dados;host=$host;charset=utf8", $user, $db_password);

$sql = "
	  CREATE TABLE IF NOT EXISTS users(
			id_user    INT AUTO_INCREMENT PRIMARY KEY,
			username VARCHAR(30) NOT NULL,
			pass  VARCHAR(100) NOT NULL,
			avatar  VARCHAR(250)
			)
			
	";
	$motor = $ligacao->prepare($sql);
	$motor->execute();
	
echo '<p>Tabela "users" criada com sucesso.</p>';	

$sql = "
	  CREATE TABLE IF NOT EXISTS posts(
			id_post    INT AUTO_INCREMENT PRIMARY KEY,
			id_user    INT NOT NULL,
			titulo     VARCHAR(100),
			mensagem   TEXT,
			data_post  DATETIME,
			FOREIGN KEY (id_user) REFERENCES users(id_user) ON DELETE CASCADE
			)		
		";	
		
		$motor = $ligacao->prepare($sql);
		$motor->execute();
		
		$ligacao = null;
		
		echo '<p>Tabela "posts" criada com sucesso</p>';
		echo '<hr>';

?>