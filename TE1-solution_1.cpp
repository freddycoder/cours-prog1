// TP-note1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <locale>
#include <string>

// Ici mesure1 vaut 0 et est en pouce, ensuite mesure2 vaut 0 et est en Pied. Il existe deux autre type, centimètre et mètre donc tout les types possible sont : 'p', 'P', 'c' et 'm'.
struct s_deuxMesures { float mesure1 = 0; char type1 = 'p'; float mesure2 = 0; char type2 = 'P'; };

void afficher(std::string texte, bool saut_de_ligne = true);
void afficheValeur(float valeur, char type);
float convertireEnCentimetre(float valeur, char type);
float convertireEnMetre(float valeur, char type);
float ajouterUnPouce(float valeur, char type);
float ajouterUnPied(float valeur, char type);

int main() {
	// Pour faire fonctionner les accents.
	std::locale::global(std::locale{ "" });
	// Déclaration des variables
	s_deuxMesures mesures;
	float change_valeur = 0;
	char change_type = 0;
	int option;
	// Lancement du programme.
	while (true) {
		afficher("1 Saisir une première mesure en pouce.");
		afficher("2 Saisir une deuxième mesure en pied.");
		afficher("3 Afficher la première valeur.");
		afficher("4 Afficher la deuxière valeur.");
		afficher("5 Interchanger les valeurs.");
		afficher("6 Convertire la première valeur en centimètre.");
		afficher("7 Convertire la première valeur en mètre.");
		afficher("8 Ajouter un pouce à la première valeur.");
		afficher("9 Ajouter un pied à la première valeur.");
		afficher("0 Quitter.");
		std::cin >> option;

		switch (option) {
		case(0):
			return 0;
		case(1):
			afficher("Entrer une première valeur en pouce : ", false);
			std::cin >> mesures.mesure1;
			mesures.type1 = 'p';
			break;
		case(2):
			afficher("Entrer une deuxième valeur en pied : ", false);
			std::cin >> mesures.mesure2;
			mesures.type2 = 'P';
			break;
		case(3):
			afficheValeur(mesures.mesure1, mesures.type1);
			break;
		case(4):
			afficheValeur(mesures.mesure2, mesures.type2);
			break;
		case(5):
			change_valeur = mesures.mesure1;
			change_type = mesures.type1;
			mesures.mesure1 = mesures.mesure2;
			mesures.type1 = mesures.type2;
			mesures.mesure2 = change_valeur;
			mesures.type2 = change_type;
			break;
		case(6):
			mesures.mesure1 = convertireEnCentimetre(mesures.mesure1, mesures.type1);
			mesures.type1 = 'c';
			break;
		case(7):
			mesures.mesure1 = convertireEnMetre(mesures.mesure1, mesures.type1);
			mesures.type1 = 'm';
			break;
		case(8):
			mesures.mesure1 = ajouterUnPouce(mesures.mesure1, mesures.type1);
			break;
		case(9):
			mesures.mesure1 = ajouterUnPied(mesures.mesure1, mesures.type1);
			break;
		default:
			afficher("Vous devez choisir une option valide.");
		}
			// return est dans switch(option) case(0) et retourne simpement 0.
	}
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

void afficheValeur(float valeur, char type) {
	std::cout << "Distance " << valeur;
	switch (type) {
	case('p'):
		afficher(" pouce(s).");
		break;
	case('P'):
		afficher(" pied(s).");
		break;
	case('c'):
		afficher(" centimètre(s).");
		break;
	case('m'):
		afficher(" mètre(s).");
		break;
	}
}

float convertireEnCentimetre(float valeur, char type) {
	if (type == 'p') {
		valeur = valeur * 2.54;
	}
	else if (type == 'P') {
		valeur = (valeur * 12) * 2.54;
	}
	else if (type == 'm') {
		valeur = valeur * 100;
	}
	return valeur;
}

float convertireEnMetre(float valeur, char type) {
	if (type == 'p') {
		valeur = (valeur * 2.54) / 100;
	}
	else if (type == 'P') {
		valeur = ((valeur * 12) * 2.54) / 100;
	}
	else if (type == 'c') {
		valeur = valeur / 100;
	}
	return valeur;
}

float ajouterUnPouce(float valeur, char type) {
	if (type == 'p') {
		valeur = valeur + 1;
	}
	else if (type == 'P') {
		valeur = valeur + (1 / 12);
	}
	else if (type == 'c') {
		valeur = valeur + 2.54;
	}
	else if (type == 'm') {
		valeur = valeur + (2.54 / 100);
	}
	return valeur;
}

float ajouterUnPied(float valeur, char type) {
	if (type == 'p') {
		valeur = valeur + 12;
	}
	else if (type == 'P') {
		valeur = valeur + 1;
	}
	else if (type == 'c') {
		valeur = valeur + (2.54 * 12);
	}
	else if (type == 'm') {
		valeur = valeur + ((2.54 * 12) / 100);
	}
	return valeur;
}
