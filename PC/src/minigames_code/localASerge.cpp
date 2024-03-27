#include "../libs/minigames.h"
#include <windows.h>
using namespace std;

struct WhoState {
    string who;
    string lastWho;
};
void printSentence(WhoState& whoState, string msg){
    if(whoState.who != whoState.lastWho)
        cout << whoState.who << ": ";
    else{
        for(int i = 0; i < whoState.who.length()+2; i++){
            cout << " ";
        }
    }
    whoState.lastWho = whoState.who;
    for(int i =0; i < msg.length(); i++){
        cout << msg[i];
        Sleep(100);
    }
    cout << endl;

}

int MiniGame::finLocalASerge(int key[6], int cell_type) {
    WhoState whoState;
    bool localASergeState = true;
    while(localASergeState){
        whoState.who = "Serge";
        printSentence(whoState, "Magnifique, qui l'aurait cru, un etudiant de S1 capable de reparer le robot.");
        printSentence(whoState, "Grace a toi, les visites au 5 a 8 de ton equipe vont pouvoir continuer.");
        printSentence(whoState, "Maintenant, allez-vous en! J'ai du travail a faire.");
        localASergeState = false;
        Sleep(3000);
    }
    return localASergeState;
}
int MiniGame::departLocalASerge() {
    WhoState whoState;
    bool localASergeState = true;
    while(localASergeState){
        whoState.who = "Serge";
        printSentence(whoState, "Comment c'est possible, ce robot n'est plus du tout fonctionnel.");
        printSentence(whoState, "Vous savez combien ca coute? 700$, 700$ de votre poche s'il ne revient pas en etat dans mes mains!");
        printSentence(whoState, "Vous etes chanceux, les locaux environnants peuvent vous aider a le reparer.");
        printSentence(whoState, "Commencez par vous instruire au 3041, on dirait un etudiant de genie en S1…");
        localASergeState = false;
        Sleep(3000);
    }
    return localASergeState;
}