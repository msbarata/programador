<?php

    echo '
        <form class="form_login" method="post" action="login_verificacao.php">

        
        <h3> Login Now <img src="image/livros.png" alt="Logo de Login"></h3>
        
                      
            <label for="text_utilizador">Enter Your Email*</label>
            <input type="text" id="text_utilizador" name="text_utilizador" placeholder="Enter Your Email" required>

            <label for="text_passoword">Enter Your Password*</label>
            <input type="password" id="text_password" name="text_password" placeholder="Enter Your Password" required>

            <button type="submit" class="btn_login">Login Now</button>

             <p>Don`t Have An Account?. <a href="signup.php"> Register Now</a></p>
            
        </form>


    ';

?>