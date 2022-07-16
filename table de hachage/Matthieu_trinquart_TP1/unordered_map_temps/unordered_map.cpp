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
	std::ofstream monFlux("data.txt");//chargement du fichier a écrire
	std::vector<std::string> tableau;//initialisation du vecteur ou va etre stoker les mots
	std::string mots2;
	std::string mots;//initialisation des mots qui vont rentrer dans la map
	std::string verife;
	int recherche = 0;//variable qui va stocker le temps de recherche
	int o = 0;//variable qui va stocker le nombre d'iteration
	int n = 0;
	int nombre ;
	int insertion = 0;//variable qui va stocker le temps d'insertion



	//-----le nombre qui sera recupérer est le nombre des premiers mots qui sera rentrer dans la map---//
	std::cout << "Donner Le nombre de mots a mettre sur la map" << std::endl;
	std::cin >> nombre;


	if (monFlux)//on verifie si le fichier peut s'ouvrir
	{
		//----entre les nombres de mots dans le vecteur----//
	while (fichier >> mots && fichier.good()&& n<= nombre )
	{
		n++;
		tableau.push_back(mots);
	}



	//--parcour tout le vecteur--//
	for (std::vector<std::string>::iterator it = tableau.begin(); it != tableau.end(); ++it)
	{
		o++;//on incremente le nombre d'iteration

		std::chrono::steady_clock::time_point debut_recherche = std::chrono::steady_clock::now();//on stoks le temps avant la recherche

		if (dictionnaire.find(*it) == dictionnaire.end())
		{

			std::chrono::steady_clock::time_point fin_recherche = std::chrono::steady_clock::now();//on stoks le temps après la recherche
			//--on soustrait les 2 et on stock le resultat du temps de recherche
			std::chrono::nanoseconds time_recherche = std::chrono::duration_cast<std::chrono::nanoseconds>(fin_recherche - debut_recherche);
			recherche = (int)time_recherche.count();



			std::chrono::steady_clock::time_point debut_insertion = std::chrono::steady_clock::now();//on stoks le temps avant l'insertion
			dictionnaire.insert(std::make_pair<std::string, unsigned int >((std::string)*it, 1));//on insert le mots
			std::chrono::steady_clock::time_point fin_insertion = std::chrono::steady_clock::now();//on stoks le temps après l'insertion
			//--on soustrait les 2 et on stock le resultat du temps d'insertion--//
			std::chrono::nanoseconds time_insertion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin_insertion - debut_insertion);
			insertion = (int)time_insertion.count();

		}
		else
		{
			std::chrono::steady_clock::time_point fin_recherche = std::chrono::steady_clock::now();//on stoks le temps après la recherche

			//--on soustrait les 2 et on stock le resultat du temps de recherche--//
			std::chrono::nanoseconds time_recherche = std::chrono::duration_cast<std::chrono::nanoseconds>(fin_recherche - debut_recherche);
			recherche = (int)time_recherche.count();


			std::chrono::steady_clock::time_point debut_insertion = std::chrono::steady_clock::now();//on stoks le temps avant l'insertion
			dictionnaire.at(*it)++;//on incremente le mots
			std::chrono::steady_clock::time_point fin_insertion = std::chrono::steady_clock::now();//on stoks le temps après l'insertion
					//--on soustrait les 2 et on stock le resultat du temps d'insertion--//
			std::chrono::nanoseconds time_insertion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin_insertion - debut_insertion);
			insertion = (int)time_insertion.count();



		}

		//on ecrit les resultat dans le fichier
		monFlux << o << " " <<  recherche << " " << insertion << std::endl;



	}
}

else
{
	std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
}

	return 0;

}