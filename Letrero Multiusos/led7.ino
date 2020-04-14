///////IAROBOTIXYZ/////////
/////YOUTUBE///////////////
/////BLOG//////////////////
//////GITHUB//////////////

//NOTA POSIBLE QUEMA DE INTEGRADOS AL MOVER EL CODIGO
void setup() 
{
  pinMode(13, OUTPUT);//P 13
  pinMode(12, OUTPUT);//A 12
  pinMode(11, OUTPUT);//B 11
  pinMode(10, OUTPUT);//c 10
  pinMode(9, OUTPUT);//d 9
  pinMode(8, OUTPUT);//e 8
  pinMode(7, OUTPUT);//eje 7
  pinMode(6, OUTPUT);//G 6
  /////////////////////////////////
  //NOTA:////PIN 2 NO SIRVE DE SALIDA EN ESTE CIRCUITO
  pinMode(0, OUTPUT);//D1
  pinMode(1, OUTPUT);//D2 
  pinMode(A0, OUTPUT);//D3
  pinMode(3, OUTPUT);//D4 
  pinMode(4, OUTPUT);//D5 
  pinMode(5, OUTPUT);//D6 
}

void loop() 
{
  digitalWrite(13, HIGH);
  digitalWrite(A0, HIGH); 
  delay(1000);
  digitalWrite(13, LOW); 
  digitalWrite(A0, LOW);
  delay(1000);   
}
