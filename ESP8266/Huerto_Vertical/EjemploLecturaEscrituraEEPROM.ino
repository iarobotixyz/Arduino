#include <EEPROM.h> // Incluimos la librería para poder usarla
// Creamos un tipo de objeto personalizado
struct Obj{
  float field1;
  byte field2;
  char name[10];
};
void setup(){
  float f = 0.00f;   // Variable to store data read from EEPROM.
  int eeAddress = 0; // Dirección EEPROM donde leer/Escribir
  Serial.begin(9600);
  // Datos a guardar.
  Obj customVarW = {
    3.14f,
    11,
    "19/11/23"
  };
  // Escribiendo datos
  EEPROM.put(eeAddress, customVarW);
  Serial.print("¡Datos escritos!");
  // Recuperamos los datos
  Obj customVarR;
  EEPROM.get(eeAddress, customVarR);
  // Mostramos los datos leídos, los cuales deben coincidir
  Serial.println("Leído objeto personalizado desde la EEPROM: ");
  Serial.println(customVarR.field1);
  Serial.println(customVarR.field2);
  Serial.println(customVarR.name);
}
void loop(){ /* Empty loop */ }