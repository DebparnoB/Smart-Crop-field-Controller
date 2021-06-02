<?php

if(!isset($_SESSION['username']))
{
  exit ("Access Denied");
}

$link = mysqli_connect("localhost","root","","users");

$reg2 = @$_POST['reg2'];
if($reg2)
{
  $region = $_POST['region'];
  if($region == 'area1')
  {
    header('Location: area1.php');
  }
  else {
    header('Location: area_other.php');
  }
}

?>

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Smart Agriculture</title>
    <link rel="stylesheet" type="text/css" href="profile_style.css">
  </head>
  <body>
    <div class = "background" id = "background2">
      <div class="block" id = "block"  >
        </div>
        <p id ="select_text">Select Location</p>

    </div>

    <div class="footer">
      <p id="copyright">&copy 2019-20 Final Year Project, Group-8. All Rights Reserved</p>
    </div>

    <div>
    <form  action="#" method="POST">
      <select id = "select_bar" name="region">
        <option selected disabled>Choose area</option>
        <option value="area1" class = "area">Area-1</option>
        <option value="area2" class = "area">Area-2</option>
        <option value="area3" class = "area">Area-3</option>
        <option value="area4" class = "area">Area-4</option>
      </select>
      <input type="submit" id = "button" name = "reg2" value="Search">
    </form>
    </div>
  </body>
</html>
