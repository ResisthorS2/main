/*
 * Auteurs: Jean-Samuel Lauzon
 * Date: Fevrier 2022
 */

/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include "../myLibraries/components.h"

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 9600 // Frequence de transmission serielle

/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false; // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false; // Drapeau prêt à lire un message

int pinLED = 38;

/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg();
void readMsg();
void serialEvent();
/*---------------------------- Fonctions "Main" -----------------------------*/

void setup()
{
    Serial.begin(BAUD); // Initialisation de la communication serielle
    pinMode(pinLED, OUTPUT);
    digitalWrite(pinLED, 1);

    pinMode(22, INPUT_PULLUP);
}

JoyStick joystick;
Accelerometer accelerometer;
Motor motor;
Pin pin;


/* Boucle principale (infinie) */
void loop()
{

    // Lecture du message Json
    
    /**JsonVariant parse_msg;

    // Lecture sur le port Seriel
    DeserializationError error = deserializeJson(jsg_msg, Serial);
    shouldRead_ = false;

    // Si erreur dans le message
    if (error)
    {
        Serial.print("deserialize() failed: ");
        Serial.println(error.c_str());
        return;
    }

    // Analyse des éléments du message message
    parse_msg = jsg_msg["led"];
    if (!parse_msg.isNull())
    {
        // mettre la led a la valeur doc["led"]
        digitalWrite(pinLED, jsg_msg["led"].as<bool>());
    }**/

    
    StaticJsonDocument<1000> jsg_msg;
    //jsg_msg["led"] = 0;
    jsg_msg["btn_180"] = 0;
    jsg_msg["btn_up"] = 0;
    jsg_msg["btn_left"] = 0;
    jsg_msg["btn_right"] = 0;
    jsg_msg["btn_select"] = 0;
    //jsg_msg["accelerometer_X"] = 0;
    //jsg_msg["accelerometer_Y"] = 0;
    //jsg_msg["accelerometer_Z"] = 0;
    //jsg_msg["potentiometer_X"] = 0;
    //jsg_msg["potentiometer_Y"] = 0;
    //jsg_msg["motor"] = 0;

    int state = 0;

    if (digitalRead(53) == LOW)
    {
        while (digitalRead(53) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_180"] =  1;
        state = 1;

    }

    if (digitalRead(51) == LOW)
    {
        while (digitalRead(51) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_up"] =  1;
        state = 1;
 
    }

    if (digitalRead(48) == LOW)
    {
        while (digitalRead(48) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_left"] =  1;
        state = 1;

    }

    if (digitalRead(50) == LOW)
    {
        while (digitalRead(50) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_right"] =  1;
        state = 1;

    }

    if (digitalRead(39) == LOW)
    {
        while (digitalRead(39) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_select"] = 1;
        state = 1;

    }
    /**
    Acceleration accel = accelerometer.ReadAxis();
    jsg_msg["accelerometer_X"] = accel.x;
    jsg_msg["accelerometer_Y"] = accel.y;
    jsg_msg["accelerometer_Z"] = accel.z;

    jsg_msg["potentiometer_X"] = joystick.getX();
    jsg_msg["potentiometer_Y"] = joystick.getY();

    // jsg_msg["motor"] = motor.getMotorState()+'0';
    jsg_msg["motor"] = 0;*/

    // Envoie
    if(state == 1)
    {
        serializeJson(jsg_msg, Serial);
        Serial.println();
    }
    

    delay(200); // delais de 10 ms**/
}

/*---------------------------Definition de fonctions ------------------------*/

void serialEvent() { shouldRead_ = true; }

/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void sendMsg()
{
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
void readMsg()
{
    // Lecture du message Json
    StaticJsonDocument<500> doc;
    JsonVariant parse_msg;

    // Lecture sur le port Seriel
    DeserializationError error = deserializeJson(doc, Serial);
    shouldRead_ = false;

    // Si erreur dans le message
    if (error)
    {
        Serial.print("deserialize() failed: ");
        Serial.println(error.c_str());
        return;
    }

    // Analyse des éléments du message message
    parse_msg = doc["led"];
    if (!parse_msg.isNull())
    {
        // mettre la led a la valeur doc["led"]
        digitalWrite(pinLED, doc["led"].as<bool>());
    }
}