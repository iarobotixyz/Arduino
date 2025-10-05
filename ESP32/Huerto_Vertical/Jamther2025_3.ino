//ROBOTICAXYZ.com/Jamther
#include <WiFi.h>
#include <Bonezegei_DHT11.h>

const char* ssid = "JAMther-CultivoVertical-0003"; // Nombre de la red Wi-Fi / SSID
const char* password = "0987654321"; // Contraseña Wi-Fi

// Puerto del Servidor
WiFiServer server(80);

// Variable para almacenar la cabecera HTTP
String header;

// Variables auxiliares para el estado de los GPIOs
String output26State = "off";
String output2State = "off";

// Tiempo actual
unsigned long currentTime = millis();
// Tiempo previo
unsigned long previousTime = 0; 
// Timeout en milisegundos (ejemplo: 2000ms = 2s)
const long timeoutTime = 2000;

// Variables del sensor analógico
int xyz, sensor_analog;
String axyz = "";
const int sensor_pin = A0; // Pin analógico VP

// DHT11
String dxyz = "";
Bonezegei_DHT11 dht(16); // Pin digital para DHT11

void setup() {
  Serial.begin(115200); // Inicializar puerto serial
  dht.begin(); // Inicializar DHT11

  // Inicializar los GPIOs como salida
  pinMode(26, OUTPUT);
  pinMode(2, OUTPUT);

  // Poner los GPIOs en LOW al inicio
  digitalWrite(26, LOW);
  digitalWrite(2, LOW);

  // Conectar a Wi-Fi
  Serial.print("Conectando a ");
  Serial.println(ssid);
  //WiFi.begin(ssid, password); // Conectar a una red (opcional)
  WiFi.softAP(ssid, password); // Crear punto de acceso
  Serial.print("Punto de acceso creado: ");
  Serial.println(ssid);
  Serial.print("Dirección IP del ESP32: ");
  Serial.println(WiFi.softAPIP()); // Obtener IP del ESP32

  server.begin(); // Iniciar servidor
}

// Función para separar cadenas por un separador
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop(){
  // Leer datos del DHT11
  if (dht.getData()) {                         
    float tempDeg = dht.getTemperature();      
    float tempFar = dht.getTemperature(true);  
    int hum = dht.getHumidity();               
    String str  = "Temperatura: ";
           str += tempDeg;
           str += "°C  ";
           str += tempFar;
           str += "°F  Humedad:";
           str += hum;
    Serial.println(str.c_str());
    dxyz=str.c_str();
  }
  
  delay(1000); // Delay para que DHT11 pueda leer datos

  // Leer sensor analógico
  sensor_analog = analogRead(sensor_pin);
  xyz = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  axyz = xyz;

  // Escuchar clientes entrantes
  WiFiClient client = server.available();   
  if (client) {                             
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("Nuevo Cliente.");          
    String currentLine = "";                

    while (client.connected() && currentTime - previousTime <= timeoutTime) {  
      currentTime = millis();
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        header += c;

        if (c == '\n') {                    
          if (currentLine.length() == 0) {

            // Cabeceras HTTP básicas
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Coneccion: cerrada");
            client.println();

            // Control de GPIOs vía HTTP
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(26, HIGH);
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(26, LOW);
            } else if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("GPIO 2 on");
              output2State = "on";
              digitalWrite(2, HIGH);
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("GPIO 2 off");
              output2State = "off";
              digitalWrite(2, LOW);
            }

            // Primer HTML inicial con botones principales
            client.println("<body><h1> ESP32 Punto de Acceso 2 GPIO<p>");
            client.println("<p>Analogico " + axyz + "</p>");
            client.println("<p>DHT 11 " + dxyz + "</p></h1>");
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            if (output26State=="off") {
              client.println("<p><a href=\"/26/on\"><button>ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button>OFF</button></a></p>");
            }  
            client.println("<p>GPIO 2 - State " + output2State + "</p>");
            if (output2State=="off") {
              client.println("<p><a href=\"/2/on\"><button>ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button>OFF</button></a></p>");
            }  

////////JAMther2024
            // Lee la petición
            String peticion = client.readStringUntil('r');
            String str = peticion;
            String cadenaGlobal;
            String strs[20];
            int StringCount = 0;
            int StringCount2 = 0;

            // Separar la cadena de la petición por espacios
            while (str.length() > 0) {
              int index = str.indexOf(' ');
              if (index == -1)  // No se encontró espacio
              {
                strs[StringCount++] = str;
                break;
              } else {
                strs[StringCount++] = str.substring(0, index);
                str = str.substring(index + 1);
              }
            }

            // Procesar la segunda parte de la cadena
            for (int i = 0; i < StringCount; i++) {
              Serial.print(i);
              if (i == 1) {
                String normalString = strs[i];
                Serial.println(normalString);
                String leetString = normalString;
                leetString.replace('&', ',');
                leetString.replace('?', ',');
                cadenaGlobal = leetString;
              }
            }

            // Obtener valores individuales de la cadena global
            String part00 = getValue(cadenaGlobal, ',', 0);
            String part01 = getValue(cadenaGlobal, ',', 1);
            String part02 = getValue(cadenaGlobal, ',', 2);
            String part03 = getValue(cadenaGlobal, ',', 3);
            String part04 = getValue(cadenaGlobal, ',', 4);
            String part05 = getValue(cadenaGlobal, ',', 5);
            String part06 = getValue(cadenaGlobal, ',', 6);
            String part07 = getValue(cadenaGlobal, ',', 7);
            String part08 = getValue(cadenaGlobal, ',', 8);
            String part09 = getValue(cadenaGlobal, ',', 9);
            String part10 = getValue(cadenaGlobal, ',', 10);
            String part11 = getValue(cadenaGlobal, ',', 11);
            String part12 = getValue(cadenaGlobal, ',', 12);
            String part13 = getValue(cadenaGlobal, ',', 13);
            String part14 = getValue(cadenaGlobal, ',', 14);
            String part15 = getValue(cadenaGlobal, ',', 15);
            String part16 = getValue(cadenaGlobal, ',', 16);

            // Remover los primeros 3 caracteres de cada parte (ajuste de formato)
            part01.remove(0, 3);  
            part02.remove(0, 3);  
            part03.remove(0, 3);  
            part04.remove(0, 3);  
            part05.remove(0, 3);  
            part06.remove(0, 3);  
            part07.remove(0, 3);  
            part08.remove(0, 3);  
            part09.remove(0, 3);  
            part10.remove(0, 3);  
            part11.remove(0, 3);  
            part12.remove(0, 3);  
            part13.remove(0, 3);  
            part14.remove(0, 3);  
            part15.remove(0, 3);  
            part16.remove(0, 3);  

            client.flush(); // Limpiar buffer del cliente

            // Manejo de la acción de guardar datos
            if (peticion.indexOf('/Save=ON') != -1) {
              Serial.println("Fecha Guardada en la eeprom entra ALMACEN");
              Serial.println(part00);

              if(part00=="/BOMBA=ON") {
                Serial.print("¡Bomba on!");
              }
              if(part00=="/LUZ=ON") {
                Serial.print("LUZ on!");
              }
              if(part00=="/Save=ON") {
                Serial.print(" ¡Datos escritos 0! Almacenar ");
                // Aquí se podría llamar a la función writeString(10, cadenaGlobal);
              }

              // Mostrar todas las partes para depuración
              Serial.println(part01);
              Serial.println(part02);
              Serial.println(part03);
              Serial.println(part04);
              Serial.println(part05);
              Serial.println(part06);
              Serial.println(part07);
              Serial.println(part08);
              Serial.println(part09);
              Serial.println(part10);
              Serial.println(part11);
              Serial.println(part12);
              Serial.println(part13);
              Serial.println(part14);
              Serial.println(part15);
              Serial.println(part16);

              // Dispositivo conectado
              String vst = client.readStringUntil('\n');
              Serial.println(vst);
            }

            ////////////////////////////////////////////////////
            // Control de Bomba
            if (peticion.indexOf('/BOMBA=ON') != -1) {
              //estado=HIGH;
            }
            if (peticion.indexOf('/BOMBA=OFF') != -1) {
              //estado=LOW;
            }
            // Control de Luz
            if (peticion.indexOf('/LUZ=ON') != -1) {
              //estado2 = HIGH;
            }
            if (peticion.indexOf('/LUZ=OFF') != -1) {
              //estado2 = LOW;
            }

            // Comienzo del HTML principal
            client.println("<!DOCTYPE HTML>");
            client.println("<meta charset='UTF-8'>");
            client.println("<html><title>Jamther-HuertoVertical-RoboticaXYZ</title><center>");
            client.println("<form action='/Save=ON' method='get' id='add_create' name='add_create'>");
            client.println("<table border='6' width='100%'>");
            client.println("<tr>");
            client.println("<td bgcolor='green' align=center width='70%'><h2>");
            client.println(ssid);
            client.println("</h2><h1>Cultivo Vertical Automatizado</h1>");
            client.println("<table border='16' width='35%'>");
            client.println("<tr>");
            client.println("<td bgcolor='yellow' align=center><b>&nbsp;&nbsp;&nbsp;__________<br>");
            client.println("Panel Solar<br>/____ /____ /");
            client.println("</b></td>");
            client.println("<td colspan='2' bgcolor='white' align=center>");
            client.println("<h2><font face='Times New Roman'>Calendario Digital</font></h2></td>");
            client.println("</tr>");
            client.println("<tr>");
            client.println("<td bgcolor='yellow' align=center><b>(-----)<br>");
            client.println("( Generador )<br>(-----)</b></td>");
            client.println("<td bgcolor='white' align=center><b>Inicio</b>");
            client.println("</td>");
            client.println("<td bgcolor='white' align=center><b>Fin</b>");
            client.println("</td>");
            client.println("</tr>");

            client.println("<tr>");
            client.println("<td bgcolor='gray' align=center><b>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
            client.println("&bsol; 1 /");
            client.println("<br>| |</b></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' name='1a' value='" + part01 + "'></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' name='1b' value='" + part02 + "'></td>");
            client.println("</tr>");
            client.println("<tr>");
            client.println("<td bgcolor='gray' align=center><b>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
            client.println("&bsol; 2 /");
            client.println("<br>| |</b></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part03 + "' name='2a'></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part04 + "' name='2b'></td>");
            client.println("</tr>");
            client.println("<tr>");
            client.println("<td bgcolor='gray' align=center><b>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
            client.println("&bsol; 3 /");
            client.println("<br>| |</b></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part05 + "' name='3a'></td>");
            client.println("<td bgcolor='gray' align=center'>");
            client.println("<input type='date' value='" + part06 + "' name='3b'></td>");
            client.println("</tr>");
            client.println("<tr>");
            client.println("<td bgcolor='gray' align=center><b>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
            client.println("&bsol; 4 /");
            client.println("<br>| |</b></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part07 + "' name='4a'></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part08 + "' name='4b'></td>");
            client.println("</tr>");
            client.println("<tr>");
            client.println("<td bgcolor='gray' align=center><b>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
            client.println("&bsol; 5 /");
            client.println("<br>| |</b></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part09 + "' name='5a'></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part10 + "' name='5b'></td>");
            client.println("</tr>");
            client.println("<tr>");
            client.println("<td bgcolor='gray' align=center><b>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
            client.println("&bsol; 6 /");
            client.println("<br>| |</b></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part11 + "' name='6a'></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part12 + "' name='6b'></td>");
            client.println("</tr>");
            client.println("<tr>");
            client.println("<td bgcolor='gray' align=center><b>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
            client.println("&bsol; 7 /");
            client.println("<br>| |</b></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part13 + "' name='7a'></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part14 + "' name='7b'></td>");
            client.println("</tr>");
            client.println("<tr>");
            client.println("<td bgcolor='gray' align=center><b>|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br>");
            client.println("&bsol; 8 /");
            client.println("<br>| |</b></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part15 + "' name='8a'></td>");
            client.println("<td bgcolor='gray' align=center>");
            client.println("<input type='date' value='" + part16 + "' name='8b'></td>");
            client.println("</tr>");

            // Sensor Humedad
            client.println("<tr>");
            client.println("<td bgcolor='cyan' align=center><b>Sensor Humedad</b></td>");
            client.println("<td colspan='2' bgcolor='gray' align=center> ");
            client.println("<marquee behavior='alternate'>< ------------ ></marquee><b>");
            client.println(" % </b></td>");
            client.println("</tr>");

            // Bomba de Agua
            client.println("<tr>");
            client.println("<td bgcolor='cyan' align=center><b>Bomba de Agua</b></td><td align='center' bgcolor='yellow'>");
            client.println("</td>");
            client.println("<td bgcolor='gray' align=center>");
            client.print("<button type='submit'>Guardar</button>");
            client.println("</td></tr>");

            // Nivel Tanque Agua
            client.println("<tr>");
            client.println("<td colspan='2' bgcolor='cyan' align=center><b>Nivel <br> Tanque Agua</b></td>");
            client.println("<td bgcolor='gray' align=center>RoboticaXYZ / Jamther</td>");
            client.println("</tr>");
            client.println("</table>");
            client.println("</form>");

            // Sección Energía y Panel Solar
            client.println("<h1>Agua y Humedad</h1><table border='16' width='80%'>");
            client.println("<tr>");
            client.println("<td bgcolor='cyan' align=center><p>");
            client.println("<p><br>--Bomba de Nutrientes--<br><p>");
            client.println("<p><br>--Luz UV--<br><p>");
            client.println("<p><br>--Luz Infrarroja--<br><p>");
            client.println("<p><br>--Luz Incandescente--<br><p>");
            client.print("<p><button type='button' onClick=location.href='/LUZ=ON'> ON </button>");
            client.print("<button type='button' onClick=location.href='/LUZ=OFF'> OFF </button>");
            client.println("</td></tr></table>");
            client.println("</td>");
            client.println("</tr>");
            client.println("</table>");
            client.println("</html>");

            delay(1);
            Serial.println("Fin HTML - Esperando Nueva Peticion Cliente");

            // Final de la respuesta HTTP
            client.println();
            break; // Salir del while de cliente
          } else { 
            currentLine = ""; // limpiar currentLine si hubo newline
          }
        } else if (c != '\r') {  
          currentLine += c; // agregar caracteres a currentLine
        }
      }
    }

    // Limpiar cabecera y cerrar conexión
    header = "";
    client.stop();
    Serial.println("Cliente desconectado.");
    Serial.println("");
  }
} // fin loop()
