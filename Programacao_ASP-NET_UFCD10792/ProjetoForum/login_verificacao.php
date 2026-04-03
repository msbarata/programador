<?php

session_start();

if(isset($_SESSION['user']))
    {

        include 'cabecalho.php';
        echo '
            <div class="mensagem">
                Já se encontra ligado<br><br>
                <a href="forum.php">Avançar</a>
            </div>
        ';
        include 'rodape.php';
        exit;

    }

    include 'cabecalho.php';

    if(empty($_POST['text_utilizador']) || empty($_POST['text_password'])){

      echo '
            <div class="erro">
                Preencha todos os campos.<br><br>
                <a href="index.php">Voltar</a>
            </div>
        ';

        include 'rodape.php';
        exit;
    }
            $utilizador = trim($_POST['text_utilizador']);
            $password_utilizador = $_POST['text_password'];

        include 'config.php';


        try{

            $ligacao = new PDO("mysql:host=$host;dbname=$base_dados;charset=utf8",
            $user, $db_password,
            [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION]);

            $motor = $ligacao->prepare("SELECT id_user, username, pass, avatar FROM users WHERE username = ? ");
            $motor->execute([$utilizador]);
            $dados_user = $motor->fetch(PDO::FETCH_ASSOC);

        }

        catch(PDOException $e){

             echo '
            <div class="erro">
                Erro de ligação a base de dados.' . $e->getMessage() . '
                
            </div>
             ';

            include 'rodape.php';
            exit;


        }
        //Verificar credenciais:
        
            if(!$dados_user || !password_verify($password_utilizador, $dados_user['pass'])){

              echo '
            <div class="erro">
                Dados de login inválido.<br><br>
                 <a href="index.php">Tente novamente</a>
                
            </div>
             ';
            include 'rodape.php';
            exit;
            }

            //login válido:

            $_SESSION['id_user'] = $dados_user['id_user'];
            $_SESSION['user'] = $dados_user['username'];
            $_SESSION['avatar'] = $dados_user['avatar'];

               echo '
            <div class="login_sucesso">
                Bem vindo, <strong>'.$dados_user['username'].'</strong><br><br>
                 <a href="forum.php">Continuar</a>                
            </div>
             ';

            include 'rodape.php';

?>