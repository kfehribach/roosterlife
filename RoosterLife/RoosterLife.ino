#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int sensorAnalogPin = A0;
int highLightPin = 12;
int normalLightPin = 11;
int lowLightPin = 10;

void setup() {
  pinMode(highLightPin, OUTPUT);  
  pinMode(normalLightPin, OUTPUT);  
  pinMode(lowLightPin, OUTPUT);
  initDisplay();
  splash("Rooster Life");
  batteryTest();
}

void batteryTest(){
  batteryTest(1);
  batteryTest(26);
  batteryTest(51);
  batteryTest(99);
  batteryTest(76);
}

void batteryTest(int percent){
  displayBatteryHealth(percent);
  display.display();
  delay(300);  
}

void initDisplay()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();
  int currentLight = analogRead(sensorAnalogPin);
  checkLightSensor(currentLight);
  writeHeaderText(String(currentLight));
  displayBatteryHealth(50);
  display.display();
  delay(100);                       // wait for a second
}

void writeHeaderText(String textToWrite){
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(textToWrite);
}

void splash(String textToWrite){
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(0,25);
  display.println(textToWrite);
  display.display();
}

void writeMainText(String textToWrite){
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,16);
  display.println(textToWrite);
}
