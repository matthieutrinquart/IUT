//R. RAFFIN, IUT Aix-Marseille, département Informatique, site d'Arles
//M4104c, ARCHI IN
//romain.raffin[AT]univ-amu.fr

//quelques fonctions utiles pour les shaders (lecture de fichier, affichage d'erreurs GLSL, chargement d'une texture par Freeimage)
#ifndef _H_FONCTIONS
#define _H_FONCTIONS

#include <GL/glew.h>
#include <GL/gl.h>

#include <iostream>
#include <fstream>

float tirage_alea(float, float);

float fDegree2Radian(const float);
float fRadian2Degree(const float);

void PrintProgramInfo(GLuint);
void PrintShaderInfo(GLuint);
int ReadSourceFile(const char*, char **);
void LoadTexture(char*, GLuint*);

#endif
