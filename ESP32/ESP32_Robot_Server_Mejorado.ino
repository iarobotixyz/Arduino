// Load Wi-Fi library
#include <WiFi.h>

//sensorimu
#include <MPU9250_WE.h>
#include <Wire.h>
#define MPU9250_ADDR 0x68

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



// Asigna GPIO pins
const int output26 = 2;//led
const int output27 = 16;//prueba motor
const int output22 = 17;//motor atras
const int output18 = 18;//motor atras
const int output19 = 19;//motor atras

unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;
MPU9250_WE myMPU9250 = MPU9250_WE(MPU9250_ADDR);

void setup() {
  Serial.begin(115200);
   Wire.begin();
     if(!myMPU9250.init()){
    Serial.println("MPU9250 does not respond");
  }
  else{
    Serial.println("MPU9250 is connected");
  }
  if(!myMPU9250.initMagnetometer()){
    Serial.println("Magnetometer does not respond");
  }
  else{
    Serial.println("Magnetometer is connected");
  }

  myMPU9250.setMagOpMode(AK8963_CONT_MODE_100HZ);
   Serial.println("Position you MPU9250 flat and don't move it - calibrating...");
  delay(1000);
  myMPU9250.autoOffsets();
  Serial.println("Done!");
  
  myMPU9250.setAccRange(MPU9250_ACC_RANGE_2G);

  /*  Enable/disable the digital low pass filter for the accelerometer 
   *  If disabled the bandwidth is 1.13 kHz, delay is 0.75 ms, output rate is 4 kHz
   */
  myMPU9250.enableAccDLPF(true);

 /*  Digital low pass filter (DLPF) for the accelerometer (if DLPF enabled) 
   *  MPU9250_DPLF_0, MPU9250_DPLF_2, ...... MPU9250_DPLF_7 
   *   DLPF     Bandwidth [Hz]      Delay [ms]    Output rate [kHz]
   *     0           460               1.94           1
   *     1           184               5.80           1
   *     2            92               7.80           1
   *     3            41              11.80           1
   *     4            20              19.80           1
   *     5            10              35.70           1
   *     6             5              66.96           1
   *     7           460               1.94           1
   */
  myMPU9250.setAccDLPF(MPU9250_DLPF_6); 

  
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

  xyzFloat gValue = myMPU9250.getGValues();
  xyzFloat angle = myMPU9250.getAngles();
  xyzFloat magValue = myMPU9250.getMagValues(); // returns magnetic flux density [µT] 
  float temp = myMPU9250.getTemperature();
  float resultantG = myMPU9250.getResultantG(gValue);



  
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
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

   //////////////////derecha
             if (header.indexOf("GET /derecha/on") >= 0) 
            {
              Serial.println("GPIO 18 on");
              output18State = "on";
              output22State = "on";
              
              digitalWrite(output18, HIGH);
              digitalWrite(output22, HIGH);
              ///izquierda off
              output19State = "off";
              output27State = "off";
               digitalWrite(output19, LOW);
              digitalWrite(output27, LOW);
            } else if (header.indexOf("GET /derecha/off") >= 0) 
            {
              Serial.println("GPIO 18 off");
              output18State = "off";
              output22State = "off";
              digitalWrite(output18, LOW);
              digitalWrite(output22, LOW);
              ///izquierda off
               output19State = "off";
               output27State = "off";
               digitalWrite(output19, LOW);
              digitalWrite(output27, LOW);
            }




   //////////////////izquierda
             if (header.indexOf("GET /izquierda/on") >= 0) 
            {
              Serial.println("GPIO 19 on");
              output19State = "on";
              output27State = "on";
              output18State = "off";
              output22State = "off";
              
              digitalWrite(output19, HIGH);
              digitalWrite(output27, HIGH);
              digitalWrite(output18, LOW);
              digitalWrite(output22, LOW);
            } else if (header.indexOf("GET /izquierda/off") >= 0) 
            {
              Serial.println("GPIO 19 off");
              output19State = "off";
              output27State = "off";
              output18State = "off";
              output22State = "off";
              
              digitalWrite(output19, LOW);
              digitalWrite(output27, LOW);

              digitalWrite(output18, LOW);
              digitalWrite(output22, LOW);
            }




   //////////////////adelante
             if (header.indexOf("GET /adelante/on") >= 0) 
            {
              Serial.println("GPIO 18 on");
              output18State = "on";
              output27State = "on";
              output19State = "off";
              output22State = "off";
              
              digitalWrite(output18, HIGH);
              digitalWrite(output27, HIGH);
              digitalWrite(output19, LOW);
              digitalWrite(output22, LOW);
            } else if (header.indexOf("GET /adelante/off") >= 0) 
            {
              Serial.println("GPIO 18 off");
              output18State = "off";
              output27State = "off";
              output19State = "off";
              output22State = "off";
              
              digitalWrite(output18, LOW);
              digitalWrite(output27, LOW);
              digitalWrite(output19, LOW);
              digitalWrite(output22, LOW);
            }

   //////////////////retrocede
             if (header.indexOf("GET /retrocede/on") >= 0) 
            {
              Serial.println("GPIO 19 on");
              output19State = "on";
              output22State = "on";
              output18State = "off";
              output27State = "off";
              
              digitalWrite(output19, HIGH);
              digitalWrite(output22, HIGH);
              digitalWrite(output18, LOW);
              digitalWrite(output27, LOW);
            } else if (header.indexOf("GET /retrocede/off") >= 0) 
            {
              Serial.println("GPIO 19 off");
              output19State = "off";
              output22State = "off";
              output18State = "off";
              output27State = "off";
              
              digitalWrite(output19, LOW);
              digitalWrite(output22, LOW);
              digitalWrite(output18, LOW);
              digitalWrite(output27, LOW);
            }

            
   ////////////////// GET Output
            else if (header.indexOf("GET /26/on") >= 0) 
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
            client.println("<head>");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<meta name=\"tipo_contenido\"  content=\"text/html;\" http-equiv=\"content-type\" charset=\"utf-8\">");
    
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 14px 30px;");
            client.println("text-decoration: none; font-size: 28px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Robot Web Server</h1>");
            client.println("<br>RoboticaXYZ.com<br>Temperatura:");
            
            client.println(temp); 
            client.println("ºC <center>");
            
            client.println("<table border=7> <TR><TD COLSPAN=3><center>Frente del Robot</TD></TR>");
            client.println(" <tr><td>1<center>");

            // Motor izquierdo Avanza
            client.println("<p>Motor Izquierdo Avanza " + output18State + "</p>"); 
            if (output18State=="off") {
              client.println("<p><a href=\"/18/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/18/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
            client.println("</td><td>2<center>");
//2////////////////// AVANZA/////////////
            if (output18State=="on" && output27State=="on" ) {
                client.println("<p>Adelante Encendido<p><a href=\"/adelante/off\"><button class=\"button button2\">DETENER</button></a></p>");
            
              } else {
            client.println("<p>Adelante Apagado<p><a href=\"/adelante/on\"><button class=\"button\">AVANZA</button></a></p>");
            
            }
            

            
            
            
            client.println("</td><td>3<center>");

            // Motor Derecha Avanza
            client.println("<p>Motor Derecho Avanza " + output27State + "</p>");
            // If the output27State is off, it displays the ON button       
            if (output27State=="off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
            client.println("</td></tr>");
            client.println(" <tr><td>4<center>");
            
///izquierda/////////////444/////////7y3

            if (output19State=="on" && output27State=="on" ) {
                client.println("<p>Izquierda Encendido<p><a href=\"/izquierda/off\"><button class=\"button button2\">DETENER</button></a></p>");
            
              } 
            else 
            {
            client.println("<p>Izquierda Apagado<p><a href=\"/izquierda/on\"><button class=\"button\">IZQUIERDA</button></a></p>");
            }
            

            




            
            
            client.println("</td><td>5");
                        
                        // LED azul
            client.println("<center>LED Azul ");
            // If the output26State is off, it displays the ON button       
            if (output26State=="off") {
              client.println("Apagado<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("Encendido<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            
            client.println("</td><td>6<center>");
            
///derecha/////////////666/////////1y9

            if (output18State=="on" && output22State=="on" ) {
                client.println("<p>Derecha Encendido<p><a href=\"/derecha/off\"><button class=\"button button2\">DETENER</button></a></p>");
            
              } 
            else 
            {
            client.println("<p>Derecha Apagado<p><a href=\"/derecha/on\"><button class=\"button\">DERECHA</button></a></p>");
            }
            

            
            client.println("</td></tr>");
  //////7/////////////7
            client.println(" <tr><td>7<center>");



            // Motor derecho Atras
            client.println("<p>Motor Izquierdo Atras " + output19State + "</p>"); 
            if (output19State=="off") {
              client.println("<p><a href=\"/19/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/19/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            

            
            client.println("</td><td>8<center>");
            
            
//8////////////////// RETROCEDE/////////////
            if (output19State=="on" && output22State=="on" ) {
                client.println("<p>Atras Encendido<p><a href=\"/retrocede/off\"><button class=\"button button2\">DETENER</button></a></p>");
            
              } else {
            client.println("<p>Atras Apagado<p><a href=\"/retrocede/on\"><button class=\"button\">ATRAS</button></a></p>");
            
            }
            
            
            
            
            client.println("</td><td>9<center>");
            
            

            // Motor Derecha Atras 
            if (output22State=="off") {
              client.println("<p><a href=\"/22/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/22/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            
            client.println("</td></tr>");

            
            client.println("<TR><TD COLSPAN=3><center>Atras del Robot</TD></TR>");
            
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
