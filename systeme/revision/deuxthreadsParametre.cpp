// Raffin R., Iut Aix-Marseille, Dept informatique, Arles
// 2014

// Création de base de 2 threads posix, premier passage de paramètre

//obligatoire pour utiliser les threads, ainsi que -lpthread à la compilation (édition de liens)
//compilation : g++ -Wall deuxthreadsParametre.cpp -o deuxthreadsParametre -lpthread

#include <pthread.h> //indispensable pour les thread (cf manuel)

#include <cstdlib>
#include <iostream>

//La fonction "externalisée" pour le thread1, fonctionnement local indépendant
void * fct_thread1(void * _arg) {

	std::cerr << "Je suis le thread 1\n";
	for ( unsigned int i = 0 ; i < 10 ; i++)
		std::cerr << "thread1 : " << i << std::endl;

return (NULL);
}

//La fonction "externalisée" pour le thread2, passage de la borne supérieure en argument
void * fct_thread2(void * _arg) {
	unsigned int * borne = (unsigned int *) (_arg); //on crée une variable locale qui permet de typer la valeur reçue dans _arg

	std::cerr << "Je suis le thread 2\n";

	for ( unsigned int i = 0 ; i < (*borne) ; i++)
		std::cerr << "thread2 : " << i << std::endl;

return (NULL);
}

int main() {

	pthread_t t1, t2; //identifiant des threads (type spécifique, cf pthread.h)

	unsigned int max = 10;

	pthread_create(&t1, NULL, fct_thread1, NULL); //lancement du thread t1, via la fonction fct_thread1
	pthread_create(&t2, NULL, fct_thread2, (void *) (&max)); //lancement du thread t2, via la fonction fct_thread2, avec un argument de type void* (cf prototype de la fonction pthread_create)

		std::cerr << "MAIN(), pendant le  thread\n";  //le programme principal peut continuer son exécution

	pthread_join(t1, NULL); //le programme principal bloque en attendant la fin du thread t1 (return)
	pthread_join(t2, NULL); //le programme principal bloque en attendant la fin du thread t2 (return)
	//remarque : le pthread_join est bloquant, on ne récupère pas le premier thread fini mais la fin de t1 PUIS la fin de t2.

return(EXIT_SUCCESS); //fin du programme principal

}

