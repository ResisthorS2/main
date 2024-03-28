#include "../libs/minigames.h"
#include "../libs/activeCell.h"
#include <conio.h>
#include <windows.h>
using namespace std;
struct AxisState {
    int y = 0;
    int x = 0;
    int lastX = 1;
    int lastY = 1;
};
struct Position {
    int x = 0;
    int y = 0;
    int lastX = 1;
    int lastY = 1;
};
struct SolderState {
    bool pin1 = 0;
    bool pin2 = 0;
    bool pin3 = 0;
    bool pin4 = 0;
};
int gameState = 1;
void UpdateAxis(AxisState& axisState, Engine* engine) {
    
    engine->j_msg_rcv = engine->updateComponents(engine->arduino, engine->j_msg_rcv);
    axisState.x = 0;
    axisState.y = 0;

    if (engine->j_msg_rcv["accelerometer_Y"] < -0.2) {
        axisState.y = 1;
    } else if (engine->j_msg_rcv["accelerometer_Y"] > 0.2) {
        axisState.y = -1;
    }

    if (engine->j_msg_rcv["accelerometer_Z"]  > 0.2) {
        axisState.x = -1;
    } else if (engine->j_msg_rcv["accelerometer_Z"]  < -0.2) {
        axisState.x = 1;
    }
    if (GetAsyncKeyState('q') & 0x8000) {
        gameState = 0;
    }
}
void printValues(AxisState& axisState, Position& pos, SolderState& solder){
    cout << "You have two resistor to solder try to be as precise as possible" << endl;
    cout << "Here are their positions:" << endl;
    cout << "    Pin 1: (10,10)";
    if(solder.pin1 == 1)
        cout << " SOLDER COMPLETED" << endl;
    else
        cout << "" << endl;

    cout << "    Pin 2: (10,15)";
    if(solder.pin2 == 1)
        cout << " SOLDER COMPLETED" << endl;
    else
        cout << "" << endl;
    cout << "    Pin 3: (0,15)";
    if(solder.pin3 == 1)
        cout << " SOLDER COMPLETED" << endl;
    else
        cout << "" << endl;
    cout << "    Pin 4: (50,50)";
    if(solder.pin4 == 1){
        cout << " SOLDER COMPLETED" << endl;
        Sleep(3000);
        gameState = 0;
    }
    else
        cout << "" << endl;
    cout <<""<<endl;
    cout << "X = " << axisState.x << ", Y = " << axisState.y << endl;
    cout << "POSX = " << pos.x << ", POSY = " << pos.y << endl;
}
int MiniGame::play_solderGame(int key[6], int cell_type, Engine* engine) {
    AxisState axisState;
    Position pos;
    SolderState solder;
    int solderTimer = 0;
    int delay = 20;
    while(gameState)
    {
        UpdateAxis(axisState,engine);
        if(axisState.x != axisState.lastX || axisState.y != axisState.lastY){
            system("cls");
            printValues(axisState, pos, solder);
        }
        axisState.lastX = axisState.x;
        axisState.lastY = axisState.y;
        if(axisState.x == -1 && pos.x > 0)  
            pos.x -= 1;
        else if(axisState.x == 1 && pos.x < 1022)
            pos.x += 1;
        if(axisState.y == -1 && pos.y > 0)  
            pos.y -= 1;
        else if(axisState.y == 1 && pos.y < 1023)
            pos.y += 1;
        
        if(pos.x != pos.lastX || pos.y != pos.lastY){
            system("cls");
            printValues(axisState, pos, solder);
        }
        pos.lastX = pos.x;
        pos.lastY = pos.y;

        if(pos.x >= 8 && pos.x <= 12 && pos.y <= 12 && pos.y >= 8){
            solderTimer +=1;
            if(pos.x >= 8 && pos.x <= 12 && pos.y <= 12 && pos.y >= 8 && solderTimer == delay){
                solderTimer = 0;
                solder.pin1 = 1;
                system("cls");
                printValues(axisState, pos, solder);
            }
        }
        else if(pos.x >= 8 && pos.x <= 12 && pos.y <= 17 && pos.y >= 13){
            solderTimer +=1;
            if(pos.x >= 8 && pos.x <= 12 && pos.y <= 17 && pos.y >= 13 && solderTimer == delay){
                solderTimer = 0;
                solder.pin2 = 1;
                system("cls");
                printValues(axisState, pos, solder);
            }
        }
        else if(pos.x >= 0 && pos.x <= 4 && pos.y <= 17 && pos.y >= 13){
            solderTimer +=1;
            if(pos.x >= 0 && pos.x <= 4 && pos.y <= 17 && pos.y >= 13 && solderTimer == delay){
                solderTimer = 0;
                solder.pin3 = 1;
                system("cls");
                printValues(axisState, pos, solder);
            }
        }
        else if(pos.x >= 48 && pos.x <= 52 && pos.y <= 52 && pos.y >= 48){
            solderTimer +=1;
            if(pos.x >= 48 && pos.x <= 52 && pos.y <= 52 && pos.y >= 48 && solderTimer == delay){
                solderTimer = 0;
                solder.pin4 = 1;
                system("cls");
                printValues(axisState, pos, solder);
            }
        }
        else{
            solderTimer = 0;
        }
        
        Sleep(15);
    }
    engine->addObjects(key, 3016);
    return gameState;
}