/*Blink_GPIO_ESP8266_DISPLAY3Y4*/
void setup() {
  pinMode(16, OUTPUT);//D0//ṔRIMER ROJO == AZUL 1
  pinMode(15, OUTPUT);//D8//BLANCO CS TXD2  //PUNTO
  pinMode(14, OUTPUT);//D5//PRIMERO AMARILLO//D
  pinMode(13, OUTPUT);//D7//ULTIMO AMARILLO //F
  pinMode(12, OUTPUT);//D6//SEGUNDO AMARILLO//E
  pinMode(10, OUTPUT);//SD3//VERDE SDD3    //G
  pinMode(9, INPUT);//SD2//SDD2 SOLO INPUT //
  pinMode(5, OUTPUT);//D1//SEGUNDO ROJO    //A
  pinMode(4, OUTPUT);//D2//TERCER ROJO    // B
  pinMode(3, OUTPUT);//RX//BLANCO RX      //
  pinMode(2, OUTPUT);//D4//AMARILLO == AZUL 2
  pinMode(1, OUTPUT);//TX//BLANCO TX     //
  pinMode(0, OUTPUT);//D3//CUARTO ROJO   // C
}
  void once()
{
  digitalWrite(1, HIGH); //TX
  digitalWrite(3, HIGH); //RX
  digitalWrite(2, HIGH); //AZUL
  digitalWrite(16, HIGH); //AZUL
  digitalWrite(4, HIGH); //b
  digitalWrite(0, HIGH); //c
  }
void loop() {
  once();
  delay(1000); 
  digitalWrite(1, LOW); //TX
  delay(500);
  digitalWrite(3, LOW); //RX
  delay(500);
  digitalWrite(2, LOW); //AZUL
  delay(500);
  digitalWrite(16, LOW); //AZUL
  delay(500);
}
