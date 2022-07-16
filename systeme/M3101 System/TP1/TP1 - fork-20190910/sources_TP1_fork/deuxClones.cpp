//R. Raffin, IUT Aix-Marseille, Dept. Informatique, Arles
//compilation : g++ -Wall deuxClones.cpp -o deuxClones
/*
  Création et exécution de deux clones avec fork()
*/
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>

#include <iostream>
using namespace std;

void infoProcessus(string _nom)
{
	cout << "Je suis " << _nom << endl;
	cout << _nom << " -> mon PID = " << getpid() << endl;
	cout << _nom << " -> PID de mon père = " << getppid() << endl;
}

int main () {

	pid_t pidfils1 = fork(); //création du fils1

	if (pidfils1 > 0)
		{ //PERE
			infoProcessus(string("Père"));
			cout << "(Père) pidfils1 = " << pidfils1 << endl;
			sleep(10);

			pid_t pidfils2 = fork();
			if (pidfils2 == 0)
			{//FILS2
				infoProcessus(string("Fils2"));
				cout << "(Fils2) pidfils2 = " << pidfils2 << endl;
			}
			else if (pidfils2 > 0)
			{//de nouveau PERE
				cout << "Pere encore\n";
			}
			else
			{ //ERREUR FILS2
				std::cerr << "Erreur à la création du fils 2\n";
			}
		}
	else if (pidfils1 == 0 )
	{ //FILS1
		infoProcessus(string("Fils1"));
		cout << "(Fils1) pidfils1 = " << pidfils1 << endl;
		sleep(10);
		}
	else
	{	//ERREUR FILS1
		cerr << "Erreur à la création du fils 1\n";
	}

//TOUS
cout << "J'ai fini...\n";
return (EXIT_SUCCESS);
}
