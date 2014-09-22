#ifndef __BLUETOOTHSERIAL_H__

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

#include <Print.h>
#include <Stream.h>
#include <SoftwareSerial.h>

class BluetoothSerial : public Stream {
private:
  SoftwareSerial mySerial;
public:
  BluetoothSerial(int rx_pin, int tx_pin) : mySerial(rx_pin, tx_pin)
  {}

  ~BluetoothSerial()
  {}

  void begin(unsigned long speed = 9600);
  void end();

  void setBaudrate(unsigned long speed);
  void setPinCode(const char*  pin_code);
  void setDeviceName(const char* device_name);



  virtual int available();
  virtual int read();
  virtual int peek();;
  virtual void flush();
  virtual size_t write(uint8_t c);

  void onSerialConnectionChange(void (*userFunc)(void));


  using Print::write;
};

extern BluetoothSerial BTSerial;

#endif
