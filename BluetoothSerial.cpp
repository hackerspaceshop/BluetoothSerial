#include "BluetoothSerial.h"

#define INTERRUPT_PIN 3
#define RX 0
#define TX 1

BluetoothSerial BTSerial(RX,TX);


void BluetoothSerial::begin(unsigned long speed) {


   //debug
   Serial.println("GO");

   pinMode(INTERRUPT_PIN,INPUT_PULLUP); 
   mySerial.begin(speed);

}






void BluetoothSerial::setBaudrate(unsigned long speed) {

  //  BAUDRATE TABLE
  //  1---1200
  //  2---2400
  //  3---4800
  //  4---9600 
  //  5---19200 
  //  6---38400 
  //  7---57600 
  //  8---115200 
  //  9---230400 
  //  A---460800 
  //  B---921600 
  //  C---1382400 
  //  default:4---9600

   if(speed == 0) speed=9600;
   char baudRateCode[1];

   switch (speed){

   case 1200:     baudRateCode[0]='1'; break;
   case 2400:     baudRateCode[0]='2'; break;
   case 4800:     baudRateCode[0]='3'; break;
   case 19200:    baudRateCode[0]='5'; break;
   case 38400:    baudRateCode[0]='6'; break;
   case 57600:    baudRateCode[0]='7'; break;
   case 115200:   baudRateCode[0]='8'; break;
   case 230400:   baudRateCode[0]='9'; break;
   case 460800:   baudRateCode[0]='A'; break;
   case 921600:   baudRateCode[0]='B'; break;
   case 1382400:  baudRateCode[0]='C'; break;

  default:
    // 9600
    baudRateCode[0]='4';
  break;

   }


   // DEBUG
   Serial.println("");
   Serial.print("Setting BAUDRATE on device to: ");
   Serial.print(speed);
   Serial.print("  (");
   Serial.print(baudRateCode[0]);
   Serial.println(")");


    mySerial.write("AT+BAUD");
    mySerial.write(baudRateCode[0]);
    mySerial.write("\r\n");
    delay(10);


  // should we close the connection and reopen with set baudrate here?

  // TODO return 1 on succcess / -1 on fail


}

void BluetoothSerial::setPinCode(const char* pin_code) {

   // DEBUG
   Serial.println("");
   Serial.print("Setting PINCODE on device to: '");
   Serial.print(pin_code);
   Serial.println("'");

  // set pin code
  mySerial.write("AT+PIN");
  mySerial.write(pin_code);
  mySerial.write("\r\n");
  delay(10);


  // TODO return 1 on succcess / -1 on fail






}

void BluetoothSerial::setDeviceName(const char* device_name) {

   // DEBUG
   Serial.println("");
   Serial.print("Setting DEVICENAME on device to: ");
   Serial.println(device_name);


  // set name of bluetooth device 
  mySerial.write("AT+NAME");
  mySerial.write(device_name);
  mySerial.write("\r\n");
  delay(10);


  // TODO return 1 on succcess / -1 on fail




}







void BluetoothSerial::onSerialConnectionChange(void (*userFunc)(void)) {
  attachInterrupt(INTERRUPT_PIN,userFunc,CHANGE);
}

void BluetoothSerial::end() {
  mySerial.end();
}

int BluetoothSerial::available() {
  return mySerial.available();
}

int BluetoothSerial::read() {
  return mySerial.read();
}

int BluetoothSerial::peek() {
  return mySerial.peek();
}

void BluetoothSerial::flush() {
  mySerial.flush();
}

size_t BluetoothSerial::write(uint8_t c) {
  mySerial.write(c);
}

