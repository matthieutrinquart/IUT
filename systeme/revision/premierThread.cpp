// Raffin R., Iut Aix-Marseille, Dept informatique, Arles
// 2014

// Création de base d'un thread posix

//obligatoire pour utiliser les threads, ainsi que -lpthread à la compilation (édition de liens)
//compilation : g++ -Wall premierThread.cpp -o premierThread -lpthread

#include <pthread.h> //indispensable pour les thread (cf manuel)

#include <iostream>
#include <cstdlib>
#include <unistd.h>

//La fonction "externalisée" pour le thread
//attention au prototype de la fonction (cf "man pthread_create")
//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

void * fct_thread(void * _arg) {

	std::cerr << "Je suis le thread\n";

	for( unsigned int i = 0; i < 10; i++)
	{
    		std::cout << "t1 " << i << std::endl;
    		sleep(1);
	}

return (NULL);
}

int main() {

	pthread_t p; //identifiant de thread (type spécifique, cf pthread.h)

	pthread_create(&p, NULL, fct_thread, NULL); //lancement du thread, via la fonction fct_thread

		std::cerr << "MAIN(), pendant le  thread\n";  //le programme principal peut continuer son exécution

	pthread_join(p, NULL); //le programme principal bloque en attendant la fin du thread (return)

        	std::cerr << "MAIN(), threads terminés\n";  //après le join() seul reste le programme principal

return(EXIT_SUCCESS); //fin du programme principal

}

