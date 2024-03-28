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


    pinMode(36, OUTPUT);
    pinMode(35, OUTPUT);
    pinMode(34, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(32, OUTPUT);
    pinMode(31, OUTPUT);

    pinMode(22, INPUT_PULLUP);
}

JoyStick joystick;
Accelerometer accelerometer;
Motor motor;
Pin pin;
int btnStateUp = 1;
int btnStateDown = 1;
int btnStateRight = 1;
int btnStateLeft = 1;
int btnStateCenter = 1;
int joyState_X = 1;
int joyState_Y = 1;
int motorState = 1;
int accSate_X = 1;
int accSate_Y = 1;
int accSate_Z = 1;
int potState = 1;




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
    jsg_msg["led"] = 0;
    Acceleration accel = accelerometer.ReadAxis();
    jsg_msg["accelerometer_X"] = accel.x;
    jsg_msg["accelerometer_Y"] = accel.y;
    jsg_msg["accelerometer_Z"] = accel.z;
    jsg_msg["joystick_X"] = joystick.getX();
    jsg_msg["joystick_Y"] = joystick.getY();
    jsg_msg["potentiometer"] = analogRead(0);
    jsg_msg["btn_180"] = digitalRead(53);
    jsg_msg["btn_up"] = digitalRead(51);
    jsg_msg["btn_left"] = digitalRead(48);
    jsg_msg["btn_right"] = digitalRead(50);
    jsg_msg["btn_select"] = digitalRead(52);

    digitalWrite(35, jsg_msg["btn_180"]);
    digitalWrite(33, jsg_msg["btn_up"]);
    digitalWrite(31, jsg_msg["btn_left"]);
    digitalWrite(32, jsg_msg["btn_right"]);
    digitalWrite(36, jsg_msg["btn_select"]);




    /**if (digitalRead(53) == LOW)
    {
        while (digitalRead(53) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_180"] =  1;

    }

    if (digitalRead(51) == LOW)
    {
        while (digitalRead(51) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_up"] =  1;
 
    }

    if (digitalRead(48) == LOW)
    {
        while (digitalRead(48) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_left"] =  1;

    }

    if (digitalRead(50) == LOW)
    {
        while (digitalRead(50) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_right"] =  1;

    }

    if (digitalRead(39) == LOW)
    {
        while (digitalRead(39) == LOW)
        {
            delay(10);
        }

        // Serialisation
        jsg_msg["btn_select"] = 1;

    }**/
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
    if(jsg_msg["btn_180"] != btnStateDown || jsg_msg["btn_up"] != btnStateUp || jsg_msg["btn_left"] != btnStateLeft || jsg_msg["btn_right"] != btnStateRight || jsg_msg["btn_select"] != btnStateCenter || jsg_msg["joystick_X"] != joyState_X || jsg_msg["joystick_Y"] != joyState_Y || jsg_msg["accelerometer_X"] != accSate_X || jsg_msg["accelerometer_Y"] != accSate_Y || jsg_msg["accelerometer_Z"] != accSate_Z || jsg_msg["potentiometer"] != potState)
    {
        serializeJson(jsg_msg, Serial);
        Serial.println();
    }


    btnStateCenter = jsg_msg["btn_select"];
    btnStateDown = jsg_msg["btn_180"];
    btnStateUp = jsg_msg["btn_up"];
    btnStateLeft = jsg_msg["btn_left"];
    btnStateRight = jsg_msg["btn_right"];
    joyState_X = jsg_msg["joystick_X"];
    joyState_Y = jsg_msg["joystick_Y"];
    accSate_X = jsg_msg["accelerometer_X"];
    accSate_Y = jsg_msg["accelerometer_Y"];
    accSate_Z = jsg_msg["accelerometer_Z"];
    potState = jsg_msg["potentiometer"];




    

    delay(100); // delais de 10 ms**/
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