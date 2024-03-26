/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
 * Modif : Janvier 2023, Compatible VisualStudio, JpGouin
*/

/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>


/*-------------------------- Librairies externes ----------------------------*/

#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
using json = nlohmann::json;

/*------------------------------ Constantes ---------------------------------*/
#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message


/*------------------------- Prototypes de fonctions -------------------------*/
bool SendToSerial(SerialPort *arduino, json j_msg);
bool RcvFromSerial(SerialPort *arduino, std::string &msg);


/*---------------------------- Variables globales ---------------------------*/


/*----------------------------- Fonction "Main" -----------------------------*/





#include "./src/libs/map.h"






int main(){
    
    #define TEST 1

    if(TEST != 1)
    {    
        
        // Structure de donnees JSON pour envoie et reception
        int led_state = 1;
        Engine engine;
        engine.Engine(); //J'ai mis le constructeur dans une fonction pour pouvoir l'appeler quand je veux
        Map map;
        std::string raw_msg;
        

        // Boucle pour tester la communication bidirectionnelle Arduino-PC
        while(1)
        {
            if(!engine.RcvFromSerial(arduino, raw_msg)){
                std::cerr << "Erreur lors de la reception du message. " << std::endl;
            }
            
            // Impression du message de l'Arduino si valide
            if(raw_msg.size()>0){
                //std::cout << "raw_msg: " << raw_msg << std::endl;  // debug
                // Transfert du message en json
                engine.j_msg_rcv = json::parse(raw_msg);
                std::cout << "Message de l'Arduino: " << engine.j_msg_rcv << std::endl;
            }

            if(engine.j_msg_rcv["btn_180"] == "HIGH")
            {
                map.activeCell->move(DOWN);
                continue;
            }

            if(engine.j_msg_rcv["btn_up"] == "HIGH")
            {
                map.activeCell->move(UP);
                continue;
            }

            if(engine.j_msg_rcv["btn_left"] == "HIGH")
            {
                map.activeCell->move(LEFT);
                continue;
            }

            if(engine.j_msg_rcv["btn_right"] == "HIGH")
            {
                map.activeCell->move(RIGHT);
                continue;
            }
            
            map.printMap();
            Sleep(1000); // 1000ms
        }
    }

    if(TEST == 1)
    {
        Map map;
        std::cout << "Test de la classe Map" << std::endl;;
        
        

        while(true)
        {
            
            map.printMap();
            char input;

            std::cin >> input;
            //std::cout<< "input "<<input<<std::endl;
            
            switch (input)
            {

            case 'w':
                map.activeCell->move(UP);
                break;
            
            case 'a':
                map.activeCell->move(LEFT);
                break;
            
            case 's':
                map.activeCell->move(DOWN);
                break;
            case 'd':
                map.activeCell->move(RIGHT);
                break;
                
                

            }
            
            map.updateMap();
            //system("cls");
        }
    }

    return 0;
}



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
        std::string dialogue
};


/*---------------------------Definition de fonctions ------------------------*/

Engine::Engine()
{
    com = "\\\\.\\COM4"; 
    arduino = new SerialPort(com, BAUD);
    if(!arduino->isConnected()){
        std::cerr << "Impossible de se connecter au port "<< std::string(com) <<". Fermeture du programme!" <<std::endl;
        exit(1);
    }
}

Engine::~Engine()
{
    delete arduino;
}

bool Engine::SendToSerial(SerialPort *arduino, json j_msg)
{
    // Return 0 if error
    std::string msg = j_msg.dump();
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}


bool Engine::RcvFromSerial(SerialPort *arduino, std::string &msg){
    // Return 0 if error
    // Message output in msg
    std::string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear std::string
    // Read serialport until '\n' character (Blocking)

    // Version fonctionnel dans VScode, mais non fonctionnel avec Visual Studio
/*  
    while(msg.back()!='\n'){
        if(msg.size()>MSG_MAX_SIZE){
            return false;
        }

        buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
        str_buffer.assign(char_buffer, buffer_size);
        msg.append(str_buffer);
    }
*/

    // Version fonctionnelle dans VScode et Visual Studio
    buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);

    //msg.pop_back(); //remove '/n' from std::string

    return true;
}

