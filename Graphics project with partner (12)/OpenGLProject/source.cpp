#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>


#include<glut.h>
#define PI 3.1416

int num_texture = -1;
GLuint  grassimg, wallimg, winimg,skyimg;

double cameraAngle, cameraAngleDelta;
int canDraw;
double cameraRadius, cameraHeight;
void upperdesign();

//texture function
int LoadBitmapImage(char *filename)
{
	int i, j = 0;
	FILE *l_file;
	unsigned char *l_texture;
	BITMAPFILEHEADER fileheader;
	BITMAPINFOHEADER infoheader;
	RGBTRIPLE rgb;

	num_texture++;

	if ((l_file = fopen(filename, "rb")) == NULL) return (-1);

	fread(&fileheader, sizeof(fileheader), 1, l_file);

	fseek(l_file, sizeof(fileheader), SEEK_SET);
	fread(&infoheader, sizeof(infoheader), 1, l_file);

	l_texture = (byte *)malloc(infoheader.biWidth * infoheader.biHeight * 4);
	memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);
	for (i = 0; i < infoheader.biWidth*infoheader.biHeight; i++)
	{
		fread(&rgb, sizeof(rgb), 1, l_file);

		l_texture[j + 0] = rgb.rgbtRed;
		l_texture[j + 1] = rgb.rgbtGreen;
		l_texture[j + 2] = rgb.rgbtBlue;
		l_texture[j + 3] = 255;
		j += 4;
	}
	fclose(l_file);

	glBindTexture(GL_TEXTURE_2D, num_texture);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	// glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

	free(l_texture);

	return (num_texture);

}

void loadImage()
{
	grassimg = LoadBitmapImage("image/grass.bmp");
	skyimg = LoadBitmapImage("image/sky.bmp");
	wallimg = LoadBitmapImage("image/wall1.bmp");
	winimg = LoadBitmapImage("image/win.bmp");
	printf("Load successful");
}




void window()
{

	glPushMatrix(); {
		glRotatef(90, 1, 0, 0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, winimg);	//bind a named texture to a texturing target

		glBegin(GL_QUADS); {
			//glNormal3f(0,0,1);
			glColor3f(1.0f, 1.0f, 1.0f);
			glTexCoord2f(1, 1);
			glVertex3f(-60, 80, 0);
			glTexCoord2f(0, 1);
			glVertex3f(-60, -60, 0);
			glTexCoord2f(0, 0);
			glVertex3f(60, -60, 0);
			glTexCoord2f(1, 0);
			glVertex3f(60, 80, 0);
		}glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
}

void curvewindow(){
	glPushMatrix(); //building inner
	{
		double equ1[4]; //gate sphere

		equ1[0] = 0;
		equ1[1] = 0;
		equ1[2] = 1;
		equ1[3] = -20;

		glClipPlane(GL_CLIP_PLANE0, equ1);

		glEnable(GL_CLIP_PLANE0); {
			glColor3f(1, .8, .6);
			glScalef(1, 0.5, 1);
			glTranslatef(0, -10, 30);
			glRotatef(90, 1, 0, 0);
			glutSolidTorus(20, 60, 120, 50);
		}glDisable(GL_CLIP_PLANE0);

	}glPopMatrix();

	glPushMatrix(); {
		glScalef(1.4, 0.3, 3);
		glTranslatef(-40, -15, 0);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(1.4, 0.3, 3);
		glTranslatef(40, -15, 0);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glColor3f(0.2, 0.2, 0.2);
		glScalef(2.4, 0.3, 4);
		glTranslatef(0, -15, 5);
		glutSolidCube(30);
	}glPopMatrix();

}


//cylinder
void lil(){
	glPushMatrix(); {
		//glTranslatef(-450,100,280);
		glColor3f(1.0f, 1.0f, 1.0f);
		glScalef(.3, .3, 3);


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, wallimg);

		GLUquadricObj *cylinder_obj = gluNewQuadric();
		gluQuadricTexture(cylinder_obj, GL_TRUE);
		gluCylinder(cylinder_obj, 50, 50, 75, 10, 10);
		glDisable(GL_TEXTURE_2D);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(-450, 100, 650);
		glColor3f(0, 0, 0);
		glScalef(.5, .5, 1);
		glColor3f(0.2, 0.2, 0.2);

	}glPopMatrix();

	//styling 2nd cylinder
	glPushMatrix(); {
		glTranslatef(-450, 100, 390);
		glScalef(.5, .5, 1);

	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(-450, 100, 300);
		glScalef(.5, .5, 1);

	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(-450, 100, 500);
		glScalef(.5, .5, 1);

	}glPopMatrix();

}

void shade(){
	glPushMatrix(); { //shade
		glColor3f(0.8, 0.8, 1);
		glRotatef(310, 1, 0, 0);
		glTranslatef(3, -38, 25);
		glScalef(4, .1, .9);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); { //shade
		glColor3f(0.8, 0.8, 1);
		glRotatef(50, 1, 0, 0);
		glTranslatef(3, 44, 18.5);
		glScalef(4, .1, .9);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); { //triangle
		glColor3f(0.9, 0.9, 0.9);
		glRotatef(90, 0, 0, 1);
		glTranslatef(-52, 59.5, 38);
		glScalef(1.89, .5, 1.5);
		glBegin(GL_TRIANGLES); {
			glVertex3f(20, 0, 0);
			glVertex3f(40, 0, 0);
			glVertex3f(30, 0, 10);
		}glEnd();
	}glPopMatrix();

	glPushMatrix(); { //triangle right
		glColor3f(0.9, 0.9, 0.9);
		glRotatef(90, 0, 0, 1);
		glTranslatef(-52, -60.5, 38);
		glScalef(1.89, .5, 1.5);
		glBegin(GL_TRIANGLES); {
			glVertex3f(20, 0, 0);
			glVertex3f(40, 0, 0);
			glVertex3f(30, 0, 10);
		}glEnd();
	}glPopMatrix();

}


void grass(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grassimg);	//bind a named texture to a texturing target

	glBegin(GL_QUADS); {
		//glNormal3f(0,0,1);
		glColor3f(0.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 1);
		glVertex3f(-30, 30, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-30, -30, 0);
		glTexCoord2f(1, 0);
		glVertex3f(30, -30, 0);
		glTexCoord2f(1, 1);
		glVertex3f(30, 30, 0);
	}glEnd();
	glDisable(GL_TEXTURE_2D);
}


void wintex(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, winimg);	//bind a named texture to a texturing target

	glBegin(GL_QUADS); {
		//glNormal3f(0,0,1);
		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 1);
		glVertex3f(-60, 60, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-60, -60, 0);
		glTexCoord2f(1, 0);
		glVertex3f(60, -60, 0);
		glTexCoord2f(1, 1);
		glVertex3f(60, 60, 0);
	}glEnd();
	glDisable(GL_TEXTURE_2D);
}

void win1(){
	glPushMatrix(); {
		glTranslatef(0, -5, 0);
		glRotatef(90, 1, 0, 0);
		glScalef(.5, 2, 2);
		wintex();
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(2, .3, 8);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(1.8, .5, 2);
		glTranslatef(5, 20, 20);

		glRotatef(90, 0, 0, 1);
		shade();
	}glPopMatrix();
}
void display(){
	//codes for Models, Camera

	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(.3, .3, .3, .3);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//clear buffers to preset values

	/***************************
	/ set-up camera (view) here
	****************************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);		//specify which matrix is the current matrix

	//initialize the matrix
	glLoadIdentity();				//replace the current matrix with the identity matrix [Diagonals have 1, others have 0]


	//gluLookAt(0,-150,20,	0,0,0,	0,0,1);
	gluLookAt(cameraRadius*sin(cameraAngle), -cameraRadius*cos(cameraAngle), cameraHeight, 0, 0, 0, 0, 0, 1);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);



	/****************************
	/ Add your objects from here
	****************************/



	glPushMatrix(); { //base
		glTranslatef(140, 50, -35);
		glColor3f(1, 1, 1);
		glScalef(55, 65, .3);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(135, 45, -25);
		glScalef(27.5, 32.5, 30);
		grass();
	}glPopMatrix();

	glPushMatrix(); { //base
		glTranslatef(140, 50, -15);
		glColor3f(1, 1, 1);
		glScalef(12, 9, .3);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); { //base
		glTranslatef(130, 350, 150);
		glColor3f(1, 1, 1);
		glScalef(40, 14, 12);
		glutSolidCube(30);
	}glPopMatrix();

	//cylinder(boulders)
	glPushMatrix(); {
		glTranslatef(-20, -50, -15);
		lil();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(80, -50, -15);
		lil();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(200, -50, -15);
		lil();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(300, -50, -15);
		lil();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(300, 30, -15);
		lil();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(300, 100, -15);
		lil();
	}glPopMatrix();


	glPushMatrix(); {
		glTranslatef(-20, 30, -15);
		lil();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(-20, 100, -15);
		lil();
	}glPopMatrix();

	//shade
	glPushMatrix(); {
		glTranslatef(140, 70, 210);
		glColor3f(1, 1, 1);
		glScalef(12, 10, .3);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(175, 70, -50);
		glScalef(8, 2.5, 7);
		glRotatef(90, 0, 0, 1);
		shade();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(150, 140, 0);
		glScalef(.5, .5, 1);
		curvewindow();
	}
	glPopMatrix();

	//window
	glPushMatrix(); {

		glTranslatef(40, 140, 0);
		win1();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(260, 140, 0);
		win1();
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(460, 140, 100);
		win1();
	}glPopMatrix();


	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(660, 140, 100);
		win1();
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(860, 140, 100);
		win1();
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(-530, 140, 100);
		win1();
	}glPopMatrix();


	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(-330, 140, 100);
		win1();
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(-130, 140, 100);
		win1();
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(460, 140, 400);
		win1();
	}glPopMatrix();


	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(660, 140, 400);
		win1();
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(860, 140, 400);
		win1();
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(-530, 140, 400);
		win1();
	}glPopMatrix();


	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(-330, 140, 400);
		win1();
	}glPopMatrix();

	glPushMatrix(); {
		glScalef(.8, 1, .5);
		glTranslatef(-130, 140, 400);
		win1();
	}glPopMatrix();


	glPushMatrix(); {
		glTranslatef(140, 350, 300);
		glColor3f(1, 0.8, 1);
		glScalef(30, 10, 5);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(140, 240, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(140, 500, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(-100, 240, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(-100, 500, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();


	glPushMatrix(); {
		glTranslatef(-300, 240, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(-300, 500, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(400, 240, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(400, 500, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(600, 240, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(600, 500, 400);
		glColor3f(.2, .4, 1);
		glScalef(1.5, 1, 4);
		glutSolidCube(30);
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(130, 320, 225);

		glScalef(6.5, 5, 4);
		shade();
	}glPopMatrix();

	//outer top boundary

	for (int i = 0; i < 116; i++) {

		glPushMatrix(); {
			glTranslatef(-450, 160, 355);
			glScalef(.7, .7, 15);
			glColor3f(1, 1, 1);
			glutSolidCube(5);
		}glPopMatrix();
		glTranslatef(10, 0, 0);
	}

	for (int i = 0; i < 118; i++) {

		glPushMatrix(); {
			glTranslatef(-1615, 550, 355);
			glScalef(.7, .7, 15);
			glColor3f(1, 1, 1);
			glutSolidCube(5);
		}glPopMatrix();
		glTranslatef(10, 0, 0);
	}
	for (int i = 0; i < 40; i++) {

		glPushMatrix(); {
			glTranslatef(-1640, 162, 355);
			glScalef(.7, .7, 15);
			glColor3f(1, 1, 1);
			glutSolidCube(5);
		}glPopMatrix();
		glTranslatef(0, 10, 0);
	}
	for (int i = 0; i < 40; i++) {

		glPushMatrix(); {
			glTranslatef(-2800, -240, 355);
			glScalef(.7, .7, 15);
			glColor3f(1, 1, 1);
			glutSolidCube(5);
		}glPopMatrix();
		glTranslatef(0, 10, 0);
	}
		glPushMatrix(); {

		glColor3f(1, 1, 1);
									   //glScalef(1, 1, 34);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, skyimg);

		GLUquadricObj *qObj = gluNewQuadric();

		gluQuadricTexture(qObj, GL_TRUE);

		gluSphere(qObj, 5000, 50, 50);

		glDisable(GL_TEXTURE_2D);

	}glPopMatrix();

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();

}


void animate(){
	//codes for any changes in Models, Camera

	cameraAngle += 0.0000;	// camera will rotate at 0.001 radians per frame.

	//codes for any changes in Models

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN

}
void keyboardListener(unsigned char key, int x, int y){
	switch (key){

	case 'r':
		if (canDraw == 1)
			canDraw = 0;
		else
			canDraw = 1;

		break;

	default:
		break;
	}
}


void specialKeyListener(int key, int x, int y){
	switch (key){
	case GLUT_KEY_DOWN:		//down arrow key
		cameraRadius += 10;
		break;
	case GLUT_KEY_UP:		// up arrow key
		if (cameraRadius > 10)
			cameraRadius -= 10;
		break;

	case GLUT_KEY_RIGHT:
		cameraAngle += 0.01;
		break;
	case GLUT_KEY_LEFT:
		cameraAngle -= 0.01;
		break;

	case GLUT_KEY_PAGE_UP:
		cameraHeight += 10;
		break;
	case GLUT_KEY_PAGE_DOWN:
		cameraHeight -= 10;
		break;

	case GLUT_KEY_INSERT:
		break;

	case GLUT_KEY_HOME:
		cameraAngleDelta = 0.001;
		break;
	case GLUT_KEY_END:
		cameraAngleDelta = 0;
		break;

	default:
		break;
	}
}


void init(){
	//codes for initialization
	loadImage();
	cameraAngle = 0;	//angle in radian
	cameraAngleDelta = .000;
	canDraw = 1;
	cameraRadius = 800;
	cameraHeight = 100;
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

int main(int argc, char **argv){

	glutInit(&argc, argv);							//initialize the GLUT library

	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(100, 100);

	/*
	glutInitDisplayMode - inits display mode
	GLUT_DOUBLE - allows for display on the double buffer window
	GLUT_RGBA - shows color (Red, green, blue) and an alpha
	GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("Project");

	init();						//codes for initialization

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
