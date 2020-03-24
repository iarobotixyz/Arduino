int sensorEntrada = A0;  
int ledPin = 13;      
int sensorValor = 0;  
void setup() 
{
  Serial.begin(115200);
   pinMode(LED_BUILTIN, OUTPUT);
}
void loop() 
{
  sensorValor = analogRead(sensorEntrada);
  digitalWrite(ledPin, HIGH);
  delay(sensorValor);
  digitalWrite(ledPin, LOW);
  delay(sensorValor);
  Serial.print(sensorEntrada);
  Serial.print("\n");
  Serial.print(sensorValor); 
}
