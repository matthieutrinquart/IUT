//R. Raffin, IUT Aix-Marseille, Dept. Informatique, Arles
//compilation : g++ -Wall fork1.cpp -o fork1
/*
  Création et exécution de deux processus avec fork()
*/

#include <cstdlib> //fonctions standard du C (pour EXIT_SUCCESS)
#include <unistd.h> //fonctions systèmes

#include <iostream>
#include <sys/wait.h>

using namespace std;

int main()
{
	pid_t pidRetour, pidRetour2, pidRetour3;


	//lancement du clone, retour de la fonction fork() dans pidRetour
	pidRetour = fork();
	

/* Si pidRetour > 0 on est dans le processus père
      pidRetour = 0 on est dans le processus fils
      pidRetour < 0 le fork n'a pas fonctionné
*/
	if (pidRetour > 0)
	{
		cout << "Processus père (pidRetour=" << pidRetour << "), mon pid est " << getpid() << endl;
		sleep(20); //attente de 20 secondes. Attention, à ne pas utiliser en dehors des tests
	}
	else if (pidRetour == 0)
	{
		pidRetour2 = fork();
		
		if(pidRetour2 > 0)
		{
			cout << "Processus fils (pidRetour=" << pidRetour2 << "), mon pid est  " << getpid() << ", le pid de mon père est " << getppid() << endl;
			sleep(20); //idem
		}else if(pidRetour2==0)
		{
			pidRetour3 = fork();
			if(pidRetour3 > 0)
			{
				cout << "Processus fils (pidRetour=" << pidRetour2 << "), mon pid est  " << getpid() << ", le pid de mon père est " << getppid() << endl;
				sleep(20); //idem
			}else if(pidRetour3==0)
			{
				cout << "Processus fils (pidRetour=" << pidRetour2 << "), mon pid est  " << getpid() << ", le pid de mon père est " << getppid() << endl;
				sleep(20); //idem
			}
		}
		
	}
	else
		cerr << "Erreur à la création du processus\n";

cout << "J'ai fini...\n"; //mais qui ?

return(EXIT_SUCCESS);
}
