#include "AsyncTrafficLight.h"

AsyncTrafficLight asyncTrafficLight(10, 9, 8, 7, 6, 5, 1000);

// button configuration
const int BUTTON_PIN = 2;

void setup(){}

void loop(){
  asyncTrafficLight.run();

  // code here can be exuceted asynchronous while the ligth are waiting... 
  asyncButton(); 
}

// sets the LED_BUILTIN to high each time the button is pressed (asynchronous)
void asyncButton() {
  digitalWrite(LED_BUILTIN, digitalRead(BUTTON_PIN));
}
