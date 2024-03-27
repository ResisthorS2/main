#ifndef ENGINE_H
#define ENGINE_H


#include "../../include/serial/SerialPort.hpp"
#include "../../include/json.hpp"
using json = nlohmann::json;
#define MSG_MAX_SIZE 1024

class Engine
{
    public:
        Engine(SerialPort *arduino);	
        bool SendToSerial(SerialPort *arduino, json j_msg);
        bool RcvFromSerial(SerialPort *arduino, std::string &msg);
        json j_msg_send, j_msg_rcv;
        std::string dialogue;
        SerialPort *arduino;
};

#endif