//Variable de tipo entero
int leer = 0;
void setup() 
{//Iniciamos la comunicación serial
  Serial.begin(9600);
}
void loop() 
{//Tomamos la lectura analógica del pin A0
  leer = analogRead(0);
  //Imprime monitor serial
  Serial.println(leer);
  delay(300);//tiempo de muestreo
}
