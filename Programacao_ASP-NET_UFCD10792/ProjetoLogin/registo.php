<?php

    echo '
        <form class="form_login" method="post" action="login_verificacao.php">

        
        <h3> Register Now <img src="image/livros.png" alt="Logo de Login"></h3>
        
                      
            <label for="text_utilizador">Your Name*</label>
            <input type="text" id="text_name" name="text_name" placeholder="Enter Your Name" required>

            <label for="text_passoword">Your Email*</label>
            <input type="email" id="text_email" name="text_email" placeholder="Enter Your Email" required>

            <label for="text_utilizador">Password*</label>
            <input type="password" id="text_password" name="text_password" placeholder="Enter Your Password" required>

            <label for="text_passoword">Confirm Password*</label>
            <input type="password" id="text_confpassword" name="text_confpassword" placeholder="Confirm Your Password" required>

            <label for="text_type">User Type*</label>
            <select id="text_type" name="text_type" required>
            <option value="">--  USER  --</option>
            </select>

            <button type="submit" class="btn_login">Register Now</button>

             <p>Already Have An Account?. <a href="signup.php"> Register Now</a></p>
            
        </form>


    ';

?>