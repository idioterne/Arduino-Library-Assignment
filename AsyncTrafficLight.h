#ifndef AsyncTrafficLight_h
#define AsyncTrafficLight_h

#include "Arduino.h"

class AsyncTrafficLight{
public:
    AsyncTrafficLight(
        int G1_PIN, int Y1_PIN, int R1_PIN,
        int G2_PIN, int Y2_PIN, int R2_PIN,
        int DELAY);

    void start();
    void stop();
    void reset();

private:
    //
    int _G1_PIN;
    int _Y1_PIN;
    int _R1_PIN;

    //
    int _G2_PIN;
    int _Y2_PIN;
    int _R2_PIN;

    //
    int _g1State;
    int _y1State;
    int _r1State;

    //
    int _g2State;
    int _y2State;
    int _r2State;

    //
    int _DELAY;
    int _mainState;
    long _previousTime;
    long _currentTime;

    //
    void _resetLightStates();   // resets all light states to LOW
    void _setLightStates();     // set sellected lightstates to HIGH
    void _writeLightStates();   // writes lightstates to digital pins
    void _incrementMainState(); // increments mainstate
};

#endif
