/*
  Blink_GPIO_ESP8266_RoboticaXYZ
*/
void setup() 
{
  pinMode(16, OUTPUT);//D0
  pinMode(15, OUTPUT);//D8
  pinMode(14, OUTPUT);//D5
  pinMode(13, OUTPUT);//D7
  pinMode(12, OUTPUT);//D6
  pinMode(10, OUTPUT);//SD3
  pinMode(9, INPUT);//SD2
  pinMode(5, OUTPUT);//D1
  pinMode(4, OUTPUT);//D2
  pinMode(3, OUTPUT);//RX
  pinMode(2, OUTPUT);//D4
  pinMode(1, OUTPUT);//TX
  pinMode(0, OUTPUT);//D3
}
void loop() 
{
  digitalWrite(16, HIGH);   
  delay(1000);                       
  digitalWrite(16, LOW);   
  delay(1000);
  digitalWrite(15, HIGH);   
  delay(1000);                       
  digitalWrite(15, LOW);   
  delay(1000);
  digitalWrite(14, HIGH);   
  delay(1000);                       
  digitalWrite(14, LOW);   
  delay(1000);
  digitalWrite(13, HIGH);   
  delay(1000);                       
  digitalWrite(13, LOW);   
  delay(1000);
  digitalWrite(12, HIGH);   
  delay(1000);                       
  digitalWrite(12, LOW);   
  delay(1000);
  digitalWrite(10, HIGH);   
  delay(1000);                       
  digitalWrite(10, LOW);   
  delay(1000);
  digitalWrite(5, HIGH);   
  delay(1000);                       
  digitalWrite(5, LOW);   
  delay(1000);
  digitalWrite(4, HIGH);   
  delay(1000);                       
  digitalWrite(4, LOW);   
  delay(1000);
  digitalWrite(3, HIGH);   
  delay(1000);                       
  digitalWrite(3, LOW);   
  delay(1000);
  digitalWrite(2, HIGH);   
  delay(1000);                       
  digitalWrite(2, LOW);   
  delay(1000);
  digitalWrite(1, HIGH);   
  delay(1000);                       
  digitalWrite(1, LOW);   
  delay(1000);
  digitalWrite(0, HIGH);   
  delay(1000);                       
  digitalWrite(0, LOW);   
  delay(1000); 
}
