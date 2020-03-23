/*iarobotxyz
Prueba Motor Brushless
*/

#include <Servo.h>
Servo clase; 
int ini = 0;   
void setup() 
{
  clase.attach(9);  
}
void loop() 
{
  for (ini = 0; ini <= 180; ini += 1) 
  { 
    clase.write(ini);             
    delay(95);                    
  }
}
