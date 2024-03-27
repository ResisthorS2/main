/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
*/

/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include "../myLibraries/components.h"

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 9600        // Frequence de transmission serielle

/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message


int pinLED = 38;


/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(); 
void readMsg();
void serialEvent();
/*---------------------------- Fonctions "Main" -----------------------------*/

void setup() {
  Serial.begin(BAUD);               // Initialisation de la communication serielle
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, 1);

  pinMode(22, INPUT_PULLUP);

}


JoyStick joystick;
/* Boucle principale (infinie) */
void loop() {

  if(shouldRead_ == true)
  {
    StaticJsonDocument<500> jsg_msg;
    if(digitalRead(28) == LOW)
    {
      while(digitalRead(28) == LOW){delay(10);}
      // Serialisation
      jsg_msg["btn_180"] = digitalRead(28);
      serializeJson(jsg_msg, Serial);
    }

    if(digitalRead(24) == LOW)
    {
      while(digitalRead(24) == LOW){delay(10);}
      // Serialisation
      jsg_msg["btn_up"] = digitalRead(24);
      serializeJson(jsg_msg, Serial);
    }

    if(digitalRead(/26) == LOW)
    {
      while(digitalRead(26) == LOW){delay(10);}
      // Serialisation
      jsg_msg["btn_left"] = digitalRead(26);
      serializeJson(jsg_msg, Serial);
    }

    if(digitalRead(22) == LOW)
    {
      while(digitalRead(22) == LOW) {delay(10);}
      // Serialisation
      jsg_msg["btn_right"] = digitalRead(22);
      serializeJson(jsg_msg, Serial);
    }

    if(digitalRead(/**Pin à mettre*/) == LOW)
    {
      while(digitalRead() == LOW){delay(10);}
      
      // Serialisation
      jsg_msg["btn_select"] = digitalRead(/**Pin à mettre*/);
      serializeJson(jsg_msg, Serial);
    }

    jsg_msg["accelerometer"] = ReadAxis();

    jsg_msg["potentiometer_X"] = joystick.getX();
    jsg_msg["potentiometer_Y"] = joystick.getY();

    jsg_msg["motor"] = getMotorState();


    
    // Envoie
    Serial.println();
  }
  
  delay(10);  // delais de 10 ms
}

/*---------------------------Definition de fonctions ------------------------*/

void serialEvent() { shouldRead_ = true; }


/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void sendMsg() {
  StaticJsonDocument<500> doc;
  // Elements du message
  doc["time"] = millis();

  // Serialisation
  serializeJson(doc, Serial);

  // Envoie
  Serial.println();
  shouldSend_ = false;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
void readMsg(){
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;

  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(doc, Serial);
  shouldRead_ = false;

  // Si erreur dans le message
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  // Analyse des éléments du message message
  parse_msg = doc["led"];
  if (!parse_msg.isNull()) {
    // mettre la led a la valeur doc["led"]
    digitalWrite(pinLED,doc["led"].as<bool>());
  }
}