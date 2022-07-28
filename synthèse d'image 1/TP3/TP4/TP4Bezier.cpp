//R. RAFFIN, IUT Aix-Marseille, dépt. Informatique - Arles
//TP événements, push & pop
//compilation par : g++ -Wall TP3.cpp -lGLEW -lGLU -lGL -lglut -o TP3

#include <cstdio>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <deque>

#include "point3.h"

#define KEY_ESC 27

using namespace std;

float angle=0.0f;

float ax = 0.0f, ay = 0.0f;

//variables pour la gestion des paramètres de la fenêtre
float windowRatio = 1.0f;
int windowHeight = 500;
int windowWidth = 500;

float mouseAngleX = 0.0;
float mouseAngleY = 0.0;
int oldMouseX = windowHeight/2;
int oldMouseY = windowWidth/2;

std::deque<point3> * controlPointList;// la structure pour les points de contrôle (sans classe à tous les points de vue)

GLuint leVBO;//pour afficher les points de contrôle

void drawAxis() {
	glBegin(GL_LINES);
		//Ox, rouge
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(8.0, 0.0, 0.0);

		//Oy, vert
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 8.0, 0.0);

		//Oz, bleu
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 8.0);

	glEnd();
}

static void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Modification de la matrice de projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //remise à 0 (identité)
	//gluPerspective(130.0, windowRatio, 0.1, 100); //définition d'une perspective (angle d'ouverture 130°,rapport L/H=1.0, near=0.1, far=100)
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);

	//Modification de la matrice de modélisation de la scène
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Définition de la position de l'observateur
	//gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //paramètres position(5.0, 5.0, 5.0), point visé(0.0, 0.0, 0.0), upVector - verticale (0.0, 1.0, 0.0)

	//rotation due aux mouvements de la souris
	glRotatef(mouseAngleX, 1.0, 0.0, 0.0);
	glRotatef(mouseAngleY, 0.0, 1.0, 0.0);

	//dessin des axes du repère
	//drawAxis();

	//dessin du polygone de contrôle
	glColor3f(0.4, 0.4, 0.4);

		//Liaison avec le buffer de vertex
		glEnableClientState(GL_VERTEX_ARRAY);
		glBindBuffer(GL_ARRAY_BUFFER, leVBO);
		glVertexPointer(3, GL_FLOAT, 0, 0); //description des données pointées

	glDrawArrays(GL_LINE_STRIP, 0, controlPointList -> size()); //les éléments à utiliser pour le dessin

	//dessin des points de contrôle
	//avec le même tableau de donnes (le VBO)
	glColor3f(0.8, 0.8, 0.3);
		//on modifie la taille d'un point pour plus de "joliesse"
		glPointSize(10.0f);
		glDrawArrays(GL_POINTS, 0, controlPointList -> size()); //les éléments à utiliser pour le dessin

	glDisableClientState(GL_VERTEX_ARRAY);

	glutSwapBuffers();
}

//A lier à la glutIdleFunc
static GLvoid callback_Idle()
{
	//angle += 1.0f;
	glutPostRedisplay();

}

// fonction de call-back pour la gestion des evenements clavier
static GLvoid callback_Keyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case KEY_ESC:
	cout << "callback_Keyboard - " << "sortie de la boucle de rendu" << endl;
		glutLeaveMainLoop ( ); //retour au main()
	break;

  default:
    	cerr << "callback_Keyboard - touche " << key << " non active." << endl;
    break;
  }
}


//fonction de call-back pour le redimensionnement de la fenêtre
static GLvoid callback_Window(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);

	windowWidth = width;
	windowHeight = height;

	windowRatio = float(windowWidth) / float(windowHeight);

	//cout << "callback_Window - " << "new width " << windowWidth << " new height " << windowHeight << endl;
}

static GLvoid callback_Mouse(int wx, int wy) {
//rotation de la scene suivant les mouvements de la souris
	int dx = oldMouseX - wx;
	int dy = oldMouseY - wy;

	oldMouseX = wx;
	oldMouseY = wy;

	mouseAngleX += dy;
	mouseAngleY += dx;

	//cout << "callback_Mouse - " << "mouseAngleX " << mouseAngleX << " mouseAngleY " << mouseAngleY << endl;
}


static void InitializeGlutCallbacks()
{
	//quelle fonction est appelée au rendu ?
	glutDisplayFunc(RenderScene);

	//quelle fonction est appelée quand le GPU est en attente ?
	glutIdleFunc(callback_Idle);

	//quelle fonction est appelée pour traiter les événements du clavier (classique) ?
	glutKeyboardFunc(callback_Keyboard);

	//quelle fonction est appelée pour traiter les événements souris ?
	glutMotionFunc(callback_Mouse);

	//quelle fonction est appelée pour traiter les événements sur la fenêtre ?
	glutReshapeFunc(callback_Window);

	//quelle fonction est appelée pour traiter les touches spéciales du clavier ?
	//glutSpecialFunc(&callback_SpecialKeys);

}

static void InitializeGL() {

	//Z Buffer pour la suppression des parties cachées
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

static void CreateVertexBuffer()
{
	float vertices[controlPointList -> size()*3]; //sommets à 3 coordonnées x,y,z par point

	unsigned n = 0;

	for (std::deque<point3>::iterator it = controlPointList -> begin(); it != controlPointList-> end(); ++it) {
		vertices[n] = (*it).x;
		vertices[n+1] = (*it).y;
		vertices[n+2] = (*it).z;
		n += 3;
	}

 	glGenBuffers(1, &leVBO); //génération d'une référence de buffer object
	glBindBuffer(GL_ARRAY_BUFFER, leVBO); //liaison du buffer avec un type tableau de données
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*controlPointList -> size() * 3, vertices, GL_STATIC_DRAW); //création et initialisation du container de données (size() sommets -> 3*size() floats)
}


void InitializeGeometry() {
	controlPointList = new std::deque<point3>();
	//d'après le sujet
	//P_0(-2,-2,0) P_1=(-1,1,0) P_2=(1,1,0) P_3=(2,-2,0)

	controlPointList -> push_back(point3(-2.0, -2.0, 0.0));
	controlPointList -> push_back(point3(-1.0, 1.0, 0.0));
	controlPointList -> push_back(point3(1.0, 1.0, 0.0));
	controlPointList -> push_back(point3(2.0, -2.0, 0.0));

	CreateVertexBuffer();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("TP4 : Courbe(s) de Bézier");


	//toujours après l'initialisation de glut
	GLenum res = glewInit();

	if (res != GLEW_OK) {
		cerr << "Error: " << glewGetErrorString(res) << endl;
		return (EXIT_FAILURE);
	}

	InitializeGlutCallbacks();
	InitializeGL();
	InitializeGeometry();

	glutMainLoop();

	//désallocation de la liste de points de contôle
	controlPointList -> clear();
	delete controlPointList;

	return (EXIT_SUCCESS);
}
