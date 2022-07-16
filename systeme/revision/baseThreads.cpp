#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>

using namespace std;

//variable globale
int a=10;

void * fonctionThread1(void * monarg) {
	a = a + 10;
	
	int * monentier = (int*)monarg;
	(*monentier) = (*monentier) + 1;

	cout << "thread1 argument=" << *monentier << endl;
	cout << "thread1 a=" << a << endl;

	sleep(10);
	return(NULL);
}

void * fonctionThread2(void * _arg) {
	a = a * 10;
	cout << "thread2 a=" << a << endl;
	sleep(10);

	return(NULL);
}


int main() {
pthread_t th1, th2;
int * i = new int();
*i=10;

	//appel de la fonction1
	pthread_create(&th1, NULL, fonctionThread1, (void*)i);

	//appel de la fonction2
	pthread_create(&th2, NULL, fonctionThread2, (void*)NULL);

//retour des threads
pthread_join(th1, NULL);
pthread_join(th2, NULL);

cout << "Fin, a= " << a << endl;

return(EXIT_SUCCESS);
}
