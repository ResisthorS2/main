#include "../libs/minigames.h"
#include <stdlib.h>
#include <windows.h>
#define SINE 1
#define SQUARE 2
#define TRIANGLE 3

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

using namespace std;
struct {
    string sine;
    string square;
    string triangle;
}fct;

enum fctState{
    noisy = 1,
    lessNoisy = 2,
    almostClear = 3,
    clear = 4
};

int MiniGame::play_oscilloscopeGame(int key[6], int cell_type, Engine* engine) {
    
    
    fct.sine = "Sine";
    fct.square = "Square";
    fct.triangle = "Triangle";
    system("cls");
    srand(time(0)); // Initialisation du generateur de nombres aleatoires avec le temps actuel
    // Generation d'un nombre aleatoire entre 1 et 3
    int random = 1 + (rand() % 2);
    fctState fonctionState = noisy;
    int gameState = 1;
    while(gameState)
    {
        engine.updateComponents(j_msg_rcv["potentiometer"]);
        int potVal = engine->input->potentiometer;
        string fonction;
        switch (random)
        {
        case SINE:
            fonction = fct.sine;
            break;
        case SQUARE:
            fonction = fct.square;
            break;
        case TRIANGLE:
            fonction = fct.triangle;
            break;
        }
        
        switch (fonctionState)
        {
        case noisy:
            cout << "****"<< fonction <<" Wave With noise****" << endl;
            cout << "****";
            cout << RED << "Light" << RESET;
            cout <<":";
            cout << RED << "Light" << RESET;
            cout <<":";
            cout << RED << "Light" << RESET;
            cout << "****"<< endl;
            cout << "Ajust potentiometer to clarify " << fonction << " Wave." << endl;
            break;
        case lessNoisy:
            system("cls");
            cout << "****"<< fonction <<" Wave With less noise****" << endl;
            cout << "****";
            cout << GREEN << "Light" << RESET;
            cout <<":";
            cout << RED << "Light" << RESET;
            cout <<":";
            cout << RED << "Light" << RESET;
            cout << "****"<< endl;
            cout << "Ajust potentiometer to clarify " << fonction << " Wave." << endl;
            break;
        case almostClear:
            system("cls");
            cout << "****"<< fonction <<" Wave With almost no noise****" << endl;
            cout << "****";
            cout << GREEN << "Light" << RESET;
            cout <<":";
            cout << GREEN << "Light" << RESET;
            cout <<":";
            cout << RED << "Light" << RESET;
            cout << "****"<< endl;
            cout << "Ajust potentiometer to clarify " << fonction << " Wave." << endl;
            break;
        case clear:
            system("cls");
            cout << "****"<< fonction <<" Wave With no noise****" << endl;
            cout << "****";
            cout << GREEN << "Light" << RESET;
            cout <<":";
            cout << GREEN << "Light" << RESET;
            cout <<":";
            cout << GREEN << "Light" << RESET;
            cout << "****"<< endl;
            cout << "You have succeded to clarify the " << fonction << " Wave." << endl;
            gameState = 0;
            Sleep(5000);
            break;
        }

        // pot val goes from 0 to 1024
        if (potVal == 1000 && fonctionState == noisy) {
            fonctionState = lessNoisy;
        } else if(potVal == 10 && fonctionState == lessNoisy){
            fonctionState = almostClear;
        } else if(potVal == 500 && fonctionState == almostClear){
            fonctionState = clear;
        }
    }
    return 0;
    // Fin du jeu sans erreur
}