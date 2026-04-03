<?php
 include 'cabecalho.php';
    echo '
    
        <form class="form_login" method="post" action="login_verificacao.php">

            <h3>Login</h3>
            <hr>
            <p>Para entrar no Fórum, necessita introduzir o seu username e password.<br>
            Senão tem conta de utilizador, pode criar uma <a href="signup.php"> nova conta de utilizador</a></p>

            <label for="text_utilizador">Username:</label>
            <input type="text" id="text_utilizador" name="text_utilizador" placeholder="Introduza o seu username" required>

            <label for="text_passoword">Password:</label>
            <input type="password" id="text_password" name="text_password" placeholder="Introduza a sua password" required>

            <button type="submit" class="btn_login">Entrar</button>
            
        </form>


    ';

?>