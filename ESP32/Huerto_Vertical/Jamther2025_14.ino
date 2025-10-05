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
String txyz = "";
String fxyz = "";
String hxyz = "";

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
    txyz=tempDeg;
    fxyz=tempFar;
    hxyz=hum;
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

// Comienzo del HTML

client.println("<!DOCTYPE HTML>");
client.println("<html lang='es'>");
client.println("<head>");
client.println("<meta charset='UTF-8'>");
client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
client.println("<title>Cultivo Vertical Automatizado</title>");
client.println("<meta http-equiv='refresh' content='5'>"); // Auto-refresh cada 5 segundos
client.println("<style>");
client.println("body { font-family: 'Arial', sans-serif; background-color: #f0f8f5; text-align: center; }");
client.println("h1,h2 { color: #2e7d32; margin: 5px; }");
client.println("table { margin: 15px auto; border-collapse: separate; border-spacing: 10px; border-radius: 12px; overflow: hidden; }");
client.println("td { padding: 12px; text-align: center; border: 1px solid #999; vertical-align: top; }");
client.println("input[type=date] { padding: 5px; font-size: 14px; border-radius: 5px; border: 1px solid #888; }");
client.println("button { padding: 10px 16px; font-size: 14px; margin: 2px; border-radius: 6px; cursor: pointer; border: none; font-weight: bold; }");
client.println(".button-on { background-color: #4caf50; color: white; }");
client.println(".button-off { background-color: #f44336; color: white; }");
client.println(".sensor-value { font-size: 18px; font-weight: bold; }");
client.println(".colA { background-color: #a5d6a7; color: #fff; border-radius: 10px; }");
client.println(".colB { background-color: #388e3c; color: #fff; border-radius: 10px; }");
client.println(".colC { background-color: #a5d6a7; color: #fff; border-radius: 10px; }");
client.println(".water { background: linear-gradient(135deg, #64b5f6, #2196f3); color: #fff; border-radius: 10px; }");
client.println(".energy { background: linear-gradient(135deg, #ffeb3b, #ffc107); color: #000; }");
client.println(".dht11 { background: #ffd54f; color: #000; font-weight: bold; border-radius: 10px; padding: 10px; }");
client.println("</style>");
client.println("</head>");
client.println("<body>");

client.println("<h1>🌿 Cultivo Vertical Automatizado 🌿</h1>");
client.println("<h2>" + String(ssid) + "</h2>");

// Formulario principal
client.println("<form action='/Save=ON' method='get'>");

// Tabla principal
client.println("<table width='95%'>");

// Luz (GPIO2) + Panel de Energía con DHT11
client.println("<tr class='energy'>");
client.println("<td colspan='3' style='background: linear-gradient(135deg, #ffe082, #ffca28); padding:15px; border-radius:12px;'>");

// Luz
client.println("<h2>💡 Luz</h2>");
client.println("Estado: <b>" + output2State + "</b><br>");
if (output2State=="off") {
    client.println("<a href='/2/on'><button class='button-on' type='button'>ENCENDER</button></a>");
} else {
    client.println("<a href='/2/off'><button class='button-off' type='button'>APAGAR</button></a>");
}

// Panel de Energía
client.println("<h2>⚡ Energía</h2>");
client.println("Panel Solar ☀️ &nbsp; Generador Eólico 🌬️<br>");

// DHT11 destacado
client.println("<div style='background:#ffd54f; color:#000; font-weight:bold; border-radius:10px; padding:10px; margin-top:10px;'>");
client.println("🌡️ DHT11 Valores:<br>");
client.println("Humedad: " + hxyz + " %<br>");
client.println("Temperatura: " + txyz + " °C / " + fxyz + " °F<br>");
client.println("</div>");

client.println("</td>");
client.println("</tr>");

// Bloque DHT11 llamativo en columna A1/B1/C1
client.println("<tr><td></td>");
client.println("<td class='water' align='center'>");
client.println("Botella 0 💧<br>Sensor Agua: <span class='sensor-value'>" + axyz + " %</span>");
client.println("</td>");
client.println("<td></td>");
client.println("</tr>");

// Botellas 1-24 en 3 columnas (A/B/C)
for (int i=0; i<8; i++) {  // 8 filas
    client.println("<tr>");
    
    // Columna A
    int idxA = i+1;
    String claseA = (idxA==1) ? "water" : "colA";
    client.println("<td class='" + claseA + "' align='center'>Botella A" + String(idxA) + "<br>");
    String valA1 = getValue(cadenaGlobal, ',', 2*idxA -1);
    if (valA1 == "") valA1 = "2025-10-17";
    String valA2 = getValue(cadenaGlobal, ',', 2*idxA);
    if (valA2 == "") valA2 = "2025-10-17";
    client.println("<input type='date' name='A" + String(idxA) + "a' value='" + valA1 + "'><br>");
    client.println("<input type='date' name='A" + String(idxA) + "b' value='" + valA2 + "'></td>");
    
    // Columna B
    int idxB = i+1;
    String claseB = (i==0) ? "water" : "colB";
    client.println("<td class='" + claseB + "' align='center'>Botella B" + String(idxB) + "<br>");
    String valB1 = getValue(cadenaGlobal, ',', 2*(i+9) -1);
    if (valB1 == "") valB1 = "2025-10-17";
    String valB2 = getValue(cadenaGlobal, ',', 2*(i+9));
    if (valB2 == "") valB2 = "2025-10-17";
    client.println("<input type='date' name='B" + String(idxB) + "a' value='" + valB1 + "'><br>");
    client.println("<input type='date' name='B" + String(idxB) + "b' value='" + valB2 + "'></td>");
    
    // Columna C
    int idxC = i+1;
    String claseC = (i==0) ? "water" : "colC";
    client.println("<td class='" + claseC + "' align='center'>Botella C" + String(idxC) + "<br>");
    String valC1 = getValue(cadenaGlobal, ',', 2*(i+17) -1);
    if (valC1 == "") valC1 = "2025-10-17";
    String valC2 = getValue(cadenaGlobal, ',', 2*(i+17));
    if (valC2 == "") valC2 = "2025-10-17";
    client.println("<input type='date' name='C" + String(idxC) + "a' value='" + valC1 + "'><br>");
    client.println("<input type='date' name='C" + String(idxC) + "b' value='" + valC2 + "'></td>");
    
    client.println("</tr>");
}

// Botella 25: Bomba de Agua (GPIO26) en columna B
client.println("<tr class='water'>");
client.println("<td></td>");
client.println("<td class='water' align='center'>Botella 25 - Bomba de Agua 💧<br>");
client.println("Estado: " + output26State + "<br>");
if (output26State=="off") {
    client.println("<a href='/26/on'><button class='button-on' type='button'>ENCENDER</button></a>");
} else {
    client.println("<a href='/26/off'><button class='button-off' type='button'>APAGAR</button></a>");
}
client.println("</td>");
client.println("<td></td>");
client.println("</tr>");

// Botón Guardar
client.println("<tr><td colspan='3'><button type='submit'>💾 Guardar Datos</button></td></tr>");

client.println("</table>");
client.println("</form>");
client.println("</body>");
client.println("</html>");



///

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
