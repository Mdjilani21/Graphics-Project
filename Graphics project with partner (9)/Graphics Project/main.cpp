#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.1416

float boost = 0.0;
float boost_fire = 0.0;
float fire = -51.5;

void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle = 2 * PI * i / 100;
        glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
    }

    glEnd();
}

void lines(float x1, float y1, float x2, float y2)
{
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f( 0, 0, 0);
    glVertex3f(x1,y1, 0);
    glVertex3f(x2,y2,0);
    glEnd();
    glPopMatrix();
}

void quads(float x1, float y1, float x2, float y2, float x3,
           float y3, float x4, float y4)
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(x1,y1+boost,0);
    glVertex3f(x2,y2+boost,0);
    glVertex3f(x3,y3+boost,0);
    glVertex3f(x4,y4+boost,0);
    glEnd();
    glPopMatrix();
}

void triangle(float x1, float y1, float x2, float y2, float x3,
              float y3)
{
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(x1,y1+boost,0);
    glVertex3f(x2,y2+boost,0);
    glVertex3f(x3,y3+boost,0);
    glEnd();
    glPopMatrix();
}

void fire_triangle(float x1, float y1, float x2, float y2, float x3,
              float y3)
{
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex3f(x1,y1+boost,0);
    glColor3f(1,0,0);
    glVertex3f(x2,y2+boost,0);
    glColor3f(0.917647 , 0.917647 , 0.678431);
    //glColor3f(1 , 0.25 , 0);
    glVertex3f(x3,y3+boost,0);
    glEnd();
    glPopMatrix();
}

void display()
{
    //clear the display
    //color black
    glClearColor(0, 0, 0, 0);

    //clear buffers to preset values
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /***************************
    / set-up camera (view) here
    ****************************/

    //load the correct matrix -- MODEL-VIEW matrix
    //specify which matrix is the current matrix
    glMatrixMode(GL_MODELVIEW);

    //initialize the matrix
    //replace the current matrix with the identity matrix [Diagonals have 1, others have 0]
    glLoadIdentity();

    //now give three info
    //1. where is the camera (viewer)?
    //2. where is the camera looking?
    //3. Which direction is the camera's UP direction?
    gluLookAt(0,0,100,	0,0,0,	0,1,0);

    //moon and stars
//    glPushMatrix();
//    glTranslatef(-57.75,55.25,0);
//    glColor3f(0, 0, .77);
//    circle(4,4);
//    glPopMatrix();

    glPushMatrix();
    glTranslatef(-57,55,0);
    glColor3f(0.8758824, 0.858824, 0.958824);
    circle(4,4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35,49,0);
    glColor3f(0.8758824, 0.858824, 0.958824);
    circle(0.4,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(16,33,0);
    glColor3f(0.8758824, 0.858824, 0.958824);
    circle(0.5,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25,45,0);
    glColor3f(0.8758824, 0.858824, 0.958824);
    circle(0.3,0.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,50,0);
    glColor3f(0.8758824, 0.858824, 0.958824);
    circle(0.3,0.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,30,0);
    glColor3f(0.8758824, 0.858824, 0.958824);
    circle(0.3,0.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(17,54,0);
    glColor3f(0.8758824, 0.858824, 0.958824);
    circle(0.5,0.5);
    glPopMatrix();

    //Rocket Holder

    lines(-39,-15.2,-30,-15.2);
    lines(-39,-15,-30,-15);

    //X lines 1
    lines(-39,-5,-30,-15.3);
    lines(-38.9,-4.9,-30.2,-15.2);

    lines(-30,-5,-39,-15.3);
    lines(-39,-15.2,-39,-15.3);


    lines(-39,-25.2,-30,-25.2);
    lines(-39,-25,-30,-25);

    //X lines 2
    lines(-39,-15.2,-30.1,-25.2);
    lines(-38.9,-15.1,-30,-25.3);

    lines(-30.2,-15.3,-39,-25.2);
    lines(-30.2,-15.2,-39,-25.1);


    lines(-39,-35.2,-30,-35.2);
    lines(-39,-35,-30,-35);

    //X lines 3
    lines(-39.1,-25,-30,-35);
    lines(-39,-25.2,-30,-34.9);

    lines(-30,-25.3,-39,-35);
    lines(-30.1,-25.2,-39.1,-34.9);

    lines(-39,-45.8,-30,-45.8);
    lines(-39,-45.6,-30,-45.6);

    //X lines 4
    lines(-39,-35,-30,-45.8);
    lines(-39.1,-35,-30,-45.7);

    lines(-30,-35,-39,-45.8);
    lines(-30,-35.1,-39.1,-45.87);

    //X lines 5
    lines(-39,-45.8,-30,-53.8);
    lines(-39.1,-45.8,-30,-53.7);

    lines(-30,-45.8,-39,-53.8);
    lines(-30,-45.7,-39.1,-53.8);


    lines(-29.7,-15.3,-27,-11);

    lines(-29.7,-25.3,-27,-20);

    lines(-29.7,-35,-27,-30);

    lines(-29.7,-45.8,-27,-41);

    // Rocket Red Belt
    glColor3f(0.647059, 0.164706, 0.164706);
    quads(-21, -38, -16, -38, -16, -36, -21, -36);

    glColor3f(0.647059, 0.164706, 0.164706);
    quads(-21, -24, -16, -24, -16, -22, -21, -22);

    //Rocket Head
    glColor3f( 0.329412,0.329412,0.329412);
    triangle(-21, -10, -16, -10, -18.5, 0);

    glColor3f(0.137255,0.137255, 0.556863);
    quads(-18.5, -53.5, -19.5, -49, -18.5, -45, -17.5, -49);
    //Main Body
    glColor3f( 1, 1, 1);
    quads(-21, -49, -16, -49, -16, -10, -21, -10);

    //Rocket Legs
    glColor3f(0.137255,0.137255, 0.556863);
    triangle(-21,-49, -21, -45, -26, -52);

    glColor3f(0.137255,0.137255, 0.556863);
    triangle(-16, -49, -16, -45, -11, -52);

    //glColor3f(0.8, 0.25500, 0);
    fire_triangle(-16.5, -51.5, -20.5, -51.5,-18.5,fire);
    //Fire tail
    glColor3f(0.435294, 0.258824, 0.258824);
    quads(-19.5, -49, -17.5, -49, -16, -51.5, -21, -51.5);

    //1
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f( 1.0, 0.498039, 0.0);
    glVertex3f(-39,-53.8,0);
    glColor3f( 0.329412,0.329412,0.329412);
    glVertex3f(-30,-53.8,0);
    glColor3f( 0.647059, 0.164706,0.164706);
    glVertex3f(-30,-5,0);
    glColor3f( 0.258824,0.258824, 0.435294);
    glVertex3f(-39,-5,0);
    glEnd();
    glPopMatrix();

//2
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f( 0.678431, 0.917647, 0.917647);
    glVertex3f(-29.7,-53.8,0);
    glVertex3f(-27,-48.8,0);
    glVertex3f(-27,-1.5,0);
    glVertex3f(-29.7,-5,0);
    glEnd();
    glPopMatrix();

    //3
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f( 0.678431, 0.917647, 0.917647);
    glVertex3f(-39,-4.8,0);
    glVertex3f(-30,-4.8,0);
    glVertex3f(-27,-1.5,0);
    glVertex3f(-36,-1.5,0);
    glEnd();
    glPopMatrix();

//background   1= glColor3f(0.00011, 0.00023 , 0.00000063); 2= glColor3f(0, 0, .92);
//sky          3= glColor3f(0, 0, 0.00059); 4= glColor3f(.78, .31, 0.0000099);

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.00011, 0.00023, 0.00000063);
    glVertex3f(-100,-15,0);
    glColor3f(.78, .31, 0.0000099);
    glVertex3f(100,-15,0);
    glColor3f(0.00011, 0.00023, 0.00000063);
    glVertex3f(100,80,0);
    glColor3f(0, 0, .92);
    glVertex3f(-100,80,0);
    glEnd();
    glPopMatrix();

    //Rocket Stand
    //1
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex3f(-55,-63,0);
    glVertex3f(28,-63,0);
    glVertex3f(25.3,-55,0);
    glVertex3f(-51,-55,0);
    glEnd();
    glPopMatrix();

    //2
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex3f(28.3,-63,0);
    glVertex3f(36.8,-51.5,0);
    glVertex3f(31.6,-48.5,0);
    glVertex3f(25.8,-55.2,0);
    glEnd();
    glPopMatrix();

    //3
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex3f(-51,-54.7,0);
    glVertex3f(25.3,-54.7,0);
    glVertex3f(31.2,-48.5,0);
    glVertex3f(-41.7,-48.5,0);
    glEnd();
    glPopMatrix();

    //FIELD
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.051,0.0082, 0.075);
    glVertex3f(-100,-75,0);
    glColor3f(0.091,0.0082, 0.052);
    glVertex3f(100,-75,0);
    glColor3f(0.081,0.062, 0.052);
    glVertex3f(100,-15,0);
    glColor3f(0.091,0.0082, 0.052);
    glVertex3f(-100,-15,0);
    glEnd();
    glPopMatrix();

    //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
    glutSwapBuffers();
}

void animate()
{

    //this will call the display AGAIN
    glutPostRedisplay();
}

void init()
{
    //clear the screen
    glClearColor(0, 0, 0, 0);

    /************************
    / set-up projection here
    ************************/

    //load the PROJECTION matrix
    glMatrixMode(GL_PROJECTION);

    //initialize the matrix
    glLoadIdentity();

    /*
    gluPerspective() — set up a perspective projection matrix

    fovy -         Specifies the field of view angle, in degrees, in the y direction.
    aspect ratio - Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
    zNear -        Specifies the distance from the viewer to the near clipping plane (always positive).
    zFar  -        Specifies the distance from the viewer to the far clipping plane (always positive).
    */

    gluPerspective(70, 1, 0.1, 10000.0);

}
void specialKeyListener(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
	    //PlaySound("Rocket.wav", NULL, SND_FILENAME| SND_ASYNC);
        boost = boost + 0.5;
        if(boost_fire > -1.5)
        {
            fire = fire + boost_fire;
            boost_fire = boost_fire - 0.05;
        }
//        if(boost_fire > 10)
//        {
//            boost_fire = boost_fire - 0.5;
//        }
    }
	else if (key == GLUT_KEY_DOWN)
	{
	    if(boost>=0)
            boost = boost - 0.5;
        if(boost_fire <= 0 )
        {
            fire = fire - boost_fire;
            boost_fire = boost_fire + 0.05;
        }
	}
}

void keyboardListener(unsigned char key, int x, int y)
{
   if(key == 's')
   {
        PlaySound("Missle_Launch.wav", NULL, SND_FILENAME| SND_ASYNC);
        PlaySound("Explosion.wav", NULL, SND_FILENAME| SND_ASYNC);
   }
}

int main()
{
    PlaySound("Rocket.wav", NULL, SND_FILENAME| SND_ASYNC);
    //PlaySound("Explosion.wav", NULL, SND_FILENAME| SND_ASYNC);
    glutInitWindowSize(1250, 700);
    glutInitWindowPosition(0, 0);
    /*
    glutInitDisplayMode - inits display mode
    GLUT_DOUBLE - allows for display on the double buffer window
    GLUT_RGBA - shows color (Red, green, blue) and an alpha
    GLUT_DEPTH - allows for depth buffer
    */
//	PlaySound("Horn Honk.wav", NULL, SND_FILENAME| SND_ASYNC);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

    glutCreateWindow("Rocket!");

    //codes for initialization
    init();

    //enable Depth Testing
    glEnable(GL_DEPTH_TEST);

    //display callback function
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeyListener);
    glutKeyboardFunc(keyboardListener);
    //what you want to do in the idle time (when no drawing is occurring)
    glutIdleFunc(animate);

    //The main loop of OpenGL
    glutMainLoop();

    return 0;

    return 0;
}
