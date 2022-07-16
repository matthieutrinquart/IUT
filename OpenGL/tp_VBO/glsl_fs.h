//R. RAFFIN, IUT Aix-Marseille, département Informatique, site d'Arles
//M4104c, ARCHI IN
//romain.raffin[AT]univ-amu.fr

#ifndef _GLSL_FS
#define _GLSL_FS

#include <cstdlib>

#include <GL/glew.h>
#include <GL/gl.h>

#include "fonctions.h"

class GLSL_FS {
public:
	GLuint idfs;

	GLSL_FS(void);
	GLSL_FS(const GLSL_FS&);

	int ReadSource(const char *);
	int Compile();
};

#endif

