// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	int nb_entrer_par_util = 0;
	bool run = true;

	while (run == true) {
		bool premier = true;
		std::cout << "Entrer un nombre entier. : ";
		std::cin >> nb_entrer_par_util;

		for (int i = 2; i * 2 < nb_entrer_par_util; i++) {
			if (nb_entrer_par_util % i == 0) {
				premier = false;
				i = nb_entrer_par_util;
			}
		}

		if (premier == true) {
			std::cout << "est un nombre premier!" << std::endl;
		}
		else {
			std::cout << "Ce n'est pas un nombre premier." << std::endl;
		}

	}
    return 0;
}

