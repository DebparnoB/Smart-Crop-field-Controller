<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Area1</title>
  </head>
  <body>
    <link rel="stylesheet" type="text/css" href="area1_style.css">

    <div class = "background" id = "background3">

      </div>
      <p id = "heading" >IOT based Smart Irrigation System</p>
      <div >

        <p id = "area_name">Area1</p>
        <iframe width="450" height="360" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/716991/charts/2?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=10&title=Temperature&type=line&yaxis=%2AC" id = "temp_area"></iframe>
        <iframe width="450" height="360" style="border: 1px solid #cccccc;" id = "humidity_area" src="https://thingspeak.com/channels/716991/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=10&title=Humidity&type=line&yaxis=%25"></iframe>
        <iframe width="450" height="360" style="border: 1px solid #cccccc;" id = "soil_area" src="https://thingspeak.com/channels/716991/charts/3?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=10&title=Soil+Moisture&type=line&yaxis=%25"></iframe>
        <iframe width="450" height="360" style="border: 1px solid #cccccc;" id = "water_area" src="https://thingspeak.com/channels/716991/charts/4?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=10&title=Waterlevel&type=line&yaxis=cm"></iframe>
      </div>

      <div class="footer">
        <p id="copyright">&copy 2019-20 Final Year Project, Group-8. All Rights Reserved</p>
      </div>
  </body>
</html>
