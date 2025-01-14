#include<gl\glew.h>
#include<GLFW\glfw3.h>
#include<stdlib.h>
#include"glut.h"
#include<iostream>
using namespace std;
void lines()
{
	int p1[] = { 6,4 }, p2[] = { 2,2 }, p3[] = { 3,7 }, p4[] = { 5,1 }, p5[] = { 0,4 };
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.1, 0.8);
	glPointSize(3);
	glBegin(GL_LINE_LOOP);
	glVertex2iv(p1);
	glVertex2iv(p2);
	glVertex2iv(p3);
	glVertex2iv(p4);
	glVertex2iv(p5);
	glEnd();
	glFlush();
}
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 20, -10, 20);
}
int main(int argc,char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);
	glutInitWindowSize(600, 500);
	glutCreateWindow("Lines");
	init();
	glutDisplayFunc(lines);
	glutMainLoop();
	return 0;

}

