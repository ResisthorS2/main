/**
 * @file map.h
 * @brief Fichier d'en-tête pour la classe Map
 * @attention Si plus de 20 salles, n'oubliez pas d'augmenter MAXROOM
 */

#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "activeCell.h"

/**
 * @class Map
 * @brief Classe représentant une carte du jeu
 */
class Map
{
public:
    /**
     * @brief Constructeur par défaut de la classe Map
     */
    Map();

    /**
     * @brief Destructeur de la classe Map
     */
    ~Map();			

    /**
     * @brief Méthode pour afficher la carte
     */
    void printMap();

    /**
     * @brief Méthode pour ajouter l'accès à une pièce
     * @param index L'index de la pièce à laquelle accéder : int
     */
    void addCle(int index);

    /**
     * @brief Méthode pour supprimer l'accès à une pièce
     * @param index L'index de la pièce dont l'accès doit être supprimé : int
     */
    void removeCle(int index);

    /**
     * @brief Méthode pour vérifier si une pièce est accessible
     * @param index L'index de la pièce à vérifier : int
     * @return true si la pièce est accessible, false sinon
     */
    bool verifCle(int index);

    /**
     * @brief Méthode pour mettre à jour la carte
     */
    void updateMap();

    Cell ***cell; // Tableau 2D de Cell* : cell[largeur][hauteur]
    ActiveCell *activeCell; // Cellule active
    int largeur; // Largeur de la carte
    int hauteur; // Hauteur de la carte

private:
    int **coordonne; // Tableau de coordonnées : coordonne[x][y]
    int cle[maxRoom]; // Tableau des clés pour accéder aux pièces
};
#endif