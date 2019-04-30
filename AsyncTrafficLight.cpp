
#include "Arduino.h"
#include "AsyncTrafficLight.h"

AsyncTrafficLight::AsyncTrafficLight(int G1_PIN, int Y1_PIN, int R1_PIN, int G2_PIN, int Y2_PIN, int R2_PIN, int DELAY){
  
    //
    pinMode(G1_PIN, OUTPUT);
    pinMode(Y1_PIN, OUTPUT);
    pinMode(R1_PIN, OUTPUT);

    //
    pinMode(G2_PIN, OUTPUT);
    pinMode(Y2_PIN, OUTPUT);
    pinMode(R2_PIN, OUTPUT);

    //
    _G1_PIN = G1_PIN;
    _Y1_PIN = Y1_PIN;
    _R1_PIN = R1_PIN;

    //
    _G2_PIN = G2_PIN;
    _Y2_PIN = Y2_PIN;
    _R2_PIN = R2_PIN;

    //
    _g1State = LOW;
    _y1State = LOW;
    _r1State = LOW;

    //
    _g2State = LOW;
    _y2State = LOW;
    _r2State = LOW;

    //
    _DELAY = DELAY;
    _mainState = 0;
    _previousTime = 0;
    _currentTime = 0;
}

void AsyncTrafficLight::start(){
    _currentTime = millis();

    if (_currentTime - _previousTime >= _DELAY || _previousTime == 0)
    {
        _previousTime = _currentTime; // updates previous time to current time

        _resetLightStates();   // resets all light states to LOW
        _setLightStates();     // set sellected lightstates to HIGH
        _writeLightStates();   // writes lightstates to digital pins
        _incrementMainState(); // increments mainstate
    }
}

void AsyncTrafficLight::stop(){
}

void AsyncTrafficLight::reset(){
}

void AsyncTrafficLight::_resetLightStates(){
    // traficlight 1 state
    _g1State = LOW;
    _y1State = LOW;
    _r1State = LOW;

    // traficlight 2 state
    _g2State = LOW;
    _y2State = LOW;
    _r2State = LOW;
}

void AsyncTrafficLight::_setLightStates(){
    switch(_mainState) {
    case 0: {
        _g1State = HIGH;
        _r2State = HIGH;
        break;
    }

    case 1: {
        _y1State = HIGH;
        _r2State = HIGH;
        break;
    }

    case 2: {
        _r1State = HIGH;
        _r2State = HIGH;
        _y2State = HIGH;
        break;
    }

    case 3: {
        _r1State = HIGH;
        _g2State = HIGH;
        break;
    }

    case 4: {
        _r1State = HIGH;
        _y2State = HIGH;
        break;
    }

    case 5: {
        _r1State = HIGH;
        _y1State = HIGH;
        _r2State = HIGH;
        break;
    }
  }
}

void AsyncTrafficLight::_writeLightStates(){
    // traficlight 1 state
    digitalWrite(_G1_PIN, _g1State);
    digitalWrite(_Y1_PIN, _y1State);
    digitalWrite(_R1_PIN, _r1State);

    // traficlight 2 state
    digitalWrite(_G2_PIN, _g2State);
    digitalWrite(_Y2_PIN, _y2State);
    digitalWrite(_R2_PIN, _r2State);
}

void AsyncTrafficLight::_incrementMainState(){
    _mainState = (_mainState < 5) ? ++_mainState : 0;
}
