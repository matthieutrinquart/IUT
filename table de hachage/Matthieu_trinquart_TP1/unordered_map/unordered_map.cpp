#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <chrono>
#include <fstream>
int main()

{

	std::unordered_map<std::string, double> dictionnaire; //initialisation de la unordered_map
	std::ifstream fichier("Jules_Verne_Voyage_au_centre_de_la_Terre.txt", std::ios::in);//chargement du fichier a lire
	std::ofstream monFlux("data2.txt");//chargement du fichier a écrire
	std::vector<std::string> tableau;//initialisation du vecteur ou va etre stoker les mots
	std::string mots2; 
	std::string mots;//initialisation des mots qui vont rentrer dans la map
	std::string verife;
	int n = 0;
	int nombre;

	//-----le nombre qui sera recupérer est le nombre des premiers mots qui sera rentrer dans la map---//
	std::cout << "Donner Le nombre de mots a mettre sur la map" << std::endl;
	std::cin >> nombre;
	if (monFlux)//on verifie si le fichier peut s'ouvrir
	{

	//----entre les nombres de mots dans le vecteur----//
	while (fichier >> mots && fichier.good() && n <= nombre)
	{
		n++;
		tableau.push_back(mots);
	}


			//--parcour tout le vecteur--//
		for (std::vector<std::string>::iterator it = tableau.begin(); it != tableau.end(); ++it)
		{

			//--si le mots n'existe pas on l'insert dans la map--//
			if (dictionnaire.find(*it) == dictionnaire.end())
			{

				dictionnaire.insert(std::make_pair<std::string, unsigned int >((std::string) * it, 1));

			}
			//--si le mots existe on incremente le nombre d'itteration--//
			else
			{
				dictionnaire.at(*it)++;


			}



		}

		//----sert a trouver le nombre d'itteration du mots rechercher-----//
		do {
			std::cout << "Qu'elle mots voulez vous chercher" << std::endl;
			std::cin >> mots2;

			//--verification que l'utilisateur veuille arreter le programme ou alors chercher le mots arret--//
			if (mots2 == "arret")
			{
				std::cout << "voulez vous arreter le programme ?" << std::endl;
				std::cin >> verife;
				if (verife != "oui")
				{

					std::cout << mots2 << " a " << dictionnaire[mots2] << " iteration" << std::endl;

				}


			}
			else {
				std::cout << mots2 << " a " << dictionnaire[mots2] << " iteration" << std::endl;
			}


		} while (verife != "oui");


	}
	//--affiche une erreur si le fichier ne s'ouvre pas --//
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
	}

	return 0;

}