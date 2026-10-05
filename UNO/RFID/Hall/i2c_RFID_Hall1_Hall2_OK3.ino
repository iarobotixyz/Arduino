//RoboticaXYZ
#include <Wire.h>
#include <Adafruit_PN532.h>

#define PN532_IRQ   2
#define PN532_RESET 3

#define RELAY_PIN 13      // Activo en LOW
#define LUZ_PIN   12

#define HALL1_PIN 8
#define HALL2_PIN 9

// Tiempo que permanece válida la RFID después de una lectura correcta
#define RFID_TIMEOUT 1000

Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

// UID AUTORIZADO
uint8_t authorizedUID[] = {0x6B, 0x31, 0xDF, 0x11};
const uint8_t authorizedUIDLength = 4;

unsigned long ultimaRFIDValida = 0;
unsigned long ultimoReporte = 0;

void setup() {

  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LUZ_PIN, OUTPUT);

  pinMode(HALL1_PIN, INPUT);
  pinMode(HALL2_PIN, INPUT);

  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LUZ_PIN, LOW);

  nfc.begin();
  nfc.SAMConfig();

  Serial.println("Sistema NFC + Hall listo");
}

void loop() {

  // ==========================
  // RFID
  // ==========================
  uint8_t uid[7];
  uint8_t uidLength;

  boolean success = nfc.readPassiveTargetID(
    PN532_MIFARE_ISO14443A,
    uid,
    &uidLength,
    20
  );

  if (success) {

    if (isAuthorized(uid, uidLength)) {
      ultimaRFIDValida = millis();
    }
  }

  bool rfidOK = (millis() - ultimaRFIDValida) < RFID_TIMEOUT;

  // ==========================
  // Hall
  // ==========================
  bool hall1OK = digitalRead(HALL1_PIN);
  bool hall2OK = digitalRead(HALL2_PIN);

  // Si tus módulos están invertidos cambia por:
  // bool hall1OK = !digitalRead(HALL1_PIN);
  // bool hall2OK = !digitalRead(HALL2_PIN);

  // ==========================
  // Condición principal
  // ==========================
  bool acceso = rfidOK && hall1OK && hall2OK;

  if (acceso) {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LUZ_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LUZ_PIN, LOW);
  }

  // ==========================
  // Serial resumido
  // ==========================
  if (millis() - ultimoReporte >= 500) {

    ultimoReporte = millis();

    Serial.print("RFID=");
    Serial.print(rfidOK);

    Serial.print(" H1=");
    Serial.print(hall1OK);

    Serial.print(" H2=");
    Serial.print(hall2OK);

    Serial.print(" RELAY=");
    Serial.println(acceso);
  }
}

// ======================================
// Compara UID
// ======================================
bool isAuthorized(uint8_t *uid, uint8_t uidLength) {

  if (uidLength != authorizedUIDLength)
    return false;

  for (uint8_t i = 0; i < uidLength; i++) {

    if (uid[i] != authorizedUID[i])
      return false;
  }

  return true;
}