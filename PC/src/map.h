/*
	ATTENTIONS SI + DE 20 ROOM NE PAS OUBLIER D'AUGMENTER MAXROOM
*/


#define MAP_H

#ifndef CELL_H
#include "cell.h"
#endif

#ifndef PLAYER_H
#include "player.h"
#endif



//#include <vector>


class Map
{
public:
	Map();
	~Map();
	void setCoordonne(int x, int y);
	void setOrientation(int orientation);
	int getCo_X();			//Donne la coordonne X
	int getCo_Y();			//Donne la coordonne Y
	int getOrientation();			//Donne l'orientation
	bool turn180();				
	void printMap();				//Affiche la map
	void addCle(int index);			//Permet d'ajouter l'acces à une piece
	void removeCle(int index);		//Permet d'enlever l'acces à une piece
	bool verifCle(int index);		//Permet de vérifier si la pièce est accessible
	void enterCell();				//Sert à mes fonction de mouvement et exitPiece
	void updateMap();
	Cell **cell;
	Player *playerInCell;
	int largeur; //faire une fonction pour les gets
	int hauteur; //faire une fonction pour le gets
	//Cell* operator[](int index);


private:
	int **coordonne;			//Tableau de coordonne coordonne[Y][X]
	int cle[maxRoom];				//La cste maxROOM doit être changer si on fait plus de room que celle-si
};

