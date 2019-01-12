int sensorAnalogPin = A0;
//int sensorDigitalPin = D0;

int highLightPin = 12;
int normalLightPin = 11;
int lowLightPin = 10;

int highLightThreshold = 75;
int lowLightThreshold = 275;

void setup() {
  Serial.begin(9600);  
  pinMode(highLightPin, OUTPUT);  
  pinMode(normalLightPin, OUTPUT);  
  pinMode(lowLightPin, OUTPUT);  
}

void loop() {
  Serial.println(analogRead(sensorAnalogPin));
  int currentLight = analogRead(sensorAnalogPin);
  if(currentLight < highLightThreshold){
    highLight();
  }
  else if(currentLight > lowLightThreshold){
    lowLight();
  }
  else {
    normalLight();
  }
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
