// jeuxDeNim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void afficher(std::string texte, bool saut_de_ligne = true);
int jouerTour(int joueur, int nbAllumette);
void jouerPartieDeuxJoueurs(int joueur1, int joueur2);

int main()
{
	int option = 1;

	while (option != 0) {
		afficher("Choisissez un partie 1 joueur contre l'ordinateur ou deux joueur.");
		afficher("1 pour deux joueur et 2 pour jouer contre l'ordinateur. 0 pour quitté");
		cin >> option;

		switch (option)
		{
		case(0):
			break;
		case(1):
			jouerPartieDeuxJoueurs(1, 2);
			break;
		case(2):
			jouerPartieDeuxJoueurs(1, 3); // Joueur 3 = ordinateur
			break;
		default:
			afficher("Erreur...");
			break;
		}
	}
	
	return 0;
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

int jouerTour(int joueur, int nbAllumette) {
	int choix = 0;
	cout << "Tour du joueur " << joueur << ", le nombre d'allumette restante : " << nbAllumette << endl;
	if (joueur == 3) {
		if (nbAllumette == 5) {
			choix = 1;
		}
		else if (nbAllumette == 6) {
			choix = 2;
		}
		else if (nbAllumette == 7) {
			choix = 2;
		}
		else if (nbAllumette == 8) {
			choix = 3;
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

void jouerPartieDeuxJoueurs(int joueur1, int joueur2 ) {
	int nbAllumette = 21;
	int choix = 0;
	int tour = 1;

	while (nbAllumette > 0) {
		cout << "Tour " << tour << endl;
		nbAllumette = jouerTour(joueur1, nbAllumette);
		tour = tour + 1;
		if (nbAllumette <= 0) {
			afficher("Le joueur 1 à gagné!");
		}
		else {
			cout << "Tour " << tour << endl;
			nbAllumette = jouerTour(joueur2, nbAllumette);
			tour = tour + 1;
			if (nbAllumette <= 0) {
				afficher("Le joueur 2 à gagné!");
			}
		}

	}
}
