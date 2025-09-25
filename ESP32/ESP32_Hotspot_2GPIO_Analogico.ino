//ROBOTICAXYZ
#include <WiFi.h>

// Remplazar las credenciales
const char* ssid = "RoboticaXYZ";
const char* password = "0987654321";

// Puerto del Servidor
WiFiServer server(80);

// HTTP
String header;

// Auxiliar variables
String output26State = "off";
String output2State = "off";

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;
///declaramos var sensor analogico
int xyz,sensor_analog;
String axyz = "";
const int sensor_pin = A0; 
////
void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(26, OUTPUT);
  pinMode(2, OUTPUT);
  // Set outputs to LOW
  digitalWrite(26, LOW);
  digitalWrite(2, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Conectando a ");
  Serial.println(ssid);
  //WiFi.begin(ssid, password);//Conectar a una Red
  WiFi.softAP(ssid, password);//Punto Acceso  
  Serial.print("Punto de acceso creado: ");
  Serial.println(ssid);
  Serial.print("Dirección IP del ESP32: ");
  Serial.println(WiFi.softAPIP()); // Obtener la IP del ESP32
  server.begin();
}

void loop(){
sensor_analog = analogRead(sensor_pin);
  xyz = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  axyz=xyz;
  //Serial.print("Lectura = ");
  //Serial.print(xyz); 


  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("Nuevo Cliente.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character

          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Coneccion: cerrada");
            client.println();
            
            // turns the GPIOs on and off
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
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1> ESP32 Punto de Acceso 2 GPIO<p>");
            client.println("<p>Analogico " + axyz + "</p></h1>");
            // Display current state, and ON/OFF buttons for GPIO 26  
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (output26State=="off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 2  
            client.println("<p>GPIO 2 - State " + output2State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (output2State=="off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Cliente desconectado.");
    Serial.println("");
  }
}