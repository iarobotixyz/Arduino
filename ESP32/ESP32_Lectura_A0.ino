// Conectado a GPIO 35 o D35
const int portPin = 35; 
// (Rango de 0-4095) 

int potValor = 0; void setup() 
    { 
    Serial.begin(115200); 
    delay(500); 
    } 
void loop() { // Lectura del valor en cada vuelta del bucle 
potValor = analogRead(portPin); Serial.println(potValor); //Envío del valor al puerto serie 
 delay(500); }