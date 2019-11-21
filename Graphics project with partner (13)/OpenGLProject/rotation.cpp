#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <windows.h>
#include <glut.h>

double a=2,b=0,xx=1,y,eggx,eggy,p=4,gameover=0,start=0,snaketextx=200,snaketexty=534,z=2,speed=300,highscor=0,num_texture=0;
double A = 0.0;
int img,score=0;
double B = 0.0;
double C = 0.0;
double D = 0.0;
double E = 0.0;
double F = 0.0;
double G = 0.0;
double L = 7.0;
double brick[100];
const float DEG2RAD = 3.14159/180;
struct Fire{
double p;
bool n=true;
};
struct position
{
double pic_x,pic_y;
};

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
	img = LoadBitmapImage("img.bmp");


	printf("Load successful");
}
position pict[200];
void bordar()
{
    if(pict[0].pic_x<-50||pict[0].pic_x>50||pict[0].pic_y<-50||pict[0].pic_y>50)
		{
			xx=1;
		}
}
void bite()
{
	int i;
	for(i=1;i<p;i++)
		{
			if(pict[0].pic_x==pict[i].pic_x&&pict[0].pic_y==pict[i].pic_y)
			{
				xx=1;
			}
		}
}

void scoregg()
{

	//iShowBMP(eggx,eggy, TEXT("egg.bmp"));
double t = 0.0,a = 0.002, R=2, PI_2 = 2*acos(-1);

    glColor3f(0, 0, 1);
	glBegin(GL_TRIANGLES);
	{
        for(t=0;t<=PI_2;t+=a)
        {
        glVertex3f(eggx, eggy, 0);
	    glVertex3f(R*cos(t-a)+eggx, R*sin(t-a)+eggy, 0);
	    glVertex3f(R*cos(t)+eggx, R*sin(t)+eggy, 0);

         }

	}
	glEnd();
	if(((pict[0].pic_x>=eggx&&pict[0].pic_x<=eggx+5)&&(pict[0].pic_y>=eggy&&pict[0].pic_y<=eggy+5))||((pict[0].pic_x+8>=eggx&&pict[0].pic_x+8<=eggx+5)&&(pict[0].pic_y+8>=eggy&&pict[0].pic_y+8<=eggy+5)))
	{
		int m,n,i;
		p++;
score++;
printf("Score : %d\n",score);
		for(i=0;i<300;i++)
		{    m=rand()%100-50;
			if((m>=-50&&m<=50)&&eggx!=m)
			{
				eggx=m;
				break;
			}
		}
		for(i=0;i<300;i++)
		{
			n=rand()%100-50;
			if((n>=-50&&n<=50)&&eggy!=n)
			{
				eggy=n;
				break;
			}
		}

	}
}

void drawRect()
{
    for(int i=0;i<=p;i++)
	{
      // iShowBMP(pict[i].pic_x, pict[i].pic_y, TEXT("b2.bmp"));
      if(i==0)
      {
          glColor3f(1,0,0);
           glBegin(GL_QUADS);
    {
        glVertex3f(-1+pict[i].pic_x,-1+pict[i].pic_y,0);
        glVertex3f(1+pict[i].pic_x,-1+pict[i].pic_y,0);
        glVertex3f(1+pict[i].pic_x,1+pict[i].pic_y,0);
        glVertex3f(-1+pict[i].pic_x,1+pict[i].pic_y,0);
    }
    glEnd();

      }
      else
      {
          glColor3f(0,1,0);
           glBegin(GL_QUADS);
    {
        glVertex3f(-1+pict[i].pic_x,-1+pict[i].pic_y,0);
        glVertex3f(1+pict[i].pic_x,-1+pict[i].pic_y,0);
        glVertex3f(1+pict[i].pic_x,1+pict[i].pic_y,0);
        glVertex3f(-1+pict[i].pic_x,1+pict[i].pic_y,0);
    }
    glEnd();
      }

	}

}

void mouseClick(int button, int state, int x, int y)
{

  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
      printf("mouse click %d   %d",x,y);
if(x>328 && x<671 && y>204 && y<287 )
{
     xx=0;
}
else if(x>328 && x<671 && y>367 && y<447)
{
    exit(1);
}


  }

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
	if(xx==1)
    {
         int i,j;
	//place your own initialization codes here.
	for(i=0;i<100;i++)
	{
		pict[i].pic_x=10-5*i;
		pict[i].pic_y=10;
	}
	eggx=-30;
	eggy=-30;
         glPushMatrix(); {

		glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D,grassimg);	//bind a named texture to a texturing target
		glBindTexture(GL_TEXTURE_2D,img);
		//glBindTexture(GL_TEXTURE_2D,);

		float pix = 1;
		glBegin(GL_QUADS);
		 {
			//glNormal3f(0,0,1);
			glColor3f(1.0f, 1.0f, 1.0f);
			glTexCoord2f(0, 1);
			glVertex3f(-50, 50, 0);
			glTexCoord2f(0, 0);
			glVertex3f(-50, -50, 0);
			glTexCoord2f(1, 0);
			glVertex3f(50, -50, 0);
			glTexCoord2f(1, 1);
			glVertex3f(50, 50, 0);
		}glEnd();

		glDisable(GL_TEXTURE_2D);

	}glPopMatrix();

    }

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
	gluLookAt(0,0,100, 0,0,0, 0,1,0);

    //drawGrid();
    //drawAxis();



    glColor3f(0,1,0);

    drawRect();

scoregg();
glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	{
		glVertex3f(50, -50, 0);
		glVertex3f(52, -50, 0);
		glVertex3f(52, 52, 0);
		glVertex3f(50, 52, 0);
	}
	glEnd();
	glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	{
		glVertex3f(50, 50, 0);
		glVertex3f(50, 52, 0);
		glVertex3f(-52, 52, 0);
		glVertex3f(-52, 50, 0);
	}
	glEnd();
	glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	{
		glVertex3f(-50, -50, 0);
		glVertex3f(-50, 50, 0);
		glVertex3f(-52, 50, 0);
		glVertex3f(-52, -50, 0);
	}
	glEnd();
	glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	{
		glVertex3f(-52, -52, 0);
		glVertex3f(52, -52, 0);
		glVertex3f(52, -50, 0);
		glVertex3f(-52, -50, 0);
	}
	glEnd();

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}
void keyboardListener(unsigned char key, int x, int y)
{


     if (key == '1')
    {


    }

}
void specialKeyListener(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{

	}
	else if (key == GLUT_KEY_DOWN)
	{

	}
	if(key == GLUT_KEY_LEFT)
	{
	    if(a!=2)
        {
        a=-2;
		b=0;
        }

	}
	if(key == GLUT_KEY_RIGHT)
	{
	    if(a!=-2)
        {
		a=2;
		b=0;
        }
	}
	if(key == GLUT_KEY_UP)
	{
	    if(b!=-2)
        {
		a=0;
		b=2;
        }
	}
	if(key == GLUT_KEY_DOWN)
	{
	    if(b!=2)
        {
		a=0;
		b=-2;
        }
	}
}
void animate(int n)
{
    glutPostRedisplay();
	//codes for any changes in Models, Camera
glutTimerFunc(n, animate, n);
	//this will call the display AGAIN
	G-=.06;
	A+=.12;
	B+=.10;
	C+=.08;
	D+=.06;
	E+=.04;
	F+=0.02;
	glutPostRedisplay();
	int i,j=0,k=0,l,m;
	/*if(pict[0].pic_x==30||pict[0].pic_y==30||pict[0].pic_x==510||pict[0].pic_y==360)
	{
	    x=x*(-1);
		y=y*(-1);
	}*/
	if(snaketextx+300==534||snaketextx==40)
	{
		z=z*(-1);
		//snaketextx=532;
	}
	snaketextx+=z;

	if(xx==0)
	{
		j=pict[0].pic_x;
	    k=pict[0].pic_y;
	  for(i=1;i<=p;i++)
	  {
		 if(i%2!=0)
		  {

		l=pict[i].pic_x;
		m=pict[i].pic_y;
		pict[i].pic_x=j;
		pict[i].pic_y=k;
		  }
		else
		  {
			j=pict[i].pic_x;
		    k=pict[i].pic_y;
		    pict[i].pic_x=l;
		    pict[i].pic_y=m;
		  }

      }
    pict[0].pic_x+=a*1;
	pict[0].pic_y+=b*1;
	}
	bite();
	bordar();
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
	gluPerspective() � set up a perspective projection matrix

	fovy -         Specifies the field of view angle, in degrees, in the y direction.
	aspect ratio - Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	zNear -        Specifies the distance from the viewer to the near clipping plane (always positive).
	zFar  -        Specifies the distance from the viewer to the far clipping plane (always positive).
	*/

	gluPerspective(70, 1, 0.1, 10000.0);

}
void run()
{
    animate(1000);
}
int main(int argc, char **argv)
{
    int i,j;
	//place your own initialization codes here.
	for(i=0;i<100;i++)
	{
		pict[i].pic_x=10-5*i;
		pict[i].pic_y=10;
	}
	eggx=-30;
	eggy=-30;
	//initialize the GLUT library
	glutInit(&argc, argv);
Fire fire[100];
	glutInitWindowSize(1000, 750);
	glutInitWindowPosition(0, 0);

	/*
	glutInitDisplayMode - inits display mode
	GLUT_DOUBLE - allows for display on the double buffer window
	GLUT_RGBA - shows color (Red, green, blue) and an alpha
	GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("First_Lab!");

	//codes for initialization
	init();

	//enable Depth Testing
	glEnable(GL_DEPTH_TEST);
loadImage();
	//display callback function
	glutDisplayFunc(display);
glutKeyboardFunc(keyboardListener);
glutSpecialFunc(specialKeyListener);
glutMouseFunc(mouseClick);
	//what you want to do in the idle time (when no drawing is occurring)
	//glutIdleFunc(run);
//glutTimerFunc(500,animate,500);
	//glutKeyboardFunc(keyboardListener);
    //glutSpecialFunc(specialKeyListener);

	//The main loop of OpenGL
	animate(50);
	glutMainLoop();

	return 0;
}
