/* R.Raffin romain.raffin@univ-amu.fr, M2 SIS
* calcul d'une moyenne en prog. concurrente
*/

#include <cstdlib>
#include <pthread.h>
#include <iostream>

#define MAXSIZE 1000
#define NBTHREADS 10

using namespace std;

struct myData {
	unsigned int size;
	float * tab;
};

void printMyData(const struct myData * _data) {
	for (unsigned int i = 0; i<_data -> size; ++i)
		cout << _data->tab[i] << " / ";
	cout << endl;
}


void * partialMean( void * _data ) {
	struct myData  * localData = (struct myData *) _data;
	
	//printMyData(localData);
	
	float * sum = new float();
	*sum = 0.0f;
	
	for (unsigned int i=0; i<(localData -> size) ; ++i) 
		(*sum) += localData -> tab[i]; 
	cerr << "sum = " << (*sum) << "\n";
	return (sum);
}


int main() {

	pthread_t thtab[NBTHREADS];
	float * t = new float[MAXSIZE];
	
	for (unsigned int i=0; i<MAXSIZE; ++i)
		t[i] = i;
	
	
	unsigned int partSize = MAXSIZE / NBTHREADS;
	
	cout << "Découpage en " << NBTHREADS << " morceaux de " << partSize << " éléments" << endl;

	struct myData * myStructs = new struct myData[NBTHREADS];
	
	for (unsigned int i=0; i<NBTHREADS ; ++i) {
		myStructs[i] . size = partSize;
		myStructs[i] . tab = new float[partSize];
		
		for (unsigned int d=0; d<partSize; ++d)
					myStructs[i] . tab[d] = t[partSize*i + d];
	
	//printMyData(&myStructs[i]);
	}
	
	cerr << "données prêtes, départ des threads\n";
	
	for (unsigned int th=0; th<NBTHREADS; ++th) {		
			cerr << "lancement du thread " << th << "\n";
			pthread_create(&thtab[th], NULL, partialMean, (void*) &myStructs[th]);
	}
	
	cerr << "Tous les threads ont été lancés\n";
	void * r;	
	float * res;

	float result = 0.0f; 

	for (unsigned int th=0; th<NBTHREADS; ++th) {
			pthread_join(thtab[th], &r);
			res = (float*) r;
			
			result += (*res);
			cerr << "arrivée du thread " << th << " r= " << *res << " result+ = " << result << "\n"; 
	}
	
	cout << "resultat = " << result << endl;
	
	delete[] myStructs;
	delete[] t;
	
	return (EXIT_SUCCESS);
}
