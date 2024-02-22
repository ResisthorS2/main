/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
*/

/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include "myLibraries/test.h"
#include "C:\Users\arthu\OneDrive\Universite\Udes\S2\Projet\Code_Arduino_PC\main\Arduino\myLibraries\param.h"

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 9600        // Frequence de transmission serielle

/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message

int ledState = 0;
int potValue = 0;

int pinLED = 7;
int pinPOT = A0;


/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(); 
void readMsg();
void serialEvent();
/*---------------------------- Fonctions "Main" -----------------------------*/

void setup() {
  Serial.begin(BAUD);               // Initialisation de la communication serielle
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, ledState);

  Pin pin;

  //bouton
  pinMode(pin.btn_devant, INPUT_PULLUP);
  pinMode(pin.btn_droit, INPUT_PULLUP);
  pinMode(pin.btn_gauche, INPUT_PULLUP);
  pinMode(pin.btn_180, INPUT_PULLUP);


}

/* Boucle principale (infinie) */
void loop() {
  StaticJsonDocument<500> doc;

  int bouton = test_bouton();     // debug
  doc["BoutonON"] = bouton;
  
  
  serializeJson(doc, Serial);
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
  doc["analog"] = potValue;

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