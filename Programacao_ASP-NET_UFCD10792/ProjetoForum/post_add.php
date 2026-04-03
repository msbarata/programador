<?php

session_start();

if(!isset($_SESSION['user'])){
    include 'cabecalho.php';

    echo'
    <div class="erro">
        Não têm permissão para ver esta página.<br><br>
        <a href="index.php">Retroceder</a>
        </div>
        
    ';

        include 'rodape.php';
        exit;

}

include 'cabecalho.php';

$id_user = $_SESSION['id_user'];
$id_post = isset($_POST['id_post']) ? (int)$_POST['id_post'] : -1;

$titulo = trim($_POST['text_titulo']);
$mensagem = trim($_POST['text_mensagem']);


if($titulo == "" || $mensagem === ""){

  echo'
    <div class="erro">
        Não foram preenchidos todos os campos.<br><br>
        <a href="editor_post.php">Tente novamente</a>
        </div>
        
    ';

     include 'rodape.php';
        exit;

}

include 'config.php';

$ligacao = new PDO(
    "mysql:host=$host;dbname=$base_dados;charset=utf8",
    $user,
    $db_password,
    [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION]
);

$data = date('Y-m-d H:i:s');


//NOVO POST


if($id_post == -1){
    $sql = "INSERT INTO posts (id_user, titulo, mensagem) VALUES (?, ?, ?)";
    $motor = $ligacao->prepare($sql);
    $motor->execute([$_SESSION['id_user'], $titulo, $mensagem]);
}

else{
    //EDITAR POST
    //Verificar se o post pertence ao utilizador

    $motor = $ligacao->prepare("SELECT id_user FROM posts WHERE id_post = ?");
    $motor->execute([$id_post]);
    $post = $motor->fetch(PDO::FETCH_ASSOC);

    if(!$post || $post['id_user'] != $id_user){

echo'
    <div class="erro">
        Não têm permissão para editar este Post.<br><br>
    </div>
        
    ';

     include 'rodape.php';
        exit;

    }

$sql = "UPDATE posts
    SET titulo = ?, mensagem = ?
    WHERE id_post = ?";

$motor = $ligacao->prepare($sql);
$motor->execute([$titulo, $mensagem, $id_post]);


}

$ligacao =  null;

echo'
    <div class="login_sucesso">
        Post gravado com sucesso.<br><br>
        <a href="forum.php">Voltar</a>
    </div>
        
    ';

   include 'rodape.php';

?>