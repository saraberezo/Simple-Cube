// Template1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"


double rotate_y = 0;
double rotate_x = 0;

void specialKeys(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	glutPostRedisplay();
}


void MyDisplay(void) {

	//  Borrar pantalla y Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// The new scene
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(0, 0, -5.0f);

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	// FRONT SIDE: white
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(1, -1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, -1, 1);
	glEnd();

	// BACK SIDE: yellow
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(1, -1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, -1, -1);
	glEnd();

	// RIGHT SIDE: purple
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(1, -1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, -1, 1);
	glEnd();

	// LEFT SIDE: green
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, -1, -1);
	glEnd();

	// TOP SIDE: blue
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, 1, 1);
	glEnd();

	// BOTTOM SIDE: red
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, -1, -1);
	glEnd();

	// The end of scene
	glFlush();//start processing buffered OpenGL routines
}


void MyInit(void) {
	glEnable(GL_DEPTH_TEST); // It test each pixel and decide if it must be shown or not
	glClearColor(0.0, 0.0, 0.0, 0.0);//select clearing (background) color
									 /* initialize viewing values */
	glViewport(0, 0, 300, 300);//window origin and size
	glMatrixMode(GL_PROJECTION);//
	glLoadIdentity();//=1
	gluPerspective(45.0f, (float)(16 / 9), 0.1f, 500.0f);
	/*
	void gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
		fovy: Specifies the field of view angle, in degrees, in the y direction.
		aspect: Specifies the aspect ratio that determines the field of view in the x direction.The aspect ratio is the ratio of x(width) to y(height).
		zNear: Specifies the distance from the viewer to the near clipping plane(always positive).
		zFar: Specifies the distance from the viewer to the far clipping plane(always positive).
	*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//=1
}

int main(int argc, char** argv) { //<- for normal API
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);//single buffer and RGBA
	glutInitWindowSize(500, 500);//initial window size
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cube");//create widnow, hello title bar
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutSpecialFunc(specialKeys);
	glutMainLoop();//enter main loop and process events
	return 0;
}