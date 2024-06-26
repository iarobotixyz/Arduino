int channel[6]; //Channel values
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
  if(channel[4]==0 && channel[3]==0  && channel[2]==0)
  {
    Serial.print(" RC Apagado ");
  }
  Serial.print("-----\n");
  
  if(channel[4]>800 && channel[4]<1400)
  {
    Serial.print(" RUDD Izquierda \n");//Robot Gira Izquierda
  }
  if(channel[4]>1600 && channel[4]<2100)
  {
    Serial.print(" RUDD Derecha \n");//Robot Gira Derecha
  }
  //Serial.print("-----\n");
    if(channel[5]>800 && channel[5]<1400)
  {
    Serial.print(" THRO Arriba \n");//Robot Avanza
  }
  if(channel[5]>1600 && channel[5]<2100)
  {
    Serial.print(" THRO Abajo \n");//Robot Retrocede
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
