//Roboticaxyz.com
//iarobotxyz
#include <ESP8266WiFi.h>
const char* ssid = "INFINITUM01A2_2.4";
const char* password = "9dMsKDpARv";
WiFiServer server(80);
//16,5,4,0,14,2 pines de control esp8266 
const int motorP = 16;//Luz Claxon
const int motorL = 2;//Luz Microcontrolador //TX1
const int motorB = 5;//izquierda
const int motorC = 4;//Avanza
const int motorD = 0;//Atras
const int motorA = 14;//Derecha
// Auxiliar variables
String output16State = "off";
String output2State = "off";
String output4State = "off";
String output5State = "off";
String output14State = "off";
String output0State = "off";
//Fin Variables Globales
void setup() {
  Serial.begin(9600);
  delay(3);
  pinMode(motorP, OUTPUT);
  pinMode(motorL, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(motorC, OUTPUT);
  pinMode(motorD, OUTPUT);
  pinMode(motorA, OUTPUT);
  /////////Fin Mode
  Serial.println();
  Serial.print("Conectandose a red : ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); //Conexión a la red
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  server.begin(); //Iniciamos el servidor
  Serial.println("Servidor Iniciado");
  Serial.println("Ingrese desde un navegador web usando la siguiente IP:");
  Serial.println(WiFi.localIP()); //Obtenemos la IP
}
void loop() {
  WiFiClient client = server.available();
  if (client) //Si hay un cliente presente
  {
    Serial.println("Nuevo Cliente");
    //esperamos hasta que hayan datos disponibles
    while (!client.available() && client.connected())
    {
      delay(1);
    }
    // Leemos la primera línea de la petición del cliente.
    String linea1 = client.readStringUntil('r');
    Serial.println(linea1);
    ///////////////////////////////////////////////// GET Output
    if (linea1.indexOf("GET /16/on") >= 0) 
            {
              Serial.println("GPIO 16 on");
              output16State = "on";
              digitalWrite(motorP, HIGH);
            } 
    else if (linea1.indexOf("GET /16/off") >= 0) 
            {
              Serial.println("GPIO 16 off");
              output16State = "off";
              digitalWrite(motorP, LOW);
            } 
    //////////////////////  ////FIN P
        if (linea1.indexOf("GET /4/on") >= 0) 
            {
              Serial.println("GPIO 4 on");
              output4State = "on";
              digitalWrite(motorC, HIGH);
            } 
    else if (linea1.indexOf("GET /4/off") >= 0) 
            {
              Serial.println("GPIO 4 off");
              output4State = "off";
              digitalWrite(motorC, LOW);
            } 
    //////////////////////FIN 4////////////////
              if (linea1.indexOf("GET /5/on") >= 0) 
            {
              Serial.println("GPIO 5 on");
              output5State = "on";
              digitalWrite(motorB, HIGH);
            } 
    else if (linea1.indexOf("GET /5/off") >= 0) 
            {
              Serial.println("GPIO 5 off");
              output5State = "off";
              digitalWrite(motorB, LOW);
            } 
    //////////////////////  FIN 5///////////////
              if (linea1.indexOf("GET /14/on") >= 0) 
            {
              Serial.println("GPIO 14 on");
              output14State = "on";
              digitalWrite(motorA, HIGH);
            } 
    else if (linea1.indexOf("GET /14/off") >= 0) 
            {
              Serial.println("GPIO 14 off");
              output14State = "off";
              digitalWrite(motorA, LOW);
            } 
    //////////////////////  FIN 14///////////////
              if (linea1.indexOf("GET /2/on") >= 0) 
            {
              Serial.println("GPIO 2 on");
              output2State = "on";
              digitalWrite(motorL, HIGH);
            } 
    else if (linea1.indexOf("GET /2/off") >= 0) 
            {
              Serial.println("GPIO 2 off");
              output2State = "off";
              digitalWrite(motorL, LOW);
            } 
    //////////////////////  FIN 14///////////////
              if (linea1.indexOf("GET /0/on") >= 0) 
            {
              Serial.println("GPIO 0 on");
              output0State = "on";
              digitalWrite(motorD, HIGH);
            } 
    else if (linea1.indexOf("GET /0/off") >= 0) 
            {
              Serial.println("GPIO 0 off");
              output0State = "off";
              digitalWrite(motorD, LOW);
            } 
    //////////////////////  FIN 0///////////////
    //digitalWrite(motorP, LOW);   //Claxon BN
    //digitalWrite(motorL, LOW);   //Luz BN
    //digitalWrite(motorA, LOW);   //Derecha BN
    //digitalWrite(motorD, LOW);   //Atras BN
    //digitalWrite(motorB, LOW);   // Izquierda BN
    //digitalWrite(motorC, LOW);   // Adelante BN
    //delay(50);
    client.flush();
    Serial.println("Enviando respuesta...");
    //Encabesado http
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");// La conexión se cierra después de finalizar de la respuesta
    client.println();
    //Pagina html  para en el navegador
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head><title>RoboticaXYZ Carro WiFi - ESP8266</title>");
                // Display HTML web 
    client.println("<link rel=\"icon\" href=\"data:,\">");
    client.println("<meta name=\"tipo_contenido\"  content=\"text/html;\" http-equiv=\"content-type\" charset=\"utf-8\">");
    //Atributos Color
    client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 14px 30px;");
    client.println("text-decoration: none; font-size: 28px; margin: 2px; cursor: pointer;}");
    client.println(".button2 {background-color: #555555;}</style></head>");      
    client.println("<body>");
    client.println("<h1 align='center'>Carro WiFi - ESP8266</h1>");
    client.println("<div style='text-align:center;'>");
    client.println("<center>");
    client.println("<table border=7> <TR><TD COLSPAN=3><center>Frente del Robot</TD></TR>");
    client.println(" <tr><td><center>");
    client.println("</td><td><center>");
//2////////////////// AVANZA/////////////
            if (output4State=="on") 
            {
             output4State="on";
                client.println("<p>Adelante Encendido<p><a href=\"/4/off\"><button class=\"button button2\">DETENER</button></a></p>");
            } else 
            {
           output4State="off";
            client.println("<p>Adelante Apagado<p><a href=\"/4/on\"><button class=\"button\">AVANZA</button></a></p>");
            }
            client.println("</td><td><center>");
            client.println("</td></tr>");
            client.println(" <tr><td><center>");
            
///izquierda/////////////444////////
            if (output5State=="on" ) {
                client.println("<p>Izquierda Encendido<p><a href=\"/5/off\"><button class=\"button button2\">DETENER</button></a></p>");
            output5State="on";
              } 
            else 
            {
              output5State="off";
            client.println("<p>Izquierda Apagado<p><a href=\"/5/on\"><button class=\"button\">IZQUIERDA</button></a></p>");
            }
            
            client.println("</td><td>");
//////////////////////////////////////////////// LED azul
            client.println("<center>Claxon - LED Azul <p>");
            // If the output26State is off, it displays the ON button       
            if (output16State=="off") 
            {
              output16State="off";
              client.println("Apagado<p><a href=\"/16/on\"><button class=\"button\">ON</button></a></p>");
            } 
            else 
            {
              output16State="on";
              client.println("Encendido<p><a href=\"/16/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
/////////////////////
            if (output2State=="off") 
            {
              output2State="off";
              client.println("Apagado<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            } 
            else 
            {
              output2State="on";
              client.println("Encendido<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            client.println("</td><td><center>");
///derecha/////////////666/////////1y9
            if (output14State=="on") 
            {
              output14State="on";
              client.println("<p>Derecha Encendido<p><a href=\"/14/off\"><button class=\"button button2\">DETENER</button></a></p>");
            } 
            else 
            {
              output14State="off";
              client.println("<p>Derecha Apagado<p><a href=\"/14/on\"><button class=\"button\">DERECHA</button></a></p>");
            }
            client.println("</td></tr>");
  //////7/////////////7
            client.println(" <tr><td><center>");
            client.println("</td><td><center>");
//8////////////////// RETROCEDE/////////////
            if (output0State=="on") 
            {
              output0State="on";
              client.println("<p>Atras Encendido<p><a href=\"/0/off\"><button class=\"button button2\">DETENER</button></a></p>");
            } 
            else 
            {
              output0State="off";
              client.println("<p>Atras Apagado<p><a href=\"/0/on\"><button class=\"button\">ATRAS</button></a></p>");
            }        
    client.println("</td><td><center>");
    client.println("</td></tr>");
    client.println("<TR><TD COLSPAN=3><center>Atras del Robot</TD></TR>");
    client.println(" </table>                ");
    client.println("<br />");
    client.println("</div><p><p>");
    client.println("</body>");
    client.println("<div><center>");
    client.println("<a href='https://roboticaxyz.com/'>");
    client.println("RoboticaXYZ.com");
    client.println("</a></div>");
    client.println("</html>");
    delay(1);
    Serial.println("respuesta enviada");
    Serial.println();
  }
}
