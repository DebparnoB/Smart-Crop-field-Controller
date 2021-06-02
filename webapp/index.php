<?php
$cond1 = $cond2 = 1;
$link = mysqli_connect("localhost","root","","agriculture");
$reg = @$_POST['reg'];
if($reg)
{
  $username = $_POST['username'];
  $password = $_POST['password'];
  $result = mysqli_query($link,"SELECT * FROM users WHERE username = '$username'");
  if(mysqli_num_rows($result)==0)
  {
    $cond1 = 0;
  }
  else {
    $cond1=1;
    $result2 = mysqli_query($link, "SELECT * FROM users WHERE username = '$username' AND password = '$password'");
    if(mysqli_num_rows($result2)==0)
    {
      $cond2 = 0;
    }
    else {
      $cond2 = 1;
      session_start();
      $_SESSION['valid'] = true;
      $_SESSION['username'] = $username;
      header('Location: profile.php');
      //session_write_close();
    }
  }
}
?>

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Smart Agriculture</title>
    <link  rel="stylesheet" type="text/css" href="index_style.css">
  </head>
  <body>
    <div id = "background" class = "background">
      <img src="style/google.png" id = "title">
      <div id = "frame">
        <p id = "admin_login_text">Admin Login</p>
        <p id = "Username_label">Username</p>
        <p id = "password_label">Password</p>
        <form class="login" action="#" method="POST">
          <input type = "text" id = "user_name" autocomplete ="on" name = "username">
          <input type="password" id = "password" autocomplete ="on" name = "password">
          <input type="submit" id = "submit_button" placeholder="Log In" name = "reg">
        </form>
      </div>
    </div>
    <div class="footer">
      <p id="copyright">&copy 2019-20 Final Year Project, Group-8. All Rights Reserved</p>
    </div>
  </body>
</html>
