//2016 R. RAFFIN, IUT Aix-Marseille, dept. Informatique - Arles
//TP simple, affichages de quelques points
//compilation par : g++ -Wall TP1points.cpp -lGL -lGLU -lglut -lGLEW -o TP1points

#include <cstdio>
#include <cstdlib>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "Cercle.hpp"
using namespace std;

GLuint leVBO;
int pas = 10000 ;//nombre de points pour le cercle
float X = 0.5;//coordonné X du centre du cercle
float Y = -0.5;//coordonné Y du centre du cercle
point millieu = {X,Y};//on met sa dans un point
float rayon = 0.4;//rayon du cercle
Cercle rond = Cercle(millieu,rayon);//on initialise le cercle

vector<point> remplissage()//retorune un vecteur remplit des point du cercle
{
	vector<point> tableau = {} ;//initialisation du tableau de point
	for(int i = 0 ; i < pas ; ++i)//boucle for qui vas jusqu'au nombre de pas
	{
		tableau.push_back(rond.Point(i , pas));//on rentre tout les points dans un vector

	}
return tableau ;//on retourne le vecteur
}

static void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);


//Liaison avec le buffer de vertex
	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, leVBO);
	glVertexPointer(3, GL_FLOAT, 0, 0); //description des données pointées

	glDrawArrays(GL_POINTS, 0, pas); //3 éléments à utiliser pour le dessin

	glDisableClientState(GL_VERTEX_ARRAY); //plus besoin de vertexArray

	glutSwapBuffers();
}


static void InitializeGlutCallbacks()
{
	glutDisplayFunc(RenderScene);
}



static void CreateVertexBuffer()
{


	std::vector<point> tableauPoint = remplissage();//on initialise tableauPoint et on el rentrera dans le glBufferData


 	glGenBuffers(1, &leVBO); //génération d'une référence de buffer object
	glBindBuffer(GL_ARRAY_BUFFER, leVBO); //liaison du buffer avec un type tableau de données
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* pas * 3, &tableauPoint[0], GL_STATIC_DRAW); //création et initialisation du container de données (3 sommets -> 9 float)
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("TP1 Matthieu TRINQUART");

	InitializeGlutCallbacks();

	//toujours après l'initialisation de glut
	GLenum res = glewInit();

	if (res != GLEW_OK) {
		cerr << "Error: " << glewGetErrorString(res) << endl;
		return (EXIT_FAILURE);
	}

	//cout << "Using GLEW Version: " << glewGetString(GLEW_VERSION);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	CreateVertexBuffer();

	glutMainLoop();

	return (EXIT_SUCCESS);
}
