#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static unsigned char PROGMEM const logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int sensorAnalogPin = A0;
int highLightPin = 12;
int normalLightPin = 11;
int lowLightPin = 10;
int highLightThreshold = 75;
int lowLightThreshold = 300;



void setup() {
  Serial.begin(9600);  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  pinMode(highLightPin, OUTPUT);  
  pinMode(normalLightPin, OUTPUT);  
  pinMode(lowLightPin, OUTPUT);
  writeHeaderText("Let it begin");
}

void loop() {
  display.clearDisplay();
  Serial.println(analogRead(sensorAnalogPin));
  int currentLight = analogRead(sensorAnalogPin);
  writeHeaderText(String(currentLight));
  if(currentLight < highLightThreshold){
    highLight();
    writeMainText("High");
  }
  else if(currentLight > lowLightThreshold){
    lowLight();
    writeMainText("Low");
  }
  else {
    normalLight();
    writeMainText("Normal");
  }
  display.display();
  delay(100);                       // wait for a second
}

void highLight(){
  digitalWrite(highLightPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(normalLightPin, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(lowLightPin, LOW);   // turn the LED on (HIGH is the voltage level)
}

void normalLight(){
  digitalWrite(highLightPin, LOW);   
  digitalWrite(normalLightPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(lowLightPin, LOW);   // turn the LED on (HIGH is the voltage level)
}

void lowLight(){
  digitalWrite(highLightPin, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(normalLightPin, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(lowLightPin, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void writeHeaderText(String textToWrite){
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(textToWrite);
}

void writeMainText(String textToWrite){
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,25);
  display.println(textToWrite);
}
