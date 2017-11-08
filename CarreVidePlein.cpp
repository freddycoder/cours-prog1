// CarreVidePlein.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	int carreOuRectangle = 0;
	int pleinOuVide = 0;

	while (carreOuRectangle != -1) {
		std::cout << "Carre ou Rectangle? Tapez 1 pour carre, 2 pour rectangle et -1 pour quitte. " << std::endl;
		std::cin >> carreOuRectangle;

		// Carre
		if (carreOuRectangle == 1) {
			std::cout << "Plein ou vide? Tapez 0 pour vide et 1 pour plein. " << std::endl;
			std::cin >> pleinOuVide;

			// Plein
			if (pleinOuVide == 1) {
				for (int lignes = 1; lignes <= 10; lignes = lignes + 1) {
					for (int colonnes = 1; colonnes <= 10; colonnes = colonnes + 1) {
						std::cout << "*";
					}
					std::cout << std::endl;
				}
			} // Vide
			else if (pleinOuVide == 0) {
				//Premiere ligne
				for (int colonnes = 1; colonnes <= 10; colonnes = colonnes + 1) {
					std::cout << "*";
				}
				std::cout << std::endl;
				// Centre
				for (int lignes = 1; lignes <= 8; lignes = lignes + 1) {
					std::cout << "*";
					for (int colonnes = 1; colonnes <= 8; colonnes = colonnes + 1) {
						std::cout << " ";
					}
					std::cout << "*" << std::endl;
				}
				//Dernière ligne
				for (int colonnes = 1; colonnes <= 10; colonnes = colonnes + 1) {
					std::cout << "*";
				}
				std::cout << std::endl;
			}

			else {
				std::cout << "Entree non valide" << std::endl;
			}
		}
		// Rectangle
		else if (carreOuRectangle == 2) {
			std::cout << "Plein ou vide? Tapez 0 pour vide et 1 pour plein. " << std::endl;
			std::cin >> pleinOuVide;

			// Plein
			if (pleinOuVide == 1) {
				for (int lignes = 1; lignes <= 20; lignes = lignes + 1) {
					for (int colonnes = 1; colonnes <= 10; colonnes = colonnes + 1) {
						std::cout << "*";
					}
					std::cout << std::endl;
				}
			} // Vide
			else if (pleinOuVide == 0) {
				//Premiere ligne
				for (int colonnes = 1; colonnes <= 20; colonnes = colonnes + 1) {
					std::cout << "*";
				}
				std::cout << std::endl;
				// Centre
				for (int lignes = 1; lignes <= 20; lignes = lignes + 1) {
					std::cout << "*";
					for (int colonnes = 1; colonnes <= 18; colonnes = colonnes + 1) {
						std::cout << " ";
					}
					std::cout << "*" << std::endl;
				}
				//Dernière ligne
				for (int colonnes = 1; colonnes <= 20; colonnes = colonnes + 1) {
					std::cout << "*";
				}
				std::cout << std::endl;
			}

			else {
				std::cout << "Entree non valide" << std::endl;
			}
		}
		// Quitte ?
		else if (carreOuRectangle == -1) {
			std::cout << std::endl;
		}
		// Utlisateur con
		else {
			std::cout << "Entree non valide" << std::endl;
		}
	}
    return 0;
}

