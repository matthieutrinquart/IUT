#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <sys/types.h>
int a=10;

int main(int _nbargs, char ** args)
{
pid_t retfork;

std::cout<<"avant le fork a="<< a<<std::endl;

retfork = fork();

if (retfork == -1)
{
	std::cerr << "Erreur !\n";
	return(EXIT_FAILURE);
}
	else if (retfork == 0)
	{//FILS
		std::cout << "Je suis le fils, retfork=" << retfork << std::endl;
		std::cout << "pid du père " << getppid() << std::endl;
		std::cout << "pid " << getpid() << std::endl;
		a=a+10;
		std::cout<<"fils a="<< a<<std::endl;
		sleep(20);
	}
		else if (retfork > 0)
		{//PERE
			std::cout << "Je suis le père, pid du fils=" << retfork << std::endl;
			std::cout << "pid du père " << getppid() << std::endl;
			std::cout << "pid " << getpid() << std::endl;
			a=a*100;
			std::cout<<"pere a="<< a<<std::endl;
			//sleep(20);
		}
std::cout<<"avant le return a="<< a<<std::endl;

return(EXIT_SUCCESS);
}
