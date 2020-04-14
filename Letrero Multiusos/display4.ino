///////IAROBOTIXYZ/////////
/////YOUTUBE///////////////
/////BLOG//////////////////
//////GITHUB//////////////

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
  //for(int i=0;i<100;i++)
  //{ //realizamos el conteo de 0 a 9 para el display
        //delay(0);
   //      escribir(i); //mandamos escribir el numero correspondiente   
   //}
   guapaguao();
}


void escribir(int var)
{ //funcion para escribir el numero en el display
   switch(var)
   {
        case 0:
          n(4);
          a(3);
         break;
        case 50: //
          a(3);
          n(4);
          a(5);
         break;
        case 99: //
          delay(5);
          r(5);
          e(4);
          n(3);
          a(2);
          t(1);
          a(0);
          
         break;
    }
   
   }

void guapaguao()
{
  int del=400;
  cont=cont+1;
    
 if (cont <= del) 
 {
      //h(4);
      //o(3);
      //l(2);
      //a(1);
      
      dos(4);
      cero(3);
      dos(2);
      cero(1);
      
          
    cont=cont+1;  
  } 
 if (cont > del  && cont <= (del*2))
    {
          //m(4);
          //u(3);
          //n(2);
          //d(1);
          //o(0);


          r(5);
          o(4);
          b(3);
          o(2);
          t(1);
          i(0);

          
    }
 if (cont > (del*2)  && cont <= (del*3))
    {
          //r(5);
          //e(4);
          //n(3);
          //a(2);
          //t(1);
          //a(0);
          x(3);
          y(2);
          z(1);
          
      if (cont == (del*3))
      {
        cont=0;
       }
      
    }


    

 }


   void cero(int ceroo)
{
if (ceroo==2)
{
  ceroo=A0;
}
    //Letra 0
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(9, HIGH);//d
  ///PIN ACTIVA
  digitalWrite(ceroo, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(9, LOW);//d 
  ///PIN ACTIVA
  digitalWrite(ceroo, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }


void dos(int doss)
{
  if (doss==2)
{
  doss=A0;
}
   //Letra E
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//
  digitalWrite(9, HIGH);//D
  digitalWrite(8, HIGH);//E
  //digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(doss, HIGH);
  delay(timer);
  
    digitalWrite(12, LOW);//A
    digitalWrite(11, LOW);//
  digitalWrite(9, LOW);//D
  digitalWrite(8, LOW);//E
  //digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(doss, LOW);
  //delay(timer);
  }


   void a(int vari)
{
if (vari==2)
{
  vari=A0;
}
    //Letra A
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vari, HIGH);
  delay(timer);
      //Letra A
  digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vari, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

void b(int vbb)
{
  if (vbb==2)
{
  vbb=A0;
}
    //Letra b
  digitalWrite(7, HIGH);//F
  digitalWrite(8, HIGH);//E
  digitalWrite(9, HIGH);//D
  digitalWrite(6, HIGH);//G 
  digitalWrite(10, HIGH);// 
  ///PIN ACTIVA
  digitalWrite(vbb, HIGH);
  delay(timer);
  ///
    digitalWrite(7, LOW);//F
  digitalWrite(8, LOW);//E
  digitalWrite(9, LOW);//D
  digitalWrite(6, LOW);//G
  digitalWrite(10, LOW);// 
  ///PIN ACTIVA
  digitalWrite(vbb, LOW);
  //delay(timer);

  }
void d(int vdd)
{
  if (vdd==2)
{
  vdd=A0;
}
    //Letra d
  digitalWrite(11, HIGH);//
  digitalWrite(10, HIGH);//
  digitalWrite(9, HIGH);//d
  digitalWrite(8, HIGH);//E
  
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vdd, HIGH);
 
  delay(timer);
      //Letra d
  digitalWrite(11, LOW);//
  digitalWrite(10, LOW);//
  digitalWrite(9, LOW);//d
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vdd, LOW);
 
  //delay(timer);
  }




  
void e(int vae)
{
  if (vae==2)
{
  vae=A0;
}
   //Letra E
  digitalWrite(12, HIGH);//A
  digitalWrite(9, HIGH);//D
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vae, HIGH);
  delay(timer);
  
    digitalWrite(12, LOW);//A
  digitalWrite(9, LOW);//D
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vae, LOW);
  //delay(timer);
  }



   void h(int vhri)
{
if (vhri==2)
{
  vhri=A0;
}
    //Letra h
  //digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vhri, HIGH);
  delay(timer);
      //Letra h
  //digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vhri, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }

 void i(int vii)
{
if (vii==2)
{
  vii=A0;
}
    //Letra h
  //digitalWrite(12, HIGH);//A
  //digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  //digitalWrite(7, HIGH);//F
  //digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vii, HIGH);
  delay(timer);
      //Letra h
  //digitalWrite(12, LOW);//A
 // digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  //digitalWrite(7, LOW);//F
  //digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vii, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }



  
void r(int varr)
{
  if (varr==2)
{
  varr=A0;
}
    //Letra r
  digitalWrite(8, HIGH);//E
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(varr, HIGH);
  delay(timer);
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(varr, LOW);
  //delay(timer);
  }
void l(int vall)
{
  if (vall==2)
{
  vall=A0;
}
    //Letra l
  digitalWrite(7, HIGH);//F
  digitalWrite(8, HIGH);//E
  digitalWrite(9, HIGH);//D
  //digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vall, HIGH);
  delay(timer);
  ///
    digitalWrite(7, LOW);//F
  digitalWrite(8, LOW);//E
  digitalWrite(9, LOW);//D
  //digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vall, LOW);
  //delay(timer);

  }

  void t(int vat)
{
  if (vat==2)
{
  vat=A0;
}
    //Letra t
  digitalWrite(7, HIGH);//F
  digitalWrite(8, HIGH);//E
  digitalWrite(9, HIGH);//D
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vat, HIGH);
  delay(timer);
  ///
    digitalWrite(7, LOW);//F
  digitalWrite(8, LOW);//E
  digitalWrite(9, LOW);//D
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vat, LOW);
  //delay(timer);

  }
void m(int vamm)
{
  if (vamm==2)
{
  vamm=A0;
}
    //Letra n
  digitalWrite(12, HIGH);//
  digitalWrite(10, HIGH);//
  
  //digitalWrite(7, HIGH);//
  digitalWrite(8, HIGH);//E
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vamm, HIGH);
 
  delay(timer);
      //Letra n
  digitalWrite(12, LOW);//
  digitalWrite(10, LOW);//
  //digitalWrite(7, LOW);//
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vamm, LOW);
 
  //delay(timer);
  }


  
void n(int vann)
{
  if (vann==2)
{
  vann=A0;
}
    //Letra n
  digitalWrite(10, HIGH);//
  digitalWrite(8, HIGH);//E
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vann, HIGH);
 
  delay(timer);
      //Letra n
  digitalWrite(10, LOW);//
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vann, LOW);
 
  //delay(timer);
  }
void o(int vao)
{
  if (vao==2)
{
  vao=A0;
}
    //Letra n
  digitalWrite(10, HIGH);//
  digitalWrite(9, HIGH);//d
  digitalWrite(8, HIGH);//E
  
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vao, HIGH);
 
  delay(timer);
      //Letra o
  digitalWrite(10, LOW);//
  digitalWrite(9, LOW);//d
  digitalWrite(8, LOW);//E
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vao, LOW);
 
  //delay(timer);
  }

  void u(int vu)
{
  if (vu==2)
{
  vu=A0;
}
    //Letra u
  digitalWrite(10, HIGH);//
  digitalWrite(9, HIGH);//d
  digitalWrite(8, HIGH);//E
  
  //digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(vu, HIGH);
 
  delay(timer);
      //Letra u
  digitalWrite(10, LOW);//
  digitalWrite(9, LOW);//d
  digitalWrite(8, LOW);//E
  //digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(vu, LOW);
 
  //delay(timer);
  }



     void x(int xxx)
{
if (xxx==2)
{
  xxx=A0;
}
    //Letra 0
  //digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//
  ///PIN ACTIVA
  digitalWrite(xxx, HIGH);
  delay(timer);
      //Letra A
  //digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);// 
  ///PIN ACTIVA
  digitalWrite(xxx, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }


void y(int yy)
{
if (yy==2)
{
  yy=A0;
}
    //Letra 0
  //digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//B
  digitalWrite(10, HIGH);//C
  //digitalWrite(8, HIGH);//E
  digitalWrite(7, HIGH);//F
  digitalWrite(9, HIGH);//d
  digitalWrite(6, HIGH);//G
  ///PIN ACTIVA
  digitalWrite(yy, HIGH);
  delay(timer);
      //Letra A
  //digitalWrite(12, LOW);//A
  digitalWrite(11, LOW);//B
  digitalWrite(10, LOW);//C
  //digitalWrite(8, LOW);//E
  digitalWrite(7, LOW);//F
  digitalWrite(9, LOW);//d 
  digitalWrite(6, LOW);//G
  ///PIN ACTIVA
  digitalWrite(yy, LOW);
  //digitalWrite(1, LOW);
  //delay(timer);
  
  }


  void z(int zz)
{
if (zz==2)
{
  zz=A0;
}
   //Letra E
  digitalWrite(12, HIGH);//A
  digitalWrite(11, HIGH);//
  digitalWrite(9, HIGH);//D
  digitalWrite(8, HIGH);//E
  //digitalWrite(7, HIGH);//F
  digitalWrite(6, HIGH);//G 
  ///PIN ACTIVA
  digitalWrite(zz, HIGH);
  delay(timer);
  
    digitalWrite(12, LOW);//A
    digitalWrite(11, LOW);//
  digitalWrite(9, LOW);//D
  digitalWrite(8, LOW);//E
  //digitalWrite(7, LOW);//F
  digitalWrite(6, LOW);//G 
  ///PIN ACTIVA
  digitalWrite(zz, LOW);
  //delay(timer);
  
  }
