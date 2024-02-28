/*
	S'ASSURER QUE LA HAUTEUR ET LA LARGEUR SOIT BIEN DÉFINIS DANS MAP.TXT
*/

#ifndef MAP_H
#include "map.h"
#endif





#include <fstream>
#include <string>
#include <iostream>
#include <sstream>





Map::Map()
{
	std::ifstream carte("map.txt");
	if (carte.fail()) {
		std::cerr << "Erreur d'ouverture du fichier" << std::endl;
		// Gérer l'erreur ici, peut-être en quittant la fonction ou en lançant une exception
	}
	std::string lecture;

	orientation = east;


	std::getline(carte, lecture);
	//Ramasse la hauteur de la map dans le fichier map
		hauteur = std::stoi(lecture);	

	std::cout<< "Hauteur : " <<hauteur<<std::endl;

	std::getline(carte, lecture);

		largeur = std::stoi(lecture);				//Ramasse la largeur de la map dans les fichiers
	
	std::cout<< "Largeur : " <<largeur<<std::endl;

	// Créer un tableau de pointeurs
	this->cell = new Cell*[largeur];

	// Pour chaque pointeur, créer un tableau
	for(int i = 0; i < largeur; i++) 
	{
		cell[i] = new Cell[hauteur];
	}			//Cree le tableau de cellule de la map

	coordonne = new int*[hauteur];					//Cree le tableau des coordonne de cases de la map
	for (int i = 0; i < hauteur; ++i) 
	{
		coordonne[i] = new int[largeur];
	}

	for(int y=0; y<hauteur; y++)					//Assigne le fichier de map au tableau coordonne
	{
		for(int x=0; x<largeur;x++)
			{
				if(x==largeur-1)
				{
					std::getline(carte, lecture);
				}
				
				else if(x<largeur-1)
				{ 
					std::getline(carte, lecture, '\t');
				}
				coordonne[x][y] = std::stoi(lecture);
				int type = std::stoi(lecture);
				cell[x][y] = Cell(type);
			}
	}

	for(int y=0; y<hauteur; y++)					//Assigne le fichier de map au tableau coordonne
	{
		for(int x=0; x<largeur;x++)
			{
				if
			}
	}


	for(int i=0;i<maxRoom;i++)
	{	
		cle[i]=0;
	}


}

Map::~Map()
{
	std::cout<<"Destruction de la map"<<std::endl;
	for (int i = 0; i < hauteur; ++i) 
	{
    	delete[] cell[i];
	}

	delete[] cell;
	
	for (int i = 0; i < hauteur; ++i) 
	{
    	delete[] coordonne[i];
	}

	delete[] coordonne;

}


void Map::enterCell()
{
	
}



void Map::printMap()
{
	//system("cls");
	

	
	for(int y=0;y<hauteur;y++)
	{
		for(int i=0;i<3;i++)
		{
			for(int x=0;x<largeur;x++)
			{
				std::cout << cell[x][y].printCellTerminal(i);
				
			}
			std::cout << std::endl;
		}
		
	}
	std::cout << "\x1b[0m" <<std::endl;


}


int Map::getOrientation()
{
	return orientation;
}

void Map::addCle(int index)
{
	cle[index]=index;
}

void Map::removeCle(int index)
{
	cle[index]=0;
}

bool Map::verifCle(int index)
{
	if(index==cle[index])
	{
		return true;
	} else return false;
}


bool Map::turn180()
{
	switch (orientation)
	{
	case north:
		orientation=south;
		return true;
		break;

	case east:
		orientation=west;
		return true;
		break;

	case south:
		orientation=north;
		return true;
	case west:
		orientation=east;
		return true;

	default:
		return false;
		break;
	}
	return false;
}


void Map::setOrientation(int SETorientation)
{
	orientation=SETorientation;
}

void Map::updateMap()
{
	
	for(int y=0;y<this->hauteur;y++)
	{
		for(int x=0;x<this->largeur;x++)
		{
			//std::cout<<"coordonne["<< x << "]["<<y<<"]"<<coordonne[x][y]<<std::endl;
			cell[x][y].setImageCell(coordonne[x][y], NONE);
		}
	}
	std::cout << "orientation = " <<getOrientation() << std::endl;
	cell[getCo_X()][getCo_Y()].setImageCell(cell[getCo_X()][getCo_Y()].getType(), getOrientation()); //mettre l'orientation dans le bonhomme
	
}

