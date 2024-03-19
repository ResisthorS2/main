Le fichier map.txt est le fichier qui définis la map en elle même. 

La première ligne est la hauteur de la carte.
La deuxième ligne est la largeur de la carte

Les cases:
0 case vide
1 case couloir
2 case avec porte Nord
3 case avec porte Sud
4 case avec porte Est
5 case avec porte Ouest
12 case avec porte Nord barré
13 case avec porte Sud barré
14 case avec porte Est barré
15 case avec porte Ouest barré
6 case intersections 



COMPILATION:
***Il faut que vous soyer dans le directory PC. Donc faites cd PC si ça ne marche pas
g++ .\main.cpp .\include\serial\SerialPort.cpp .\src\map.cpp .\src\cells_code\cell.cpp .\src\cells_code\activeCell.cpp .\src\cells_code\intersection.cpp .\src\cells_code\gameCell.cpp .\src\minigames_code\game_resistance.cpp 
./a.exe


COMMENT AJOUTER UN MINI JEU
***Dans le fichier .cpp de votre mini jeu
-mettre le fichier du mini-jeux dans le dossier minigames_code
-modifier la fonction à appeler pour faire le mini-jeu pour qu'elle fasse partie de la classe MiniGame
ex pour la fonction play_resistanceGame(), elle devient MiniGame::play_resistanceGame() ***dans le fichier du minijeu
-include dans le fichier du minijeu; #include "../libs/minigames.h" pour avoir accès au header des minijeux
***Dans le fichier minigames.h
-ajouter la fonction de votre minijeu. Nous pourrons donc appeler votre fonction avec la classe MiniGame
ex pour play_resistanceGame():
class MiniGame
{
    public:
    ...
        int play_resistanceGame();
        //ajouter votre fonction ici
};
