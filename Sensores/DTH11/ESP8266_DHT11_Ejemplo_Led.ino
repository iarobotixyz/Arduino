#include "DHT.h"
//Ejemplo_Sin_LED
//https://iarobotixyz.blogspot.com/2022/01/esp8266-con-sensor-de-temperatura-y.html 
// CONSTRUCTOR DEL OBJETO DHT RECIBE EL PIN EN EL QUE SE CONECTA EL SENSOR
// Y TAMBIEN RECIBE EL TIPO DE SENSOR QUE VAMOS A CONECTAR
DHT dht(0, DHT11);
 
void setup() {
  // PREPARAR LA COMUNICACION SERIAL
  Serial.begin(9600);
  Serial.println("Prueba del sensor DHT11");
  //LED PIN GPIO2 //PIN D4 de ESP8266 EN MODO SALIDA
  pinMode(2, OUTPUT);
  // PREPARAR LA LIBRERIA PARA COMUNICARSE CON EL SENSOR
  dht.begin();
}
 
void loop() {
  // ESPERAR ENTRE MEDICIONES, NECESARIO PARA EL BUEN FUNCIONAMIENTO
  //delay(2000); EN LUGAR DE LOS 2 SEGUNDOS LO DIVIDIMOS EN UN SEGUNDO ENCENDIDO Y UN SEGUNDO APAGADO
  
  digitalWrite(2, HIGH);   // LED ON
  delay(1000);              // PAUSA 1 SEG
  digitalWrite(2, LOW);    // LED OFF
  delay(1000);              // PAUSA 1 SEG
  
  // LEER LA HUMEDAD USANDO EL METRODO READHUMIDITY
  float h = dht.readHumidity();
  // LEER LA TEMPERATURA USANDO EL METRODO READTEMPERATURE
  float t = dht.readTemperature();
 
  // REVISAR QUE LOS RESULTADOS SEAN VALORES NUMERICOS VALIDOS, INDICANDO QUE LA COMUNICACION ES CORRECTA
  if (isnan(h) || isnan(t)) {
    Serial.println("Falla al leer el sensor DHT11!");
    return;
  }
 
  // IMPRIMIR RESULTADO AL MONITOR SERIAL
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");
}
