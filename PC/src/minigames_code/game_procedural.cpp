#include "../libs/minigames.h"
#include "../libs/engine.h"
#include "../libs/globalVar.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>

std::string question[]= 
{
"calculez la derivee de f(x)",
"utiliser les series de fourrier",
"le make file est-il fonctionnele",
"utiliser un filtre passe bas",
"utilliser un filtre passe haut",
"utiliser un filtre passe bande",
"faire une simulation monte carlo",
"calculez la fonction de transfert"
};


int random_procedural(int base)     //Génère un chiffre aleatoire entre 0 et base ( inclut 0 et exclut base)
{
/*
Note utiliser ce code ralentit l'exécution du code car time(NULL) varie très lentements donc la fonction revoit plusieurs fois d'affiller le même nombre
car la seed ne change pas.
*/
    using namespace std;
    srand(time(NULL));
    return rand() % base;

}


int MiniGame::play_proceduralGame(int key[6], int cell__type, Engine* engine)
{

    int nombre_aleatoire=5;
    int nombre_phrase=8;
    
    int nombre_mots=0;
    using namespace std;
    vector<string> mots;

    
    string lecture;

    lecture = question[random_procedural(nombre_phrase)];


    stringstream ss(lecture);
    std::string mot;
    
    while (ss >> mot) {         //Sépare la phrase en plusieurs mots
        nombre_mots++;
        mots.push_back(mot);
    }

    vector<int> position_mots;
    
    std::cout<<"Arranger les mots suivants dans le bon ordre"<<std::endl;

    int index = 0;

    while(index < 5){                                       //Scramble les mots
        int position = random_procedural(5);
        if(position_mots.size() ==0){                       // Ajoute le premier mots
            position_mots.push_back(position);
            index++;
        }

        bool verif = true;
        for(int j = 0; j < position_mots.size(); j++){      //Vérifie si position est dans le vecteur qui contient l'ordre des positions 
            if(position_mots[j] == position){
                verif = false;
            }
        }

        if(verif){                                          //Si la position n'est pas dans le vecteur ajoute la position
            position_mots.push_back(position);
            index++;
        }
    }

    for(int y=0 ; y<position_mots.size(); y++)
    {
        std::cout << mots[position_mots[y]] << "  :  ";
    }
    std::cout<<std::endl;

    string CYAN   = "\x1b[36m";      /* Cyan */
    string YELLOW = "\x1b[33m";      /* Yellow */
    string RESET =  "\033[0m";

    int pointeur= 1;
    int count=0;
    while(count<5)
    {
        engine->j_msg_rcv = engine->updateComponents(engine->arduino, engine->j_msg_rcv);
        system("cls");
        std::cout<<" Ordre melanger : "<<std::endl;
        std::cout<< YELLOW;
        for(int y=0 ; y<position_mots.size(); y++)
        {
            if(y==(pointeur-1)){
                std::cout << CYAN << mots[position_mots[y]] << "  :  " << YELLOW ;
            }else std::cout << mots[position_mots[y]] << "  :  ";
        }

        std::cout<< RESET << std::endl;
        std::cout<<std::endl;


        std::cout<<" Ordre organise : "<<std::endl;
        for(int y=0 ; y<count; y++)
        {
            std::cout << mots[y] << "  :  ";
        }

        std::cout<<std::endl;

        std::cout<<"Utiliser a ou d pour déplacer le pointeur et sélectionner avec w"<<std::endl;

        if(engine->j_msg_rcv["btn_left"] == 0)
        {
            if(pointeur>1){
                pointeur--;
            }
        }

        if(engine->j_msg_rcv["btn_right"] == 0){
            if(pointeur<5){
                pointeur++;
            }
        }
        
        if(engine->j_msg_rcv["btn_select"] == 0){
            if(count == position_mots[pointeur - 1]){
                count++;
            }
        }
    }

/*
=============================================================================================================================================
allumer les LED
=============================================================================================================================================
*/

    

    std::cout << "Felicitations vous avez reussis"<<std::endl;
    std::cout << "Voici la phrase : "<<std::endl;
    for(int y=0 ; y<count; y++)
    {
        std::cout << mots[y]<< " ";
    }

    std::cout<<std::endl;

    std::cout << "Appuyer sur une touche afin de retourner sur la carte" << std::endl;
    engine->addObjects(key, 3018);

    return 0;
    
}