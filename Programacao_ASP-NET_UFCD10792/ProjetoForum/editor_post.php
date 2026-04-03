<?php

session_start();

if(!isset($_SESSION['user'])){

    include 'cabecalho.php';
    echo'

    <div class = "erro">
        Não tem permissão para ver esta página.<br><br>
        <a href="index.php">Retroceder</a>
    </div>
    ';
    include 'rodape.php';
    exit;

}

include 'cabecalho.php';

$pid = -1;
$editar = false;
$titulo = "";
$mensagem = "";

if(isset($_GET['pid']) && is_numeric($_GET['pid'])){
        $pid = (int) $_GET['pid'];
        $editar = true;

        include 'config.php';

        $ligacao = new PDO(
        "mysql:host=$host;dbname=$base_dados;charset=utf8",
        $user,
        $db_password,
        [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION]

        );
$motor = $ligacao->prepare(

    "SELECT id_user, titulo, mensagem
    from posts
    WHERE id_post = ?"
);

$motor-> execute([$pid]);
$dados = $motor->fetch(PDO::FETCH_ASSOC);

if(!$dados){

        echo'

        <div class="erro">
            Post não encontrado.
        </div>
';

    include 'rodape.php';
    exit;

}

if($dados['id_user'] != $_SESSION['id_user']){
    
    
        echo'

        <div class="erro">
           Não tem permissões para editar este Post
        </div>
';
    include 'rodape.php';
    exit;

}
    $titulo = $dados['titulo'];
    $mensagem = $dados['mensagem'];

    $ligacao = null;

}

// dados do utilizador

$avatar = $_SESSION['avatar'] ? $_SESSION['avatar'] : 'default.jpg';
$user = htmlspecialchars($_SESSION['user']);

     echo'

        <div class="dados_utiizador">
           <img src="image/'.$avatar.'" alt="Avatar">
           <spam>'.$user.'</span> |
           <a href="logout.php">Logout</a>           
        </div>
';

   echo'

        <form class="form_post" method="POST" action="post_add.php">
                <h3>Post</h3><br><br>

        <input type="hidden" name="id_post" value="'.$pid.'">

        Titulo:<br>
        <input type="text" name="text_titulo" size="80" required value="'.htmlspecialchars($titulo).'"><br><br>

        Mensagem:<br>
        <textarea rows="10" cols="80" name="text_mensagem" required>'.htmlspecialchars($mensagem).'</textarea><br><br>   
            
        <input type="submit" value="Gravar"><br><br>

        <a href="forum.php">Voltar</a>

        </form>

         
    ';
    
    {


}

?>