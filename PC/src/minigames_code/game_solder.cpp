#include "../libs/minigames.h"
#include "../libs/activeCell.h"
#include <conio.h>
#include <windows.h>
using namespace std;
struct AxisState {
    int x = 0;
    int y = 0;
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
void UpdateAxis(AxisState& axisState) {
    axisState.x = 0;
    axisState.y = 0;

    if (GetAsyncKeyState('A') & 0x8000) {
        axisState.x = -1;
    } else if (GetAsyncKeyState('D') & 0x8000) {
        axisState.x = 1;
    }

    if (GetAsyncKeyState('W') & 0x8000) {
        axisState.y = 1;
    } else if (GetAsyncKeyState('S') & 0x8000) {
        axisState.y = -1;
    }
    if (GetAsyncKeyState('q') & 0x8000) {
        gameState = 0;
    }
}
void printValues(AxisState& axisState, Position& pos, SolderState& solder){
    cout << "You have two resistor to solder try to be as precise as possible" << endl;
    cout << "Here are their positions:" << endl;
    cout << "    Pin 1: (400,150)";
    if(solder.pin1 == 1)
        cout << " SOLDER COMPLETED" << endl;
    else
        cout << "" << endl;

    cout << "    Pin 2: (100,650)";
    if(solder.pin2 == 1)
        cout << " SOLDER COMPLETED" << endl;
    else
        cout << "" << endl;
    cout << "    Pin 3: (700,150)";
    if(solder.pin3 == 1)
        cout << " SOLDER COMPLETED" << endl;
    else
        cout << "" << endl;
    cout << "    Pin 4: (400,650)";
    if(solder.pin4 == 1)
        cout << " SOLDER COMPLETED" << endl;
    else
        cout << "" << endl;
    cout <<""<<endl;
    cout << "X = " << axisState.x << ", Y = " << axisState.y << endl;
    cout << "POSX = " << pos.x << ", POSY = " << pos.y << endl;
}
int MiniGame::play_solderGame(ActiveCell*a_cell) {
    AxisState axisState;
    Position pos;
    SolderState solder;
    int solderTimer = 0;
    while(gameState)
    {
        UpdateAxis(axisState);
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

        if(pos.x == 400 && pos.y == 150){
            solderTimer +=1;
            if(pos.x == 400 && pos.y == 150 && solderTimer == 333){
                solderTimer = 0;
                solder.pin1 = 1;
                system("cls");
                printValues(axisState, pos, solder);
            }
        }
        else if(pos.x == 100 && pos.y == 650){
            solderTimer +=1;
            if(pos.x == 100 && pos.y == 650 && solderTimer == 333){
                solderTimer = 0;
                solder.pin2 = 1;
                system("cls");
                printValues(axisState, pos, solder);
            }
        }
        else if(pos.x == 700 && pos.y == 150){
            solderTimer +=1;
            if(pos.x == 700 && pos.y == 150 && solderTimer == 333){
                solderTimer = 0;
                solder.pin3 = 1;
                system("cls");
                printValues(axisState, pos, solder);
            }
        }
        else if(pos.x == 400 && pos.y == 650){
            solderTimer +=1;
            if(pos.x == 400 && pos.y == 650 && solderTimer == 333){
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
    
    return gameState;
}
