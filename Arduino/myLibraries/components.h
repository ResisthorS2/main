#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <Arduino.h>
#include <ArduinoJson.h>


#define ON true
#define OFF false


#define POT_MIDDLE_X 0
#define POT_MIDDLE_Y 0
#define DEFAULT_DEAD_ZONE 5
#define DEFAULT_RANGE 100

class JoyStick {
private:
    int _pinX;
    int _pinY;
    int _x;
    int _y;
    int _deadZoneVal;
    int _range;
public:
    JoyStick(int pinX = A0, int pinY = A1, int deadZone = DEFAULT_DEAD_ZONE, int range = DEFAULT_RANGE);
    ~JoyStick();
    int getX();
    int getY();
    int getDeadZoneVal();
    void setDeadZoneVal(int deadZone = DEFAULT_DEAD_ZONE);
    int getRange();
    void setRange(int range = DEFAULT_RANGE);


};




class Motor {
private:
    int _motorPin;
    bool _motorState;
public:
    Motor(int motorPin = 7, bool motorState = OFF);
    ~Motor();
    bool getMotorState();
    void setMotorState(bool motorState);
};

struct Acceleration {
  float x;
  float y;
  float z;
};

class Accelerometer
{
    public:
        Accelerometer();
        float x;
        float y;
        float z;
        Acceleration ReadAxis();
};


#endif