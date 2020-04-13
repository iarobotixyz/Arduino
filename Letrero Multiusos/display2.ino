///////IAROBOTIXYZ/////////
/////YOUTUBE//Robotixyz/////////////
/////BLOG// https://iarobotixyz.blogspot.com ////////////////
//////GITHUB// https://github.com/iarobotixyz/Arduino ////////////

int timer = 500;
int letra = 6;//13-6

void setup() 
{
  pinMode(13, OUTPUT);//P 13
  pinMode(12, OUTPUT);//A 12
  pinMode(11, OUTPUT);//B 11
  pinMode(10, OUTPUT);//c 10
  pinMode(9, OUTPUT);//d 9
  pinMode(8, OUTPUT);//e 8
  pinMode(7, OUTPUT);//eje 7
  pinMode(6, OUTPUT);//G 6 -
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
  digitalWrite(letra, HIGH);
  digitalWrite(0, HIGH); 
  delay(timer);
  digitalWrite(letra, LOW); 
  digitalWrite(0, LOW);
  //delay(timer);
  
  digitalWrite(letra, HIGH);
  digitalWrite(1, HIGH); 
  delay(timer);
  digitalWrite(letra, LOW); 
  digitalWrite(1, LOW);
  //delay(timer); 
 
  digitalWrite(letra, HIGH);
  digitalWrite(A0, HIGH); 
  delay(timer);
  digitalWrite(letra, LOW); 
  digitalWrite(A0, LOW);
  //delay(timer); 

  digitalWrite(letra, HIGH);
  digitalWrite(3, HIGH); 
  delay(timer);
  digitalWrite(letra, LOW); 
  digitalWrite(3, LOW);
  //delay(timer); 

  digitalWrite(letra, HIGH);
  digitalWrite(4, HIGH); 
  delay(timer);
  digitalWrite(letra, LOW); 
  digitalWrite(4, LOW);
  //delay(timer); 

  digitalWrite(letra, HIGH);
  digitalWrite(5, HIGH); 
  delay(timer);
  digitalWrite(letra, LOW); 
  digitalWrite(5, LOW);
  //delay(timer); 
}
