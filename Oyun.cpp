#include "pch.h"
#include <GL/glut.h>
#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <time.h>

using namespace std;
float X = -1;
float Y = 0.001;
float hedefKonum = 0.7;
float hedefYon = 0.0;
float yukari1 = 0.78716669559478759765625;
float yukari2 = 0.8;
float asagi1 = -1.00014126300811767578125;
float asagi2 = -1.1;

float sabitHiz = 0.0002;
float konum = 0.0;

float mermiX = +1.9;
float mermiY = 0;



int i = 0;



void mermi(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);

	glVertex2f(0.0 + hedefKonum, 0.1);
	glVertex2f(0.0 + hedefKonum, 0.0);
	glVertex2f(0.05 + hedefKonum, 0.0);

	glVertex2f(0.0 + hedefKonum, 0.1);
	glVertex2f(0.05 + hedefKonum, 0.1);
	glVertex2f(0.05 + hedefKonum, 0.0);
	glEnd();
	glFlush();


}


void hedef(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	konum += sabitHiz;
	if ((konum >= yukari1) && (konum <= yukari2) || (konum >= asagi2) && (konum <= asagi1))
	{
		sabitHiz *= -1;
	}


	mermiX += 0.0009;

	//mermi oluşturma
	glColor3f(1.0, 1.0, 0.0);

	glBegin(GL_TRIANGLES);
	glVertex2f(0.0 + mermiX, 0.05 + mermiY);
	glVertex2f(0.0 + mermiX, 0.0 + mermiY);
	glVertex2f(0.05 + mermiX, 0.0 + mermiY);

	glVertex2f(0.0 + mermiX, 0.05 + mermiY);
	glVertex2f(0.05 + mermiX, 0.05 + mermiY);
	glVertex2f(0.05 + mermiX, 0.0 + mermiY);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);

	//hedef oluşturma
	glBegin(GL_TRIANGLES);

	glVertex2f(0.0 + hedefKonum, 0.19 + konum);
	glVertex2f(0.0 + hedefKonum, 0.0 + konum);
	glVertex2f(0.05 + hedefKonum, 0.0 + konum);

	glVertex2f(0.0 + hedefKonum, 0.19 + konum);
	glVertex2f(0.05 + hedefKonum, 0.19 + konum);
	glVertex2f(0.05 + hedefKonum, 0.0 + konum);
	glEnd();

	//silah oluşturma
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_TRIANGLES);
	glVertex2f(0.0 + X, 0.1 + Y);
	glVertex2f(0.1 + X, 0.0 + Y);
	glVertex2f(0.0 + X, -0.1 + Y);
	glEnd();


	srand(time(0));
	float r = ((float)rand() / RAND_MAX) - 0.5;

	if ((0.0 + mermiY) <= (0.19 + konum) && (0.0 + mermiY) >= (0.0 + konum) && (0.025 + mermiX) >= 0.0 + hedefKonum && (0.025 + mermiX) <= (0.05 + hedefKonum))
	{
		i += 1;
		cout << "Skor: " << i << "\n";
		konum = r;
		mermiY = 1.1;
		mermiX = 1.1;
	}

	glFlush();


}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		Y += 0.07;
		break;
	case 's':
		Y -= 0.07;
		break;
	case 'f':
		mermiX = -0.9;
		mermiY = Y;
		break;


	}

}






int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	//  glMatrixMode(GL_PROJECTION);
	  //glLoadIdentitiy();
	  //gluOrtho2d(0,400,0,600);
	  //glutInitWindowPosition(100, 100);

	glutCreateWindow("ODEV 2 ");

	glutKeyboardFunc(keyboard);

	
	glutDisplayFunc(hedef);
	glutIdleFunc(hedef);
	glutMainLoop();
	return 1;
}