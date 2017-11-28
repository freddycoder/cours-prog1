// jeuxDeNim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void afficher(std::string texte, bool saut_de_ligne = true);
int jouerTour(int joueur, int nbAllumette);
void jouerPartieDeuxJoueurs();

int main()
{
	int option = 1;

	switch (option)
	{
	case(1):
		jouerPartieDeuxJoueurs();
		cin.get();
		break;
	default:
		int nbAllumette = 21;
		int choix = 0;
		int tour = 1;

		while (nbAllumette > 0) {
			nbAllumette = jouerTour(1, nbAllumette);
			nbAllumette = jouerTour(3, nbAllumette);
		}
		
		break;
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
	cout << "Tour du joueur 1, le nombre d'allumette restante : " << nbAllumette << endl; 
	while (choix > 3 || choix < 1) {
		cin >> choix;
		if (choix > 3 || choix < 1) {
			afficher("La valeur doit être entre 1 et 3!");
		}
	}
	nbAllumette = nbAllumette - choix;
	return nbAllumette;
}

void jouerPartieDeuxJoueurs() {
	int nbAllumette = 21;
	int choix = 0;
	int tour = 1;

	while (nbAllumette > 0) {
		cout << "Tour " << tour << endl;
		nbAllumette = jouerTour(1, nbAllumette);
		tour = tour + 1;
		if (nbAllumette <= 0) {
			afficher("Le joueur 1 à gagné!");
		}
		else {
			cout << "Tour " << tour << endl;
			nbAllumette = jouerTour(2, nbAllumette);
			tour = tour + 1;
			if (nbAllumette <= 0) {
				afficher("Le joueur 2 à gagné!");
			}
		}

	}
}
