//Publicacion //http://roboticaxyz.com/
//https://iarobotxyz.blogspot.com/2024/06/arduino-uno-y-receiver-ar610-de-spektrum.html
//PuenteH
int ledPin11 = 11;  // LED connected to digital pin 11
int ledPin10 = 10;  // LED connected to digital pin 10
int ledPin9 = 9;  // LED connected to digital pin 9
int ledPin6 = 6;  // LED connected to digital pin 6
/////
int channel[6]; //Channel values Receiver
int PinCinco = 5;
int PinCuatro = 4;
int PinTres = 3;
int PinDos = 2;
void setup()
{
  Serial.begin(9600); //Inicia serial/
  pinMode(PinCinco, INPUT); //Pin-5-input
  pinMode(PinCuatro, INPUT); //Pin-4-input
  pinMode(PinTres, INPUT); //Pin-3-input 
  pinMode(PinDos, INPUT); //Pin-2-input 
}
void loop()
{
  channel[5]=pulseIn(PinCinco, HIGH);
  channel[4]=pulseIn(PinCuatro, HIGH);
  channel[3]=pulseIn(PinTres, HIGH);
  channel[2]=pulseIn(PinDos, HIGH);
  int valor=0;
  analogWrite(ledPin11, 0);
  analogWrite(ledPin10, 0);
  analogWrite(ledPin9, 0);
  analogWrite(ledPin6, 0);

  if(channel[4]==0 && channel[3]==0  && channel[2]==0)
  {
    Serial.print(" RC Apagado ");
  }
  Serial.print("-----\n");
  
  if(channel[4]>800 && channel[4]<1400)
  {
    Serial.print(" RUDD Izquierda \n");//Robot Gira Izquierda
          // sets the value (range from 0 to 255):
          valor = map (channel[4], 700, 1500, 255, 0); //Valor por PWM
          //valor = map (pulso, 60, 120, 255, 0);
          //x = pulso
          //in_min = 60
          //in_max = 120
          //out_min = 255
          //out_max = 0
          Serial.println(valor); // Imprime el valor/ 
          Serial.print("--");//Robot Retrocede
          Serial.println(channel[4]); // Imprime el valor/
          analogWrite(ledPin6, valor);
          analogWrite(ledPin11, valor);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);

          
  }
  if(channel[4]>1600 && channel[4]<2100)
  {
    Serial.print(" RUDD Derecha \n");//Robot Gira Derecha

          // sets the value (range from 0 to 255):
          valor = map (channel[4], 1500, 2200, 0, 255); //Valor por PWM
          //valor = map (pulso, 60, 120, 255, 0);
          //x = pulso
          //in_min = 60
          //in_max = 120
          //out_min = 255
          //out_max = 0
          Serial.println(valor); // Imprime el valor/ 
          Serial.print("--");//Robot Retrocede
          Serial.println(channel[4]); // Imprime el valor/
          analogWrite(ledPin9, valor);
          analogWrite(ledPin10, valor);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);

  }
  //Serial.print("-----\n");
    if(channel[5]>800 && channel[5]<1400)
  {
    Serial.print(" THRO Arriba \n");//Robot Avanza

          // sets the value (range from 0 to 255):
          valor = map (channel[5], 700, 1500, 255, 0); //Valor por PWM
          //valor = map (pulso, 60, 120, 255, 0);
          //x = pulso
          //in_min = 60
          //in_max = 120
          //out_min = 255
          //out_max = 0
          Serial.println(valor); // Imprime el valor/ 
          Serial.print("--");//Robot Retrocede
          Serial.println(channel[5]); // Imprime el valor/
          analogWrite(ledPin9, valor);
          analogWrite(ledPin11, valor);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);

  }
  if(channel[5]>1600 && channel[5]<2100)
  {
    Serial.print(" THRO Abajo \n");//Robot Retrocede

           // sets the value (range from 0 to 255):
           valor = map (channel[5], 1500, 2200, 0, 255); //Valor por PWM
           //valor = map (pulso, 60, 120, 255, 0);
          //x = pulso
          //in_min = 60
          //in_max = 120
          //out_min = 255
          //out_max = 0
          Serial.println(valor); // Imprime el valor/ 
          Serial.print("--");//Robot Retrocede
          Serial.println(channel[5]); // Imprime el valor/
          analogWrite(ledPin6, valor);
          analogWrite(ledPin10, valor);
          // wait for 30 milliseconds to see the dimming effect
          delay(30);
  }
  //////////
	Serial.print(" 2-AUX1- ");
	Serial.println(channel[2]); // Imprime el valor/ 
	Serial.print(" 3-GEAR- ");
	Serial.println(channel[3]); // Imprime el valor/ 
	Serial.print(" 4-RUDD- ");
	Serial.println(channel[4]); // Imprime el valor/ 
  Serial.print(" 5-THRO- ");
	Serial.println(channel[5]); // Imprime el valor/ 
  delay(100);
}
