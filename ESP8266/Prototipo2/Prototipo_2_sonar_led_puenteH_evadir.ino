

const int trigPin = 12;
const int echoPin = 14;
const int led = 2;

const int motorA = 16;
const int motorB = 5;
const int motorC = 4;
const int motorD = 0;



//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  pinMode(led, OUTPUT);
  
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(motorC, OUTPUT);
  pinMode(motorD, OUTPUT);
  
}
void avanza() 
{
    digitalWrite(motorA, HIGH);   //Derecha Adelante
    digitalWrite(motorD, HIGH);   //Izquierda Adelante
    digitalWrite(motorB, LOW);   // Derecha Adelante
    digitalWrite(motorC, LOW);   // Izquierda Adelante
    delay(50);
}
void izquierda() 
{
    digitalWrite(motorA, LOW);   //Derecha Adelante
    digitalWrite(motorC, LOW);   //Izquierda Adelante 

    digitalWrite(motorB, HIGH);   // Derecha Adelante
    digitalWrite(motorD, HIGH);   // Izquierda Adelante
     delay(20);
}
void derecha() 
{
    digitalWrite(motorA, HIGH);   //Derecha Adelante
    digitalWrite(motorC, HIGH);   //Izquierda Adelante 

    digitalWrite(motorB, LOW);   // Derecha Adelante
    digitalWrite(motorD, LOW);   // Izquierda Adelante
     delay(20);
}
void atras() 
{
    digitalWrite(motorA, LOW);   //Derecha Adelante
    digitalWrite(motorD, LOW);   //Izquierda Adelante
    digitalWrite(motorB, HIGH);   // Derecha Adelante
    digitalWrite(motorC, HIGH);   // Izquierda Adelante
    delay(50);
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  if(distanceCm<=20)
    {
     digitalWrite(led, HIGH);   //
     
     atras();
     delay(200);  
     izquierda();

     
     delay(15);                       // 
      }
  else
    {
     digitalWrite(led, LOW);   
     avanza();
     delay(50);  
      }
  
  // Prints the distance on the Serial Monitor
  Serial.print("---------Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("----------");
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  
  delay(500);
}
