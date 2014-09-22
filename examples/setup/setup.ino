#include <SoftwareSerial.h>
#include <BluetoothSerial.h>

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);  
  
  // set AT on connect and see if devide is there .. this will be integrated into the library  
  BTSerial.write("AT\r\n");  // expect "OK"
  
  // set the pin for connectiong to the bluetooth module
  BTSerial.setPinCode("1234");
  
  // ste the device name shon on bluetooth device scan
  BTSerial.setDeviceName("blubber"); 


  // if you call this the baudrate is PERMANENTLY set to the new baudrate and you need to close the serial connection to the bluetooth module and reopen with the new baudrate
  // BTSerial.setBaudrate(9600);  
  // BTSerial.end();
  // Serial.end();
  
  
  

  
  
}

void loop() {
 
  
  
  if(BTSerial.available())
    Serial.write(BTSerial.read());

  if(Serial.available())
    BTSerial.write(Serial.read());
}
