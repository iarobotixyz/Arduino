/* V2
RoboticaXYZ.com
 */
#include <EEPROM.h> // Incluimos la librería para poder usarla
#include <ESP8266WiFi.h>                  //Incluye la librería ESP8266WiFi
//#include <ESP8266HTTPClient.h>

const char ssid[] = "A-CultivoVertical-RobotXYZ-0002";    //Definimos la SSDI WIFI -nombre de red- 
const char password[] = "0987654321";       //Definimos la contraseña de WIFI
WiFiServer server(80);                    //Definimos el puerto de comunicaciones
int PinLED = 2;                           //GPIO2 / D4
int PinLED2 = 16;                           //

int estado = LOW;                         //Definimos la variable que va a recoger el estado del LED
int estado2 = LOW;                         //Definimos la variable que va a recoger el estado del LED

// Creamos un tipo de objeto personalizado
struct Obj{
  char fecha1[9];
  char fecha2[9];
  char fecha3[9];
  char fecha4[9];
  char fecha5[9];
  char fecha6[9];
  char fecha7[9];
  char fecha8[9];
};
void setup() {
  //float f = 0.00f;   // Variable to store data read from EEPROM.
  int eeAddress = 0; // Dirección EEPROM donde leer/Escribir
  Serial.begin(9600);
  // Datos a guardar.
  Obj customVarW = {
    "19/11/23",
    "19/11/23",
    "19/11/23",
    "19/11/23",
    "19/11/23",
    "19/11/23",
    "16/11/23",
    "19/11/23"
  };
  // Escribiendo datos
  EEPROM.put(eeAddress, customVarW);
  Serial.print(" ¡Datos escritos! ");
  // Recuperamos los datos
  Obj customVarR;
  EEPROM.get(eeAddress, customVarR);
  // Mostramos los datos leídos, los cuales deben coincidir
  Serial.println(" -- Leyendo fecha de la EEPROM: ");
  
  Serial.println(customVarR.fecha1);
  Serial.println(customVarR.fecha2);
  Serial.println(customVarR.fecha3);
  Serial.println(customVarR.fecha4);
  Serial.println(customVarR.fecha5);
  Serial.println(customVarR.fecha6);
  Serial.println(customVarR.fecha7);
  Serial.println(customVarR.fecha8);
  
  pinMode(PinLED, OUTPUT);                //Inicializamos el GPIO2 como salida
  pinMode(PinLED2, OUTPUT);                //Inicializamos el GPIO2 como salida
  
  digitalWrite(PinLED, LOW);              //Dejamos inicialmente el GPIO2 apagado
  digitalWrite(PinLED2, LOW);              //Dejamos inicialmente el GPIO2 apagado
  
  server.begin();                         //inicializamos el servidor
  WiFi.mode(WIFI_AP);
  //WiFi.softAP(ssid, password);            //Red con clave, en el canal 1 y visible
  //WiFi.softAP(ssid, password,3,1);      //Red con clave, en el canal 3 y visible 
  WiFi.softAP(ssid);                    //Red abierta
  Serial.println();
  //Serial.print("Direccion IP Punto de acceso - por defecto: ");      //Imprime la dirección IP
  //Serial.println(WiFi.softAPIP()); 
  //Serial.print("Direccion MAC Punto de acceso: ");                   //Imprime la dirección MAC
  //Serial.println(WiFi.softAPmacAddress()); 
}
void loop() 
{

  // Comprueba si el cliente ha conectado
  WiFiClient client = server.available(); 
  //HTTPClient http;
  



  //WiFiClient client;
  //HTTPClient http; 
  //Serial.println(http);//si es =0 no trae peticion
  //Serial.println(client);//si es =0 no trae peticion
  if (!client) 
  {
    return;
  }

  // Espera hasta que el cliente envía alguna petición
  //Serial.println("Cliente Nuevo");
  while(!client.available())
  {
    delay(1);
  }

  // Imprime el número de clientes conectados
  //Serial.printf("Clientes conectados al Punto de acceso: %dn", WiFi.softAPgetStationNum()); 

  // Lee la petición
  String peticion = client.readStringUntil('r');
  //Serial.println(peticion);
  //Serial.println(peticion[10]);

String  str = peticion;
//String  str = "A1N c2 hola d4 t0 b5 t0 a2 mundo e2 t452 1c t0 e1 fechas";
String cadenaGlobal;
String strs[20];
int StringCount = 0;
  // Split the string into substrings
  while (str.length() > 0)
  {
    int index = str.indexOf(' ');
    if (index == -1) // No space found
    {
      strs[StringCount++] = str;
      break;
    }
    else
    {
      strs[StringCount++] = str.substring(0, index);
      str = str.substring(index+1);
    }
  }

  // Show the resulting substrings
  for (int i = 0; i < StringCount; i++)
  {
    Serial.print(i);
     if (i == 1) 
    {
        Serial.print("1 Cadena- \"");
        Serial.print(strs[i]);
        // you can also use replace() on single characters:
        String normalString = strs[i];
        //String normalString = "1a=2023-11-19&1b=2023-11-19&2a=2023-11-19&";
        Serial.println("normal: " + normalString);
        String leetString = normalString;
        leetString.replace('&', ',');
        leetString.replace('?', ',');
        Serial.println("Remplaza: " + leetString);
        cadenaGlobal=leetString;

    }
  }





Serial.println(cadenaGlobal);

//char msg[10] = peticion.c_str();
//std::string myString = "HELLO";
char msg[] = "1,20,30,400,500";
//char msg[] = leetString;

//char msg[] = peticion;
Serial.println("\"");
Serial.println(msg);
  char* ptr = strtok(msg, ",");
  byte i = 0;
  Serial.println(F("index\ttext\tNumeric Value"));
  while (ptr) {
    Serial.print(i);
    Serial.print(F("\t\""));
    Serial.print(ptr); // this is the ASCII text we want to transform into an integer
    Serial.print(F("\"\t"));
    Serial.println(atol(ptr)); // atol(ptr) will be your long int you could store in your array at position i. atol() info at http://www.cplusplus.com/reference/cstdlib/atol
    ptr = strtok(NULL, ",");
    i++;
  }


  String vst = client.readStringUntil('\n');
  Serial.println(vst);




  
  client.flush();

  if (peticion.indexOf('/Save=ON') != -1) 
  {
   Serial.println("Fecha Guardada Separar todas las fechas que llegan por get para guardar en la eeprom");
   Serial.println("Separar peticion pero solo la parte de GET");
   digitalWrite(16, LOW);
   delay(100);
   digitalWrite(16, HIGH);
   delay(100);
  } 
  // Bomba
  if (peticion.indexOf('/BOMBA=ON') != -1) {
    estado = HIGH;
  } 
  if (peticion.indexOf('/BOMBA=OFF') != -1){
    estado = LOW;
  }

  // Luz
  if (peticion.indexOf('/LUZ=ON') != -1) {
    estado2 = HIGH;
  } 
  if (peticion.indexOf('/LUZ=OFF') != -1){
    estado2 = LOW;
  }
  //Enciende o apaga el LED en función de la petición
  digitalWrite(PinLED, estado);
  digitalWrite(PinLED2, estado2);
  // Comprueba la petición

  // Envía la página HTML de respuesta al cliente
  client.println("HTTP/1.1 200 OK");
  client.println("");                                     
  client.println("<!DOCTYPE HTML>");
  client.println("<meta charset='UTF-8'>");
  client.println("<html><title>Hidroponia-RoboticaXYZ</title><center>");
  client.println("<form action='/Save=ON' method='get' id='add_create' name='add_create'>");

client.println("<table border='6' width='100%'>");
client.println("<tr>");
client.println("<td bgcolor='green' align=center width='70%'><h2>");
client.println(ssid);
client.println("</h2><h1>Cultivo Vertical Automatizado</h1>");
client.println("<table border='16' width='35%'>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center><b>Panel Solar</b></td>");
client.println("<td colspan='2' bgcolor='white' align=center>");
client.println("<h2>Calendario Digital</h2></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center><b>Generador</b></td>");
client.println("<td bgcolor='white' align=center><b>Inicio</b>");
client.println("</td>");
client.println("<td bgcolor='white' align=center><b>Fin</b>");
client.println("</td>");
client.println("</tr>");
client.println("<tr>");

client.println("<td bgcolor='gray' align=center>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
client.println("&bsol; 1 /");

client.println("<br>| |</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' name='1a' value='2023-11-19'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' name='1b' value='2023-11-19'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
client.println("&bsol; 2 /");
client.println("<br>| |</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='2a'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='2b'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
client.println("&bsol; 3 /");
client.println("<br>| |</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='3a'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='3b'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
client.println("&bsol; 4 /");
client.println("<br>| |</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='4a'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='4b'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
client.println("&bsol; 5 /");
client.println("<br>| |</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='5a'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='5b'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
client.println("&bsol; 6 /");
client.println("<br>| |</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='6a'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='6b'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
client.println("&bsol; 7 /");
client.println("<br>| |</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='7a'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='7b'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='gray' align=center>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
client.println("&bsol; 8 /");
client.println("<br>| |</td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='8a'></td>");
client.println("<td bgcolor='gray' align=center>");
client.println("<input type='date' value='2023-11-19' name='8b'></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='cyan' align=center><b>Sensor Humedad</b></td>");
client.println("<td colspan='2' bgcolor='gray' align=center> ");
client.println("<marquee behavior='alternate'>Buscando...</marquee></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='cyan' align=center><b>Bomba de Agua</b></td><td align='center' bgcolor='yellow'>");
  if(estado == HIGH) {
    client.print("Encendida");  
  } else {
    client.print("Apagada");
  }
client.println("</td>");
client.println("<td bgcolor='gray' align=center>");
//client.print("<button type='button' onClick=location.href='/Save=ON'> Guardar </button>");
client.print("<button type='submit' class='btn btn-primary btn-block'>Guardar</button>");
client.println("</td></tr>");
client.println("<tr>");
client.println("<td colspan='2' bgcolor='cyan' align=center><b>Nivel <br> Tanque Agua</b></td>");
client.println("<td bgcolor='gray' align=center>RoboticaXYZ</td>");
client.println("</tr>");
client.println("</table>");
client.println("<p></td>");


client.println("<td bgcolor='cyan' align=center width='30%'>");

client.println("<table border='0' width='100%'>");
client.println("<tr><td bgcolor='yellow' align=center width='20%'>");
client.println("<h1>Energía</h1>");
client.println("<table border='16' width='80%'>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center><b><marquee behavior='alternate'> -- Sin Bateria -- </marquee></b></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center><b>Panel Solar</b></td>");
client.println("</tr>");
client.println("<tr>");
client.println("<td bgcolor='yellow' align=center><b>Generador</b></td>");
client.println("</tr>");
client.println("</table>");
client.println("<p></td></tr>");

client.println("</table>");


client.println("<h1>Agua y Humedad</h1><table border='16' width='80%'>");
client.println("<tr>");
client.println("<td bgcolor='cyan' align=center><p>");
      //Imprime el estado del led
  client.print("<h3>Bomba de Agua: ");                 
  if(estado == HIGH) {
    client.print("ENCENDIDO</h3>");  
  } else {
    client.print("APAGADO</h3>");
  }
  client.println("</td>");
  client.println("</tr><tr><td><center>");
      
  if(estado == HIGH) 
  {
      client.println("<button type='button' onClick=location.href='/BOMBA=OFF' style='margin:auto; background-color:red; color:#F6D8CE; padding:5px; border:2px solid black; width:200;'><h2> APAGAR</h2> </button>");
  } 
  else 
  {
    client.println("<button type='button' onClick=location.href='/BOMBA=ON' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'><h2> ENCENDER</h2> </button>");
  }

  client.println("<br>-----<br>");
  if(estado2 == HIGH) 
  {
      client.println("<button type='button' onClick=location.href='/LUZ=OFF' style='margin:auto; background-color:red; color:#F6D8CE; padding:5px; border:2px solid black; width:200;'><h2> APAGAR</h2> </button>");
  } 
  else 
  {
    client.println("<button type='button' onClick=location.href='/LUZ=ON' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'><h2> ENCENDER</h2> </button>");
  }

client.print("<button type='button' onClick=location.href='/LUZ=ON'> ON </button>");
client.print("<button type='button' onClick=location.href='/LUZ=OFF'> OFF </button>");

  client.println("</td></tr></table>");
  client.println("</td>");
  client.println("</tr>");
  client.println("</table>");
  client.println("</form>");
  client.println("</html>"); 
  delay(1);
  Serial.println("Fin HTML - Esperando Nueva Peticion Cliente");



}