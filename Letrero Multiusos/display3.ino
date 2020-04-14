///////IAROBOTIXYZ/////////
/////YOUTUBE///////////////
/////BLOG//////////////////
//////GITHUB//////////////
//subproceso
int timer = 1;
int letra = 6;//13-6
int cont=0;
void setup() 
{
  pinMode(13, OUTPUT);//P 13
  pinMode(12, OUTPUT);//A 12
  pinMode(11, OUTPUT);//B 11
  pinMode(10, OUTPUT);//c 10
  pinMode(9, OUTPUT);//d 9
  pinMode(8, OUTPUT);//e 8
  pinMode(7, OUTPUT);//F 7
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

renata();
}


void escribir(int n)
{ //funcion para escribir el numero en el display
   switch(n)
   {
        case 4: //
          r();
         break;
    case 5: //
          e();
         break;
    }
   
   }

void renata()
{
  int del=500;
 if (cont <= del) 
 {
    r();
    e();
    n();
    cont=cont+1;  
  } 
  else 
    {
      
      r();
      e();
      n();
      a1();
      t(); 
      a2();
      //delay(del);
      cont=0;
    }

 }

void e()
{
   //Letra E
  digitalWrite(12, HIGH);//A
  digitalWrite(9, HIGH);//D
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(4, HIGH);
  delay(timer);
  
    digitalWrite(12, LOW);//A
  digitalWrite(9, LOW);//D
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(4, LOW);
  delay(timer);
  }
void r()
{
    //Letra r
  digitalWrite(8, HIGH);//E
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(5, HIGH);
  delay(timer);
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(5, LOW);
  delay(timer);
  }
void t()
{
    //Letra t
  digitalWrite(7, HIGH);//F
  digitalWrite(8, HIGH);//E
  digitalWrite(9, HIGH);//D
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(1, HIGH);
  delay(timer);
  ///
    digitalWrite(7, LOW);//F
  digitalWrite(8, LOW);//E
  digitalWrite(9, LOW);//D
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(1, LOW);
  delay(timer);

  }
void n()
{
    //Letra n
  digitalWrite(10, HIGH);//
  digitalWrite(8, HIGH);//E
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(3, HIGH);
 
  delay(timer);
      //Letra n
  digitalWrite(10, LOW);//
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(3, LOW);
 
  delay(timer);
  }
void a1()
{
    //Letra A1
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  //digitalWrite(0, HIGH);
  digitalWrite(A0, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  //digitalWrite(0, LOW);
  digitalWrite(A0, LOW);
  delay(timer);
  }
 void a2()
{
    //Letra A1
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(0, HIGH);
  //digitalWrite(A0, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(0, LOW);
  //digitalWrite(A0, LOW);
  delay(timer);
  }

void linea() {
    //Letra A1
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(0, HIGH);
  //digitalWrite(A0, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(0, LOW);
  //digitalWrite(A0, LOW);
  delay(timer);
  
}
