#include <GL/gl.h>
#include <GL/glut.h>

#include <math.h>
#define PI 3.14159265
float theta=0;
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { -20.0f, 10.0f, 0.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 50.0f };

void display () {
    float displacement=0;
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0.0009,0);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);

    /* draw scene */
                glPushMatrix();
                    //draw the Sun
                    glRotated(theta*PI,0.5,0.5,0.50);
                    glColor3f(1.0, 0.6 ,0.0);
                    glutSolidSphere(.3,36,36);
                glPopMatrix();
                glPushMatrix();
                    //Draw Mercury
                    glRotated(theta*PI,0.5,0.35,0.750);
                    displacement+=0.5;
                    glTranslated(displacement,0,0);
                    glColor3f(0.5,.4,.4);
                    glutSolidSphere(0.05,36,36);
                glPopMatrix();
                glPushMatrix();
                   //Draw Venus
                    glRotated(theta*PI/2,0.2,0.6,0.70);
                    displacement+=0.2;
                    glTranslated(displacement,0,0);
                    glColor3f(0.6,.6,.2);
                    glutSolidSphere(0.08,36,36);
                glPopMatrix();
                glPushMatrix();
                 //Draw the Earth
                    glRotated(theta*PI/3,0.5,0.76,0.60);
                    double rEarth=0.1;
                 /*   float x=rEarth* cos(theta*PI/180);
                    float y=rEarth* sin(theta*PI/180);*/
                    displacement+=0.2;
                    glTranslated(displacement,0,0);
                    glColor3f(0,0,.7);               //adjust Earth's Colour
                    glutSolidSphere(0.085,36,36);

                glPopMatrix();
                glPushMatrix();
                    //Draw Mars
                    glRotated(theta*PI/4,0.4,0.5,0.50);
                        displacement+=0.25;
                        glTranslated(displacement,0,0);
                        glColor3f(1,.3,0);
                        glutSolidSphere(.045,36,36);
                glPopMatrix();
                glPushMatrix();
                    //Draw Jupiter
                    glRotated(theta*PI/5,0.5,0.5,0.50);
                        displacement+=.3;
                        glTranslated(displacement,0,0);
                        glColor3f(.8,.6,0.3);
                        glutSolidSphere(.15,36,36);
                glPopMatrix();
                glPushMatrix();
                    //Draw Saturn
                    glRotated(theta*PI/6,0.5,0.45,0.55);
                    displacement+=0.3;
                    glTranslated(displacement,0,0);
                        glColor3f(.9,.8,0.3);
                        glutSolidSphere(.12,36,36);
                glPopMatrix();
                glPushMatrix();
                    //Draw Uranus
                    glRotated(theta*PI/7,0.65,0.55,0.70);
                         displacement+=0.3;
                        glTranslated(displacement,0,0);
                        glColor3f(.9,.8,0.3);
                        glutSolidSphere(.1,36,36);
                glPopMatrix();
                glPushMatrix();
                    //Draw Neptune
                    glRotated(theta*PI/8,0.4,0.5,0.50);

                        displacement+=0.3;
                        glTranslated(displacement,0,0);
                        glColor3f(0,0,0.3);
                        glutSolidSphere(.1,36,36);

                glPopMatrix();
     theta= (theta+.3);
    /* flush drawing routines to the window */

    glFlush();

}

void reshape ( int width, int height ) {

    /* define the viewport transformation */
    glViewport(0,0,width,height);

}
void idle ()
{
    glutPostRedisplay();
}
int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */

    glutInitWindowSize(1500,800);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB);

    /* create and set up a window */
    glutCreateWindow("hello, teapot!");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,-2,2.0);
    //gluPerspective(60,2,1,1000);
    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0,1.0,1.0,0,0,0.0,0.0,1.0,0.0);


    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH);
    glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    /* tell GLUT to wait for events */



    glutMainLoop();
}
