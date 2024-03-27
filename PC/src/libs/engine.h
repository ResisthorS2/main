#ifndef ENGINE_H
#define ENGINE_H

#include "../include/serial/SerialPort.hpp"
#include "../include/json.hpp"
using json = nlohmann::json;
#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message



class Engine
{
    public:
        SerialPort * arduino; //doit etre un objet global!
        Engine();
        ~Engine();	
        bool SendToSerial(SerialPort *arduino, json j_msg);
        bool RcvFromSerial(SerialPort *arduino, std::string &msg);
        char *com; 
        json j_msg_send, j_msg_rcv;
        std::string dialogue;
};

#endif