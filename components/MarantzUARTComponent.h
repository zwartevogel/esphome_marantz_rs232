#include "esphome.h"

class MarantzUARTComponent : public Component, public UARTDevice {
 public:
  MarantzUARTComponent(UARTComponent *parent) : UARTDevice(parent) {}

  TextSensor *status_sensor = new TextSensor();

  void setup() override {
    // Setup wordt hier uitgevoerd als ESPHome opstart.
  }

  void loop() override {
    // Lees continu de UART-buffer
    while (available()) {
      std::string line = readStringUntil('\n').c_str();

      // Publiceer de volledige lijn naar de tekstsensor
      status_sensor->publish_state(line);
    }
  }
};
