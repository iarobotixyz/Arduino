/*
  old bootloader
  https://iarobotxyz.blogspot.com/2025/10/que-es-un-clicker-y-como-crear-uno-paso.html
*/


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// 60 baneado , te bajan en lugar de subir
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(60);  
  digitalWrite(LED_BUILTIN, LOW);  
  delay(60);             
}
