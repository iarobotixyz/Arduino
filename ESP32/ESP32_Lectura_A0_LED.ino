// Conectado a GPIO 35 o D35
const int portPin = 35; 
// (Rango de 0-4095) 

int potValor = 0; 
void setup() 
    { 
    pinMode(2, OUTPUT);
    Serial.begin(115200); 
    delay(500); 
    
    } 
void loop() { // Lectura del valor en cada vuelta del bucle 
potValor = analogRead(portPin); Serial.println(potValor); //Envío del valor al puerto serie 
if (potValor<=750 and potValor>=600)
    {
    digitalWrite(2, LOW);
    delay(400);             
    digitalWrite(2, HIGH);
    delay(400);              // pausa 1seg
    }
 delay(500);
   
     }