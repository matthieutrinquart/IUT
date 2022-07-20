
//Famechon Trinquart info2 TD IN TP1 2020
#include <GL/glew.h> //attention, à inclure avant gl.h

#include <GL/gl.h>
#include <GL/freeglut.h>

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <time.h>
#include <deque>

#include <iostream>

//pour la gestion des sources des shaders et la compilation de chacun
#include "glsl_fs.h"
#include "glsl_vs.h"
#include "glsl_program.h"

//des fonctions utiles (lecture fichier, glewInfo, classe objetOFF)
#include "fonctions.h"
#include "objetsOFF.h"

using namespace std;
#define ECHAP 27

#ifndef M_PI
	define M_PI	3.14159265358979323846
#endif

float MatSpec[4] = {1.0f, 1.0f, 1.0f, 1.0f}; //blanc
float MatDif[4] = {1.0f, 1.0f, 1.0f, 1.0f}; //blanc
float MatAmb[4] = {0.3f, 0.3f, 0.3f, 1.0f}; //gris foncé

float Light1Pos[4] = {0.0f, 0.0f, 20.0f, 1.0f};
float Light1Dif[4] = {0.0f, 0.2f, 0.2f, 1.0f};
float Light1Spec[4] = {0.0f, 0.2f, 0.2f, 1.0f};
float Light1Amb[4] = {0.5f, 0.5f, 0.5f, 1.0f};

GLSL_Program * mes_shaders;
GLint adresse_mem;

float lpos[4] = {1, 0.5, 1,0};
float angle = 0.0f;
float mytime = 0.0f;

float angle_x = 0.0f;
float angle_y = 0.0f;

//variables pour la gestion des paramètres de la fenêtre
float windowRatio = 1.0f;
int windowHeight = 500;
int windowWidth = 500;

//pour les points aléatoires
float pointTab[3];
bool isFirstTime = true;
unsigned int indexSommetActuel;

//une structure pour stocker les paramètres de la contrainte
struct Contrainte {
	float centre[3];
	float vecteur[3];
	float rayon;
};

int rendu;
unsigned int nbimages;

struct Contrainte maContrainte;

//les adresses où ou enverra ces valeurs sur la carte graphique
GLint where_point;
GLint where_vecteur;
GLint where_rayon;
Objet monObjet;

point3D CentremonObjet;
point3D largeur;
float RayonTrajContrainte;

//--------------------------------------------------
//pour les VBO
GLuint VBOCouleurs;
GLuint VBOSommets;
GLuint VBONormales;


void CreateVBOFromObject(Objet * _monObjet)
{

	if (glewIsSupported("GL_ARB_vertex_buffer_object") == GL_FALSE) {
			cerr << "VBO impossibles, non supportés\n";
			exit (1);
	}

	//A priori, les VBO sont supportés

	//création des tableaux de normales et points
	float * lnormales = new float[_monObjet -> nbfaces * 9];
	float * lsommets = new float[_monObjet -> nbfaces * 9];
	float * lcolors = new float[_monObjet -> nbfaces * 9];

	//remplissage des tableaux
	//tableau des couleurs, 1 par point, tirée aléatoirement
	unsigned int cpt = 0;
	for (unsigned int i = 0; i < _monObjet -> nbfaces; i++) {
		lcolors[cpt++] = tirage_alea(0.0, 0.5); //R
		lcolors[cpt++] = tirage_alea(0.0, 0.5); //G
		lcolors[cpt++] = tirage_alea(0.0, 0.5); //B

		lcolors[cpt++] = tirage_alea(0.0, 0.5); //R
		lcolors[cpt++] = tirage_alea(0.0, 0.5); //G
		lcolors[cpt++] = tirage_alea(0.0, 0.5); //B

		lcolors[cpt++] = tirage_alea(0.0, 0.5); //R
		lcolors[cpt++] = tirage_alea(0.0, 0.5); //G
		lcolors[cpt++] = tirage_alea(0.0, 0.5); //B
	}

	//tableau des normales
	cpt=0;
	for (unsigned int i = 0; i < _monObjet -> nbfaces; i++) {
	//On recopie UNE normale par sommets
		lnormales[cpt++] = _monObjet -> lfacesnormales[i].x;
		lnormales[cpt++] = _monObjet -> lfacesnormales[i].y;
		lnormales[cpt++] = _monObjet -> lfacesnormales[i].z;

		lnormales[cpt++] = _monObjet -> lfacesnormales[i].x;
		lnormales[cpt++] = _monObjet -> lfacesnormales[i].y;
		lnormales[cpt++] = _monObjet -> lfacesnormales[i].z;

		lnormales[cpt++] = _monObjet -> lfacesnormales[i].x;
		lnormales[cpt++] = _monObjet -> lfacesnormales[i].y;
		lnormales[cpt++] = _monObjet -> lfacesnormales[i].z;
	}

	cpt = 0;
	//remplissage du tableau des sommets (!! non indexé, 3 points par faces = lourd)
	for (unsigned int i = 0; i < _monObjet -> nbfaces; i++) {

		lsommets[cpt++] = _monObjet->lpoints[_monObjet->lfaces[i].S1].x;
		lsommets[cpt++] = _monObjet->lpoints[_monObjet->lfaces[i].S1].y;
		lsommets[cpt++] = _monObjet->lpoints[_monObjet->lfaces[i].S1].z;

		lsommets[cpt++] = _monObjet->lpoints[_monObjet->lfaces[i].S2].x;
		lsommets[cpt++] = _monObjet->lpoints[_monObjet->lfaces[i].S2].y;
		lsommets[cpt++] = _monObjet->lpoints[_monObjet->lfaces[i].S2].z;

		lsommets[cpt++] = _monObjet->lpoints[_monObjet->lfaces[i].S3].x;
		lsommets[cpt++] = _monObjet->lpoints[_monObjet->lfaces[i].S3].y;
		lsommets[cpt++] = _monObjet->lpoints[_monObjet->lfaces[i].S3].z;
	}


	//VBO pour les sommets
	glGenBuffers((GLsizei) 1, &VBOSommets);
		glBindBuffer(GL_ARRAY_BUFFER, VBOSommets);
		glBufferData(GL_ARRAY_BUFFER, _monObjet -> nbfaces * 9 * sizeof(float), lsommets, GL_STATIC_DRAW);

	//VBO pour les couleurs
	glGenBuffers((GLsizei) 1, &VBOCouleurs);
		glBindBuffer(GL_ARRAY_BUFFER, VBOCouleurs);
		glBufferData(GL_ARRAY_BUFFER, _monObjet -> nbfaces * 9 * sizeof(float), lcolors, GL_STATIC_DRAW);

	//VBO pour les normales
	glGenBuffers((GLsizei) 1, &VBONormales);
		glBindBuffer(GL_ARRAY_BUFFER, VBONormales);
		glBufferData(GL_ARRAY_BUFFER, _monObjet -> nbfaces * 9 * sizeof(float) , lnormales, GL_STATIC_DRAW);

	//on peut les jeter, ca a été transféré à la CG
	delete []lcolors;
	delete []lnormales;
	delete []lsommets;

}

void callback_Timer(int value)
{
	char message[200];
	strcpy(message, "VertexBufferObject ");

}


void LoadOFFObject(Objet * _objet, const char * _fichier_off)
{
	_objet -> charge_OFF(_fichier_off);
}


//Chargement de l'objet 3D, nom du fichier en dur=pas beau
void GeomInit(void)
{
	//unsigned int nfaces;

	//TP3--------------------------------------------------

	monObjet.charge_OFF((const char*) "bunny/bunny.off");
	// monObjet.calcul_normales_faces();
	// monObjet.calcul_normales_points();
	//monObjet.affiche();

	CreateVBOFromObject(&monObjet);
	//-----------------------------------------------------

	//


	monObjet.id=glGenLists(1);

	CentremonObjet.x = (monObjet.max.x+monObjet.min.x)/2.0f;
	CentremonObjet.y = (monObjet.max.y+monObjet.min.y)/2.0f;
	CentremonObjet.z = (monObjet.max.z+monObjet.min.z)/2.0f;


	largeur.x = fabs(monObjet.max.x - CentremonObjet.x);
	largeur.y = fabs(monObjet.max.y - CentremonObjet.y);
	largeur.z = fabs(monObjet.max.z - CentremonObjet.z);


	std::cout << CentremonObjet.x << " " << CentremonObjet.y << " " << CentremonObjet.z << " " << std::endl;


	RayonTrajContrainte=0.6f;

	maContrainte.centre[0]=0.0f;
	maContrainte.centre[1]=0.0f;
	maContrainte.centre[2]=0.0f;

	maContrainte.vecteur[0]=0.0f;
	maContrainte.vecteur[1]=0.0f;
	maContrainte.vecteur[2]=2.0f;

	maContrainte.rayon=0.2f;

}

//fonction de call-back pour le redimensionnement de la fenêtre
static GLvoid callback_Window(GLsizei width, GLsizei height)
{
	//au cas où h soit nul et entraîne une division par 0
	if(height == 0)
		height = 1;

	glViewport(0, 0, width, height);

	windowWidth = width;
	windowHeight = height;

	windowRatio = float(windowWidth) / float(windowHeight);

	cout << "callback_Window - " << "new width " << windowWidth << " new height " << windowHeight << endl;
}

//pour l'instant on ne fait rien en cas d'inactivité
//mais cela pourrait servir à modifier la contrainte...
void callback_Idle() {
	//angle += 0.01f;
	glutPostRedisplay();
}

void DrawVBO()
{
		//On éteint la lumière pour profiter des couleurs...
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

		glBindBuffer( GL_ARRAY_BUFFER, VBOSommets);
		glVertexPointer( 3, GL_FLOAT, 0, (char *) NULL );

		glBindBuffer( GL_ARRAY_BUFFER, VBOCouleurs);
		glColorPointer( 3, GL_FLOAT, 0, (char *) NULL );

		glBindBuffer( GL_ARRAY_BUFFER, VBONormales);
		glNormalPointer(GL_FLOAT, 0, (char *) NULL );

			glDrawArrays(GL_POINTS, 0, monObjet.nbfaces * 3);

	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

//classique OpenGL, l'objet est dans une DisplayList puisqu'il n'est pas modifié
//cela accélère l'envoi de l'objet 3D à la carte graphique
void RenderScene(void)
{



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	glRotatef(angle_x,1,0,0);
	glRotatef(angle_y,0,1,0);

	glOrtho(-largeur.x, largeur.x, -largeur.y, largeur.y, -largeur.z * 2.0f, largeur.z * 2.0f);
	//gluPerspective(90.0, windowRatio, 0.01, 100);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glTranslatef(-CentremonObjet.x, -CentremonObjet.y, -CentremonObjet.z);

	//-------------------------------------------QUESTION 3 --------------------------------------------
	//Si c'est la premiere fois qu'on viens dans le RenderScene
	if(isFirstTime)
	{
		//on choisis un sommet
		indexSommetActuel = rand() % monObjet.nbsommets;

		//on le stock dans un tableau
		pointTab[0] = (float)monObjet.lpoints[indexSommetActuel].x;
		pointTab[1] = (float)monObjet.lpoints[indexSommetActuel].y;
		pointTab[2] = (float)monObjet.lpoints[indexSommetActuel].z;

		isFirstTime = false;
	}else	//si ce n'est pas la premiere fois qu'on est dans le RenderScene
	{
		//booléen pour savoir s'il y a un doublon
		bool doublon1, doublon2;
		//un tableau qui stocke les index des points voisins
		std::deque<unsigned int> tabPointsPossible;
		//on parcour toute les faces
		for(unsigned int i = 0 ; i < monObjet.nbfaces ; ++i)
		{
			doublon1 = false;
			doublon2 = false;

			//Si on trouve le dernier point utilisé
			//Alors on stocke ses voisins
			//et on verifie qu'ils ne sont pas déja stocké
			//on le fait pour S1, S2 et S3
			if(indexSommetActuel == monObjet.lfaces[i].S1 )
			{
				for(unsigned int j = 0 ; j < tabPointsPossible.size() ; ++j)
				{
					if(monObjet.lfaces[i].S2 == tabPointsPossible[j])
						doublon1 = true;
					if(monObjet.lfaces[i].S3 == tabPointsPossible[j])
						doublon2 = true;
				}
				if(!doublon1)
					tabPointsPossible.push_back(monObjet.lfaces[i].S2);
				if(!doublon2)
					tabPointsPossible.push_back(monObjet.lfaces[i].S3);
			}
			else if(indexSommetActuel == monObjet.lfaces[i].S2 )
			{
				for(unsigned int j = 0 ; j < tabPointsPossible.size() ; ++j)
				{
					if(monObjet.lfaces[i].S1 == tabPointsPossible[j])
						doublon1 = true;
					if(monObjet.lfaces[i].S3 == tabPointsPossible[j])
						doublon2 = true;
				}
				if(!doublon1)
					tabPointsPossible.push_back(monObjet.lfaces[i].S1);
				if(!doublon2)
					tabPointsPossible.push_back(monObjet.lfaces[i].S3);
			}
			else if(indexSommetActuel == monObjet.lfaces[i].S3 )
			{
				for(unsigned int j = 0 ; j < tabPointsPossible.size() ; ++j)
				{
					if(monObjet.lfaces[i].S1 == tabPointsPossible[j])
						doublon1 = true;
					if(monObjet.lfaces[i].S2 == tabPointsPossible[j])
						doublon2 = true;
				}
				if(!doublon1)
					tabPointsPossible.push_back(monObjet.lfaces[i].S1);
				if(!doublon2)
					tabPointsPossible.push_back(monObjet.lfaces[i].S2);
			}

		}

		//on choisis un point aléatoirement parmis ses voisins
		unsigned int indexPossible = rand() % (tabPointsPossible.size()) ;

		//on remplace l'ancien index par le nouveau
		indexSommetActuel = tabPointsPossible[indexPossible];

		//on stocke les coordoné du nouveau point voisin
		pointTab[0] = (float)monObjet.lpoints[indexSommetActuel].x;
		pointTab[1] = (float)monObjet.lpoints[indexSommetActuel].y;
		pointTab[2] = (float)monObjet.lpoints[indexSommetActuel].z;
	}

	//on envoie le point a la Carte Graphique a l'addresse de where_point
	// Addresse, 1, valeur
	glUniform3fv(where_point, 1, pointTab);

	//on dessine le VBO
	DrawVBO();

	nbimages++;

	glutSwapBuffers();
}

void BeforeReallyQuit()
{

	cerr << "Nettoyage des ressources\n";


	glDeleteBuffers((GLsizei) 1, &VBOSommets);
	glDeleteBuffers((GLsizei) 1, &VBOCouleurs);
	glDeleteBuffers((GLsizei) 1, &VBONormales);


	cerr << "System Clear :-)\n";
}

//classique
//l'appui sur les touche qsdz modifie l'angle de vue
void callback_Keyboard(unsigned char key, int x, int y) {
switch (key) {

	case 'z':
		angle_x++;
		std::cout << 'z' << std::endl;
		break;
	case 's':
		angle_x--;
		break;

	case 'q':
		angle_y--;
		break;
	case 'd':
		angle_y++;
		break;

	case ECHAP:
		delete mes_shaders;
		cout << "callback_Keyboard - " << "sortie de la boucle de rendu" << endl;
		glutLeaveMainLoop(); //retour au main()
		break;

	default:
		cerr << "La touche " << int(key) << " est non active." << endl;
		cerr << "\t -> Z S Q D pour faire tourner l'objet" << endl;
		break;
	}
}

//La construction des shaders
void SetShaders(void) {
GLSL_VS le_vertex_shader;
GLSL_FS le_fragment_shader;

	le_vertex_shader.ReadSource("Vertex.vert");
	le_vertex_shader.Compile();

	le_fragment_shader.ReadSource("Fragment.frag");
	le_fragment_shader.Compile();

PrintShaderInfo(le_vertex_shader.idvs);
PrintShaderInfo(le_fragment_shader.idfs);
mes_shaders = new GLSL_Program();

	mes_shaders -> Use_VertexShader(le_vertex_shader);
	mes_shaders -> Use_FragmentShader(le_fragment_shader);

	mes_shaders -> Link_Shaders();
	mes_shaders -> Activate();

	//on aura besoin de localiser ces données dans la mémoire de la carte graphique
	//(pour pouvoir les modifier)
										//id de l'adresse, "nom_variable"
	where_point = glGetUniformLocation(mes_shaders -> idprogram, "pointActuel");

PrintProgramInfo(mes_shaders -> idprogram);

}

static void InitializeGlutCallbacks()
{
	//quelle fonction est appelée au rendu ?
	glutDisplayFunc(RenderScene);

	//quelle fonction est appelée quand le GPU est en attente ?
	//fonction inutile, on utilise un timer pour bloquer le framerate
	glutIdleFunc(callback_Idle);

	//quelle fonction est appelée pour traiter les événements du clavier (classique) ?
	glutKeyboardFunc(callback_Keyboard);

	//quelle fonction est appelée pour traiter les événements souris ?
	//glutMotionFunc(callback_Mouse);

	//quelle fonction est appelée pour traiter les événements sur la fenêtre ?
	glutReshapeFunc(callback_Window);

	//quelle fonction est appelée pour traiter les touches spéciales du clavier ?
	//glutSpecialFunc(&callback_SpecialKeys);

}

//Classique OpenGL
void InitializeGL() {

		GLfloat lightPosition [] = { 0.0f, 10.0f, 0.0f, 0.0 };

	//Crée une source de lumière directionnelle
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Définit un modèle d'ombrage
	glShadeModel(GL_SMOOTH);

	//prise en compte des faces avant et arrières
	//glEnable(GL_CULL_FACE);

	//Z Buffer pour la suppression des parties cachées
	glEnable(GL_DEPTH_TEST);

	//La variable d'état de couleur GL_AMBIENT_AND_DIFFUSE
	//est définie par des appels à glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

}

//on s'assure que la carte graphique peut faire de l'openGL2
void GlewInit() {
GLenum err = glewInit();

	if (err != GLEW_OK)
	{
		cerr << "Erreur: " << glewGetErrorString(err) << endl;
	}
	cerr << "initGLEW_ok, ref GLEW " << glewGetString(GLEW_VERSION) << endl;

	if (glewIsSupported("GL_VERSION_2_0"))
		cerr << "ok OpenGL 2.0\n";
	else {
		cerr << "OpenGL 2.0 impossible\n";
		exit(EXIT_FAILURE);
	}

	cout << "OpenGL Vendor: " << (char*) glGetString(GL_VENDOR) << "\n";
	cout << "OpenGL Renderer: " << (char*) glGetString(GL_RENDERER) << "\n";
	cout << "OpenGL Version: " << (char*) glGetString(GL_VERSION) << "\n";
      //cout << "OpenGL Extensions:\n" << (char*) glGetString(GL_EXTENSIONS) << "\n";

}

void MyInit() {
	atexit(&BeforeReallyQuit); // fonction appellée dès que le signal QUIT est reçu

	srand((unsigned int)(time(NULL))); // pour le générateur pseudo-aléatoire
}

void GlInit() {
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.5, 0.5, 1.0, 1.0);

	glShadeModel(GL_SMOOTH);

	//gestion de la lumière
	glEnable(GL_LIGHTING); 	// Active l'éclairage
	glEnable(GL_LIGHT0);

	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,MatSpec);  	//On applique les paramètres du matériau
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,MatDif);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,MatAmb);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,60);

	nbimages = 0;
	glutTimerFunc( 5000, callback_Timer, 0); //démarrage de la fontion action_timer dans 5s
}

int main(int argc, char **argv) {

	//rendu = RENDU_VBO;

	//on crée le contexte OpenGL et la fenêtre
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);

	glutInitWindowPosition(100,100);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("PROJET FAMECHON TRINQUART");

	InitializeGlutCallbacks();

	//attachement des fonctions de l'OpenGL
	//toujours après l'initialisation de glut
	MyInit();
	GlewInit();

	GlInit();
	GeomInit();

	InitializeGL();
	SetShaders();


	glutMainLoop();

	delete mes_shaders;

	return (EXIT_SUCCESS);
}
