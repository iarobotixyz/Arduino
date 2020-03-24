const int sensorPin = A0;
const long referenceMv = 5000;
void setup() 
{
   Serial.begin(115200);
   pinMode(LED_BUILTIN, OUTPUT);
} 
void loop() 
{
   int val = analogRead(sensorPin);
   int mV = (val * referenceMv) / 1023;
   int cm = getDistance(mV);
   Serial.print(mV);
   Serial.print(",");
   Serial.println(cm);
   delay(100);
}
const int TABLE_ENTRIES = 12;
const int INTERVAL  = 250;
static int distance[TABLE_ENTRIES] = {150,140,130,100,60,50,40,35,30,25,20,15};
int getDistance(int mV) 
{
   if (mV > INTERVAL * TABLE_ENTRIES - 1)      return distance[TABLE_ENTRIES - 1];
   else 
   {
      int index = mV / INTERVAL;
      float frac = (mV % 250) / (float)INTERVAL;
      return distance[index] - ((distance[index] - distance[index + 1]) * frac);
   }
}
