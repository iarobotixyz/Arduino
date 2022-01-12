#include <ESP8266WiFi.h>
const char* ssid = "INFINITUM9h4v";
const char* password = "f9c53b6229";
WiFiServer server(80);
void setup() {
  Serial.begin(9600);
  delay(10);
  //Configuración  del GPIO2
  pinMode(2, OUTPUT);
  digitalWrite(2,LOW);
  Serial.println();
  Serial.println();
  Serial.print("Conectandose a red : ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); //Conexión a la red
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
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
    while(!client.available()&&client.connected())
    {
    delay(1);
    }
    // Leemos la primera línea de la petición del cliente.
    String linea1 = client.readStringUntil('r');
    Serial.println(linea1);

    if (linea1.indexOf("LED=ON")>0) //Buscamos un LED=ON en la 1°Linea
    {
      digitalWrite(2,HIGH);
    }
    if (linea1.indexOf("LED=OFF")>0)//Buscamos un LED=OFF en la 1°Linea
    {
      digitalWrite(2,LOW);
    }
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
    client.println("<head><title>Robotxyz Test ESP8266</title>");
    client.println("<body>");
    client.println("<h1 align='center'>Test ESP8266</h1>");
    client.println("<div style='text-align:center;'>");
    client.println("<br />");            
    client.println("<button onClick=location.href='./?LED=ON'>LED ON</button>");           
    client.println("<button onClick=location.href='./?LED=OFF'>LED OFF</button>");
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
