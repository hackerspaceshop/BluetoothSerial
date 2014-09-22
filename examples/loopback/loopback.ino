#include <SoftwareSerial.h>
#include <BluetoothSerial.h>

void setup() {
  BTSerial.begin(9600);
}

void loop() {
  if(BTSerial.available())
    Serial.write(BTSerial.read());

  if(Serial.available())
    BTSerial.write(Serial.read());
}
