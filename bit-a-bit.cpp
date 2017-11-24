// Bit-a-bit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

struct s_couleur { int maCouleur; int valpha; int vrouge; int vvert; int vbleu; };

void affiche(std::string texte, bool saut_de_ligne = true);
void chiffre(int entier, bool saut_de_ligne = true);
s_couleur entrerUnChiffre();
void afficheResultat(s_couleur couleur);
void afficheTableValeurMinMax();

int main()
{
	std::locale::global(std::locale{ "" });

	afficheTableValeurMinMax();
	while(true) {
		afficheResultat(entrerUnChiffre());
	}

    return 0;
}

void affiche(std::string texte, bool saut_de_ligne) {
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

void chiffre(int entier, bool saut_de_ligne) {
	switch (saut_de_ligne)
	{
	case(false):
		std::cout << entier;
		break;
	default:
		std::cout << entier << std::endl;
		break;
	}
}

s_couleur entrerUnChiffre() {

	affiche("Un nombre de de type entier pouvant être reçu par l'ordinateur : ", false);
	s_couleur couleur;
	std::cin >> couleur.maCouleur;

	couleur.valpha = (couleur.maCouleur >> 24) & 255;
	couleur.vrouge = (couleur.maCouleur >> 16) & 255;
	couleur.vvert = (couleur.maCouleur >> 8) & 255;
	couleur.vbleu = couleur.maCouleur & 255;
	return couleur;
}

void afficheResultat(s_couleur couleur) {
	affiche("");
	affiche("Canal alpha : ", false); chiffre(couleur.valpha);
	affiche("Rouge : ", false); chiffre(couleur.vrouge);
	affiche("Vert : ", false); chiffre(couleur.vvert);
	affiche("Bleu : ", false); chiffre(couleur.vbleu);
	affiche("");
}

void afficheTableValeurMinMax() {
	affiche("\nUn table de valeur minimale et maximale des types de variables en c++\n");
	std::cout << "Type\t\t" << "Size" << "\t" << "Min"
		<< "\t\t\t" << "Max" << "\t\t\t" << "Number of posibility" << std::endl;
	std::cout << "char\t\t" << sizeof(char) << "\t" << SCHAR_MIN
		<< "\t\t\t" << SCHAR_MAX << "\t\t\t" << UCHAR_MAX << std::endl;
	std::cout << "short\t\t" << sizeof(short) << "\t" << SHRT_MIN
		<< "\t\t\t" << SHRT_MAX << "\t\t\t" << USHRT_MAX << std::endl;
	std::cout << "int\t\t" << sizeof(int) << "\t" << INT_MIN
		<< "\t\t" << INT_MAX << "\t\t" << UINT_MAX << std::endl;
	std::cout << "long\t\t" << sizeof(long) << "\t" << LONG_MIN
		<< "\t\t" << LONG_MAX << "\t\t" << ULONG_MAX << std::endl;
	std::cout << "long long\t" << sizeof(long long) << "\t" << LLONG_MIN
		<< "\t" << LLONG_MAX << "\t" << ULLONG_MAX << std::endl;
	affiche("\nFin de la table\n\n");
}
