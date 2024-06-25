int channel[6]; //Channel values
int PinCuatro = 4;
void setup()
{
  Serial.begin(9600); //Inicia serial/
  pinMode(PinCuatro, INPUT); //Pin-4-input
}
void loop()
{
  if(pulseIn(PinCuatro , HIGH) > 4000);//Val-Min-Pin-4 
  {
	channel[1]=pulseIn(PinCuatro, HIGH);
	Serial.print(" - ");
	Serial.println(channel[1]); // Imprime el valor/ 
  delay(100); 
  }
}
