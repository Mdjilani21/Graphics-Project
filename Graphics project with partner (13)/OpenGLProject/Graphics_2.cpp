#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <windows.h>
#include <glut.h>


//double cameraAngle;
double R, Rspeed, vAngle, hAngle, angleSpeed,F=0,G=0,H=0,I=0,J=0,K=0;

void drawAxis(){
    glBegin(GL_LINES);

	//+X axis
	glColor3f(1, 0, 0);//red
	glVertex3f(0, 0, 0);
	glVertex3f(1000, 0, 0);

	//-X axis
	glColor3f(1, 0, 1);//purple
	glVertex3f(0, 0, 0);
	glVertex3f(-1000, 0, 0);

    //+Y axis
	glColor3f(0, 1, 0);//green
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1000, 0);

	//-Y axis
	glColor3f(1, 1, 0);//yellow
	glVertex3f(0, 0, 0);
	glVertex3f(0, -1000, 0);

	//+Z axis
	glColor3f(0, 0, 1);//blue
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1000);

	//-Z axis
	glColor3f(0, 1, 1);//cyan
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, -1000);
	glEnd();
}

void drawGrid(){
    int i;

	glColor3f(0.5, 0.5, 0.5);//gray

	glBegin(GL_LINES);
	for (i = -10; i <= 10; i++)
	{
		if (i == 0)
		{
			continue;//SKIP the MAIN axes
		}

		//lines parallel to Y-axis
		glVertex3f(i * 10, -100, 0);
		glVertex3f(i * 10, 100, 0);

		//lines parallel to X-axis
		glVertex3f(-100, i * 10, 0);
		glVertex3f(100, i * 10, 0);
	}
	glEnd();
}

void drawHouse(){



	//yellow
	 glPushMatrix();
	 glColor3f(1, 0, 0);
glRotatef(F, 1,0,0);
	glBegin(GL_QUADS);
	{
		glVertex3f(0, 0, 0);
		glVertex3f(10, 0, 0);
		glVertex3f(10, 10, 0);
		glVertex3f(0, 10, 0);
	}
	glEnd();
	 glPopMatrix();
	 glPushMatrix();
	 glColor3f(0, 1, 0);
     glRotatef(G, 1,0,0);
	glBegin(GL_QUADS);
	{
		glVertex3f(0, 0, 0);
		glVertex3f(10, 0, 0);
		glVertex3f(10, -10, 0);
		glVertex3f(0, -10, 0);
	}
	glEnd();
	 glPopMatrix();

glPushMatrix();
glColor3f(0, 0, 1);
 glTranslatef(10,0,0);
glRotatef(H, 0,1,0);
  glTranslatef(-10,0,0);
	glBegin(GL_QUADS);
	{
		glVertex3f(10, 0, 0);
		glVertex3f(20, 0, 0);
		glVertex3f(20, 10, 0);
		glVertex3f(10, 10, 0);
	}
	glEnd();
	 glPopMatrix();
glPushMatrix();
glColor3f(3, 3, 0);
glTranslatef(0,10,0);
glRotatef(I, 1,0,0);
  glTranslatef(0,-10,0);
	glBegin(GL_QUADS);
	{
		glVertex3f(0, 10, 0);
		glVertex3f(10, 10, 0);
		glVertex3f(10, 20, 0);
		glVertex3f(0, 20, 0);
	}
	glEnd();
	glColor3f(3, 1, 9);
glTranslatef(0,20,0);
glRotatef(J, 1,0,0);
  glTranslatef(0,-20,0);
	glBegin(GL_QUADS);
	{
		glVertex3f(0, 20, 0);
		glVertex3f(10, 20, 0);
		glVertex3f(10, 30, 0);
		glVertex3f(0, 30, 0);
	}
	glEnd();
	 glPopMatrix();

	 glPushMatrix();

	 glPopMatrix();

	  glPushMatrix();
  glColor3f(8, 4, 4);
glRotatef(K, 0,1,0);
	glBegin(GL_QUADS);
	{
		glVertex3f(0, 0, 0);
		glVertex3f(-10, 0, 0);
		glVertex3f(-10, 10, 0);
		glVertex3f(0, 10, 0);
	}
	glEnd();
	 glPopMatrix();


}
void darwSquare(double Length, double R, double G, double B)
{
    glBegin(GL_QUADS);
	{
		glVertex3f(0, 0, 0);
		glVertex3f(10, 0, 0);
		glVertex3f(10, 10, 0);
		glVertex3f(0, 10, 0);
	}
	glEnd();
}
void display()
{
	//codes for Models, Camera

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

	//gluLookAt(0,0,100,	0,0,0,	0,1,0);
	//gluLookAt(200 * sin(cameraAngle), -200 * cos(cameraAngle), 50, 30, 0, 20, 0, 0, 1);

    double x = sqrt(R*R+1);
    double y = atan(1.0/R);

    double a = x*cos(vAngle+y)*cos(hAngle)-R*cos(vAngle)*cos(hAngle);
    double b = x*cos(vAngle+y)*sin(hAngle)-R*cos(vAngle)*sin(hAngle);
    double c = x*sin(vAngle+y)-R*sin(vAngle);

	gluLookAt(R*cos(vAngle)*cos(hAngle),R*cos(vAngle)*sin(hAngle),R*sin(vAngle),  0,0,0,  a,b,c);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);

	/**************************************************
	/ Grid and axes Lines(You can remove them if you want)
	***************************************************/

	// draw the three major AXES
	drawAxis();

	//some grid lines along the field
	drawGrid();

    // drawing a house
    drawHouse();

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void specialKeyListener(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		vAngle+=angleSpeed;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		vAngle-=angleSpeed;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		hAngle-=angleSpeed;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		hAngle+=angleSpeed;
	}
	else if (key == GLUT_KEY_PAGE_UP)
	{
	    if(R>=Rspeed){
            R-=Rspeed;
	    }
	}
	else if (key == GLUT_KEY_PAGE_DOWN)
    {
        R+=Rspeed;
    }

}
void keyboardListener(unsigned char key, int x, int y)
{


     if (key == '1')
    {
        if(G>-90 && G<=0)
        {
            G--;
        }

    }
    else if (key == '2')
    {
        if(G>=-90 && G<0)
        {
            G++;
        }
    }
    else if (key == '5')
    {
        if(H>-90 && H<=0)
        {
            H--;
        }
    }
    else if (key == '6')
    {
        if(H>=-90 && H<0)
        {
            H++;
        }
    }
    else if (key == '7')
    {
        if(I<90 && I>=0)
        {
            I++;
        }
    }
     else if (key == '8')
    {
        if(I<=90 && I>0)
        {
            I--;
        }
    }
     else if (key == '9')
    {
        if(J<90 && J>=0)
        {
            J++;
        }
    }
     else if (key == '0')
    {
       if(J<=90 && J>0)
        {
            J--;
        }
    }
     else if (key == '3')
    {
       if(K<90 && K>=0)
        {
            K++;
        }
    }
     else if (key == '4')
    {
      if(K<=90 && K>0)
        {
            K--;
        }
    }
}
void animate()
{
	//codes for any changes in Models, Camera

	//camera will rotate at 0.0001 radians per frame.
	//cameraAngle += 0.0001;

	//codes for any changes in Models

	//this will call the display AGAIN
	glutPostRedisplay();

}

void init()
{
	//codes for initialization

	//angle in radian
	//cameraAngle = 0;
	R = 100.0;
	Rspeed = 3.0;

	vAngle = 0.0;
    hAngle = 0.0;
    angleSpeed = 0.05;

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
	gluPerspective() � set up a perspective projection matrix

	fovy -         Specifies the field of view angle, in degrees, in the y direction.
	aspect ratio - Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	zNear -        Specifies the distance from the viewer to the near clipping plane (always positive).
	zFar  -        Specifies the distance from the viewer to the far clipping plane (always positive).
	*/

	gluPerspective(70, 1, 0.1, 10000.0);

}

int main(int argc, char **argv)
{
	//initialize the GLUT library
	glutInit(&argc, argv);

	glutInitWindowSize(1000, 750);
	glutInitWindowPosition(0, 0);

	/*
	glutInitDisplayMode - inits display mode
	GLUT_DOUBLE - allows for display on the double buffer window
	GLUT_RGBA - shows color (Red, green, blue) and an alpha
	GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("First_Lab_Another!");

	//codes for initialization
	init();

	//enable Depth Testing
	glEnable(GL_DEPTH_TEST);

	//display callback function
	glutDisplayFunc(display);

	glutSpecialFunc(specialKeyListener);
glutKeyboardFunc(keyboardListener);
	//what you want to do in the idle time (when no drawing is occuring)
	glutIdleFunc(animate);

	//The main loop of OpenGL
	glutMainLoop();

	return 0;
}
