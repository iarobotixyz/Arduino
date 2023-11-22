/*
RoboticaXYZ.com
 */
#include <ESP8266WiFi.h>                  //Incluye la librería ESP8266WiFi
const char ssid[] = "A-CultivoVertical-RobotXYZ-0002";    //Definimos la SSDI WIFI -nombre de red- 
const char password[] = "0987654321";       //Definimos la contraseña de WIFI
WiFiServer server(80);                    //Definimos el puerto de comunicaciones
int PinLED = 2;                           //Definimos el pin de salida - GPIO2 / D4
int estado = LOW;                         //Definimos la variable que va a recoger el estado del LED
void setup() {
  Serial.begin(115200);
  pinMode(PinLED, OUTPUT);                //Inicializamos el GPIO2 como salida
  digitalWrite(PinLED, LOW);              //Dejamos inicialmente el GPIO2 apagado
  server.begin();                         //inicializamos el servidor
  WiFi.mode(WIFI_AP);
  //WiFi.softAP(ssid, password);            //Red con clave, en el canal 1 y visible
  //WiFi.softAP(ssid, password,3,1);      //Red con clave, en el canal 3 y visible 
  WiFi.softAP(ssid);                    //Red abierta
  Serial.println();
  Serial.print("Direccion IP Punto de acceso - por defecto: ");      //Imprime la dirección IP
  Serial.println(WiFi.softAPIP()); 
  Serial.print("Direccion MAC Punto de acceso: ");                   //Imprime la dirección MAC
  Serial.println(WiFi.softAPmacAddress()); 
}
void loop() 
{
  // Comprueba si el cliente ha conectado
  WiFiClient client = server.available();  
  if (!client) {
    return;
  }

  // Espera hasta que el cliente envía alguna petición
  Serial.println("Cliente Nuevo");
  while(!client.available()){
    delay(1);
  }

  // Imprime el número de clientes conectados
  Serial.printf("Clientes conectados al Punto de acceso: %dn", WiFi.softAPgetStationNum()); 

  // Lee la petición
  String peticion = client.readStringUntil('r');
  Serial.println(peticion);
  client.flush();

  // Comprueba la petición
  if (peticion.indexOf('/BOMBA=ON') != -1) {
    estado = HIGH;
  } 
  if (peticion.indexOf('/BOMBA=OFF') != -1){
    estado = LOW;
  }

  //Enciende o apaga el LED en función de la petición
  digitalWrite(PinLED, estado);

  // Envía la página HTML de respuesta al cliente
  client.println("HTTP/1.1 200 OK");
  client.println("");                                     
  client.println("<!DOCTYPE HTML>");
  client.println("<meta charset='UTF-8'>");
  client.println("<html><title>Hidroponia-RoboticaXYZ</title><center>");
client.println("<table border='6' width='100%'>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center width='20%'><h1>Energía</h1>");
client.println("<table border='16' width='50%'>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center><b>Panel Solar</b></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center><b>Generador</b></td>");
client.println("</tr>");
client.println("</table>");
client.println("</td>");
client.println("<td bgcolor='green' align=center width='60%'><h2>");
client.println(ssid);
client.println("</h2><h1>Cultivo Vertical</h1>");
client.println("<table border='16' width='35%'>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center><b>Panel Solar</b></td>");
client.println("<td colspan='2' bgcolor='gray' align=center>");
client.println("<h2>Calendario Digital</h2></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center><b>Generador</b></td>");
client.println("<td bgcolor='gray' align=center><b>Inicio</b>");
client.println("</td>");
client.println("<td bgcolor='gray' align=center><b>Fin</b>");
client.println("</td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>1");
client.println("</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>2");
client.println("</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>3");
client.println("</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>4");
client.println("</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>5");
client.println("</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>6");
client.println("</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>7");
client.println("</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>8");
client.println("</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='true'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='cyan' align=center><b>Sensor Humedad</b></td>");
client.println("<td colspan='2' bgcolor='gray' align=center> </td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='cyan' align=center><b>Bomba de Agua</b></td><td align='center' bgcolor='cyan'>");
  if(estado == HIGH) {
    client.print("Encendida");  
  } else {
    client.print("Apagada");
  }
client.println("</td>");
client.println("<td bgcolor='gray' align=center> </td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td colspan='2' bgcolor='cyan' align=center><b>Nivel <br> Tanque Agua</b></td>");
client.println("<td bgcolor='gray' align=center>RoboticaXYZ</td>");
client.println("</tr>");
client.println("</table>");
client.println("<p></td>");
client.println("<td bgcolor='cyan' align=center width='20%'><h1>Agua y Humedad</h1>");
client.println("<table border='16' width='50%'>");
client.println("<tr>");
client.println("<td bgcolor='cyan' align=center><p>");
      //Imprime el estado del led
  client.print("<h1>Bomba de Agua: ");                 
  if(estado == HIGH) {
    client.print("ENCENDIDO</h1>");  
  } else {
    client.print("APAGADO</h1>");
  }
  client.println("</td>");
  client.println("</tr><tr><td><center>");
      
  client.println("<button type='button' onClick=location.href='/BOMBA=ON' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'><h2> ENCENDER</h2> </button>");
  client.println("<button type='button' onClick=location.href='/BOMBA=OFF' style='margin:auto; background-color:red; color:#F6D8CE; padding:5px; border:2px solid black; width:200;'><h2> APAGAR</h2> </button><br><br>");
    
  if(estado == HIGH) {
    client.print("<button type='button' onClick=location.href='/BOMBA=OFF'> APAGAR </button><br><br>");  
  } else {
    client.print("<button type='button' onClick=location.href='/BOMBA=ON'> ENCENDER </button><br><br>");
  }
  client.println("</td></tr></table>");
  client.println("</td>");
  client.println("</tr>");
  client.println("</table>");
  client.println("</html>"); 
  delay(1);
  Serial.println("Esperando Cliente"); 
}