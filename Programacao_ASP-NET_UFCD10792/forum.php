<?php

session_start();

if(!isset($_SESSION['user'])){
    include 'cabecalho.php';
    echo '
        <div class="erro">
            Não tem permissões para ver o conteúdo do fórum.<br><br>
            <a href="index.php">Retroceder</a>
        </div> 
        
    ';

    include 'rodape.php';
    exit;

}

include 'cabecalho.php';

//DADOS DO UTILIZADOR LIGADO:

$avatarSessao = !empty($_SESSION['avatar']) ? $_SESSION['avatar'] : 'imagem.jpeg';
$userSessao = htmlspecialchars($_SESSION['user']);

echo '
  <div class="dados_utilizador">
            <img src="image/'.$avatarSessao.'" alt="Avatar">
            <span>'.$userSessao.'</span> |   
            <a href="logout.php">Logout</a>
        </div> 
    ';

  echo '
  <div class="novo_post">
                <a href="editor_post.php">Novo Post</a>
        </div> 
        
    ';  
    include 'config.php';

    try{

        $ligacao = new PDO(
            "mysql:host=$host;dbname=$base_dados;charset=utf8",
            $user,
            $db_password,
            [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION]

        
        );

        //Ir buscar os posts

        $sql = "
        SELECT
        posts.id_post,
        posts.id_user,
        posts.titulo,
        posts.mensagem,
        posts.created_at,
        users.username,
        users.avatar
        FROM posts
        INNER JOIN users ON posts.id_user = users.id_user
        ORDER BY posts.created_at DESC

        ";

        $motor = $ligacao->prepare($sql);
        $motor->execute();   

        $posts = $motor->fetchAll(PDO::FETCH_ASSOC);

        if(!$posts){

        echo '
            <div class="mensagem">
                Não existem posts no fórum.
            </div> 
        
        ';
        }
        else{

        foreach ($posts as $post){
            $id_post = $post['id_post'];
            $id_user = $post['id_user'];
            $titulo = htmlspecialchars($post['titulo']);
            $mensagem = nl2br(htmlspecialchars($post['mensagem']));
            $data = $post['created_at'];
            $username = htmlspecialchars($post['username']);
            $avatar = !empty($post['avatar']) ? $post['avatar'] : 'imagem.jpeg';


        echo '<div class="post">';
        echo '<img src="image/'.$avatar.'" alt="Avatar">';


        echo '<div class="post_conteudo">';
        echo '<div class="post_topo">';
        echo '<span class="post_username">'.$username.'</span>';
        echo '<span class="post_titulo">'.$titulo.'</span>';
        echo '</div>';

        echo '<div class="post_mensagem">'.$mensagem.'</div>';

        echo '<div class="post_rodape">';

        if($id_user == $_SESSION['id_user']){

        echo '<div class="botoes">';
        echo '<a class="btn_editar" href="editor_post.php?pid='.$id_post.'">Editar</a>';
        echo '<a class="btn_apagar" href="delete_post.php?pid='.$id_post.'"
        onclick="return confirma(\'Tem a certeza?\')">Apagar</a>';
        echo '</div>';

        }

         echo '<div class="post_data">'.$data.'</div>';
         echo '</div></div></div>';

               }

        }

                       
    }
    catch(PDOException $e){

     echo '
        <div class="erro">
            Erro ao aceder à Base de Dados.
           
        </div> 
        
    ';
    
    }

    include 'rodape.php';



?>