#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<glut.h>
#pragma warning(disable: 4996)

double cameraAngle, cameraAngleDelta;
int canDrawGrid;

double cameraHeight;
double cameraRadius;

GLUquadricObj *quadric = gluNewQuadric();
int num_texture = -1;
GLuint  wallimg,skyimg,grassimg,sandimg,cylimg;

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
	cylimg = LoadBitmapImage("image/cyl.bmp");
	sandimg = LoadBitmapImage("image/sand.bmp");
	skyimg = LoadBitmapImage("image/sky.bmp");
	printf("Load suscore=0ccessful");
}

void window(){
	//glScalef(5,5,5);
	glPushMatrix(); {
		glColor3f(0, 0, 0);
		//glTranslatef(-23, 0, 2.5);
		glTranslatef(0,1,0);
		glScalef(10, 5, 2);
		glutSolidCube(1);

	}glPopMatrix();

	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(-5, 0, 0);
		glScalef(1, 10, 4);
		glutSolidCube(1);
	}glPopMatrix();
	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(5, 0, 0);
		glScalef(1, 10, 4);
		glutSolidCube(1);

	}glPopMatrix();
	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(0, 0, 1.5);
		glScalef(10, 10, 1);
		glutSolidCube(1);

	}glPopMatrix();
	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(0, 0, -1.5);
		glScalef(10, 10, 1);
		glutSolidCube(1);

	}glPopMatrix();

	glPushMatrix(); {
		glColor3f(0, 0, .4);
		glTranslatef(0, -4.9, -1.5);
		glScalef(10, 1, 1);
		glutSolidCube(1);

	}glPopMatrix();

	glPushMatrix(); {
		glColor3f(0, 0, .4);
		glTranslatef(0, -4.9, 1.5);
		glScalef(10, 1, 1);
		glutSolidCube(1);

	}glPopMatrix();


	glPushMatrix(); {
		glColor3f(0, 0, .4);
		glTranslatef(-5, -4.9, 0);
		glScalef(1, 1, 4);
		glutSolidCube(1);

	}glPopMatrix();


	glPushMatrix(); {
		glColor3f(0, 0, .4);
		glTranslatef(5, -4.9, 0);
		glScalef(1, 1, 4);
		glutSolidCube(1);

	}glPopMatrix();

}

void bodyBase() {
	glPushMatrix(); {
		glColor3f(.7, .7, .7);
		glTranslatef(0, 0, 0);
		glScalef(100, 100, 1);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();

	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 1, .9);
		glTranslatef(0, 0, 2.5);
		glScalef(100, 100, 4);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();

}

void sideBodyOne() {
	glPushMatrix(); {
		glColor3f(.9, .9, .9);
		glTranslatef(0, 0, 0);
		glScalef(76, 10, 1);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();

	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 1, .9);
		glTranslatef(33, 0, 2.5);
		glScalef(10, 10, 4);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();

	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 1, .9);
		glTranslatef(-33, 0, 2.5);
		glScalef(10, 10, 4);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();

	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 1, .9);
		glTranslatef(0, 0, 2.5);
		glScalef(36, 10, 4);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();


	glPushMatrix(); {
		glTranslatef(23, 0, 2.5);
		window();
	}glPopMatrix();

	glPushMatrix(); {

		glTranslatef(-23, 0, 2.5);
		window();
	}glPopMatrix();

	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(-39, 0, 2);
		glScalef(2, 10, 5);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();
	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(39, 0, 2);
		glScalef(2, 10, 5);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();

}
void sideBodyTwo() {

	glPushMatrix(); {
		glColor3f(.9, .9, .9);
		glTranslatef(0, 0, 0);
		glScalef(76, 10, 1);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();

	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 1, .9);
		glTranslatef(0, 0, 2.5);
		glScalef(76, 10, 4);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();
	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(-39, 0, 2);
		glScalef(2, 10, 5);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();
	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(39, 0, 2);
		glScalef(2, 10, 5);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();

}

void sideBodyThree() {
	glPushMatrix(); {
		glColor3f(.9, .9, .9);
		glTranslatef(0, 0, 0);
		glScalef(76, 10, 1);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();

	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1, 1, 1, .9);
		glTranslatef(33, 0, 2.5);
		glScalef(10, 10, 4);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();

	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1, 1, 1, .9);
		glTranslatef(-33, 0, 2.5);
		glScalef(10, 10, 4);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();

	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 1, .9);
		glTranslatef(0, 0, 2.5);
		glScalef(36, 10, 4);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();


	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 1, .9);
			glTranslatef(23, 0, 2.5);
			glScalef(10, 10, 4);
			glutSolidCube(1);
			glColor3f(0, 0, 0);
			glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();

	glPushMatrix(); {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 1, .9);
		glTranslatef(-23, 0, 2.5);
		glScalef(10, 10, 4);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
		glDisable(GL_BLEND);
	}glPopMatrix();

	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(-39, 0, 2);
		glScalef(2, 10, 5);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();
	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(39, 0, 2);
		glScalef(2, 10, 5);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();

}
void sideBodyPartThree() {
	glPushMatrix(); {
		glColor3f(1, 1, 1);
		glTranslatef(0, 0, 0);
		glScalef(80, 10, 10);
		glutSolidCube(1);
		glColor3f(0, 0, 0);
		glutWireCube(1);
	}glPopMatrix();

}
void sideDesign() {
	for (int i = 10; i <= 55; i += 5) {
		if (i <= 45) {

			glPushMatrix(); {
				glTranslatef(0, 0, i);
				sideBodyOne();
			}glPopMatrix();
		}
		if (i > 45) {
			glPushMatrix(); {
				glTranslatef(0, 0, i);
				sideBodyTwo();
			}glPopMatrix();

		}
	}

}
void sideDesignTwo() {
	for (int i = 10; i <= 120; i += 5) {
		if (i <= 55) {

			glPushMatrix(); {
				glTranslatef(0, 0, i);
				sideBodyThree();
			}glPopMatrix();
		}
		if (i > 60 && i<=65) {
			glPushMatrix(); {
				glTranslatef(0, 0, i);
				sideBodyPartThree();
			}glPopMatrix();
		}

		if (i > 90 && i<=95) {
			glPushMatrix(); {
				glTranslatef(0, 0, i);
				sideBodyPartThree();
			}glPopMatrix();
		}

		if (i > 115 && i <= 120) {
			glPushMatrix(); {
				glTranslatef(0, 0, i);
				sideBodyPartThree();
			}glPopMatrix();
		}
		if (i > 65 && i<=90) {
			glPushMatrix(); {
				glTranslatef(0, 0, i);
				sideBodyTwo();
			}glPopMatrix();
		}


		if (i>95 && i<=115) {
			glPushMatrix(); {
				glTranslatef(0, 0, i);
				sideBodyTwo();
			}glPopMatrix();
		}

	}

}

void sidePartOne() {
	glPushMatrix(); {
		glTranslatef(0, -50, 0);
		sideDesign();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(0, -50, 50);
		sideDesign();
	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(0, -50, 100);
		sideDesign();
	}glPopMatrix();

}
void display() {
	//codes for Models, Camera

	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//clear buffers to preset values

															/***************************
															/ set-up camera (view) here
															****************************/
															//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);		//specify which matrix is the current matrix

									//initialize the matrix
	glLoadIdentity();				//replace the current matrix with the identity matrix [Diagonals have 1, others have 0]

									//now give three info
									//1. where is the camera (viewer)?
									//2. where is the camera looking?
									//3. Which direction is the camera's UP direction?

									//gluLookAt(0,-150,20,	0,0,0,	0,0,1);
	gluLookAt(cameraRadius*sin(cameraAngle), -cameraRadius*cos(cameraAngle), cameraHeight, 0, 0, 0, 0, 0, 1);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/**************************************************
	/ Grid and axes Lines(You can remove them if u want)
	***************************************************/
	// draw the three major AXES
	/*glBegin(GL_LINES);
	//X axis
	glColor3f(0, 1, 0);	//100% Green
	glVertex3f(-150, 0, 0);
	glVertex3f(150, 0, 0);

	//Y axis
	glColor3f(0, 0, 1);	//100% Blue
	glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
	glVertex3f(0, 150, 0);

	//Z axis
	glColor3f(1, 1, 1);	//100% White
	glVertex3f(0, 0, -150);
	glVertex3f(0, 0, 150);
	glEnd();

	//some gridlines along the field
	int i;
	if (canDrawGrid) {
		glColor3f(0.5, 0.5, 0.5);	//grey
		glBegin(GL_LINES);
		for (i = -10; i <= 10; i++) {

			if (i == 0)
				continue;	//SKIP the MAIN axes

							//lines parallel to Y-axis
			glVertex3f(i * 10, -100, 0);
			glVertex3f(i * 10, 100, 0);

			//lines parallel to X-axis
			glVertex3f(-100, i * 10, 0);
			glVertex3f(100, i * 10, 0);
		}
		glEnd();
	}





	/****************************
	/ Add your objects from here
	****************************/

	glScalef(1,1,1.6);
	glPushMatrix(); {
		for (float i = 0; i <= 275; i += 5) {
			glPushMatrix(); {
				glTranslatef(0, 0, 0 + i);
				bodyBase();
			}glPopMatrix();
		}
	}glPopMatrix();



    glPushMatrix(); {
		glRotatef(90, 0, 0, 1);
		sidePartOne();
		glPushMatrix(); {
			glTranslatef(0, -50, 165);
			sideBodyPartThree();
		}glPopMatrix();
		glPushMatrix(); {
			glTranslatef(0, -50, 160);
			sideDesignTwo();
		}glPopMatrix();
	}glPopMatrix();



	glPushMatrix(); {
		glRotatef(180, 1, 0, 0);
		glPushMatrix(); {
			glRotatef(180, 0, 1, 0);
			glPushMatrix(); {
				glRotatef(90, 0, 0, 1);
				sidePartOne();
				glPushMatrix(); {
					glTranslatef(0, -50, 165);
					sideBodyPartThree();
				}glPopMatrix();
				glPushMatrix(); {
					glTranslatef(0, -50, 160);
					sideDesignTwo();
				}glPopMatrix();
			}glPopMatrix();
		}glPopMatrix();
	}glPopMatrix();




	glPushMatrix(); {
		sidePartOne();
		glPushMatrix(); {
			glTranslatef(0, -50, 165);
			sideBodyPartThree();
		}glPopMatrix();
		glPushMatrix(); {
			glTranslatef(0, -50, 160);
			sideDesignTwo();
		}glPopMatrix();
	}glPopMatrix();



	glPushMatrix(); {
		glRotatef(180, 1, 0, 0);
		glPushMatrix(); {
			glRotatef(180, 0, 1, 0);
			glPushMatrix(); {
				//glRotatef(90, 0, 0, 1);
				sidePartOne();
				glPushMatrix(); {
					glTranslatef(0, -50, 165);
					sideBodyPartThree();
				}glPopMatrix();
				glPushMatrix(); {
					glTranslatef(0,-50,160);
					sideDesignTwo();
				}glPopMatrix();
			}glPopMatrix();
		}glPopMatrix();
	}glPopMatrix();


	glPushMatrix(); {

		glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D,grassimg);	//bind a named texture to a texturing target
		glBindTexture(GL_TEXTURE_2D,sandimg);
		//glBindTexture(GL_TEXTURE_2D,);

		float pix = 1;
		glBegin(GL_QUADS); {
			//glNormal3f(0,0,1);
			glColor3f(1.0f, 1.0f, 1.0f);
			glTexCoord2f(0, 1);
			glVertex3f(-150, 150, 0);
			glTexCoord2f(0, 0);
			glVertex3f(-150, -150, 0);
			glTexCoord2f(1, 0);
			glVertex3f(150, -150, 0);
			glTexCoord2f(1, 1);
			glVertex3f(150, 150, 0);
		}glEnd();

		glDisable(GL_TEXTURE_2D);

	}glPopMatrix();


	glPushMatrix(); {

		glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D,grassimg);	//bind a named texture to a texturing target
		glBindTexture(GL_TEXTURE_2D, grassimg);
		//glBindTexture(GL_TEXTURE_2D,);

		float pix = 1;
		glBegin(GL_QUADS); {
			//glNormal3f(0,0,1);
			glColor3f(1.0f, 1.0f, 1.0f);
			glTexCoord2f(0, 1);
			glVertex3f(-1000, 1000, -1);
			glTexCoord2f(0, 0);
			glVertex3f(-1000, -1000, -1);
			glTexCoord2f(1, 0);
			glVertex3f(1000, -1000, -1);
			glTexCoord2f(1, 1);
			glVertex3f(1000, 1000, -1);
		}glEnd();

		glDisable(GL_TEXTURE_2D);

	}glPopMatrix();

	glPushMatrix(); {
		glColor3f(1.0f, 1.0f, 1.0f);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, skyimg);

		GLUquadricObj *qObj = gluNewQuadric();

		gluQuadricTexture(qObj, GL_TRUE);

		gluSphere(qObj, 1000, 24, 24);

		glDisable(GL_TEXTURE_2D);
	}glPopMatrix();

	glPushMatrix(); {
		glColor3f(1.0f, 1.0f, 1.0f);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, cylimg);

		GLUquadricObj *cylinder_obj = gluNewQuadric();
		gluQuadricTexture(cylinder_obj, GL_TRUE);
		glPushMatrix(); {
			glColor3f(1, 1, 1);
			glTranslatef(0, 0, 275);
			glScalef(50, 50, 30);
			//gluCylinder(cylinder_obj, 1, 1, 1, 8, 100);
		}glPopMatrix();

		glPushMatrix(); {
			glColor3f(1, 1, 1);
			glTranslatef(0, 0, 305);
			glScalef(50, 50, 50);
			//gluCylinder(cylinder_obj, 1, .001, 1, 8, 100);
		}glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}glPopMatrix();
	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate() {
	//codes for any changes in Models, Camera

	cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.

	//codes for any changes in Models

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN

}

void keyboardListener(unsigned char key, int x, int y) {
	switch (key) {

	case '1':	//reverse the rotation of camera
		cameraAngleDelta = -cameraAngleDelta;
		break;

	case '2':	//increase rotation of camera by 10%
		cameraAngleDelta *= 1.1;
		break;

	case '3':	//decrease rotation
		cameraAngleDelta /= 1.1;
		break;

	case '8':	//toggle grids
		canDrawGrid = 1 - canDrawGrid;
		break;

	case 'p':	//toggle grids
		cameraAngleDelta = 0;
		break;
	case 'r':	//toggle grids
		cameraAngleDelta = .001;
		break;

	default:
		break;
	}
}


void specialKeyListener(int key, int x, int y) {
	switch (key) {
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


	default:
		break;
	}
}


void mouseListener(int button, int state, int x, int y) {	//x, y is the x-y of the screen (2D)
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {		// 2 times?? in ONE click? -- solution is checking DOWN or UP
			cameraAngleDelta = -cameraAngleDelta;
			//printf("cameraAngleDelta= %f",cameraAngleDelta);
		}
		break;

	case GLUT_RIGHT_BUTTON:
		//........
		break;

	case GLUT_MIDDLE_BUTTON:
		//........
		break;

	default:
		break;
	}
}



void init() {
	//codes for initialization

	loadImage();

	cameraAngle = 0;	//angle in radian
	cameraAngleDelta  = 0.001;
	canDrawGrid = 1;

	cameraHeight = 50;
	cameraRadius = 150;
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

int main(int argc, char **argv) {

	glutInit(&argc, argv);							//initialize the GLUT library

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	/*
	glutInitDisplayMode - inits display mode
	GLUT_DOUBLE - allows for display on the double buffer window
	GLUT_RGBA - shows color (Red, green, blue) and an alpha
	GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("Some Title");

	init();						//codes for initialization

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

								//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	//ADD mouse listeners:
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
