int highLightThreshold = 75;
int lowLightThreshold = 300;
int displayTopBluePixel = 10;

void checkLightSensor(int currentLight)
{
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
