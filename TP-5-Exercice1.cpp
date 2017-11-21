// GestionHeures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

// Déclarations
struct s_heure {
	int heure;
	int minutes;
	int secondes;
};
void afficher(std::string text, bool saut_de_ligne = true);
void afficherHeure(s_heure heure);
s_heure saisirHeure();
int convertirHeureEnSecondes(s_heure heure);
int calculerDifferenceHeureEnSecondes(s_heure heure1, s_heure heure2);

// Fin des déclaration - Début du main
int main() {
	s_heure donne_entre_par_util;
	s_heure donne_entre_par_util2;
	int choix = 0;
	afficher("Bienvenu dans mon programme!");
	while (true) {
		afficher("Choisir une option : \n1 pour entrer une heure et l'afficher tell quel puis en seconde, \n2 pour calculer la difference de seconde entre deux heures donnee, \n3 pour quitter.");
		std::cin >> choix;
		switch (choix) {
		case(1):
			afficher("Vous aller devoir saisir dabord l'heure, ensuite les minutes et les secondes.");
			donne_entre_par_util = saisirHeure();
			afficherHeure(donne_entre_par_util);
			afficher("L'heure convertie en seconde donne : ", false);
			std::cout << convertirHeureEnSecondes(donne_entre_par_util) << std::endl;
			break;
		case(2):
			afficher("Entrer la premiere donnee : ", false);
			donne_entre_par_util = saisirHeure();
			afficher("Puis la deuxieme : ", false);
			donne_entre_par_util2 = saisirHeure();
			std::cout << calculerDifferenceHeureEnSecondes(donne_entre_par_util, donne_entre_par_util2) << std::endl;
			break;
		case(3):
			return 0;
		default:
			afficher("S.V.P. Entrer une option valide. ");
			break;
		}
	}
}

// Définition des fonctions
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

void afficherHeure(s_heure heure) {
	std::cout << "L'heure est " << heure.heure << ": " << heure.minutes << ": " << heure.secondes << " " << std::endl;
}

s_heure saisirHeure() {
	s_heure donneeHeure;
	afficher("Entrer l'heure : ", false);
	std::cin >> donneeHeure.heure;
	afficher("Entrer les minutes : ", false);
	std::cin >> donneeHeure.minutes;
	afficher("Entrer les secondes : ", false);
	std::cin >> donneeHeure.secondes;
	return donneeHeure;
}

int convertirHeureEnSecondes(s_heure heure) {
	int secondes;
	secondes = heure.heure * 60 * 60;
	secondes = secondes + heure.minutes * 60;
	secondes = secondes + heure.secondes;
	return secondes;
}

int calculerDifferenceHeureEnSecondes(s_heure heure1, s_heure heure2) {
	int val1 = convertirHeureEnSecondes(heure1);
	int val2 = convertirHeureEnSecondes(heure2);
	if (val1 < val2) {
		return val2 - val1;
	}
	return val1 - val2;
}
