#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <GL/glut.h>
#define pi (2*acos(0.0))

int sph,scl,posx,inc;
double ang;
int drawgrid;
int drawaxes;
double angle;

struct point
{
	double x,y,z;
};

double cameraLookingX = 0;
double cameraLookingY = 0;
double cameraLookingZ = 0;

double cameraAngle =1.0;
double cameraRadius = 300;

double cameraX = 30;
double cameraY = 300;
double cameraHeight = 150;

double cameraAngleDelta = -0.0003;

double move_X = 0;
double move_Y = 0;
double move_Z = 0;
double speed = 30;
double ang_speed = 0.5;
int num_texture = -1;
int forward1 =1;
int forward2 =1;

GLuint skyImage, abc,grassimg,windowimg,lowerwindowimg,roofimg,upperroofimg,cylinderimg,pillarsideimg,ff,def,ttt,f,sk,sk1,u,fg;

int a=0;
double Kep_x , Kep_y , Kep_z;
double Kep_rx,Kep_ry,Kep_rz,Kep_ang;
double cc_xx,cc_yy,cc_zz,x,y,c;
double c2;
double mov=0,v,d_mov=1;
//GLUquadric* IDquadric = gluNewQuadric();
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
	grassimg = LoadBitmapImage("C:\\Users\\HIMU\\Desktop\\GRAPHICS=PROJECT\\FINAL_PROJECT=OpenGLProject\\images\\G.bmp");
	ttt = LoadBitmapImage("C:\\Users\\HIMU\\Desktop\\GRAPHICS=PROJECT\\FINAL_PROJECT=OpenGLProject\\images\\tree.bmp");
    def= LoadBitmapImage("C:\\Users\\HIMU\\Desktop\\GRAPHICS=PROJECT\\FINAL_PROJECT=OpenGLProject\\images\\C2.bmp");
    f= LoadBitmapImage("C:\\Users\\HIMU\\Desktop\\GRAPHICS=PROJECT\\FINAL_PROJECT=OpenGLProject\\images\\Ca.bmp");
    ff= LoadBitmapImage("C:\\Users\\HIMU\\Desktop\\GRAPHICS=PROJECT\\FINAL_PROJECT=OpenGLProject\\images\\tree11.bmp");
    fg= LoadBitmapImage("C:\\Users\\HIMU\\Desktop\\GRAPHICS=PROJECT\\FINAL_PROJECT=OpenGLProject\\images\\u.bmp");
    sk= LoadBitmapImage("C:\\Users\\HIMU\\Desktop\\GRAPHICS=PROJECT\\FINAL_PROJECT=OpenGLProject\\images\\sky.bmp");
    sk1= LoadBitmapImage("C:\\Users\\HIMU\\Desktop\\GRAPHICS=PROJECT\\FINAL_PROJECT=OpenGLProject\\images\\skk.bmp");
    u= LoadBitmapImage("C:\\Users\\HIMU\\Desktop\\GRAPHICS=PROJECT\\FINAL_PROJECT=OpenGLProject\\images\\um.bmp");

}



/****************************** GridLines and Axes ***********************************/

void drawAxes()
{
           //glTranslated(0,0,-150);
		glBegin(GL_LINES);{
		    glColor3f(0, 1.0, 0);
			glVertex3f( 500,0,0);
			glVertex3f(-500,0,0);

			glColor3f(0, 0, 1.0);
			glVertex3f(0,-500,0);
			glVertex3f(0, 500,0);

			glColor3f(1.0, 1.0, 1.0);
			glVertex3f(0,0, 500);
			glVertex3f(0,0,-500);
		}glEnd();

}
void humanBody(){
     //glColor3f(1,0,1);
	glPushMatrix();
	glRotatef(Kep_ang,Kep_rx,Kep_ry,Kep_rz);
	glTranslatef(Kep_x,Kep_y,Kep_z);
	glScalef(-.5,1,1);

	//head
	glColor3f(0,0,0);
	glPushMatrix();

	glTranslatef(0,0,13);
	glutSolidSphere(3,20,20);
	glPopMatrix();

	//body
	glColor3f(1,1,1);
	GLUquadric *obj = gluNewQuadric();
	gluCylinder(obj,4,4,10,20,20);

	//right hand
	glColor3f(0,0,0);
	glPushMatrix();
	glTranslated(7,0,4);
	glRotatef(-45,0,1,0);
	GLUquadric *righthand = gluNewQuadric();
	gluCylinder(righthand,1,2,6,20,20);
	glPopMatrix();

	//lefthand
	glPushMatrix();
	glTranslated(-7,0,4);
	glRotatef(45,0,1,0);
	GLUquadric *lefthand = gluNewQuadric();
	gluCylinder(lefthand,1,2,6,20,20);
	glPopMatrix();

	//right leg
	glPushMatrix();
	glTranslated(2,0,-7);
	//glRotatef(-30,0,1,0);
	GLUquadric *rightthi = gluNewQuadric();
	gluCylinder(rightthi,1,1.5,7,20,20);
	glPopMatrix();

	//left leg
	glPushMatrix();
	glTranslated(-2,0,-7);
	//glRotatef(-30,0,1,0);
	GLUquadric *leftthi = gluNewQuadric();
	gluCylinder(leftthi,1,1.5,7,20,20);
	glPopMatrix();


	glPopMatrix();


}

//light working complete
void light (){
    	glPushMatrix();{
	glPushMatrix();
	{

	glColor3f(.6,.2,0);
	//glRotated(90,1,0,0);
	//glTranslated(0,0,-149);
	glBegin(GL_QUADS);{
		glVertex3f(-5,0,-90);
		glVertex3f(3,0,-90);
		glVertex3f(3,0,50);
		glVertex3f(-5,0,50);
	}
	glEnd();


	}
	glPopMatrix();

	glPushMatrix();
	{    glTranslated(0,0,48);
	    //glutWireCone(10,10,10,10);
	  //  glutWireCone(6,20,8,8);
	   glColor3f(.6, .2, 0);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				gluCylinder(obj,3,8,12,30,30);
	}glPopMatrix();



	glPushMatrix();
{

	glColor3f(1,1,1);
	glTranslated(0,0,-72);
	glScaled(1.8,1.8,1.8);
	//glRotated(90,1,0,0);
	//glTranslated(0,0,-149);
	glBegin(GL_QUADS);{
		glVertex3f(-3,0,70);
		glVertex3f(3,0,70);
		glVertex3f(5,0,80);
		glVertex3f(-5,0,80);
	}
	glEnd();


}
	glPopMatrix();
	glPushMatrix();{
	    glTranslated(0,0,71);
	   // glutWireCone(8,20,8,8);
	   glColor3f(1,.6,.2);
	   glBegin(GL_TRIANGLES);{
		glVertex3f(9,0,0);
		glVertex3f(-9,0,0);
		glVertex3f(0,0,14);
	}glEnd();

	}
glPopMatrix();}
glPopMatrix();



}


void chairleg(){

    glBegin(GL_QUADS);{
		glVertex3f(-5,0,0);
		glVertex3f(3,0,0);
		glVertex3f(3,0,30);
		glVertex3f(-5,0,30);
	}
	glEnd();


}
void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,0);
		glVertex3f( a,-a,0);
		glVertex3f(-a,-a,0);
		glVertex3f(-a, a,0);
	}glEnd();

}

void chair(){

 glPushMatrix();{
	glPushMatrix();{
	    glTranslated(0,0,0);
	    drawSquare(20);
	}
	glPopMatrix();


    glPushMatrix();{
        glTranslated(18,19,-30);
        glColor3f(.6,0,0);
        chairleg();

    }glPopMatrix();

     glPushMatrix();{
        glTranslated(18,-19,-30);
        glColor3f(.6,0,0);
        chairleg();

    }glPopMatrix();


     glPushMatrix();{
        glTranslated(-16,19,-30);
        glColor3f(.6,0,0);
        chairleg();

    }glPopMatrix();

glPushMatrix();{
        glTranslated(-16,-19,-30);
        glColor3f(.6,0,0);
        chairleg();

    }glPopMatrix();


    glPushMatrix();
    {
        glColor3f(1, .6, .2);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(0,0,2);
				glRotated(90,0,0,1);
				glScaled(.7,.7,.7);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,20,0,15,15);

    }glPopMatrix();

    glPushMatrix();
    {   glColor3f(.6,0,0);
        glTranslated(-16,-19,0);
        chairleg();
    } glPopMatrix();


    glPushMatrix();{
        glTranslated(18,-19,0);
        glColor3f(.6,0,0);
        chairleg();

    }glPopMatrix();

     glPushMatrix();
    {   glColor3f(.6,0,0);
        glRotated(90,0,1,0);
        glTranslated(-28,-18,-20);
        glScaled(1.4,1.4,1.4);
        chairleg();
    } glPopMatrix();}
    glPopMatrix();
}

void drawCircle(double radius)
{
    int i,segments=150;
    struct point points[200];
    glColor3f(0.7,0.7,0.7);
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw segments using generated points
    for(i=0;i<segments;i++)
    {
        glBegin(GL_LINES);
        {
			glVertex3f(points[i].x,points[i].y,0);
			glVertex3f(points[i+1].x,points[i+1].y,0);
        }
        glEnd();
    }
}


void display()
{
	//codes for Models, Camera
	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);    //color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        //clear buffers to preset values

    /***************************
    / set-up camera (view) here
	****************************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);  //specify which matrix is the current matrix

	 //initialize the matrix
	glLoadIdentity();  //replace the current matrix with the identity matrix [Diagonals have 1, others have 0]

	 //now give three info
	 //1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

    gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//gluLookAt(cameraX, cameraY, cameraHeight, cameraLookingX, cameraLookingY, cameraLookingZ, 0, 0, 1);
	//gluLookAt(cameraRadius * sin(cameraAngle), -cameraRadius * cos(cameraAngle), cameraHeight, cameraLookingX, cameraLookingY, cameraLookingZ, 0, 0, 1);

    glMatrixMode(GL_MODELVIEW);

	/**************************************************
	/ Grid and axes Lines(You can remove them if u want)
	***************************************************/

	drawAxes();
    /****************************
    / Add your objects from here
    ****************************/
    glPushMatrix();{
    glTranslated(0,0,-150);
    glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, grassimg);//grass coordinate

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-500, 500, 0);

			glTexCoord2f(0, 0);
			glVertex3f(500, 500, 0);

			glTexCoord2f(1, 0);
			glVertex3f(500, -500, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-500, -500, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();

	////sky
	glPushMatrix();{
    glScaled(20,20,20);
    glRotatef(90,0,0,1);
    glTranslated(0,0,-200);
	glPushMatrix();{

    glEnable(GL_TEXTURE_2D);
	{
    glBindTexture(GL_TEXTURE_2D,sk1);
	//glColor3f(1,0,0);
	double equ[4];
	equ[0] = 0;
	equ[1] = 0;
	equ[2] = 15;
	equ[3] = -90;

	glClipPlane(GL_CLIP_PLANE0, equ);

	glEnable(GL_CLIP_PLANE0);
	GLUquadricObj *obj = gluNewQuadric();
    gluQuadricTexture(obj, GL_TRUE);

    glTranslatef(0, 0, 90);
    glRotatef(90,0,1,0);
    //sky spher!
    gluSphere(obj,125,110,110);
	glDisable(GL_CLIP_PLANE0);}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();}
	glPopMatrix();


	///////////////umbrella
    glPushMatrix();{
    glTranslated(100,-330,-120);
    glPushMatrix();{
    glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D,def);
	//glColor3f(1,0,0);
	double equ[4];
	equ[0] = 0;
	equ[1] = 0;
	equ[2] = 1;
	equ[3] = -90;

	glClipPlane(GL_CLIP_PLANE0, equ);

	glEnable(GL_CLIP_PLANE0);
	GLUquadricObj *obj = gluNewQuadric();
	gluQuadricTexture(obj, GL_TRUE);

    glColor3f(1,0,0);
    glTranslatef(0, 0, 90);
    //glRotatef(70,0,1,0);
    //glutWireSphere(30, 20, 20);
    gluSphere(obj,30,20,10);
	glDisable(GL_CLIP_PLANE0);}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();}
	glPopMatrix();


	////umbrella lathi
    glPushMatrix();
    {
        glColor3f(0,1,0);
        glTranslated(14,-323,-70);
        glRotated(90,0,0,1);
        glRotated(90,0,1,0);
        glBegin(GL_QUADS);{
            glVertex3f(-68,-80,0);
            glVertex3f(80,-80,0);
            glVertex3f(80,-85,0);
            glVertex3f(-68,-85,0);
	}
	glEnd();
    }
	glPopMatrix();

	/////road
	glPushMatrix();
    {
        glColor3f(.2,.2,.2);
        glTranslated(0,0,-149);
        glBegin(GL_QUADS);{
            glVertex3f(-500,-150,0);
            glVertex3f(500,-150,0);
            glVertex3f(500,-300,0);
            glVertex3f(-500,-300,0);
	}
	glEnd();
    }
	glPopMatrix();

	///road border1
    glPushMatrix();
    {

        glColor3f(1,1,1);
        glTranslated(0,0,-148);
        glBegin(GL_QUADS);{
            glVertex3f(-500,-150,0);
            glVertex3f(500,-150,0);
            glVertex3f(500,-170,0);
            glVertex3f(-500,-170,0);
	}
	glEnd();
    }
	glPopMatrix();

	////road border2
    glPushMatrix();
    {

        glColor3f(1,1,.6);
        glTranslated(0,0,-148);
        glBegin(GL_QUADS);{
            glVertex3f(-500,-210,0);
            glVertex3f(500,-210,0);
            glVertex3f(500,-230,0);
            glVertex3f(-500,-230,0);
	}
	glEnd();
    }
	glPopMatrix();

    //road border3
    glPushMatrix();
    {

        glColor3f(1,1,1);
        glTranslated(0,0,-148);
        glBegin(GL_QUADS);{
            glVertex3f(-500,-280,0);
            glVertex3f(500,-280,0);
            glVertex3f(500,-300,0);
            glVertex3f(-500,-300,0);
	}
	glEnd();
    }
	glPopMatrix();

	////table
	glPushMatrix();{
    glEnable(GL_TEXTURE_2D);
    {
        glBindTexture(GL_TEXTURE_2D, def);
        glPushMatrix();
		{
				glColor3f(1, 1, 1);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(100,-330,-80);
				glRotated(90,0,0,1);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,40,0,15,15);

        }
        glPopMatrix();}
	}

	/////nagordola
glPushMatrix();{


glTranslated(220,-310,-80);

	glPushMatrix();{

	glPushMatrix();{
 glEnable(GL_TEXTURE_2D);
		{
		    glBindTexture(GL_TEXTURE_2D, def);

			glPushMatrix();
			{
				glColor3f(1, 1, 1);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glRotated(90,1,0,0);

				//glTranslated(220,-45,300);
				glScaled(3,3,3);
				//gluSphere(obj, 20, 40, 40);
				//gluCylinder(obj,10,10,10,20,20);
				//gluCylinder(obj,10,10,5,20,20);


				drawCircle(12);
				//gluCylinder(obj,10,5,5,5,4);

			}
			glPopMatrix();

		}
		glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();

			glPushMatrix();{
	    glRotated(v,0,1,0);
 glEnable(GL_TEXTURE_2D);
		{
		    glBindTexture(GL_TEXTURE_2D, fg);

			glPushMatrix();
			{
				double equ[4];
	equ[0] = 0;
	equ[1] = 0;
	equ[2] = 1;
	equ[3] = 150;

	glClipPlane(GL_CLIP_PLANE0, equ);


	glEnable(GL_CLIP_PLANE0);
	glTranslated(-35,0,0);
	//glTranslated(220,-50,300);
		//glTranslatef(180,-280, -20);
		glutWireSphere(10, 5, 5);
	glDisable(GL_CLIP_PLANE0);
			}
			glPopMatrix();

		}
		glDisable(GL_TEXTURE_2D);}
		glPopMatrix();



	glPushMatrix();{
	    glRotated(v,0,1,0);
 glEnable(GL_TEXTURE_2D);
		{
		    glBindTexture(GL_TEXTURE_2D, fg);

			glPushMatrix();
			{
				double equ[4];
	equ[0] = 0;
	equ[1] = 0;
	equ[2] = 1;
	equ[3] = 150;

	glClipPlane(GL_CLIP_PLANE0, equ);


	glEnable(GL_CLIP_PLANE0);
	glTranslated(-15,0,30);
	glColor3f(1,.2,.4);
	//glTranslated(220,-50,300);
		//glTranslatef(180,-280, -20);
		glutWireSphere(10, 5, 5);
	glDisable(GL_CLIP_PLANE0);
			}
			glPopMatrix();

		}
		glDisable(GL_TEXTURE_2D);}
		glPopMatrix();

	glPushMatrix();{
	    glRotated(v,0,1,0);
 glEnable(GL_TEXTURE_2D);
		{
		    glBindTexture(GL_TEXTURE_2D, fg);

			glPushMatrix();
			{
				double equ[4];
	equ[0] = 0;
	equ[1] = 0;
	equ[2] = 1;
	equ[3] = 150;

	glClipPlane(GL_CLIP_PLANE0, equ);


	glEnable(GL_CLIP_PLANE0);
	glTranslated(15,0,40);
	glColor3f(1,1,0);
	//glTranslated(220,-50,300);
		//glTranslatef(180,-280, -20);
		glutWireSphere(10, 5, 5);
	glDisable(GL_CLIP_PLANE0);
			}
			glPopMatrix();

		}
		glDisable(GL_TEXTURE_2D);}
		glPopMatrix();

	//////
	glPushMatrix();{
	    glRotated(v,0,1,0);
 glEnable(GL_TEXTURE_2D);
		{
		    glBindTexture(GL_TEXTURE_2D, fg);

			glPushMatrix();
			{
				double equ[4];
	equ[0] = 0;
	equ[1] = 0;
	equ[2] = 1;
	equ[3] = 150;

	glClipPlane(GL_CLIP_PLANE0, equ);


	glEnable(GL_CLIP_PLANE0);
	glTranslated(-15,0,-40);
	glColor3f(1,0,0);
	//glTranslated(220,-50,300);
		//glTranslatef(180,-280, -20);
		glutWireSphere(10, 5, 5);
	glDisable(GL_CLIP_PLANE0);
			}
			glPopMatrix();

		}
		glDisable(GL_TEXTURE_2D);}
		glPopMatrix();









	glPushMatrix();{
	    glRotated(v,0,1,0);
 glEnable(GL_TEXTURE_2D);
		{
		    glBindTexture(GL_TEXTURE_2D, fg);

			glPushMatrix();
			{
				double equ[4];
	equ[0] = 0;
	equ[1] = 0;
	equ[2] = 1;
	equ[3] = 150;

	glClipPlane(GL_CLIP_PLANE0, equ);


	glEnable(GL_CLIP_PLANE0);
	glTranslated(35,0,0);
	glColor3f(0,1,0);
	//glTranslated(220,-50,300);
		//glTranslatef(180,-280, -20);
		glutWireSphere(10, 5, 5);
	glDisable(GL_CLIP_PLANE0);
			}
			glPopMatrix();

		}
		glDisable(GL_TEXTURE_2D);}
		glPopMatrix();


	 }
glPopMatrix();

////lathi
    glPushMatrix();{
        glColor3f(.5,0,0);

       glTranslated(-10,0,-40);  ///z=uper
        glRotated(90,0,1,0);
       glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, def);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-40, 10, 0);

			glTexCoord2f(0, 0);
			glVertex3f(40, 10, 0);

			glTexCoord2f(1, 0);
			glVertex3f(40, -10, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-40, -10, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();
}glPopMatrix();


///human


glPushMatrix(); //roadside human
{     glColor3f(1,.6,.2);
    glTranslated(85,50,-107);
     glScaled(5,5,5);
humanBody();

}glPopMatrix();

glPushMatrix(); //roadside human
{     glColor3f(1,.6,.2);
    glTranslated(50,50,-107);
     glScaled(5,5,5);
humanBody();

}glPopMatrix();

///dheki
glPushMatrix();{



	glTranslated(-130,-80,-130);
	glRotated(-65,0,1,0);
    glScaled(3,3,3);
     glColor3f(1,1,1);

glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, def);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-8, 4, 0);

			glTexCoord2f(0, 0);
			glVertex3f(8, 4, 0);

			glTexCoord2f(1, 0);
			glVertex3f(8, -4, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-8, -4, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();

	glPushMatrix();{



	glTranslated(-110,-80,-130);
	glRotated(65,0,1,0);
    glScaled(3,3,3);
    glColor3f(1,1,1);

glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, def);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-8, 4, 0);

			glTexCoord2f(0, 0);
			glVertex3f(8, 4, 0);

			glTexCoord2f(1, 0);
			glVertex3f(8, -4, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-8, -4, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();

	glPushMatrix();{



	glTranslated(-120,-80,-108);
	glRotated(mov,0,1,0);
    glScaled(5,5,5);

glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, def);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-10, 4, 0);

			glTexCoord2f(0, 0);
			glVertex3f(10, 4, 0);

			glTexCoord2f(1, 0);
			glVertex3f(10, -4, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-10, -4, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();



	////dolna
	glPushMatrix();{

		glTranslated(-220,-350,-110);
	glRotated(90,0,1,0);
	//glTranslated(0,0,-20);
    glScaled(2,2,2);




    glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, def);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-20, 10, 0);

			glTexCoord2f(0, 0);
			glVertex3f(20, 10, 0);

			glTexCoord2f(1, 0);
			glVertex3f(20, -10, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-20, -10, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();


	glPushMatrix();{

		glTranslated(-150,-350,-110);
	glRotated(90,0,1,0);
	//glTranslated(0,0,20);
    glScaled(2,2,2);

glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, def);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-20, 10, 0);

			glTexCoord2f(0, 0);
			glVertex3f(20, 10, 0);

			glTexCoord2f(1, 0);
			glVertex3f(20, -10, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-20, -10, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();


	glPushMatrix();{
     glColor3f(1,.6,0);
	glTranslated(-185,-350,-71);
	glScaled(2,2,2);

glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, def);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-20, 10, 0);

			glTexCoord2f(0, 0);
			glVertex3f(20, 10, 0);

			glTexCoord2f(1, 0);
			glVertex3f(20, -10, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-20, -10, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();

	//chair
	glPushMatrix();
     {

     glTranslated(-185,-335,-122);
     glRotated(-7,1,0,0);
     glColor3f(.8,0,.4);
     drawSquare(12);

     }glPopMatrix();

     glPushMatrix();
     {

     glTranslated(-185,-343,-110);
     glRotated(88,1,0,0);
     glColor3f(1,1,0);
     drawSquare(12);

     }glPopMatrix();




glPushMatrix();
{

	glColor3f(0,1,0);
	glTranslated(-218,-344,-100);
	glScaled(.4,.4,.4);
	glRotated(90,0,0,1);
	glRotated(90,0,1,0);
	glBegin(GL_QUADS);{
		glVertex3f(-68,-75,0);
		glVertex3f(70,-75,0);
		glVertex3f(70,-78,0);
		glVertex3f(-68,-78,0);
	}
	glEnd();


}glPopMatrix();

////human

	glPushMatrix();{
	    glTranslated(0,0,x);
	glPushMatrix();{

        glTranslated(-152,-80,-83);
	   glScaled(3,3,3);
	   glColor3f(1,1,1);
	   humanBody() ;
	}
	glPopMatrix();}
	glPopMatrix();

	glPushMatrix();{
	    glTranslated(0,0,y);
	glPushMatrix();{

        glTranslated(-80,-75,-80);
	   glScaled(3,3,3);
	   glColor3f(1,1,1);
	   humanBody() ;
	}
	glPopMatrix();}
	glPopMatrix();



//// car full
glPushMatrix();{
 glTranslated(c,-200,-140);
glPushMatrix();{
glPushMatrix();
{

	glColor3f(1,0,0);
	glRotated(90,1,0,0);
	//glTranslated(0,0,-149);
	glBegin(GL_QUADS);{
		glVertex3f(-50,0,0);
		glVertex3f(50,0,0);
		glVertex3f(38,25,0);
		glVertex3f(-38,25,0);
	}
	glEnd();


}
	glPopMatrix();

	glPushMatrix();
{

	glColor3f(1,0,0);
	glRotated(90,1,0,0);
	glTranslated(0,0,-30);
	glBegin(GL_QUADS);{
		glVertex3f(-50,0,0);
		glVertex3f(50,0,0);
		glVertex3f(38,25,0);
		glVertex3f(-38,25,0);
	}
	glEnd();


}
	glPopMatrix();


		glPushMatrix();
{

	//glColor3f(0,1,0);
	glColor3f(.2,.2,1);
	//glRotated(90,1,0,0);
	glTranslated(0,0,25);
	glBegin(GL_QUADS);{
		glVertex3f(-38,0,0);
		glVertex3f(38,0,0);
		glVertex3f(38,30,0);
		glVertex3f(-38,30,0);
	}
	glEnd();


}
	glPopMatrix();

	glPushMatrix();
     {

     glTranslated(-44,15,12.5);
     glRotated(-68,0,1,0);
     glColor3f(.2,.2,1);
     drawSquare(14.3);

     }glPopMatrix();


glPushMatrix();
     {

     glTranslated(44,15,12.5);
     glRotated(68,0,1,0);
     glColor3f(.2,.2,1);
     drawSquare(14.3);

     }glPopMatrix();

   ////upper car
   glPushMatrix();{
       glTranslated(0,7,25);
       glScaled(.5,.5,.5);
   glPushMatrix();{
glPushMatrix();
{

	//glColor3f(1,0,0);
	glColor3f(.58,.58,.58);
	glRotated(90,1,0,0);
	//glTranslated(0,0,-149);
	glBegin(GL_QUADS);{
		glVertex3f(-50,0,0);
		glVertex3f(50,0,0);
		glVertex3f(38,25,0);
		glVertex3f(-38,25,0);
	}
	glEnd();


}
	glPopMatrix();

	glPushMatrix();
{

	//glColor3f(1,0,0);
	glColor3f(.58,.58,.58);
	glRotated(90,1,0,0);
	glTranslated(0,0,-30);
	glBegin(GL_QUADS);{
		glVertex3f(-50,0,0);
		glVertex3f(50,0,0);
		glVertex3f(38,25,0);
		glVertex3f(-38,25,0);
	}
	glEnd();


}
	glPopMatrix();


		glPushMatrix();
{

	//glColor3f(0,1,0);
	//glRotated(90,1,0,0);
	glColor3f(.58,.58,.58);
	glTranslated(0,0,25);
	glBegin(GL_QUADS);{
		glVertex3f(-38,0,0);
		glVertex3f(38,0,0);
		glVertex3f(38,30,0);
		glVertex3f(-38,30,0);
	}
	glEnd();


}
	glPopMatrix();

	glPushMatrix();
     {

     glTranslated(-44,15,12.5);
     glRotated(-68,0,1,0);
    // glColor3f(1,1,0);
    glColor3f(.58,.58,.58);
     drawSquare(14.3);

     }glPopMatrix();


glPushMatrix();
     {

     glTranslated(44,15,12.5);
     glRotated(68,0,1,0);
    // glColor3f(1,1,0);
    glColor3f(.58,.58,.58);
     drawSquare(14.3);

     }glPopMatrix();



   }
   glPopMatrix();}
   glPopMatrix();

//////chaka
glPushMatrix();
{          glColor3f(0, 0, 0);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(20,31,0);
				glRotated(90,1,0,0);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,10,0,80,60);

}
glPopMatrix();



glPushMatrix();
{          glColor3f(0, 0, 0);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(20,-1,0);
				glRotated(90,1,0,0);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,10,0,80,60);

}
glPopMatrix();

glPushMatrix();
{          glColor3f(0, 0, 0);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(-20,31,0);
				glRotated(90,1,0,0);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,10,0,80,60);

}
glPopMatrix();

glPushMatrix();
{          glColor3f(0, 0, 0);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(-20,-1,0);
				glRotated(90,1,0,0);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,10,0,80,60);

}
glPopMatrix();
}
glPopMatrix();}
glPopMatrix();


/////light
glPushMatrix();{
    glTranslated(-10,-145,-58);
    light();

}
glPopMatrix();

glPushMatrix();
{glTranslated(-40,-295,-58);
light();
}
glPopMatrix();


glPushMatrix();{
    glTranslated(-175,-145,-58);
    light();

}
glPopMatrix();

glPushMatrix();{
    glTranslated(210,-145,-58);
   light();

}
glPopMatrix();


///bench
glPushMatrix();{
glTranslated(-230,-100,-120);
glPushMatrix();{
glPushMatrix();{

	glRotated(90,0,0,1);
    glScaled(5,5,5);

glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, def);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-10, 4, 0);

			glTexCoord2f(0, 0);
			glVertex3f(10, 4, 0);

			glTexCoord2f(1, 0);
			glVertex3f(10, -4, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-10, -4, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();


	glPushMatrix();{
    glTranslated(-20,0,20);
	glRotated(90,0,1,0);
	glRotated(90,0,0,1);
    glScaled(5,5,5);

glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, def);

		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 1);
			glVertex3f(-10, 4, 0);

			glTexCoord2f(0, 0);
			glVertex3f(10, 4, 0);

			glTexCoord2f(1, 0);
			glVertex3f(10, -4, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-10, -4, 0);
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);}
	glPopMatrix();

	//
	glPushMatrix();
{

	glColor3f(.6,.2,0);
	//glRotated(90,1,0,0);
	glTranslated(17,50,-30);
	chairleg();

}
	glPopMatrix();


		glPushMatrix();
{

	glColor3f(.6,.2,0);
	//glRotated(90,1,0,0);
	glTranslated(17,-50,-30);
	chairleg();

}
	glPopMatrix();

	glPushMatrix();
{

	glColor3f(.6,.2,0);
	//glRotated(90,1,0,0);
	glTranslated(-15,50,-30);
	chairleg();

}
	glPopMatrix();

		glPushMatrix();
{

	glColor3f(.6,.2,0);
	//glRotated(90,1,0,0);
	glTranslated(-15,-50,-30);
	chairleg();

}
	glPopMatrix(); }
	glPopMatrix();}
	glPopMatrix();





/////chair///


glPushMatrix();{
    glTranslated(40,-300,-80);
    glRotated(-90,0,0,1);
    //glTranslated(40,-300,-80);
    chair();

}glPopMatrix();

glPushMatrix();{
    glTranslated(140,-300,-80);
    glRotated(90,0,0,1);
    //glTranslated(40,-300,-80);
    chair();

}glPopMatrix();

glPushMatrix();{
    glColor3f(1,1,1);
    glTranslated(290,-350,-110);
    glScaled(5,5,5);
    humanBody();

}glPopMatrix();

///
//// full car
glPushMatrix();{
 glTranslated(c2,-260,-140);
glPushMatrix();{
glPushMatrix();
{

	glColor3f(1,1,0);
	glRotated(90,1,0,0);
	//glTranslated(0,0,-149);
	glBegin(GL_QUADS);{
		glVertex3f(-50,0,0);
		glVertex3f(50,0,0);
		glVertex3f(38,25,0);
		glVertex3f(-38,25,0);
	}
	glEnd();


}
	glPopMatrix();

	glPushMatrix();
{

	glColor3f(1,1,0);
	glRotated(90,1,0,0);
	glTranslated(0,0,-30);
	glBegin(GL_QUADS);{
		glVertex3f(-50,0,0);
		glVertex3f(50,0,0);
		glVertex3f(38,25,0);
		glVertex3f(-38,25,0);
	}
	glEnd();


}
	glPopMatrix();


		glPushMatrix();
{

	//glColor3f(0,1,0);
	glColor3f(.2,.3,1);
	//glRotated(90,1,0,0);
	glTranslated(0,0,25);
	glBegin(GL_QUADS);{
		glVertex3f(-38,0,0);
		glVertex3f(38,0,0);
		glVertex3f(38,30,0);
		glVertex3f(-38,30,0);
	}
	glEnd();


}
	glPopMatrix();

	glPushMatrix();
     {

     glTranslated(-44,15,12.5);
     glRotated(-68,0,1,0);
     glColor3f(.2,.2,1);
     drawSquare(14.3);

     }glPopMatrix();


glPushMatrix();
     {

     glTranslated(44,15,12.5);
     glRotated(68,0,1,0);
     glColor3f(.2,.2,1);
     drawSquare(14.3);

     }glPopMatrix();

   ////upper car2
   glPushMatrix();{
       glTranslated(0,7,25);
       glScaled(.5,.5,.5);
   glPushMatrix();{
glPushMatrix();
{

	//glColor3f(1,0,0);
	glColor3f(.58,.58,1);
	glRotated(90,1,0,0);
	//glTranslated(0,0,-149);
	glBegin(GL_QUADS);{
		glVertex3f(-50,0,0);
		glVertex3f(50,0,0);
		glVertex3f(38,25,0);
		glVertex3f(-38,25,0);
	}
	glEnd();


}
	glPopMatrix();

	glPushMatrix();
{

	//glColor3f(1,0,0);
	glColor3f(.58,.58,1);
	glRotated(90,1,0,0);
	glTranslated(0,0,-30);
	glBegin(GL_QUADS);{
		glVertex3f(-50,0,0);
		glVertex3f(50,0,0);
		glVertex3f(38,25,0);
		glVertex3f(-38,25,0);
	}
	glEnd();


}
	glPopMatrix();


		glPushMatrix();
{

	//glColor3f(0,1,0);
	//glRotated(90,1,0,0);
	glColor3f(.58,.58,1);
	glTranslated(0,0,25);
	glBegin(GL_QUADS);{
		glVertex3f(-38,0,0);
		glVertex3f(38,0,0);
		glVertex3f(38,30,0);
		glVertex3f(-38,30,0);
	}
	glEnd();


}
	glPopMatrix();

	glPushMatrix();
     {

     glTranslated(-44,15,12.5);
     glRotated(-68,0,1,0);
    // glColor3f(1,1,0);
    glColor3f(.58,.58,.58);
     drawSquare(14.3);

     }glPopMatrix();


glPushMatrix();
     {

     glTranslated(44,15,12.5);
     glRotated(68,0,1,0);
    // glColor3f(1,1,0);
    glColor3f(.58,.58,.58);
     drawSquare(14.3);

     }glPopMatrix();



   }
   glPopMatrix();}
   glPopMatrix();

//////chaka
glPushMatrix();
{          glColor3f(0, 0, 0);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(20,31,0);
				glRotated(90,1,0,0);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,10,0,80,60);

}
glPopMatrix();



glPushMatrix();
{          glColor3f(0, 0, 0);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(20,-1,0);
				glRotated(90,1,0,0);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,10,0,80,60);

}
glPopMatrix();

glPushMatrix();
{          glColor3f(0, 0, 0);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(-20,31,0);
				glRotated(90,1,0,0);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,10,0,80,60);

}
glPopMatrix();

glPushMatrix();
{          glColor3f(0, 0, 0);
				GLUquadricObj *obj = gluNewQuadric();
				gluQuadricTexture(obj, GL_TRUE);
				glTranslated(-20,-1,0);
				glRotated(90,1,0,0);
				//gluSphere(obj, 20, 30, 40);
				gluCylinder(obj,0,10,0,80,60);

}
glPopMatrix();
}
glPopMatrix();}
glPopMatrix();




	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glFlush();
	glutSwapBuffers();
}

void animate()
{   //cameraAngle += 0.0001;
    v+=.07;
    c+=.1;

    printf("%d\n",c);
     mov+=d_mov*.5;
	//x++;
	if(mov==45 && d_mov==1)//move
        {
            d_mov=-1;
            x+=20;
            y-=20;
            //printf("move: %d\n",mov);
        }
        else if(mov==0 && d_mov==-1)
        {
            d_mov=1;
            x-=20;
            y+=20;

             //printf("move 22222222: %d\n",mov);
        }
        if(c>=350){//car movement
            forward1=0;
        }
        else if(c<=-350){
            forward1=1;
        }
        if(forward1==1)
        {
            c+=.5;
        }
          else if(forward1==0 && forward1==1){ //forward1==0 && forward1==1
            c=0;
        }

       else
        {
            c-=.5;
        }
        if(c2>=350){//car movement2
            forward2=0;
        }
        else if(c2<=-350){
            forward2=1;
        }
        if(forward2==1)
        {
            c2+=.3;
        }
          else if(forward2==0 && forward2==1){ //forward1==0 && forward1==1
            c2=0;
        }

       else
        {
            c2-=.3;
        }

	glutPostRedisplay();    //this will call the display AGAIN

}

void init()
{


    loadImage();
	glClearColor(0, 0, 0, 0);
	Kep_rz=0,Kep_x=0,Kep_y=0,Kep_z=0;
	Kep_ang = 0;
    cc_yy=1;
    mov=0;
    v=0;
    x=0;
    y=0;
    c=0;

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	/*
	gluPerspective() ? set up a perspective projection matrix

	fovy -         Specifies the field of view angle, in degrees, in the y direction.
	aspect ratio - Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	zNear -        Specifies the distance from the viewer to the near clipping plane (always positive).
	zFar  -        Specifies the distance from the viewer to the far clipping plane (always positive).
	*/

	gluPerspective(70, 1, 0.1, 10000.0);

}

void keyboardListener(unsigned char key, int x, int y)
{
	switch (key)
	{

	case '+':
		break;

	case '-':
		break;

	case 'l':
	case 'L':
		break;

	case 'r':
	case 'R':
		break;

	case 'q':
	case 'Q':
		break;

	case 'e':
	case 'E':
		break;

    case '1' :



	default:
		break;
	}
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			cameraHeight -= 3.0;
			break;
		case GLUT_KEY_UP:		// up arrow key
			cameraHeight += 3.0;
			break;

		case GLUT_KEY_RIGHT:
			cameraAngle += 0.03;
			break;
		case GLUT_KEY_LEFT:
			cameraAngle -= 0.03;
			break;

		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:

			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}

/*void mouseListener(int button, int state, int x, int y)
{    //x, y is the x-y of the screen (2D)
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			// 2 times?? in ONE click? -- solution is checking DOWN or UP
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
}*/

int main(int argc, char **argv)
{
	glutInit(&argc, argv);                            //initialize the GLUT library

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);

	/*
	glutInitDisplayMode - inits display mode
	GLUT_DOUBLE - allows for display on the double buffer window
	GLUT_RGBA - shows color (Red, green, blue) and an alpha
	GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("Some Title");

	printf("Camera Controls\n\n");
	printf("Roll: UP and DOWN arrow\n");
	printf("Pitch: Q and E\n");
	printf("Yaw: LEFT and RIGHT arrow\n");
	printf("Up-Down: PAGEUP and PAGEDOWN\n");
	printf("Left-Right: L and R\n");
	printf("Zoom in-out: + and -\n");
	printf("Reset Camera: HOME\n");

	init();                        //codes for initialization

//	loadAllImages();

	glEnable(GL_DEPTH_TEST);    //enable Depth Testing

								//loadAllImages();

	glutDisplayFunc(display);    //display callback function
	glutIdleFunc(animate);        //what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	//glutMouseFunc(mouseListener);

	glutMainLoop();        //The main loop of OpenGL

	return 0;
}
