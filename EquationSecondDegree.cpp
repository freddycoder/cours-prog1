// EquationSecondDegre.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	long a = 0.0;
	long b = 0.0;
	long c = 0.0;
	long long delta = 0.0;
	long long  r1 = 0.0;
	long long r2 = 0.0;
	bool run = true;

	while (run == true) {
		std::cout << "Entrer la valeur de a : ";
		std::cin >> a;
		std::cout << "Entrer la valeur de b : ";
		std::cin >> b;
		std::cout << "Entrer la valeur de c : ";
		std::cin >> c;

		delta = (b ^ 2) - (4 * a*c);
		if (delta < 0) {
			std::cout << "aucune racine reel" << std::endl;
		}
		else if (delta == 0) {
			r1 = -b / (2 * a);
			std::cout << std::setw(10) << std::setprecision(4) << std::fixed << r1 << '\n';
		}
		else {
			r1 = (-b - sqrt(delta)) / (2 * a);
			r2 = (-b + sqrt(delta)) / (2 * a);
			std::cout << std::setw(10) << std::setprecision(4) << std::fixed << r1 << '\n';
			std::cout << std::setw(10) << std::setprecision(4) << std::fixed << r2 << '\n';
		}
		a = 0.0;
		b = 0.0;
		c = 0.0;
	}
    return 0;
}
