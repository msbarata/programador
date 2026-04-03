<?php

    session_start();

    include 'cabecalho.php';

    //verificar se foram inseridos dados de utilizador
    if(!isset($_POST['btn_submit'])){

        ApresentarFormulario();

    }
    else{
        RegistarUtilizador();
    }

    include 'rodape.php';

    // Funções


    function ApresentarFormulario(){

        echo '
            <form class="form_signup" method="POST" action="signup.php"
            enctype="multipart/form-data">

                <h3>Signup</h3>
                <hr>

                <label>Username:</label>
                <input type="text" name="text_utilizador" required>

                <label>Password:</label>
                <input type="password" name="text_password_1" required>

                <label>Re-escrever Password:</label>
                <input type="password" name="text_password_2" required>

                <label>Avatar (opcional):</label>

                <input type="file" name="imagem_avatar" accept=".jpg, .jpeg">
                <small>(Imagem JPG, máximo 50kb)</small><br><br>

                <button type="submit" name="btn_submit">Registar</button><br><br>

                <a href="index.php">Voltar</a>

            </form>       
        
        ';


    }

    function RegistarUtilizador(){

    $utilizador = trim($_POST['text_utilizador']);
    $password_1 = trim($_POST['text_password_1']);
    $password_2 = trim($_POST['text_password_2']);
    $avatar = $_FILES['imagem_avatar'];

    $erro = false;
    $maxSize = 50000;
    $nomeAvatar = null;


    //VALIDAÇÕES

    if($utilizador == "" || $password_1 == '' || $password_2 == ''){

        echo '        
        <div class="erro">
        Não foram preenchidos os campos.
        </div>       
        
        ';
        $erro = true;
    }
    
    else if($password_1 != $password_2){

        echo '        
        <div class="erro">
        As Passwords inseridas não coincidem.
        </div>       
        
        ';
        $erro = true;  
    
    }

 //VALIDAÇÕES do Avatar (opcional)

    if($avatar['name'] != ""){

        $ext = strtolower(pathinfo($avatar['name'], PATHINFO_EXTENSION));

        if($ext != "jpg" && $ext != "jpeg"){

            echo '
            <div class="erro">
                O avatar deve ser uma imagem JPG ou JPEG.
            </div>
        ';
          $erro = true;

        }

        else if($avatar['size'] > $maxSize){

            echo '
            <div class="erro">
                O avatar excede os 50 kb permitidos.
            </div>            
            ';
            $erro = true;

        }        
}

    if($erro){

        ApresentarFormulario();
        return;

    }

    //LIGAR Á BASE DE DADOS (MYSQL)

    include 'config.php';
    $ligacao = new PDO(
        "mysql:dbname=$base_dados;host=$host;charset=utf8",
        $user,
        $db_password,
        [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION]

    );
    
    //VERIFICAR SE USERNAME JÁ EXISTE NA BASE DE DADOS

    $motor = $ligacao->prepare("
        SELECT id_user from users WHERE username = ?"
    );

    $motor->execute([$utilizador]);

    if($motor->rowCount() > 0){

            echo '
            <div class="erro">
                Já existe um utilizador com o mesmo username.
            </div>
            ';
            ApresentarFormulario();
            return;       
    }  
    
    //Processamento do AVATAR

    if($avatar['name'] != ""){
        $nomeAvatar = uniqid() . '.jpg';
        move_uploaded_file($avatar['tmp_name'], 'image/' . $nomeAvatar);

    }
    //Encriptar password
    $passwordEncriptada = password_hash($password_1, PASSWORD_DEFAULT);

    //INSERIR UTILIZADOR NA BASE DE DADOS

    $sql = "
        INSERT INTO users (username, pass, avatar)
            VALUES (:user, :pass, :avatar)           
    ";

    $motor = $ligacao->prepare($sql);
    $motor->bindParam(':user', $utilizador);
    $motor->bindParam(':pass', $passwordEncriptada);
    $motor->bindParam(':avatar', $nomeAvatar);
    $motor->execute();

    $ligacao = null;

    echo '
    
        <div class="novo_registo_sucesso">
            Bem vindo ao Fórum, <strong>'.$utilizador.'</strong><br><br>
            Já podes fazer login e participar na comunidade.<br><br>
            <a href="index.php">Ir para o Login</a>
        </div>
        
    ';   


    }
    
?>