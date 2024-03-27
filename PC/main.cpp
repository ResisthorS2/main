/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
 * Modif : Janvier 2023, Compatible VisualStudio, JpGouin
*/

/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>


/*-------------------------- Librairies externes ----------------------------*/


#include "./include/serial/SerialPort.hpp"
#include "./include/json.hpp"
using json = nlohmann::json;
#define BAUD 9600           // Frequence de transmission serielle
   // Longueur maximale d'un message


/*------------------------------ Constantes ---------------------------------*/


/*------------------------- Prototypes de fonctions -------------------------*/


/*---------------------------- Variables globales ---------------------------*/


char com[] = "\\\\.\\COM4"; 
SerialPort *arduino = new SerialPort(com, BAUD);
#include "./src/libs/engine.h"
Engine *engine = new Engine(arduino);
/*----------------------------- Fonction "Main" -----------------------------*/





#include "./src/libs/map.h"
#include "./src/libs/player.h"









int main(){
    
    #define TEST 0
    

    if(TEST != 1)
    {    
        
        // Structure de donnees JSON pour envoie et reception
        int led_state = 1;
        
        Map map;
        std::string raw_msg;

        if(!arduino->isConnected()){
            std::cerr << "Impossible de se connecter au port "<< std::string(com) <<". Fermeture du programme!" <<std::endl;
            exit(1);
        }

        // Boucle pour tester la communication bidirectionnelle Arduino-PC
        while(1)
        {
            if(!engine->RcvFromSerial(engine->arduino, raw_msg)){
                std::cerr << "Erreur lors de la reception du message. " << std::endl;
            }
            
            // Impression du message de l'Arduino si valide
            if(raw_msg.size()>0){
                //std::cout << "raw_msg: " << raw_msg << std::endl;  // debug
                // Transfert du message en json
                engine->j_msg_rcv = json::parse(raw_msg);
                std::cout << "Message de l'Arduino: " << engine->j_msg_rcv << std::endl;
            }

            if(engine->j_msg_rcv["btn_180"] == "HIGH")
            {
                map.activeCell->move(DOWN, engine);
                continue;
            }

            if(engine->j_msg_rcv["btn_up"] == "HIGH")
            {
                map.activeCell->move(UP, engine);
                continue;
            }

            if(engine->j_msg_rcv["btn_left"] == "HIGH")
            {
                map.activeCell->move(LEFT, engine);
                continue;
            }

            if(engine->j_msg_rcv["btn_right"] == "HIGH")
            {
                map.activeCell->move(RIGHT, engine);
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





