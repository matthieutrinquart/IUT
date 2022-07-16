// Raffin R., Iut Aix-Marseille, Dept informatique, Arles
// 2014
/* Programme simple de thread. Cr�ation de deux threads pointant sur les fonctions fct_thread1 et fct_thread2. Passage d'une chaine en param�re de t2. R�union par 2 pthread_join.*/

#include <cstdio>
#include <cstdlib>

//utilisation de l'en-tete de pthread obligatoire
#include <pthread.h>

//pour les fonctions syst�mes (sleep)
#include <unistd.h>

//1ere fonction excut�e par t1
void* fct_thread1(void * arg){
int i;
for (i=0;i<10;i++){
	write(1,"t1\n",3);
	}
return NULL;
}

//2eme fonction ex�cut�e par t2, recoit une chaine en param�tre
void* fct_thread2(void * chaine){
int i;

for(i=0;i<20;i++){
	write(1,"\tt2\n",4);
	printf("%s\n ", chaine);
	sleep(1);
	}
return NULL;
}

int main(void)
{
//d�claration de 2 descripteurs de thread
pthread_t t1, t2;
char texte[10]="toto";

printf("Depart de threads\n");
//lancement des 2 threads. t2 est lanc� avec passage de "toto" en param�tre
pthread_create(&t1, NULL, fct_thread1, NULL);
pthread_create(&t2, NULL, fct_thread2,(void*)texte);

//on attend les 2 threads ici
pthread_join(t1,NULL);
printf("fin de thread1\n");
pthread_join(t2,NULL);
printf("fin de thread2\n");

//� partir de la ligne pr�c�dente, on se retrouve dans le processus initial
printf("Fin des threads\n");
printf("partie finale\n");

return(EXIT_SUCCESS);
}
