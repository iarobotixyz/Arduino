//**********
/*
 * Filename    : Sensor Efecto Hall
 * Autor      : http://www.Roboticaxyz.com
*/
int val = 0;
int hallPin = 15;  //Hall sensorGPIO15
void setup() {
  Serial.begin(115200);//Set baud rate to 9600
  pinMode(hallPin, INPUT);//pin to input mode
}

void loop() 
{
  val = digitalRead(hallPin);//Read value of hall sensor
  Serial.print(val);//Print val
  delay(200);
  if (val == 0) 
  {
    Serial.println(" Hay algo Magnetico!");
  }
  else 
  {
    Serial.println(" Estado normal!");
  }
    
}
//*************