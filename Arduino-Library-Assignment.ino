#include "AsyncTrafficLight.h"

AsyncTrafficLight asyncTrafficLight(10, 9, 8, 7, 6, 5, 1000);

void setup(){}

void loop(){
  asyncTrafficLight.start();
}
