/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
 * Modif : Janvier 2023, Compatible VisualStudio, JpGouin
*/

/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>
using namespace std;

/*-------------------------- Librairies externes ----------------------------*/
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
using json = nlohmann::json;
json j_msg_send, j_msg_rcv1;

/*------------------------------ Constantes ---------------------------------*/
#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message





/*---------------------------- Variables globales ---------------------------*/
SerialPort * arduino; //doit etre un objet global!




#include "./src/libs/map.h"
#include "./src/libs/player.h"










int main(){
    
    #define TEST 0
    
    
    char com[] = "\\\\.\\COM5"; 
    SerialPort *arduino = new SerialPort(com, BAUD);

    if(!arduino->isConnected()){    
        std::cerr << "Impossible de se connecter au port "<< std::string(com) <<". Fermeture du programme!" <<std::endl;
        exit(1);
    }
    #include "./src/libs/engine.h"
    Engine *engine = new Engine();

    if(TEST != 1)
    {    
        
        // Structure de donnees JSON pour envoie et reception
        int led_state = 1;
        
        Map map;
        std::string raw_msg;

        

        // Boucle pour tester la communication bidirectionnelle Arduino-PC
        map.printMap();
        while(1)
        {



            
            // Reception message Arduino

            j_msg_rcv1.clear();
            raw_msg.clear();
            while(raw_msg.back()!='\n')
            {
                if(raw_msg.size()>MSG_MAX_SIZE)
                {
                    break;
                }
                std::string str_buffer;
                char char_buffer[MSG_MAX_SIZE];
                int buffer_size;
                buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
                str_buffer.assign(char_buffer, buffer_size);
                raw_msg.append(str_buffer);
            }
            
            
            // Impression du message de l'Arduino si valide
            if(raw_msg.size()>0){
                cout << "raw_msg: " << raw_msg  << "----------" << endl;  // debug
                // Transfert du message en json
                try
                {
                    j_msg_rcv1 = json::parse(raw_msg);
                    //engine->updateComponents(j_msg_rcv1, raw_msg);
                    std::cout << "parse "<< std::endl;
                } 
                catch (json::exception& e) {}
            }
            
            

                
            //std::cout << "*engine->input->btn_180 = " << j_msg_rcv1["btn_180"] << std::endl;

            if(j_msg_rcv1["btn_180"] == LOW)
            {
                map.activeCell->move(DOWN, engine);
                map.updateMap();
                map.printMap();
                continue;
            }
            //std::cout << "l.117" << std::endl;
            if(j_msg_rcv1["btn_up"] == LOW)
            {
                map.activeCell->move(UP, engine);
                map.updateMap();
                map.printMap();
                continue;
            }

            if(j_msg_rcv1["btn_left"] == LOW)
            {
                map.activeCell->move(LEFT, engine);
                map.updateMap();
                map.printMap();
                continue;
            }

            if(j_msg_rcv1["btn_right"] == LOW)
            {
                map.activeCell->move(RIGHT, engine);
                map.updateMap();
                map.printMap();
                continue;
            }
            //std::cout << "l.107" << std::endl;
            
            Sleep(100); // 1000ms
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
                map.activeCell->move(UP, engine);
                break;
            
            case 'a':
                map.activeCell->move(LEFT, engine);
                break;
            
            case 's':
                map.activeCell->move(DOWN, engine);
                break;
            case 'd':
                map.activeCell->move(RIGHT, engine);
                break;
                
                

            }
            
            map.updateMap();

            //system("cls");
        }
    }

    return 0;
}





