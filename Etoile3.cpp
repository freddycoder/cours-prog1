// Etoile3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	int mesureDuCote = 0;
	char caractere;
	char espace = ' ';


	std::cout << "Entrer la longueur d'un carree" << std::endl;
	std::cin >> mesureDuCote;

	std::cout << "Entrer le caractère qui sera utilise pour faire le carre." << std::endl;
	std::cin >> caractere;

	// Première ligne
	for (int i = 1; mesureDuCote >= i; i = i + 1) {
		std::cout << caractere;
	}
	std::cout << std::endl;
	// Centre du carré
	for (int j = 1; mesureDuCote - 2 >= j; j = j + 1) {
		std::cout << caractere;
		for (int k = 1; mesureDuCote - 2 >= k; k = k + 1)
			std::cout << " ";
		std::cout << caractere << std::endl;
	}
	// Dernière ligne
	for (int i = 1; mesureDuCote >= i; i = i + 1) {
		std::cout << caractere;
	}
	std::cout << std::endl;
	

	std::cin.get();
	std::cin.clear();
	std::cin.ignore();

	return 0;
}
