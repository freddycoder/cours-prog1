#include <iostream>
#include <string>

using namespace std;

void jouerPartieDeuxJoueurs(int joueur1, int joueur2);
int jouerTour(int joueur, int nbAllumette);
void afficher(std::string texte, bool saut_de_ligne = true);

int main()
{
	int option = 1;
        afficher("\t\t *** Jeux de Nim *** ");
	afficher("Le but du jeux est de prendre la dèrnière allumette.\n");
	
	while (option != 0) {

		afficher("Choisir une option : ");
		afficher("1. Partie deux joueur");
		afficher("2. Partie contre l'ordinateur");
		afficher("0. Quitter");
		afficher("Option : ", false);
		cin >> option;
                afficher(""); // Fait un saut de ligne
    
    
		switch (option)
		{
		case(0):
			break;
		case(1): // Partie 2 joueur
			jouerPartieDeuxJoueurs(1, 2);
			break;
		case(2): // Partie contre l'ordinateur
			jouerPartieDeuxJoueurs(1, 3); // Joueur 3 = ordinateur
			break;
		default:
			afficher("Erreur...");
			break;
		}
	}
	
	return 0;
}

void jouerPartieDeuxJoueurs(int joueur1, int joueur2 ) {
	int nbAllumette = 21;
	int choix = 0;
	int tour = 1;

	while (nbAllumette > 0) {
		cout << "Tour " << tour << endl;
		nbAllumette = jouerTour(joueur1, nbAllumette);
		tour = tour + 1;
		if (nbAllumette <= 0) {
			afficher("Le joueur 1 à gagné!\n");
		}
		else {
			cout << "Tour " << tour << endl;
			nbAllumette = jouerTour(joueur2, nbAllumette);
			tour = tour + 1;
			if (nbAllumette <= 0 && joueur2 == 2) {
				afficher("Le joueur 2 à gagné!\n");
			} else if (nbAllumette <= 0 && joueur2 == 3) {
			  afficher("L'ordinateur à gagné!\n");
			}
		}

	}
}

int jouerTour(int joueur, int nbAllumette) {
	int choix = 0;
	cout << "Tour du joueur " << joueur << ", le nombre d'allumette restante : " << nbAllumette << endl;
	if (joueur == 3) { // *** Section AI ***
		if (nbAllumette == 5) {
			choix = 1;
		}
		else if (nbAllumette == 6) {
			choix = 2;
		}
		else if (nbAllumette == 7) {
			choix = 3;
		}
		else if (nbAllumette == 8) {
			choix = 1;
		}
		else if (nbAllumette == 9 || nbAllumette == 10) {
			choix = 1;
		}
		else {
			choix = 3;
		}
	}
	else {
		while (choix > 3 || choix < 1) {
			cin >> choix;
			if (choix > 3 || choix < 1) {
				afficher("La valeur doit être entre 1 et 3!");
			}
		}
	}
	nbAllumette = nbAllumette - choix;
	return nbAllumette;
}

void afficher(std::string texte, bool saut_de_ligne) {
	switch (saut_de_ligne)
	{
	case(false):
		std::cout << texte;
		break;
	default:
		std::cout << texte << std::endl;
		break;
	}
}
