#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>

int main(int _nbargs, char ** args)
{
pid_t retfork;
int mavar;

mavar = 1;

retfork = fork();

if (retfork == -1)
{
	std::cerr << "Erreur !\n";
	return(EXIT_FAILURE);
}
	else if (retfork == 0)
	{
		std::cout << "Je suis le fils\n";
		mavar = mavar * 10;
		std::cout << "Fils " << mavar << "\n";
		sleep(2);
	}
		else if (retfork > 0)
		{
		std::cout << "Je suis le père\n";
				wait(NULL);
		mavar = mavar + 100;
		std::cout << "Père " << mavar << "\n";
		}

return(EXIT_SUCCESS);
}
