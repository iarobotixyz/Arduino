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
  if(channel[4]==0 && channel[3]==0  && channel[2]==0)
  {
    Serial.print(" RC Apagado ");
  }
  Serial.print("-----\n");
  
  if(channel[4]>800 && channel[4]<1400)
  {
    Serial.print(" RUDD Izquierda \n");//Robot Gira Izquierda
                          // fade in from min to max in increments of 5 points:
          for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
            // sets the value (range from 0 to 255):
            analogWrite(ledPin9, fadeValue);
            analogWrite(ledPin10, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            delay(30);
          }
        //delay(100);
          // fade out from max to min in increments of 5 points:
          for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
            // sets the value (range from 0 to 255):
            analogWrite(ledPin9, fadeValue);
            analogWrite(ledPin10, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            delay(30);
          }
  }
  if(channel[4]>1600 && channel[4]<2100)
  {
    Serial.print(" RUDD Derecha \n");//Robot Gira Derecha
                      // fade in from min to max in increments of 5 points:
          for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
            // sets the value (range from 0 to 255):
            analogWrite(ledPin6, fadeValue);
            analogWrite(ledPin11, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            delay(30);
          }
        //delay(100);
          // fade out from max to min in increments of 5 points:
          for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
            // sets the value (range from 0 to 255):
            analogWrite(ledPin6, fadeValue);
            analogWrite(ledPin11, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            delay(30);
          }
          
  }
  //Serial.print("-----\n");
    if(channel[5]>800 && channel[5]<1400)
  {
    Serial.print(" THRO Arriba \n");//Robot Avanza
              // fade in from min to max in increments of 5 points:
          for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
            // sets the value (range from 0 to 255):
            analogWrite(ledPin9, fadeValue);
            analogWrite(ledPin11, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            delay(30);
          }
        //delay(100);
          // fade out from max to min in increments of 5 points:
          for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
            // sets the value (range from 0 to 255):
            analogWrite(ledPin9, fadeValue);
            analogWrite(ledPin11, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            delay(30);
          }

  }
  if(channel[5]>1600 && channel[5]<2100)
  {
    Serial.print(" THRO Abajo \n");//Robot Retrocede
                  // fade in from min to max in increments of 5 points:
          for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
            // sets the value (range from 0 to 255):
            analogWrite(ledPin6, fadeValue);
            analogWrite(ledPin10, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            delay(30);
          }
        //delay(100);
          // fade out from max to min in increments of 5 points:
          for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
            // sets the value (range from 0 to 255):
            analogWrite(ledPin6, fadeValue);
            analogWrite(ledPin10, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            delay(30);
          }
          
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

  delay(50);
}
