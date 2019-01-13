int highLightThreshold = 75;
int lowLightThreshold = 300;
int displayTopBluePixel = 10;
int sensorAnalogPin = A0;
int highLightPin = 12;
int normalLightPin = 11;
int lowLightPin = 10;

void lightSensor_init()
{
  pinMode(highLightPin, OUTPUT);  
  pinMode(normalLightPin, OUTPUT);  
  pinMode(lowLightPin, OUTPUT);
}

String checkLightSensor()
{
  int currentLight = analogRead(sensorAnalogPin);
//  int currentLightD = digitalRead(22);
//  return String(currentLightD);
  if(currentLight < highLightThreshold){
    highLight();
    return "High";
  }
  else if(currentLight > lowLightThreshold){
    lowLight();
    return "Low";
  }
  else {
    normalLight();
    return "Normal";
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
