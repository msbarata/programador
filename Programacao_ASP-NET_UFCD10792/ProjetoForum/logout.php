<?php

    session_start();

    include 'cabecalho.php';

    if(isset($_SESSION['user'])){
        $mensagem = 'Até a próxima, '.htmlspecialchars($_SESSION['user']).'!';
    }
    else{
        $mensagem = 'Página não está disponível a visitantes.';

    }

    // Limpar todas as variaveis
    $_SESSION = [];

    //Apagar os cookies
    if(ini_get("session.use_cookies")){
        $params = session_get_cookie_params();
        setcookie(
            session_name(),
            '',
            time() - 42000,
            $params['path'],
             $params['domain'],
              $params['secure'],
               $params['httponly'],
        );
    }

    //Destruir sessão
    session_destroy();


    echo '
    
        <div class="login_sucesso">
            '.$mensagem.'<br><br>
            <a href="index.php">Inicio</a>
        </div>
    
    ';
    
include 'rodape.php';

?>