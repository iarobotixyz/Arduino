int channel[6]; //Channel values
int PinSiete = 7;
int PinSeis = 6;
int PinCinco = 5;
int PinCuatro = 4;
int PinTres = 3;
int PinDos = 2;
void setup()
{
  Serial.begin(9600); //Inicia serial/
  pinMode(PinSiete, INPUT); //Pin-7-input
  pinMode(PinSeis, INPUT); //Pin-6-input
  pinMode(PinCinco, INPUT); //Pin-5-input
  pinMode(PinCuatro, INPUT); //Pin-4-input
  pinMode(PinTres, INPUT); //Pin-3-input 
  pinMode(PinDos, INPUT); //Pin-2-input 
}
void loop()
{
	channel[7]=pulseIn(PinSiete, HIGH);
  channel[6]=pulseIn(PinSeis, HIGH);
  channel[5]=pulseIn(PinCinco, HIGH);
  channel[4]=pulseIn(PinCuatro, HIGH);
  channel[3]=pulseIn(PinTres, HIGH);
  channel[2]=pulseIn(PinDos, HIGH);
  
	Serial.print(" 2-AUX1- ");
	Serial.println(channel[2]); // Imprime el valor/ 

	Serial.print(" 3-GEAR- ");
	Serial.println(channel[3]); // Imprime el valor/ 

	Serial.print(" 4-RUDD- ");
	Serial.println(channel[4]); // Imprime el valor/ 
  
  Serial.print(" 5-ELEV- ");
	Serial.println(channel[5]); // Imprime el valor/ 
  
  Serial.print(" 6-AILE- ");
	Serial.println(channel[6]); // Imprime el valor/ 
  
  Serial.print(" 7-THRO- ");
	Serial.println(channel[7]); // Imprime el valor/ 

  delay(100);
}
