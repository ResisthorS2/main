#include "../libs/minigames.h"




using namespace std;

// Definition de la serie E24
string pe24_series = {
    "1.0 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0\n3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1"
};
const double e24_series[] = {
    1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0,
    3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1
};

// Multiplicateurs de la serie E24
const double multiplicateurs[] = {1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0};

// Fonction pour trouver la resistance la plus proche dans la serie E24
double findResistance(double valeur) {
    double meilleure_resistance = e24_series[0];
    double difference_min = abs(valeur - e24_series[0]);

    for (int i = 0; i < sizeof(e24_series) / sizeof(e24_series[0]); ++i) {
        for (int j = 0; j < sizeof(multiplicateurs) / sizeof(multiplicateurs[0]); ++j) {
            double resistance_combinee = e24_series[i] * multiplicateurs[j];
            double difference = abs(valeur - resistance_combinee);
            if (difference < difference_min) {
                meilleure_resistance = resistance_combinee;
                difference_min = difference;
            }
        }
    }
    // par defaut, si la resistance choisie est pile entre deux valeurs correctes, la plus petite va l'emporter.
    // par exemple, si la valeur à trouver est 4.1, les resistances de 3.9 et 4.3 seraient de bons choix, mais
    // le programme va prendre 3.9 comme la bonne reponse car c'est la plus petite
    // vous pourriez le changer en ajoutant une verification if(difference == difference_min), mais
    // je ne veux pas retourner plusieurs valeurs avec cette fonction
    return meilleure_resistance;
}

// Fonction principale du jeu
int MiniGame::play_resistanceGame(int key[6], int cell_type) {
    

    while(1)
    {
        system("cls");
        srand(time(0)); // Initialisation du generateur de nombres aleatoires avec le temps actuel
        // Generation d'un nombre aleatoire entre 10 et 99
        double nombre_aleatoire = 10.0 + (rand() % 90);
        nombre_aleatoire /= 10.0;

        // Generation d'un multiplicateur aleatoire parmi ceux de la serie E24
        int index_multiplicateur = rand() % ((sizeof(multiplicateurs)/ sizeof(multiplicateurs[0])) - 1);
        double multiplicateur_choisi = multiplicateurs[index_multiplicateur];

        double resistance_voulue = nombre_aleatoire * multiplicateur_choisi;
        cout << "Valeur de resistance a trouver: " << resistance_voulue << " Ohms" << endl;

        cout << "Serie E24: " << pe24_series << endl;

        double resistance_choisie;
        cout << "Entrez votre valeur de resistance (en Ohms) : ";
        cin >> resistance_choisie;

        double resistance_proche = findResistance(resistance_voulue);
        cout << "La resistance la plus proche dans la serie E24 est : " << resistance_proche << " Ohms" << endl;

        if (resistance_choisie == resistance_proche) {
            cout << "Felicitations! Vous avez choisi la resistance exacte!" << endl;
            cout << "Appuyer sur une touche pour sortir du local" << endl;
            char wait;
            std::cin >> wait;
            for(int i = 0; i < 6; i++)
            {
                if(key[i] == -1)
                {
                    key[i] = 3016;
                    break;
                }
            }
            return 0; // Fin du jeu sans erreur
        } else {
            cout << "Desole, vous n'avez pas choisi la bonne resistance." << endl;
            cout << "Appuyer sur une touche pour réessayer" << endl;
        }
    }
    
}

