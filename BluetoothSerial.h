/*-------------------------------------------------------------------------
  
  Arduino library for the Teensy3Bluetooth Serial shield available at the hackerspaceshop.com

  Check it out here:
  http://www.hackerspaceshop.com/teensy/teensy-3-1-bluetooth-module.html


  Written by Amir Hassan and Florian Bittner for hackerspaceshop.com,
  contributions by members of the open source community.


  This is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation, either version 3 of
  the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library.  If not, see
  <http://www.gnu.org/licenses/>.
  -------------------------------------------------------------------------*/

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
