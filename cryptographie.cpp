#include <iostream>
#include <iomanip>
#include <string>

struct s_matrice {
	int nbElement;
	int nbLigne;
	int nbColonne;
	int *matrice;
};
s_matrice *matriceNull(int nbLigne, int nbColonne) {
	s_matrice *mN = new s_matrice;
	mN->nbLigne = nbLigne;
	mN->nbColonne = nbColonne;
	mN->nbElement = nbLigne * nbColonne;
	mN->matrice = new int[mN->nbElement];
	for (int i = 0; i < mN->nbElement; i++) {
		mN->matrice[i] = 0;
	}
	return mN;
}
s_matrice *multiplierMatrice(s_matrice &m1, s_matrice &m2) {
	s_matrice *m3 = NULL;
	if (m1.nbColonne == m2.nbLigne) {
		m3 = matriceNull(m1.nbLigne, m2.nbColonne);
		int prod = 0;
		for (int l = 0; l < m3->nbLigne; l++) {
			for (int c = 0; c < m3->nbColonne; c++) {
				prod = 0;
				for (int add = 0; add < m2.nbLigne; add++) {
					prod = prod + (m1.matrice[add+(l*m1.nbColonne)] * m2.matrice[(m2.nbColonne*add)+c]);
				}
				m3->matrice[l*m3->nbColonne+c] = prod;
			}
		}
	}
	return m3;
}
int chercherDansMatrice(char lettre, std::string matrice[]) {
	for (int l = 0; l < 9; l++) {
		for (int c = 0; c < matrice[l].size(); c++) {
			if (matrice[l][c] == lettre) {
				return (l*10)+c;
			}
		}
	}
	return 100; // Je ne sais pas quoi retourner, il faut retourner une valeur si le caractère n'est pas dans la matrice.
}
s_matrice *faireMatrice(std::string text, std::string matriceCharactere[]) {
	if (text.length() % 2) {
		text = text + " ";
	}
	s_matrice *matricePrincipale = matriceNull(2, text.length()/2);
	for (int elemNouvelMatrice = 0; elemNouvelMatrice < matricePrincipale->nbElement; elemNouvelMatrice++) {
		matricePrincipale->matrice[elemNouvelMatrice] = chercherDansMatrice(text[elemNouvelMatrice], matriceCharactere);
	}
	return matricePrincipale;
}
void afficherResultat(s_matrice *matrice) {
	for (int i = 0; i < matrice->nbElement; i++) {
		if (i && i % matrice->nbColonne == 0 && matrice->nbColonne != 1) {
			std::cout << '|' << std::endl << '|';
		}
		else if (!i) {
			std::cout << '|';
		}
		std::cout << std::setw(4) << matrice->matrice[i];
	}
	std::cout << '|' << std::endl << std::endl;
}
s_matrice *coderMessage(s_matrice &matrice) {
	s_matrice *matriceDeCodage = matriceNull(matrice.nbLigne, matrice.nbLigne);
	matriceDeCodage->matrice[0] = 2;
	matriceDeCodage->matrice[1] = -1;
	matriceDeCodage->matrice[2] = -3;
	matriceDeCodage->matrice[3] = 1;
	s_matrice *matriceCoder = multiplierMatrice(*matriceDeCodage, matrice);
	delete[] matriceDeCodage->matrice;
	delete matriceDeCodage;
	return matriceCoder;
}
s_matrice *decoderMessage(s_matrice &matrice) {
	s_matrice *matriceDeDecodage = matriceNull(matrice.nbLigne, matrice.nbLigne);
	matriceDeDecodage->matrice[0] = -1;
	matriceDeDecodage->matrice[1] = -1;
	matriceDeDecodage->matrice[2] = -3;
	matriceDeDecodage->matrice[3] = -2;
	s_matrice *matriceDecoder = multiplierMatrice(*matriceDeDecodage, matrice);
	delete[] matriceDeDecodage->matrice;
	delete matriceDeDecodage;
  	return matriceDecoder;
}
void afficherMessage(s_matrice &m, std::string alphabet[]) {
	std::string s = "";
	for (int i = 0; i < m.nbElement; i++) {
		s = s + alphabet[m.matrice[i]/10][m.matrice[i]%10];
	}
	std::cout << "Le message est : " << s << std::endl;
}



int main() {
	std::string matriceCharactere[] = {"ABCDEFGHI",
				 	   "JKLMNOPQR",
				 	   "STUVWXYZ'",
					   ".!?:;-123",
				 	   "4567890$ ",
					   "abcdefghi",
					   "jklmnopqr",
					   "stuvwxyz_",
					   ",{}[]*()%"};
	std::cout << "Message initial : " << std::endl;
	std::string monMessage = "IL FAIT BEAU";
	std::cout << monMessage << std::endl << std::endl;
	// Encodage1 dans la matrice
	s_matrice *ptrMatricePrincipal = faireMatrice(monMessage, matriceCharactere);
	std::cout << "Le message transformer en matrice" << std::endl;
	std::cout << "La matrice à " << ptrMatricePrincipal->nbElement << " elements" << std::endl;
	afficherResultat(ptrMatricePrincipal);
	//Cryptage
	std::cout << "Phase cryptage" << std::endl;
	ptrMatricePrincipal = coderMessage(*ptrMatricePrincipal);
        std::cout << "La matrice à " << ptrMatricePrincipal->nbElement << " elements" << std::endl;
        afficherResultat(ptrMatricePrincipal);
	//Phase Décodage
	std::cout << "Phase Décodage" << std::endl;
	ptrMatricePrincipal = decoderMessage(*ptrMatricePrincipal);
	std::cout << "La matrice 1 à " << ptrMatricePrincipal->nbElement << " elements" << std::endl;
	afficherResultat(ptrMatricePrincipal);
	//Afficher Message Matrice 1
	std::cout << "Affichage Final" << std::endl;
	afficherMessage(*ptrMatricePrincipal, matriceCharactere);

	std::cout << std::endl << std::endl;

	//Test d'un message entrer par l'utilisateur
	std::string messageUtilisateur;
	std::cout << "Entrer un message  : " << std::endl;
	std::getline(std::cin, messageUtilisateur);
	std::cin.clear();
	std::cout << std::endl;
	// Encoder le message dans la matrice
	s_matrice *matriceUtilisateur = faireMatrice(messageUtilisateur, matriceCharactere);
	afficherResultat(matriceUtilisateur);
	// Crypter le message
	matriceUtilisateur = coderMessage(*matriceUtilisateur);
	afficherResultat(matriceUtilisateur);
	// Decrypter le message
	matriceUtilisateur = decoderMessage(*matriceUtilisateur);
	afficherResultat(matriceUtilisateur);
	// Afficher message
	afficherMessage(*matriceUtilisateur, matriceCharactere);

	return 0;
}
