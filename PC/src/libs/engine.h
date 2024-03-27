#ifndef ENGINE_H
#define ENGINE_H


#include "../../include/serial/SerialPort.hpp"
#include "../../include/json.hpp"
using json = nlohmann::json;
#define MSG_MAX_SIZE 1024

struct input
        {
            int potentiometer_X;
            int potentiometer_Y;
            int motor;
            int btn_180;
            int btn_up;
            int btn_left;
            int btn_right;
            int btn_select;
            int accelerometer_X;
            int accelerometer_Y;
            int accelerometer_Z;
        };
        typedef struct input Input;

        struct output
        {
            int motor;
            int led;
        };
class Engine
{
    public:
        Engine();
        ~Engine();	
        bool SendToSerial(SerialPort *arduino, json j_msg);
        bool RcvFromSerial(SerialPort *arduino, std::string &msg);
        json updateComponents(SerialPort *arduino, json j_msg_rcv, std::string raw_msg);
        json j_msg_send, j_msg_rcv;
        std::string dialogue;
        SerialPort *arduino;
        Input * input;
        

};

#endif