#include <Arduino.h>
#include "C:\Users\arthu\OneDrive\Universite\Udes\S2\Projet\RetrouverP15\Map\lib\test.h"

#ifndef PARAM_H
#include "C:\Users\arthu\OneDrive\Universite\Udes\S2\Projet\RetrouverP15\Map\lib\param.h"
#endif

#define RED     "\x1b[31m"      /* Red */
#define GREEN   "\x1b[32m"      /* Green */




int test_bouton()
{
    Pin pin;
    while(1)
    {
        Serial.print("XXX\n");
        if(digitalRead(pin.btn_180) == LOW)
            {
                while(digitalRead(pin.btn_180) == LOW)
                {
                    delay(50);
                }
                Serial.print("BTN_180 - HIGH\n");
                return 28;
            }

        if(digitalRead(pin.btn_gauche) == LOW)
            {
                while(digitalRead(pin.btn_gauche) == LOW)
                {
                    delay(50);
                }
                Serial.print("BTN_GAUCHE - HIGH\n");
                return 26;
            }

        if(digitalRead(pin.btn_droit) == LOW)
            {
                while(digitalRead(pin.btn_droit) == LOW)
                {
                    delay(50);
                }
                Serial.print("BTN_DROIT - HIGH\n");
                return 24;
            }

        if(digitalRead(pin.btn_devant) == LOW)
            {
                while(digitalRead(pin.btn_devant) == LOW)
                {
                    delay(50);
                }
                Serial.print("BTN_DEVANT - HIGH\n");
                return 22;
            }

        if(digitalRead(pin.btn_180) == LOW && digitalRead(pin.btn_gauche) == LOW)
            {
                return;
            }
            

        delay(50);
    }
}

