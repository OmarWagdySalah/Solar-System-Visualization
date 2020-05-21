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
    glClearColor(0,0,0.0,0);                            //clearing the backGround with a black colour

    glMatrixMode(GL_MODELVIEW); /* future matrix manipulations should affect the modelview matrix */

    /* draw scene */
                glPushMatrix();
                    ///drawing the Sun
                    glRotated(theta*PI,0.5,0.5,0.50);         ///Specifying the axis of rotation and the rotational speed
                    glColor3f(1.0, 0.6 ,0.0);                 ///setting  the sun's colour to yellow
                    glutSolidSphere(.3,36,36);                 /// Drawing the Sun as a solid sphere with radius 0.3
                glPopMatrix();
                glPushMatrix();
                    ///Draw Mercury
                    glRotated(theta*PI,0.5,0.35,0.750);         ///Specifying the axis of rotation and the rotational speed
                    displacement+=0.5;
                    glTranslated(displacement,0,0);               ///Translating mercury 0.5 away from the sun
                    glColor3f(0.5,.4,.4);                           ///setting mercury's colour to gray
                    glutSolidSphere(0.05,36,36);                    /// Drawing Mercury as a solid sphere with radius 0.05
                glPopMatrix();
                glPushMatrix();
                   ////Draw Venus
                    glRotated(theta*PI/2,0.2,0.6,0.70);     ///Specifying the axis of rotation and the rotational speed
                    displacement+=0.2;
                    glTranslated(displacement,0,0);          ///Translating Venus 0.2 away from  mercury
                    glColor3f(0.6,.6,.2);                       ///setting Venus's colour to  pale yellow
                    glutSolidSphere(0.08,36,36);                 /// Drawing Venus as a solid sphere with radius 0.08
                glPopMatrix();
                glPushMatrix();
                 ///Draw the Earth
                    glRotated(theta*PI/3,0.5,0.76,0.60);            ///Specifying the axis of rotation and the rotational speed

                    displacement+=0.2;
                    glTranslated(displacement,0,0);                     ///Translating Earth 0.2 away from  Venus
                    glColor3f(0,0,.7);                                     ///adjust Earth's Colour tp blue
                    glutSolidSphere(0.085,36,36);                       /// Drawing the Earth as a solid sphere with radius 0.085

                glPopMatrix();
                glPushMatrix();
                    ///Draw Mars
                    glRotated(theta*PI/4,0.4,0.5,0.50);                          ///Specifying the axis of rotation and the rotational speed
                        displacement+=0.25;
                        glTranslated(displacement,0,0);                     ///Translating Mars 0.25 away from the Earth
                        glColor3f(1,.3,0);                                  ///setting Mars's colour to   reddish brown
                        glutSolidSphere(.045,36,36);                       /// Drawing  Mars as a solid sphere with radius 0.045
                glPopMatrix();
                glPushMatrix();
                    ///Draw Jupiter
                    glRotated(theta*PI/5,0.5,0.5,0.50);                  ///Specifying the axis of rotation and the rotational speed
                        displacement+=.3;
                        glTranslated(displacement,0,0);                     ///Translating Jupiter 0.3 away from  Mars
                        glColor3f(.8,.6,0.3);                                  ///setting Jupiter's colour to  Orange-White
                        glutSolidSphere(.15,36,36);                       /// Drawing  Jupiter as a solid sphere with radius 0.15
                glPopMatrix();
                glPushMatrix();
                    ///Draw Saturn
                    glRotated(theta*PI/6,0.5,0.45,0.55);                         ///Specifying the axis of rotation and the rotational speed
                    displacement+=0.3;
                    glTranslated(displacement,0,0);                     ///Translating Saturn 0.3 away from  Jupiter
                        glColor3f(.9,.8,0.4);                                  ///setting Saturn's colour to  Pale Gold
                        glutSolidSphere(.12,36,36);                       /// Drawing  Saturn as a solid sphere with radius 0.12
                glPopMatrix();
                glPushMatrix();
                    ///Draw Uranus
                    glRotated(theta*PI/7,0.65,0.55,0.70);                         ///Specifying the axis of rotation and the rotational speed
                         displacement+=0.3;
                        glTranslated(displacement,0,0);                     ///Translating Uranus 0.3 away from  Saturn
                        glColor3f(.9,.8,0.3);                                  ///setting Uranus's colour to  pale blue
                        glutSolidSphere(.1,36,36);                       /// Drawing  Uranus as a solid sphere with radius 0.1
                glPopMatrix();
                glPushMatrix();
                    ///Draw Neptune
                    glRotated(theta*PI/8,0.4,0.5,0.50);                         ///Specifying the axis of rotation and the rotational speed

                        displacement+=0.3;
                        glTranslated(displacement,0,0);                     ///Translating Neptune 0.3 away from  Uranus
                        glColor3f(0,0,0.3);                                  ///setting Neptune's colour to  pale blue
                        glutSolidSphere(.1,36,36);                       /// Drawing  Neptune as a solid sphere with radius 0.1

                glPopMatrix();
     theta= (theta+.3);                                         ///Incrementing the angle of rotation

    glFlush();                              /// flush drawing routines to the window


}

void reshape ( int width, int height ) {

    /// define the viewport transformation
    glViewport(0,0,width,height);

}
void idle ()
{
    ///Redisplaying the scene
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
    glutCreateWindow("Solar System");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,-2,2.0);              ///Applying orthogonal projection
    //gluPerspective(60,2,1,1000);
    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0,1.0,1.0,0,0,0.0,0.0,1.0,0.0);         ///Look at point


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
