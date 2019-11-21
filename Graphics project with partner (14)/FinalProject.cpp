#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<glut.h>

double cameraAngle;
double move_X, move_Y, move_Z;
int canDrawGrid, canDrawAxis;
double speed=30,ang_speed=.1;
double cameraRadius, cameraHeight, cameraAngleDelta;
int num_texture  = -1;
GLuint grassimg,wallimg,darkwallimg,smallwindowimg,lowsmallwindowimg,tallwindowimg,wallwindowimg,skyimage,mapimg;

/***************************** VECTOR structure **********************************/

struct V;

V operator+(V a,V b);
V operator*(V a,V b);
V operator*(V b,double a);
V operator*(double a,V b);

struct V{
	double x,y,z;

	V(){}
	V(double _x,double _y){x=_x;y=_y;z=0;}
	V(double _x,double _y,double _z){x=_x;y=_y;z=_z;}


	double	mag(){	return sqrt(x*x+y*y+z*z);	}

	void 	norm(){	double d = mag();x/=d;y/=d;	z/=d;}
	V 		unit(){	V ret = *this;	ret.norm(); return ret;}

	double	dot(V b){		return x*b.x + y*b.y + z*b.z;}
	V		cross(V b){		return V( y*b.z - z*b.y , z*b.x - x*b.z , x*b.y - y*b.x );}


	double	projL(V on){	on.norm();	return this->dot(on);}
	V		projV(V on){	on.norm();	return on * projL(on);}

	V rot(V axis, double angle){
		return this->rot(axis, cos(angle), sin(angle));
	}

	V rot(V axis, double ca, double sa){
		V rotatee = *this;
		axis.norm();
		V normal = (axis * rotatee).unit();
		V mid = (normal * axis).unit();
		double r = rotatee.projL(mid);
		V ret=r*mid*ca + r*normal*sa + rotatee.projV(axis);
		return ret.unit();
	}
};

V operator+(V a,V b){		return V(a.x+b.x, a.y+b.y, a.z+b.z);	}
V operator-(V a){			return V (-a.x, -a.y, -a.z);			}
V operator-(V a,V b){		return V(a.x-b.x, a.y-b.y, a.z-b.z);	}
V operator*(V a,V b){		return a.cross(b);						}
V operator*(double a,V b){	return V(a*b.x, a*b.y, a*b.z);			}
V operator*(V b,double a){	return V(a*b.x, a*b.y, a*b.z);			}
V operator/(V b,double a){	return V(b.x/a, b.y/a, b.z/a);			}




V loc,dir,perp;


V  _L(0,-150,20);
V  _D(0,1,0);
V  _P(0,0,1);

/***************************** Texture Functions *******************************/

int LoadBitmapImage(char *filename)
{
    int i, j=0;
    FILE *l_file;
    unsigned char *l_texture;

    BITMAPFILEHEADER fileheader;
    BITMAPINFOHEADER infoheader;
    RGBTRIPLE rgb;

    num_texture++;

    if( (l_file = fopen(filename, "rb"))==NULL) return (-1);

    fread(&fileheader, sizeof(fileheader), 1, l_file);

    fseek(l_file, sizeof(fileheader), SEEK_SET);
    fread(&infoheader, sizeof(infoheader), 1, l_file);

    l_texture = (byte *) malloc(infoheader.biWidth * infoheader.biHeight * 4);
    memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);
	for (i=0; i < infoheader.biWidth*infoheader.biHeight; i++)
		{
				fread(&rgb, sizeof(rgb), 1, l_file);

				l_texture[j+0] = rgb.rgbtRed;
				l_texture[j+1] = rgb.rgbtGreen;
				l_texture[j+2] = rgb.rgbtBlue;
				l_texture[j+3] = 255;
				j += 4;
		}
    fclose(l_file);

    glBindTexture(GL_TEXTURE_2D, num_texture);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

    free(l_texture);

    return (num_texture);

}

void loadImage()
{
	mapimg = LoadBitmapImage("image/map.bmp");
	skyimage = LoadBitmapImage("image/sky.bmp");
	wallwindowimg = LoadBitmapImage("image/wallwindow.bmp");
	tallwindowimg = LoadBitmapImage("image/tallwindow.bmp");
	lowsmallwindowimg = LoadBitmapImage("image/lowsmallwindow.bmp");
	smallwindowimg = LoadBitmapImage("image/smallwindow.bmp");
	grassimg = LoadBitmapImage("image/grass.bmp");
	wallimg = LoadBitmapImage("image/wall.bmp");
	darkwallimg = LoadBitmapImage("image/darkwall.bmp");

	if(grassimg != -1)
		printf("Load successful!!\n");
	else printf("Image loading Failed!!\n");
}

/****************************** GridLines and Axes ***********************************/

void gridAndAxis(){
	// draw the three major AXES
	if(canDrawAxis==1){
		glBegin(GL_LINES);
			//X axis
			glColor3f(0, 1, 0);	//100% Green
			glVertex3f(-150, 0, 0);
			glVertex3f( 150, 0, 0);

			//Y axis
			glColor3f(0, 0, 1);	//100% Blue
			glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
			glVertex3f(0,  150, 0);

			//Z axis
			glColor3f(1, 1, 1);	//100% White
			glVertex3f( 0, 0, -150);
			glVertex3f(0, 0, 150);
		glEnd();
	}

	if(canDrawGrid == 1){
	//some gridlines along the field
		int i;

		glColor3f(0.5, 0.5, 0.5);	//grey
		glBegin(GL_LINES);
			for(i=-10;i<=10;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -100, 0);
				glVertex3f(i*10,  100, 0);

				//lines parallel to X-axis
				glVertex3f(-100, i*10, 0);
				glVertex3f( 100, i*10, 0);
			}
		glEnd();

	}
}

/********************************************************************************/

/*********************************** Make Custom Cube ***********************************/
void solidCube1Part(double size) {
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(-size, 0, size);
	glTexCoord2f(0, 0);
	glVertex3f(size, 0, size);
	glTexCoord2f(1, 0);
	glVertex3f(size, 0, -size);
	glTexCoord2f(1, 1);
	glVertex3f(-size, 0, -size);
	glEnd();
}

// up and down part
void solidCube2Part(double size) {
	solidCube1Part(size);
	glRotated(90, 1, 0, 0);
	glTranslated(0, -size, -size);
	solidCube1Part(size);
}

void customSolidCube(double size) {
	glPushMatrix(); {
		glTranslated(0, -size/2, 0);
		solidCube2Part(size/2);
		glRotated(90, 1, 0, 0);
		glTranslated(0, -size/2, -size/2);
		solidCube2Part(size/2);
	}glPopMatrix();

	glPushMatrix(); {
		glRotated(90, 0, 0, 1);
		glTranslated(0, size/2, 0);
		solidCube1Part(size/2);
	}glPopMatrix();

	glPushMatrix(); {
		glRotated(90, 0, 0, 1);
		glTranslated(0, -size/2, 0);
		solidCube1Part(size/2);
	}glPopMatrix();
}
/******************************** /End Make Custom Cube *********************************/

void smallWindowFunc()
{
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, smallwindowimg);
		glRotatef(90,1,0,0);
		glColor3f(1,1,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 1);
			glVertex3f(-10, 30, 0);

			glTexCoord2f(0, 0);
			glVertex3f(-10, 0, 0);

			glTexCoord2f(1, 0);
			glVertex3f(10, 0, 0);

			glTexCoord2f(1, 1);
			glVertex3f(10, 30, 0);
		glEnd();

	glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
}
void tallWindowFunc()
{
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tallwindowimg);
		glRotatef(90,1,0,0);
		glColor3f(1,1,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 1);
			glVertex3f(-10, 30, 0);

			glTexCoord2f(0, 0);
			glVertex3f(-10, 0, 0);

			glTexCoord2f(1, 0);
			glVertex3f(10, 0, 0);

			glTexCoord2f(1, 1);
			glVertex3f(10, 30, 0);
		glEnd();

	glDisable(GL_TEXTURE_2D);

	}
	glPopMatrix();
}
void lowsmallWindowFunc()
{
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, lowsmallwindowimg);
		glRotatef(90,1,0,0);
		glColor3f(1,1,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 1);
			glVertex3f(-10, 30, 0);

			glTexCoord2f(0, 0);
			glVertex3f(-10, 0, 0);

			glTexCoord2f(1, 0);
			glVertex3f(10, 0, 0);

			glTexCoord2f(1, 1);
			glVertex3f(10, 30, 0);
		glEnd();

	glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
}
void Building1 ()
{
	glPushMatrix();
	{
		glColor3f(.87,.87,.87);
		glTranslatef(135,15,40);
		glScalef(200,100,80);				//RightBodyPart
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, wallimg);
		customSolidCube(1);
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(52,-35.5,30);
		glScalef(1.5,1,1.2);

		for(int i=0;i<12;i++)				//UpperSmallWindow
		{
			smallWindowFunc();
			glTranslatef(10,0,0);
		}

	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(52,-35.5,10);
		glScalef(1.5,1,1.2);

		for(int i=0;i<12;i++)				//LowerSmallWindow
		{
			smallWindowFunc();
			glTranslatef(10,0,0);
		}

	}
	glPopMatrix();
}

void FrontDome()
{
	glPushMatrix();
	{
		glPushMatrix();
		{
			glColor3f(.5,.5,.5);
			glRotatef(90,0,0,1);
			glTranslatef(0,-29,20);
			glScalef(10,2,15),
			glutSolidCube(1);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor3f(.5,.5,.5);
			glRotatef(90,0,0,1);
			glTranslatef(0,29,20);
			glScalef(10,2,15),
			glutSolidCube(1);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glColor3f(.5,.5,.5);
			glTranslatef(0,29,20);
			glScalef(10,2,15),
			glutSolidCube(1);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glColor3f(.5,.5,.5);
			glTranslatef(0,-29,20);
			glScalef(10,2,15),
			glutSolidCube(1);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glRotatef(-45,0,0,1);
			glPushMatrix();
			{
				glColor3f(.9,.9,.9);
				glTranslatef(0,0,98);
				glScalef(2,2,12);
				glutSolidCone(1,1,50,50);
			}
			glPopMatrix();

			glPushMatrix();
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D,wallimg);
				glTranslatef(0,0,80);
				glColor3f(.7,.7,.7);
				glScalef(7,7,20);
				GLUquadricObj *sphere = gluNewQuadric();
				gluQuadricTexture(sphere, GL_TRUE);
				gluSphere(sphere, 1, 50, 50);
			}
			glPopMatrix();

			glPushMatrix();
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D,wallimg);
				glTranslatef(0,0,55);
				//glColor3f(.58,.58,.58);
				glColor3f(1,1,1);
				glScalef(28,28,35);
				GLUquadricObj *sphere = gluNewQuadric();
				gluQuadricTexture(sphere, GL_TRUE);
				gluSphere(sphere, 1, 50, 50);
			}
			glPopMatrix();
			glPushMatrix();
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D,wallimg);
				glTranslatef(0,0,46);
				glColor3f(1,1,1);
				glScalef(30,30,0);
				GLUquadricObj *sphere = gluNewQuadric();
				gluQuadricTexture(sphere, GL_TRUE);
				gluSphere(sphere, 1, 12, 10);
			}
			glPopMatrix();
			glPushMatrix();
			{
				glTranslatef(0,0,43);
				glScalef(30,30,3);
				glColor3f(1,1,1);
				glEnable(GL_TEXTURE_2D);

					glBindTexture(GL_TEXTURE_2D, darkwallimg);

					GLUquadricObj *cylinder=gluNewQuadric();
					gluQuadricTexture(cylinder, GL_TRUE);
					gluCylinder(cylinder,1,1,1,12,10);
				glDisable(GL_TEXTURE_2D);

				/*glTranslatef(0,0,43);
				glColor3f(.75,.75,.75);
				glScalef(30,30,3);
				GLUquadricObj *obj1=gluNewQuadric();
				gluCylinder(obj1,1,1,1,12,10);*/
			}
			glPopMatrix();


			glPushMatrix();
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, wallimg);
				glTranslatef(0,0,43);
				glColor3f(1,1,1);
				glScalef(47,47,0);
				GLUquadricObj *sphere = gluNewQuadric();
				gluQuadricTexture(sphere, GL_TRUE);
				gluSphere(sphere, 1, 12, 10);
			}
			glPopMatrix();
			glPushMatrix();
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, darkwallimg);
				glColor3f(1,1,1);
				glTranslatef(0,0,40);
				//glColor3f(.75,.75,.75);
				glScalef(47,47,3);

				GLUquadricObj *obj1=gluNewQuadric();
				gluQuadricTexture(obj1, GL_TRUE);
				gluCylinder(obj1,1,1,1,12,10);
				glDisable(GL_TEXTURE_2D);
			}
			glPopMatrix();
			glPushMatrix();
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, wallimg);
				glTranslatef(0,0,40);
				glColor3f(1,1,1);
				glScalef(47,47,0);
				GLUquadricObj *sphere = gluNewQuadric();
				gluQuadricTexture(sphere, GL_TRUE);
				gluSphere(sphere, 1, 12, 10);
			}
			glPopMatrix();
			glPushMatrix();
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, wallimg);
				glColor3f(1,1,1);
				glScalef(30,30,40);
				GLUquadricObj *obj1=gluNewQuadric();
				gluQuadricTexture(obj1, GL_TRUE);
				gluCylinder(obj1,1,1,1,12,10);
				glDisable(GL_TEXTURE_2D);
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void FrontDomePiller()
{
	glPushMatrix();
	{
		glColor3f(.7,.7,.7);
		glTranslatef(0,0,45);
		glScalef(.4,.4,.5);
		glPushMatrix();
		{
			/*glTranslatef(-30,0,30);
			glColor3f(.5,.5,.5);
			glScalef(10,5,60);
			glutSolidCube(1);*/
			glTranslatef(-30,0,30);
			glScalef(8,5,60);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallimg);
			customSolidCube(1);
			glDisable(GL_TEXTURE_2D);

		}
		glPopMatrix();
		glPushMatrix();
		{
			/*glTranslatef(0,0,65);
			glColor3f(.5,.5,.5);
			glScalef(70,5,10);
			glutSolidCube(1);*/
			glTranslatef(0,0,65);
			glScalef(70,5,10);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallimg);
			customSolidCube(1);
			glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();
		glPushMatrix();
		{
			/*glTranslatef(30,0,30);
			glColor3f(.5,.5,.5);
			glScalef(10,5,60);
			glutSolidCube(1);*/
			glTranslatef(30,0,30);
			glScalef(8,5,60);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallimg);
			customSolidCube(1);
			glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();

		glPushMatrix();
		{
			/*glEnable(GL_TEXTURE_2D);

					glBindTexture(GL_TEXTURE_2D, wallimg);

					GLUquadricObj *cylinder=gluNewQuadric();
					gluQuadricTexture(cylinder, GL_TRUE);
					gluCylinder(cylinder,1,1,1,12,10);
				glDisable(GL_TEXTURE_2D);*/
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallimg);
			glTranslatef(-15,0,0);
			glScalef(3,3,60);
			GLUquadricObj *obj1=gluNewQuadric();
			gluQuadricTexture(obj1, GL_TRUE);
			for (int i=0;i<4;i++)
			{
				gluCylinder(obj1,1,1,1,20,20);
				glTranslatef(3.5,0,0);

			}
			glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();

		glPushMatrix();
		{
			/*glTranslatef(0,0,65);
			glScalef(70,5,20);
			glutSolidCube(1);*/
			glTranslatef(0,0,70);
			glScalef(70,5,20);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallimg);
			customSolidCube(1);
			glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();
	}
	glPopMatrix();
}
void SmallerDomes()
{
	glPushMatrix();
	{
		glTranslatef(-56,-56,0);
		glScalef(.25,.25,.25);
		FrontDome();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-56,56,0);
		glScalef(.25,.25,.25);
		FrontDome();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(56,-56,0);
		glScalef(.25,.25,.25);
		FrontDome();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(56,56,0);
		glScalef(.25,.25,.25);
		FrontDome();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(.75,.75,.75);
		glEnable(GL_TEXTURE_2D);
		glTranslatef(0,0,-1);
		glScalef(130,130,3);
		glBindTexture(GL_TEXTURE_2D, wallimg);
		customSolidCube(1);
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
}
void FrontBuilding()
{
	//RightSide
	Building1();
	//LeftSide
	glPushMatrix();
	{
		glTranslatef(-290,0,0);
		Building1();
	}
	glPopMatrix();
	//RightSideInward
	glPushMatrix();
	{
		glTranslatef(300,-70,0);
		glRotatef(90,0,0,1);
		Building1();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(193,0,0);
		glPushMatrix();
		{
			glTranslatef(52,-35.5,30);
			glScalef(1.5,1,1.2);

			for(int i=0;i<6;i++)				//UpperSmallWindow
			{
				smallWindowFunc();
				glTranslatef(10,0,0);
			}

		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(52,-35.5,10);
			glScalef(1.5,1,1.2);

			for(int i=0;i<6;i++)				//LowerSmallWindow
			{
				smallWindowFunc();
				glTranslatef(10,0,0);
			}

		}
		glPopMatrix();
	}
	glPopMatrix();

	//LeftSideInward
	glPushMatrix();
	{
		glTranslatef(-300,200,0);
		glRotatef(-90,0,0,1);
		Building1();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-370,0,0);
		glPushMatrix();
		{
			glTranslatef(52,-35.5,30);
			glScalef(1.5,1,1.2);

			for(int i=0;i<6;i++)				//UpperSmallWindow
			{
				smallWindowFunc();
				glTranslatef(10,0,0);
			}

		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(52,-35.5,10);
			glScalef(1.5,1,1.2);

			for(int i=0;i<6;i++)				//LowerSmallWindow
			{
				smallWindowFunc();
				glTranslatef(10,0,0);
			}

		}
		glPopMatrix();
	}
	glPopMatrix();

	//RightSideInwardFinish
	glPushMatrix();
	{
		glTranslatef(300,125,0);
		glRotatef(90,0,0,1);
		Building1();
	}
	glPopMatrix();

	//LeftSideInwardFinish
	glPushMatrix();
	{
		glTranslatef(-300,380,0);
		glRotatef(-90,0,0,1);
		Building1();
	}
	glPopMatrix();


	glPushMatrix();
	{
		glColor3f(.87,.87,.87);
		glTranslatef(0,57,41);
		glScalef(70,16,82);				//BackSmallPart
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, wallimg);
		customSolidCube(1);
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(.7,.7,.7);
		glTranslatef(0,80,41);
		glScalef(140,40,78);				//BackCubeExtension
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, wallimg);
		customSolidCube(1);
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
}
void FrontBuildingBackExtension()
{
	glPushMatrix();
	{
		glTranslatef(0,100,0);
		glPushMatrix();
		{

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallwindowimg);
			/*glTranslatef(0,100,0);*/
			/*glScalef(60,60,76);*/
			glColor3f(1,1,1);								//BackCylinder
			GLUquadricObj *obj1=gluNewQuadric();
			gluQuadricTexture(obj1, GL_TRUE);

			gluCylinder(obj1,60,60,76,50,50);
			glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();

		glPushMatrix();
			{

				glTranslatef(0,0,76);
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D,wallimg);
				glColor3f(.87,.87,.87);
				glScalef(63,63,3);
				GLUquadricObj *sphere = gluNewQuadric();
				gluQuadricTexture(sphere, GL_TRUE);
				gluSphere(sphere, 1, 50, 50);
			}
		glPopMatrix();

	}
	glPopMatrix();
}
void BackExtension()
{
	glPushMatrix();
	{
		glTranslatef(235,390,0);
		glRotatef(45,0,0,1);

			glPushMatrix();
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D,wallimg);
				glTranslatef(0,0,80);
				glColor3f(.7,.7,.7);
				glScalef(71,71,1);
				GLUquadricObj *sphere = gluNewQuadric();
				gluQuadricTexture(sphere, GL_TRUE);
				gluSphere(sphere, 1, 50, 50);

			}

			glPopMatrix();

		glPushMatrix();
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallwindowimg);
			/*glTranslatef(0,100,0);*/
			glScalef(70,70,83);
			glColor3f(1,1,1);								//BackCylinder
			GLUquadricObj *obj1=gluNewQuadric();
			gluQuadricTexture(obj1, GL_TRUE);

			gluCylinder(obj1,1,1,1,50,50);
			glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();
	}
	glPopMatrix();
}
void FrontMap()
{
	glPushMatrix();
	{
		glColor3f(.87,.87,.87);
		glPushMatrix();
		{
			/*glColor3f(.87,.87,.87);*/
			glTranslatef(0,-70,35);
			glScalef(50,40,5);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallimg);
			customSolidCube(1);
			glDisable(GL_TEXTURE_2D);

		}
		glPopMatrix();
		glPushMatrix();
		{
			/*glColor3f(.7,.7,.7);*/
			glTranslatef(0,-85,20);
			glScalef(50,5,35);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallimg);
			customSolidCube(1);
			glDisable(GL_TEXTURE_2D);

		}
		glPopMatrix();
		glPushMatrix();
		{
			//glColor3f(.7,.7,.7);
			glTranslatef(0,-62,20);
			glScalef(50,5,35);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wallimg);
			customSolidCube(1);
			glDisable(GL_TEXTURE_2D);

		}
		glPopMatrix();

		glPushMatrix();
		{
			/*glRotatef(-90,1,0,0);*/
			glTranslatef(-15,-90,30);
			glRotatef(90,0,1,0);
			glScalef(1,1,3);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, mapimg);

			/*glColor3f(1,1,1);*/
			glBegin(GL_QUADS);
			glTexCoord2f(0,1);
			glVertex3f(0,0,0);
			glTexCoord2f(0,0);
			glVertex3f(20,0,0);
			glTexCoord2f(1,0);
			glVertex3f(20,0,10);
			glTexCoord2f(1,1);
			glVertex3f(0,0,10);
		glEnd();

	glDisable(GL_TEXTURE_2D);


		}
		glPopMatrix();
	}
	glPopMatrix();
}



void display(){
	//codes for Models, Camera

	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
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
	//gluLookAt(cameraRadius*sin(cameraAngle), -cameraRadius*cos(cameraAngle), cameraHeight,		0,0,0,		0,0,1);

	V to=loc+dir;
	gluLookAt(loc.x, loc.y, loc.z,		to.x,to.y,to.z,		perp.x,perp.y,perp.z);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/**************************************************
	/ Grid and axes Lines(You can remove them if u want)
	***************************************************/

	gridAndAxis();


	/****************************
	/ Add your objects from here
	****************************/
	glPushMatrix();
	{
		glTranslatef(0,0,87);
		//glScalef(.75,.75,.75);
		FrontDome();
		SmallerDomes();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(.75,.75,.75);
		glTranslatef(0,0,82);
		glScalef(100,100,10);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, wallimg);
		customSolidCube(1);
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(1, 1, 1);
		glTranslatef(0,0,40);
		glScalef(110,110,80);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, wallimg);
		customSolidCube(1);
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,-60,-10);
	FrontDomePiller();
	glPopMatrix();

	//Front Building
	FrontBuilding();


	//Front Back Extension
	FrontBuildingBackExtension();

	/*glPushMatrix();
	{
		glScaled(.2, .2, .6);
		glTranslated(-60, -60, 0);
		tallWindowFunc();
		for (int i = 0; i <100; i++)			//Experimental
		{
			glRotated(-8, 0, 0, 1);
			glTranslated(-60, 0, 0);
			tallWindowFunc();
		}
	}
	glPopMatrix();*/

	//BackBuilding
	glPushMatrix();
	{

		glTranslatef(-50,400,0);
		Building1();
	}
	glPopMatrix();
	glPushMatrix();
	{

		glTranslatef(-230,400,0);
		Building1();
	}
	glPopMatrix();

	//BackExtensions
	glPushMatrix();
	{
		BackExtension();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-470,0,0);
		BackExtension();
	}
	glPopMatrix();

	//Front Map
	FrontMap();


	//Sky
	double equ[4];
	equ[0] = 0;
	equ[1] = 0;
	equ[2] = 1;
	equ[3] = 0;
	glPushMatrix();
	{
		glClipPlane(GL_CLIP_PLANE0, equ);
		glEnable(GL_CLIP_PLANE0);

		glEnable(GL_TEXTURE_2D);
		{
			glRotatef(180, 1, 0, 0);
			glBindTexture(GL_TEXTURE_2D, skyimage);

			glPushMatrix();
			{
				glColor3f(1, 1, 1);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				gluSphere(obj, 1500, 20, 20);

			}
			glPopMatrix();
		}
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_CLIP_PLANE0);
	}
	glPopMatrix();

	//Surface

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, grassimg);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0,1);
			glVertex3f(-1000,1000,0);
			glTexCoord2f(0,0);
			glVertex3f(-1000,-1000,0);
			glTexCoord2f(1,0);
			glVertex3f(1000,-1000,0);
			glTexCoord2f(1,1);
			glVertex3f(1000,1000,0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glFlush();
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Models, Camera

	//cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.

	//codes for any changes in Models

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN

}

void init(){
	//codes for initialization
	loadImage();

	cameraAngle = 0;	//angle in radian
	move_X = 0;
	move_Y = 0;
	move_Z = 0;
	canDrawGrid = 1;
	canDrawAxis = 1;

	cameraAngleDelta = .001;

	cameraRadius = 150;
	cameraHeight = 50;


	loc=_L,dir=_D,perp=_P;
	//clear the screen
	glClearColor(0,0,0, 0);

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

	gluPerspective(70,	1,	0.1,	10000.0);

}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

	case 'w':case 'W':
		loc=loc+speed*dir;
		break;

	case 'a':case 'A':
		loc=loc+speed*((perp*dir).unit());
		break;

	case 's':case 'S':
		loc=loc-speed*dir;
		break;

	case 'd':case 'D':
		loc=loc+speed*((dir*perp).unit());
		break;


	default:
		break;
	}
}

void specialKeyListener(int key, int x,int y){
	V p;

	switch(key){
	case GLUT_KEY_UP:

		break;
	case GLUT_KEY_DOWN:

		break;

	case GLUT_KEY_LEFT:
		dir=dir.rot(-perp,ang_speed);
		break;
	case GLUT_KEY_RIGHT:
		dir=dir.rot(perp,ang_speed);
		break;

	case GLUT_KEY_PAGE_UP:

		break;
	case GLUT_KEY_PAGE_DOWN:

		break;

	case GLUT_KEY_INSERT:
		break;

	case GLUT_KEY_HOME:
		loc=_L,dir=_D,perp=_P;
		break;
	case GLUT_KEY_END:
		break;

	default:
		break;
	}
}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP

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

int main(int argc, char **argv){

	glutInit(&argc,argv);							//initialize the GLUT library

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	/*
		glutInitDisplayMode - inits display mode
		GLUT_DOUBLE - allows for display on the double buffer window
		GLUT_RGBA - shows color (Red, green, blue) and an alpha
		GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("Supreme court of Bangladesh");

	printf("Camera Control\n");
	printf("_____________\n");
	printf("Horizontal Rotate: LEFT and RIGHT arrow\n");
	printf("Left-Right side move: A and D\n");
	printf("Zoom in-out: W and S\n");
	printf("Reset Camera: HOME\n");

	init();						//codes for initialization

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
