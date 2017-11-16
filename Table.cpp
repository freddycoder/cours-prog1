// Tables.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	char operation = 'x';
	int valeur_operation = 0;
	int table = 0;
	int run = 111;

	std::cout << "Pour quitte tapez 'n' dans lors du choix d'un operateur." << std::endl;

	while (run == 111) {
		while (valeur_operation != 43 && valeur_operation != 45 && valeur_operation != 42 && valeur_operation != 47 && valeur_operation != 110) {
			std::cout << "Choisissez un operateur '(+, -, *, /)' : ";
			std::cin >> operation;
			valeur_operation = operation;
			if (valeur_operation == 110) {
				run = valeur_operation;
			}
		}

		if (run == 111) {
			while (table < 1 || table > 10) {
				std::cout << "Choisissez un nombre entre de 1 à 10 : ";
				std::cin >> table;
			}

		switch (valeur_operation) {
		case(43): {
			std::cout << "Table d'addition de " << table << ". " << std::endl;
			for (int i = 1; i <= 12; i++) {
				std::cout << i << " + " << table << " = " << i + table << std::endl;
			}
			valeur_operation = 0;
			table = 0;
			std::cout << std::endl;
			break;
		}
		case(45): {
			std::cout << "Table de soustraction de " << table << ". " << std::endl;
			for (int i = 1; i <= 12; i++) {
				std::cout << i << " - " << table << " = " << i - table << std::endl;
			}
			valeur_operation = 0;
			table = 0;
			std::cout << std::endl;
			break;
		}
		case(42): {
			std::cout << "Table de multiplication de " << table << ". " << std::endl;
			for (int i = 1; i <= 12; i++) {
				std::cout << i << " * " << table << " = " << i * table << std::endl;
			}
			valeur_operation = 0;
			table = 0;
			std::cout << std::endl;
			break;
		}
		case(47): {
			std::cout << "Table de division de " << table << ". " << std::endl;
			for (int i = 1; i <= 12; i++) {
				std::cout << i * table << " / " << table << " = " << i << std::endl;
			}
			valeur_operation = 0;
			table = 0;
			std::cout << std::endl;
			break;
		}
		}
	}
		else {
			std::cout << "Merci d'avoir utilise mon programme!";
		}
	}

	std::cin.get(); std::cin.clear(); std::cin.ignore();
	return 0;
}

