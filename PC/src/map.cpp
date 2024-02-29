/*
	S'ASSURER QUE LA HAUTEUR ET LA LARGEUR SOIT BIEN DÉFINIS DANS MAP.TXT
*/


#include "map.h"






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


	std::getline(carte, lecture);
	//Ramasse la hauteur de la map dans le fichier map
		hauteur = std::stoi(lecture);	

	//std::cout<< "Hauteur : " <<hauteur<<std::endl;

	std::getline(carte, lecture);

		largeur = std::stoi(lecture);				//Ramasse la largeur de la map dans les fichiers
	
	//std::cout<< "Largeur : " <<largeur<<std::endl;

	// Créer un tableau de pointeurs

	this->cell = new Cell**[largeur];
	
	// Pour chaque pointeur, créer un tableau
	for(int i = 0; i < largeur; i++) 
	{
		cell[i] = new Cell*[hauteur];
	}			//Cree le tableau de cellule de la map
		
	coordonne = new int*[hauteur];					//Cree le tableau des coordonne de cases de la map
	for (int i = 0; i < hauteur; ++i) 
	{
		coordonne[i] = new int[largeur];
	}
	
	for(int y=0; y<hauteur; y++) {
		for(int x=0; x<largeur; x++) {
			std::getline(carte, lecture, x == largeur - 1 ? '\n' : ' ');
			coordonne[x][y] = std::stoi(lecture);
			int type = std::stoi(lecture);
			cell[x][y] = new Cell(type);
		}
	}

	for(int y=0; y<hauteur; y++)					//Assigne le fichier de map au tableau coordonne
	{
		for(int x=0; x<largeur;x++)
			{
				std::cout<<coordonne[x][y];
			}
		std::cout<<std::endl;
	}
	
	for(int x=0; x<largeur; x++)					//Assigne le fichier de map au tableau coordonne
	{
		for(int y=0; y<hauteur;y++)
			{	printf("type : %d\n", *cell[x][y]->getType());
				if(*cell[x][y]->getType()!=0)
				{	
					
					if(*cell[x][y+1]->getType()>0)
					{printf("1\n");cell[x][y]->setCellAround(south, cell[x][y+1]);printf("MovePossible South\n");}

					else// if(*cell[x][y+1]->getType()==0)
					{printf("2\n");cell[x][y]->setCellAround(south, NULL);}
					

					if(*cell[x][y-1]->getType()>0)
					{printf("3\n");cell[x][y]->setCellAround(north, cell[x][y-1]);printf("MovePossible North\n");}

					else// if(*cell[x][y-1]->getType()==0)
					{printf("4\n");cell[x][y]->setCellAround(north, NULL);}

					if(*cell[x+1][y]->getType()>0)
					{printf("5\n");cell[x][y]->setCellAround(east, cell[x+1][y]);printf("MovePossible East\n");}


					else// if(*cell[x+1][y]->getType()==0)
					{printf("6\n");cell[x][y]->setCellAround(east, NULL);}

					if(*cell[x-1][y]->getType()>0)
					{printf("7\n");cell[x][y]->setCellAround(west, cell[x-1][y]);printf("MovePossible West\n");}

					else// if(*cell[x-1][y]->getType()==0)
					{printf("8\n");cell[x][y]->setCellAround(west, NULL);}

				}
			}
	}



	for(int i=0;i<maxRoom;i++)
	{	
		cle[i]=0;
	}
	
		
	activeCell = new ActiveCell();
	activeCell->cpyCell(cell[1][1]);

	cell[2][1]->setKeyToUnlock(1);
	cell[3][5]->setKeyToUnlock(2);
}

Map::~Map()
{
	std::cout<<"Destruction de la map"<<std::endl;
	for (int i = 0; i < largeur; ++i) 
	{
		for(int j = 0; j < hauteur; j++)
		{
			delete cell[i][j];
		}
		delete[] cell[i];
	}

	delete[] cell;
	
	for (int i = 0; i < hauteur; ++i) 
	{
    	delete[] coordonne[i];
	}

	delete[] coordonne;

}




void Map::printMap()
{
	system("cls");
	

	
	for(int y=0;y<hauteur;y++)
	{
		for(int i=0;i<3;i++)
		{
			for(int x=0;x<largeur;x++)
			{
				std::cout << cell[x][y]->printCellTerminal(i);
			}
			std::cout << std::endl;
		}
		
	}
	std::cout << "\x1b[0m" <<std::endl;


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


void Map::updateMap()
{
	
	for(int y=0;y<this->hauteur;y++)
	{
		for(int x=0;x<this->largeur;x++)
		{
			//std::cout<<"coordonne["<< x << "]["<<y<<"]"<<coordonne[x][y]<<std::endl;
			cell[x][y]->setImageCell(cell[x][y]);
		}
	}
	activeCell->setImageCell(activeCell);
}

