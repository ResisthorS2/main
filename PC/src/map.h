/*
	ATTENTIONS SI + DE 20 ROOM NE PAS OUBLIER D'AUGMENTER MAXROOM
*/

#ifndef MAP_H
#define MAP_H


#include "cell.h"



#include "player.h"




//#include <vector>


class Map
{
public:
	Map();
	~Map();			
	void printMap();				//Affiche la map
	void addCle(int index);			//Permet d'ajouter l'acces à une piece
	void removeCle(int index);		//Permet d'enlever l'acces à une piece
	bool verifCle(int index);		//Permet de vérifier si la pièce est accessible
	void updateMap();
	Cell ***cell;
	Player *playerInCell;
	int largeur; //faire une fonction pour les gets
	int hauteur; //faire une fonction pour le gets
	//Cell* operator[](int index);


private:
	int **coordonne;			//Tableau de coordonne coordonne[Y][X]
	int cle[maxRoom];				//La cste maxROOM doit être changer si on fait plus de room que celle-si
};
#endif

