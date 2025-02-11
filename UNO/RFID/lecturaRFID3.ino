#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN	9    //Pin 9 para el reset del RC522
#define SS_PIN	10   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522

void setup() {
 pinMode(7, OUTPUT);
	Serial.begin(115200); //Iniciamos la comunicación  serial
	SPI.begin();        //Iniciamos el Bus SPI
	mfrc522.PCD_Init(); // Iniciamos  el MFRC522
	Serial.println("Lectura del UID");
    
    
 
}


byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuario1[4]= {0x7E, 0x76, 0xEA, 0x21} ; //código del usuario 1
        
/// 7E 76 EA 21

void loop() {
	// Revisamos si hay nuevas tarjetas  presentes
	if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
  		//Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
// Enviamos serialemente su UID
  Serial.print("Card UID:");
for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
ActualUID[i]=mfrc522.uid.uidByte[i];              
 } 
            
            
            
 Serial.println();
            
if(compareArray(ActualUID,Usuario1))
  
                
Serial.println("Acceso concedido...");
digitalWrite(7, HIGH);
delay(1000);
digitalWrite(7, LOW);
                
     
              
  
  
                
// Terminamos la lectura de la tarjeta  actual
 mfrc522.PICC_HaltA();         
            }      
	}	
}





//Función para comparar dos vectores
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}