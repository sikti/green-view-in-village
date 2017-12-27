#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

float _move_boat1 = 0.00f;
float _speed_boat1 = 0.0025f;

float _move_boat = 0.00f;
float _move_dot = 0.00f;
void update_boat1(int value) {
    if(_speed_boat1>1 || _speed_boat1<0)
    {
        _speed_boat1 = 0.0f;
    }
    _move_boat1 -= _speed_boat1;
    if(_move_boat1 +1.3 < -1.0)
    {
        _move_boat1 = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_boat1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_boat(int value) {
    _move_boat += 0.0025f;
    if(_move_boat-.3 > 1.0)
    {
        _move_boat = -1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_boat, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update_dot(int value) {
    _move_dot += 0.0025f;
    if(_move_dot-1.3 > 1.0)
    {
        _move_dot = -1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(.5, update_dot, 0); //Notify GLUT to call update again in 25 milliseconds
}

void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          update_boat1(0);
          break;
      case GLUT_KEY_DOWN:
          exit(0);
          break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
      case 68:
          _speed_boat1+=0.0025f;
          update_boat1(0);
          break;
      case 70:
          _speed_boat1-=0.0025f;
          update_boat1(0);
          break;
    }
}

void sky(){
    //Sky
        glClear (GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.922);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(1.0, 0.30);
        glVertex2f(-1.0, 0.30);
        glEnd();
}
void river(){
    glBegin(GL_QUADS);
    glColor3f(0.000, 1.000, 1.000);
    glVertex2f(1.0, 0.30);
    glVertex2f(-1.0, 0.30);
    glVertex2f(-1.0, -0.30);
    glVertex2f(1.0, -0.30);
    glEnd();
}
void dot(){
        glPushMatrix();//start_pushpop
    glTranslatef(_move_dot, 0.0f, 0.0f);
        glTranslatef(0.0, 0.03, 0.0);
        glScalef(0.1, 0.90, 0);
        glPushMatrix();
        glColor3f(0.125, 0.698, 0.667);
        glBegin(GL_QUADS);
    //glColor3f(0.184, 0.310, 0.310);
    for(float i = -1; i<=1000; i =i+0.25){
        glVertex2f(i,0.30);
        glVertex2f(i,-0.30);
        glVertex2f(i+0.01,-0.30);
        glVertex2f(i+0.01,0.30);
    }
        glEnd();
        glPopMatrix();

}


void boat(){
        glPushMatrix();//start_pushpop
    glTranslatef(_move_boat, 0.0f, 0.0f);
        glTranslatef(0.0, 0.15, 0.0);
        glScalef(0.55, 0.55, 0);
        glPushMatrix();
        glColor3f(0.647, 0.165, 0.165);
        glBegin(GL_QUADS);
        glVertex2f(0.35, 0.20);
        glVertex2f(0.75, 0.20);
        glVertex2f(0.95, 0.30);
        glVertex2f(0.15, 0.30);

        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_boat, 0.0f, 0.0f);
        glTranslatef(0.12, 0.16, 0.0);
        glScalef(0.50, 0.50, 0);
        glColor3f(0.948,0.934,0.734);
        glBegin(GL_QUADS);
        glVertex2f(0.70, 0.30);
        glVertex2f(0.10, 0.30);
        glVertex2f(0.10, 0.45);
        glVertex2f(0.70, 0.45);

        glEnd();
        glPopMatrix();

}

void boat1(){
    glPushMatrix();//start_pushpop
    glTranslatef(_move_boat1, 0.0f, 0.0f);
        glColor3f(0.647, 0.165, 0.165);
        glBegin(GL_POLYGON);
        glVertex2f(0.75, -0.20);
        glVertex2f(0.45, -0.20);
        glVertex2f(0.40, -0.05);
        glVertex2f(0.80, -0.05);
        glEnd();
        glPopMatrix();
    glPushMatrix();//start_pushpop
    glTranslatef(_move_boat1, 0.0f, 0.0f);
        glColor3f(0.529, 0.808, 0.922);
        glBegin(GL_POLYGON);
        glVertex2f(0.75, -0.05);
        glVertex2f(0.45, -0.05);
        glVertex2f(0.45, 0.10);
        glVertex2f(0.75, 0.10);
        glEnd();
        glPopMatrix();
}

void myDisplay(void){
    glLoadIdentity();
    sky();
    river();
    dot();
    boat();
    boat1();
    glFlush();
}

void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1366, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("village");
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(20, update_boat, 0);
    glutTimerFunc(.1, update_dot, 0);
    myInit ();
    glutMainLoop();
}
