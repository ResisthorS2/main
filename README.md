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
g++ .\main.cpp .\include\serial\SerialPort.cpp .\src\map.cpp .\src\cell.cpp .\src\activeCell.cpp .\src\intersection.cpp .\src\gameCell.cpp
./a.exe
