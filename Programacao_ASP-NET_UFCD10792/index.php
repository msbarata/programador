<?php

session_start();

    if(isset($_SESSION['user'])){
        include 'cabecalho.php';
        echo'
            <div class="mensagem">
                <strong>'.$_SESSION['user'].'</strong> já se encontra ligado no site.<br><br>
                <a href="forum.php">Avançar</a>
            </div>
        ';
        include 'rodape.php';
        exit;
    }

    include 'cabecalho.php';

    include 'login.php';

    include 'registo.php';

?>