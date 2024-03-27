#include "../libs/minigames.h"


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>



int random_labo(int base)     //Génère un chiffre aleatoire entre 0 et base ( inclut 0 et exclut base)
{
/*
Note utiliser ce code ralentit l'exécution du code car time(NULL) varie très lentements donc la fonction revoit plusieurs fois d'affiller le même nombre
car la seed ne change pas.
*/
    using namespace std;
    srand(time(NULL));
    return rand() % base;

}


int MiniGame::play_laboGame(){

    int nombre_aleatoire=5;
    int nombre_phrase=8;
    
    int nombre_mots=0;
    using namespace std;
    vector<string> mots;
    ifstream question("labo.txt");


    if (question.fail()) {
        cerr << "Erreur d'ouverture du fichier" << std::endl;
        return -1;
    }
    
    string lecture;


    getline(question, lecture);
    

    question.close();

    stringstream ss(lecture);
    std::string mot;
    
    while (ss >> mot) {         //Sépare la phrase en plusieurs mots
        nombre_mots++;
        mots.push_back(mot);
    }

    vector<int> position_mots;
    
    cout<<"Programmer un programme pour imprimer Hello word en C"<<endl;

    int index = 0;

    while(index < 5){                                       //Scramble les mots
        int position = random_labo(5);
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
        cout << mots[position_mots[y]] << "  :  ";
    }
    cout<<endl;

    string CYAN   = "\x1b[36m";      /* Cyan */
    string YELLOW = "\x1b[33m";      /* Yellow */
    string RESET =  "\033[0m";

    int pointeur= 1;
    int count=0;
    while(count<5)
    {
        system("cls");
        cout<<"Programmer un programme pour imprimer Hello word en C"<<endl;
        cout<<" Fonction connue : "<<endl;
        cout<< YELLOW;
        for(int y=0 ; y<position_mots.size(); y++)
        {
            if(y==(pointeur-1)){
                cout << CYAN << mots[position_mots[y]] << "  :  " << YELLOW ;
            }else cout << mots[position_mots[y]] << "  :  ";
        }

        cout<< RESET << endl;
        cout<<endl;


        cout<<" Ce que vous avez ecris : "<<endl;
        for(int y=0 ; y<count; y++)
        {
            cout << mots[y];
        }

        cout<<endl;

        cout<<"Utiliser a ou d pour deplacer le pointeur et selectionner avec w"<<endl;

        string clavier;

        cin>>clavier;

        if(clavier == "a"){
            if(pointeur>1){
                pointeur--;
            }
        }

        if(clavier == "d"){
            if(pointeur<5){
                pointeur++;
            }
        }
        
        if(clavier == "w"){
            if(count == position_mots[pointeur - 1]){
                count++;
            }
        }
        
    }

    cout << "Felicitations vous avez reussis"<<endl;
    cout << "Voici votre code : "<<endl;
    for(int y=0 ; y<count; y++)
    {
        cout << mots[y]<< " ";
    }

    cout<<endl;


    system("cls");

    cout<<"L'ordianteur de l'universite a planter, relancer l'ordinateur en appuyant sur une touche"<<endl;

    string reset_ordi;

    cin>> reset_ordi;

    cout<<"Redémarage en cours"<<endl;

    system("cls");
    cout<< "Ordi allumé"<< endl;

    system("cls");
    cout<< "Execution du programme"<< endl;
    cout << "Voici votre code : "<<endl;
    for(int y=0 ; y<count; y++)
    {
        cout << mots[y]<< " ";
    }

    cout<<endl;

    cout<<"Voici la sortie console : "<<endl;

    cout<< "Hello word"<<endl;

    cout << "Appuyer sur une touche afin de retourner sur la carte" << endl;


    return 0;
}