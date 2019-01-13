static unsigned char PROGMEM const battery_full_bmp[] =
{ B01111111, B11111111,
  B01000000, B00000001,
  B11011011, B01101101,
  B11011011, B01101101,
  B11011011, B01101101,
  B11011011, B01101101,
  B01000000, B00000001,
  B01111111, B11111111 };

static unsigned char PROGMEM const battery_threequarter_bmp[] =
{ B01111111, B11111111,
  B01000000, B00000001,
  B11000011, B01101101,
  B11000011, B01101101,
  B11000011, B01101101,
  B11000011, B01101101,
  B01000000, B00000001,
  B01111111, B11111111 };

static unsigned char PROGMEM const battery_half_bmp[] =
{ B01111111, B11111111,
  B01000000, B00000001,
  B11000000, B01101101,
  B11000000, B01101101,
  B11000000, B01101101,
  B11000000, B01101101,
  B01000000, B00000001,
  B01111111, B11111111 };

static unsigned char PROGMEM const battery_quarter_bmp[] =
{ B01111111, B11111111,
  B01000000, B00000001,
  B11000000, B00001101,
  B11000000, B00001101,
  B11000000, B00001101,
  B11000000, B00001101,
  B01000000, B00000001,
  B01111111, B11111111 };

static unsigned char PROGMEM const battery_empty_bmp[] =
{ B01111111, B11111111,
  B01000000, B00000001,
  B11000000, B00000001,
  B11000000, B00000001,
  B11000000, B00000001,
  B11000000, B00000001,
  B01000000, B00000001,
  B01111111, B11111111 };

void batteryMonitor_init(){
    batteryTest();
}

void displayBatteryHealth(int percent)
{
  if(percent >= 95){
    display.drawBitmap(112, 0, battery_full_bmp, 16, 8, 1);
  }
  else if(percent >= 75){
    display.drawBitmap(112, 0, battery_threequarter_bmp, 16, 8, 1);
  }
  else if(percent >= 50){
    display.drawBitmap(112, 0, battery_half_bmp, 16, 8, 1);
  }  
  else if(percent >= 25){
    display.drawBitmap(112, 0, battery_quarter_bmp, 16, 8, 1);
  }
  else{
    display.drawBitmap(112, 0, battery_empty_bmp, 16, 8, 1);
  }
  display.display();
}

void batteryTest(){
  batteryTest(1);
  batteryTest(25);
  batteryTest(50);
  batteryTest(76);
  batteryTest(99);
}

void batteryTest(int percent){
  displayBatteryHealth(percent);
  display.display();
  delay(300);  
}
