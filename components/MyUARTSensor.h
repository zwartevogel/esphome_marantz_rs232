#include "esphome.h"

class MyUARTSensor : public Component, public UARTDevice, public TextSensor {
 public:
  MyUARTSensor(UARTComponent *parent) : UARTDevice(parent) {}

  void loop() override {
    while (available()) {
      char c = read();  // Lees een byte
      buffer += c;      // Voeg de byte toe aan de buffer
      if (c == '\n') {  // Als het een nieuwe regel is
        publish_state(buffer);  // Publiceer de volledige string
        buffer = "";            // Maak de buffer leeg
      }
    }
  }

 private:
  std::string buffer;
};
