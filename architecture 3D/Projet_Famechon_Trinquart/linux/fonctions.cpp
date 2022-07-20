//R. RAFFIN, IUT Aix-Marseille, département Informatique, site d'Arles
//M4104c, ARCHI IN
//romain.raffin[AT]univ-amu.fr

//quelques fonctions utiles pour les shaders (lecture de fichier, affichage d'erreurs GLSL, chargement d'une texture par Freeimage)

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <time.h>

#include "freeImage/FreeImage.h"

#include <GL/glew.h>

#include "fonctions.h"

#ifndef M_PI
	#define M_PI	3.14159265358979323846
#endif

using namespace std;

void PrintProgramInfo(GLuint _program)
{
    int length = 0;
    int charsWritten  = 0;
    char *info;

	glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &length);

    if (length > 0)
    {
	info = new char[length];
        glGetProgramInfoLog(_program, length, &charsWritten, info);
		cerr << info << endl;
        delete [] info;
    }
}

void PrintShaderInfo(GLuint _shader) {
int length = 0;
int charsWritten= 0;
char *info;

glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &length);

	if (length > 0) {
		info = new char[length];
		glGetShaderInfoLog(_shader, length, &charsWritten, info);
		cerr << info << endl;
		delete [] info;
	}
}

int ReadSourceFile(const char* _filename, char ** _wtabchar ) {
int taille;

ifstream monfichier;
monfichier.open (_filename, ios::binary );

	//on "calcule" le nombre de caractères dans le fichier
	monfichier.seekg (0, ios::end);
	taille = monfichier.tellg();
	monfichier.seekg (0, ios::beg);

	(*_wtabchar) = new char [taille + 1];

	//on lit tout le fichier en 1 coup
	monfichier.read (*_wtabchar , taille);
	(*_wtabchar)[taille] = '\0';

monfichier.close();

return (taille);
}




float tirage_alea(float _borneinf, float _bornesup) {
//random() -> entre 0 et RAND_MAX
	srand(time(NULL));
	float res = _borneinf + ((double)rand() / ((double)RAND_MAX + 1.0) * _bornesup);
	return res;
}

float fDegree2Radian(const float _Dangle) {
	return (_Dangle * M_PI / 180.0f);
}

float fRadian2Degree(const float _Rangle) {
	return (_Rangle * 180.0f / M_PI);
}

