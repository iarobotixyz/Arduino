/*
  Blink_GPIO_ESP8266_7_Segmentos
*/
void setup(){
pinMode(16, OUTPUT);//D0//AZUL 1
pinMode(15, OUTPUT);//D8//PUNTO
pinMode(14, OUTPUT);//D5//D
pinMode(13, OUTPUT);//D7//F
pinMode(12, OUTPUT);//D6//E
pinMode(10, OUTPUT);//SD3//G
pinMode(5, OUTPUT);//D1//A
pinMode(4, OUTPUT);//D2//B
pinMode(3, OUTPUT);//RX//
pinMode(2, OUTPUT);//D4//AZUL 2
pinMode(1, OUTPUT);//TX// 
pinMode(0, OUTPUT);//D3//C
    }
void cinco()
{
  digitalWrite(5, HIGH); //A
  digitalWrite(4, LOW); //B 
  digitalWrite(0, HIGH); //C 
  digitalWrite(14, HIGH);//D  
  digitalWrite(12, LOW);//E  
  digitalWrite(13, HIGH);//F  
  digitalWrite(10, HIGH);//G    
}
void cuatro()
{
  digitalWrite(5, LOW); //A
  digitalWrite(4, HIGH); //B 
  digitalWrite(0, HIGH); //C 
  digitalWrite(14, LOW);//D  
  digitalWrite(12, LOW);//E  
  digitalWrite(13, HIGH);//F  
  digitalWrite(10, HIGH);//G  
}
void tres()
{
  digitalWrite(5, HIGH); //A
  digitalWrite(4, HIGH); //B 
  digitalWrite(0, HIGH); //C 
  digitalWrite(14, HIGH);//D  
  digitalWrite(12, LOW);//E  
  digitalWrite(13, LOW);//F  
  digitalWrite(10, HIGH);//G  
}
void dos()
{
  digitalWrite(5, HIGH); //A
  digitalWrite(4, HIGH); //B 
  digitalWrite(0, LOW); //C 
  digitalWrite(14, HIGH);//D  
  digitalWrite(12, HIGH);//E  
  digitalWrite(13, LOW);//F  
  digitalWrite(10, HIGH);//G  
}
void uno()
{
  digitalWrite(5, LOW); //A
  digitalWrite(4, HIGH); //B 
  digitalWrite(0, HIGH); //C 
  digitalWrite(14, LOW);//D  
  digitalWrite(12, LOW);//E  
  digitalWrite(13, LOW);//F  
  digitalWrite(10, LOW);//G  
}
void cero()
{
  digitalWrite(5, LOW); //A
  digitalWrite(4, LOW); //B 
  digitalWrite(0, LOW); //C 
  digitalWrite(14, LOW);//D  
  digitalWrite(12, LOW);//E  
  digitalWrite(13, LOW);//F  
  digitalWrite(10, LOW);//G   
}
void loop() {
  cinco();
  delay(1000);
  cuatro();
  delay(1000); 
  tres();
  delay(1000); 
  dos();
  delay(1000); 
  uno();
  delay(1000);           
  cero();
  delay(1000); 
  digitalWrite(16, HIGH); //AZUL
  delay(500);
  digitalWrite(16, LOW); //AZUL 
  delay(500);
  digitalWrite(2, HIGH); //AZUL
  delay(500); 
  digitalWrite(2, LOW); //AZUL 
  delay(500);
}
