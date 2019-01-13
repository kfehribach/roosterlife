#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  initDisplay();
  lightSensor_init();
  batteryMonitor_init();
  splash("Rooster Life");
}

void loop() {
  clearDisplay();
  String lightLevel = checkLightSensor();
  writeHeader(lightLevel);
  displayBatteryHealth(51);
  applyDisplay();
  delay(100);
}
