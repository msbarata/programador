<?php

session_start();

if(!isset($_SESSION['user'])){

    include 'cabecalho.php';

    echo '
            <div class="erro">
            Não têm permissões para ver o conteúdo do fórum.<br><br>
            <a href="index.php">Retroceder</a>
            </div>    
         
        ';

    include 'rodape.php';
    exit;
}

include 'cabecalho.php';

$pid = (int) $_GET['pid'];

include 'config.php';

try{

    $ligacao = new PDO(
        "mysql:host=$host;dbname=$base_dados;charset=utf8",
        $user,
        $db_password,
        [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION]
    );

    //Verificar se o post pertence ao utilizador
    $motor = $ligacao->prepare("SELECT id_user FROM posts WHERE id_post = ?");
    $motor->execute([$pid]);

    $post = $motor->fetch(PDO::FETCH_ASSOC);

    if(!$post || $post['id_user'] != $_SESSION['id_user']){

        header("Location: forum.php");
        exit;

    }
    //Apagar o post

    $motor = $ligacao->prepare("DELETE FROM posts WHERE id_post = ?");
    $motor->execute([$pid]);

    echo '
         <div class="login_sucesso">
            Post apagado com sucesso.<br><br>
            <a href="forum.php">Voltar ao fórum</a>
            </div>  

    ';
}
    catch(PDOException $e){

        echo '
            <div class="erro">
            Ocorreu um erro ao apagar o post.<br><br>
            <a href="forum.php">Voltar ao fórum</a>
            </div>    
         
        ';


    }

    include 'rodape.php';


?>