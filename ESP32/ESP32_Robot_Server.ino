// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "INFINITUM9h4v";
const char* password = "f9c53b6229";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";
String output22State = "off";
String output18State = "off";
String output19State = "off";



// Assign output variables to GPIO pins
const int output26 = 2;//led
const int output27 = 23;//prueba motor
const int output22 = 22;//motor atras
const int output18 = 18;//motor atras
const int output19 = 19;//motor atras

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  pinMode(output22, OUTPUT);
  pinMode(output18, OUTPUT);
  pinMode(output19, OUTPUT);
  
  
  // Set outputs to LOW
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);
  digitalWrite(output22, LOW);
   digitalWrite(output18, LOW);
    digitalWrite(output19, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
   ////////////////// turns the GPIOs on and off
            if (header.indexOf("GET /26/on") >= 0) 
            {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, HIGH);
            } 
            else if (header.indexOf("GET /26/off") >= 0) 
            {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output26, LOW);
            } 
//////////////////////
            
            else if (header.indexOf("GET /27/on") >= 0) 
            {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, HIGH);
            }
            else if (header.indexOf("GET /27/off") >= 0) 
            {
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output27, LOW);
            }
//////////////////
            else if (header.indexOf("GET /22/on") >= 0) 
            {
              Serial.println("GPIO 22 on");
              output22State = "on";
              digitalWrite(output22, HIGH);
            } else if (header.indexOf("GET /22/off") >= 0) 
            {
              Serial.println("GPIO 22 off");
              output22State = "off";
              digitalWrite(output22, LOW);
            }

   //////////////////
            else if (header.indexOf("GET /18/on") >= 0) 
            {
              Serial.println("GPIO 18 on");
              output18State = "on";
              digitalWrite(output18, HIGH);
            } else if (header.indexOf("GET /18/off") >= 0) 
            {
              Serial.println("GPIO 18 off");
              output18State = "off";
              digitalWrite(output18, LOW);
            }

   //////////////////
            else if (header.indexOf("GET /19/on") >= 0) 
            {
              Serial.println("GPIO 19 on");
              output19State = "on";
              digitalWrite(output19, HIGH);
            } else if (header.indexOf("GET /19/off") >= 0) 
            {
              Serial.println("GPIO 19 off");
              output19State = "off";
              digitalWrite(output19, LOW);
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
            client.println("<body><h1>ESP32 Robot Web Server</h1>");
            client.println("<h2>RoboticaXYZ.com</h2>");
            


            client.println(" <center>");
            
            client.println("<table border=7> <TR><TD COLSPAN=3><center>Frente</TD></TR>");
            client.println(" <tr><td>1");

            // Motor izquierdo Avanza
            client.println("<p>Motor Izquierdo Avanza " + output18State + "</p>"); 
            if (output18State=="off") {
              client.println("<p><a href=\"/18/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/18/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
            client.println("</td><td>2</td><td>3");

            // Motor Derecha Avanza
            client.println("<p>Motor Derecho Avanza " + output27State + "</p>");
            // If the output27State is off, it displays the ON button       
            if (output27State=="off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
            client.println("</td></tr>");
            client.println(" <tr><td>4</td><td>5");
                        
                        // LED azul
            client.println("<p>GPIO 26 - LED " + output26State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (output26State=="off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            
            client.println("</td><td>6</td></tr>");
            client.println(" <tr><td>7");



            // Motor derecho Atras
            client.println("<p>Motor Izquierdo Atras " + output19State + "</p>"); 
            if (output19State=="off") {
              client.println("<p><a href=\"/19/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/19/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            

            
            client.println("</td><td>8</td><td>9");
            
            

            // Motor Derecha Atras
            client.println("<p>Motor Derecho Atras " + output22State + "</p>");
            // If the output22State is off, it displays the ON button       
            if (output22State=="off") {
              client.println("<p><a href=\"/22/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/22/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
            client.println("</td></tr>");
            client.println(" </table>                ");
            




            
            
            client.println(" </body></html>                ");
            
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
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
