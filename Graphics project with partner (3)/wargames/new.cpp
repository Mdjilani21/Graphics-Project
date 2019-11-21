#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<string.h>
#include<windows.h>
#include<Mmsystem.h>
#define PI 3.1416
using namespace std;
////////////////////////////////



//
float speed = 0.15;
int time=200;
float positionX=-5;
float positionY=-1.5;
float flow=4.5;
float randomY=-2;
float temp;
float scoreCount=0;
GLint i;

float ran(){
 float r;
 r=(rand()%7);
 return (r/10);//it will give 0.1-0.7
}

float ran2(){
 float r;
 r=(rand()%5);
 return r;// it will give 1-5
}

void gameOver(){

    float scoreFloat=ceil(scoreCount);
    int scoreInt=(int)scoreFloat;
    char scoreString[8];
    itoa(scoreInt,scoreString,10);//10 is for decimal
    char text[15]="Your score : ";
    strcat(text,scoreString);
   MessageBox(NULL,text,"Game Over",0);
    //PlaySound(NULL,NULL,0);
    exit(0);
}
void levelUp(){
    if(scoreCount<5)time=200;
    else if(scoreCount<20)time=150;
    else if(scoreCount<25)time=110;
    else if(scoreCount<35)time=90;
    else if(scoreCount<45)time=70;
    else if(scoreCount<50)time=50;
    else if(scoreCount<55)time=40;
    else if(scoreCount<70)time=30;
    else if(scoreCount<145)time=20;
    else if(scoreCount<190)time=15;
    else if(scoreCount<330)time=10;
    else if(scoreCount<400)time=2;
}
///////////////////////////////

void colCheck(){
        if(((randomY<=positionY+0.47) && (randomY>=positionY+0.2)) && ((flow<positionX+1.1) && (flow>positionX-1.1))){
            cout<<"\n******attacked!!***********\n"<<"final score is :"<<scoreCount<<endl;

            gameOver();
        }

}
//


///////////////////////////////
//Initializes 3D rendering
void initRendering()
{
  //  glShadeModel (GL_SMOOTH);
   //glEnable(GL_LIGHTING);
  // glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);
}
//static int X = 0;
static bool paused = false;
//static char keys = '0';
///////////////////////////////
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
//////////////////////
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.25, 0.25, 0.25, 0.0);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
////////////////////////
float _angl_1 = 0.0;
float _angl_2 = 0.0;
float _angl_3 = 0.0;
float _angl_4 = 0.0;
float _angl_5 = 0.0;
float _angl_6 = 0.0;
float _angl_7 = 0.0;
float _angl_8 = 0.0;
///////////////////////////////////
//display_text

void displayRasterText(float x ,float y ,float z ,char *stringToDisplay) {
	int length;
	glRasterPos3f(x, y, z);
		length = strlen(stringToDisplay);

	for(int i=0 ;i<length ;i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,stringToDisplay[i]);
	}
}

//Draws the 3D scene
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    //PlaySound(TEXT("Off_Limits.wav"),NULL,SND_ASYNC);
	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.3, -7.0);
	//backgroud color
    glClearColor(0.0,0.0,0.0,0.0);


///////////////////////////////////////////
////clouds
//cloud1 left
glPushMatrix();
glTranslatef(-_angl_1,0.12,0.0);

glPushMatrix();

glTranslatef(-4.0,0.60,0.0);
//cloud c1
	glPushMatrix();
	glTranslatef(-0.1,1.2,0);
    glScalef(0.1, 0.05, 0.0);
    glColor3f(1.0, 0.99, 1.0);
    circle(4);
    glPopMatrix();
//cloud c2
	glPushMatrix();
    glTranslatef(-0.92,1.13,0);
    glScalef(0.069, 0.05, 0.0);
    glColor3f(1.0, 1.0, 0.99);
    circle(4);
    glPopMatrix();
//cloud c3
	glPushMatrix();
    glTranslatef(-0.6,1.16,0);
    glScalef(0.07, 0.05, 0.90);
    glColor3f(1.0, 1.0, 1.0);
    circle(4);
    glPopMatrix();
//cloud c4
	glPushMatrix();
    glTranslatef(-0.3,1.1,0);
    glScalef(0.07, 0.06, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circle(4);
    glPopMatrix();
//cloud c5
	glPushMatrix();
    glTranslatef(-0.7,1.18,0);
    glScalef(0.089, 0.08, 0.90);
    glColor3f(1.0, 1.0, 0.98);
    circle(4);
    glPopMatrix();



glPopMatrix();

//cloud2 right1
glPushMatrix();
glTranslatef(1.4,0.40,0.0);

//cloud c1
	glPushMatrix();
	glTranslatef(-0.1,1.2,0);
    glScalef(0.1, 0.05, 0.0);
    glColor3f(1.0, 1, 1.0);
    circle(4);
    glPopMatrix();
//cloud c2
	glPushMatrix();
    glTranslatef(-0.92,1.13,0);
    glScalef(0.069, 0.05, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circle(4);
    glPopMatrix();
//cloud c3
	glPushMatrix();
    glTranslatef(-0.6,1.16,0);
    glScalef(0.07, 0.05, 0.90);
    glColor3f(1.0, 1.0, 1.0);
    circle(4);
    glPopMatrix();
//cloud c4
	glPushMatrix();
    glTranslatef(-0.3,1.2,0);
    glScalef(0.07, 0.06, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circle(4);
    glPopMatrix();
//cloud c5
	glPushMatrix();
    glTranslatef(-0.7,1.28,0);
    glScalef(0.089, 0.09, 0.90);
    glColor3f(1.0, 1.0, 0.98);
    circle(4);
    glPopMatrix();



glPopMatrix();
//cloud3 right2
glPushMatrix();
glTranslatef(4.4,0.60,0.0);

//cloud c1
	glPushMatrix();
	glTranslatef(-0.1,1.2,0);
    glScalef(0.1, 0.05, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circle(4);
    glPopMatrix();
//cloud c2
	glPushMatrix();
    glTranslatef(-0.92,1.13,0);
    glScalef(0.069, 0.05, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circle(4);
    glPopMatrix();
//cloud c3
	glPushMatrix();
    glTranslatef(-0.6,1.16,0);
    glScalef(0.07, 0.05, 0.90);
    glColor3f(1.0, 1.0, 1.0);
    circle(4);
    glPopMatrix();
//cloud c4
	glPushMatrix();
    glTranslatef(-0.3,1.2,0);
    glScalef(0.07, 0.06, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circle(4);
    glPopMatrix();
//cloud c5
	glPushMatrix();
    glTranslatef(-0.5,1.28,0);
    glScalef(0.089, 0.09, 0.90);
    glColor3f(1.0, 1.0, .98);
    circle(4);
    glPopMatrix();
//cloud c6
	glPushMatrix();
    glTranslatef(-0.68,1.28,0);
    glScalef(0.1, 0.1, 0.90);
    glColor3f(.98, 0.98, 0.98);
    circle(4);
    glPopMatrix();


glPopMatrix();

glPopMatrix();
glPushMatrix();
 glColor3f(0, 0, 0);
displayRasterText(2 ,1 ,0.0 ,"Up=w,Down=s,Left=a,Right=d,Quit=q");
glPopMatrix();
//sun
glPushMatrix();
glPushMatrix();
	glTranslatef(-2.5, 1.86, 0.0);
	//glRotatef(_angl_1, 0.0, 1.0, 0.0);
//	glRotatef(90, 0.0, 0.9, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	//glutSolidSphere(0.4,15,7);
	circle(.4);
	glPopMatrix();
glPopMatrix();




////////////////////////////////////////
////hill
 glPushMatrix();

  glColor3f(0.60,0.40,0.12);
    glBegin(GL_POLYGON);
glColor3f(0.2,0.82,0.32);
	glVertex2f(3,0);
glColor3f(0.20,0.20,0.42);
	glVertex2f(1,-0.06);
glColor3f(0.52,0.32,0.12);
	glVertex2f(-0.61,0);
glColor3f(0.15,0.30,0.12);
	glVertex2f(0.1,0.8);
glColor3f(0.60,0.40,0.12);
	glVertex2f(2,0.4);
	glEnd();

glColor3f(0.60,0.40,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(1,0.0);
glColor3f(0.20,0.20,0.42);
	glVertex2f(0,-0.04);
	glColor3f(0.60,0.40,0.12);
	glVertex2f(-2.3,0.0);
	glVertex2f(-2,0.28);
glColor3f(.3,.6,0.3);
	glVertex2f(-1.7,0.85);
	glVertex2f(-0.2,1.2);
glColor3f(0.35,0.50,0.12);
	glVertex2f(-0.9,0.0);
	glEnd();

glColor3f(0.60,0.40,0.12);
	glBegin(GL_TRIANGLES);
	glVertex2f(-1,0);
glColor3f(0.50,0.40,0.12);
	glVertex2f(-3,0);
glColor3f(0.25,0.50,0.12);
	glVertex2f(-2,1);
	glEnd();

glColor3f(0.60,0.42,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(-2.5,0);
	glVertex2f(-4.0,0);
glColor3f(0.15,0.40,0.12);
	glVertex2f(-3.3,0.5);

	glVertex2f(-3,0.6);
	glVertex2f(-2.8,.5);
	glVertex2f(-2.6,.3);
	glEnd();

	glColor3f(0.62,0.42,0.13);
	glBegin(GL_POLYGON);

	glVertex2f(-3,0);
	glColor3f(0.20,0.20,0.42);
	glVertex2f(-4.2,-0.03);
	glColor3f(0.50,0.40,0.12);
	glVertex2f(-4.5,0.0);
	glColor3f(0.05,0.40,0.12);
	glVertex2f(-4.0,0.5);
	glVertex2f(-3.8,0.3);
    glEnd();

	glColor3f(0.62,0.42,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(-4,0);
	glColor3f(0.20,0.20,0.42);
	glVertex2f(-4.6,-0.06);
	glColor3f(0.05,0.20,0.02);
	glVertex2f(-5.8,0);
	glVertex2f(-5.8,0.5);
	glVertex2f(-5.4,1.0);
	glVertex2f(-5,0.98);
	glVertex2f(-4.2,0.5);
	glEnd();



  glPopMatrix();



//////////////////////////////////////////


//Sky
glPushMatrix();
glColor3f(.50, .50, 1.0);
glBegin(GL_POLYGON);
	glVertex2f(6,0);
	glVertex2f(-6,0);
	glVertex2f(-6,6);
	glVertex2f(6,6);
glEnd();
glPopMatrix();


////////////////////////////////////////
//////////
//boat
glPushMatrix();

glTranslatef(positionX,positionY, 0.0);
glScalef(0.5, 0.5, 0.90);
glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1.8,1);
	glVertex2f(1.7,1);
	glVertex2f(1.83,1.10);
    glEnd();
glColor3f(.0,1,0);
	glBegin(GL_POLYGON);
	glVertex2f(2,.6);
	glVertex2f(1.6,.6);
	glVertex2f(1.7,.89);
	glVertex2f(1.8,.89);
    glVertex2f(2,.65);
    glEnd();

glColor3f(0.0,1.40,1.2);
	glBegin(GL_POLYGON);

	glVertex2f(2,0.0);
	glVertex2f(0.5,0.0);

    glVertex2f(0.4,0.2);
    glVertex2f(0.2,0.4);
    glVertex2f(0.2,0.6);
    glVertex2f(1.5,0.6);
	glVertex2f(1.6,1.0);
	glVertex2f(1.8,1.0);
	glVertex2f(2,0.8);
	glVertex2f(2.5,0.6);
	glVertex2f(2.4,0.2);
	glEnd();


glPopMatrix();



// enemy boat

glPushMatrix();
glTranslatef(4.0, 0.0, 0.0);
glScalef(0.5, 0.5, 0.90);
//1st
glPushMatrix();
glTranslatef(0, -2.6, 0.0);
glScalef(0.5, 0.5, 0.90);
glColor3f(1.0,0.4,0.2);
	glBegin(GL_POLYGON);
glColor3f(1,0.0,0.2);
	glVertex2f(4.0,1.0);
	glVertex2f(4.5,1.5);
	glVertex2f(4.5,2.0);
    glVertex2f(0.5,2.0);
    glVertex2f(1.5,1.0);

    glColor3f(0.2,0.5,0.6);
    glVertex2f(4.0,2.0);
	glVertex2f(4.0,2.5);
	glVertex2f(2.5,2.5);
	glVertex2f(2.0,2.0);

	glEnd();


glPopMatrix();


//2nd

glPushMatrix();
glTranslatef(0, -1.5, 0.0);
glScalef(0.5, 0.5, 0.90);
glColor3f(1.0,0.4,0.2);
	glBegin(GL_POLYGON);
glColor3f(1,0,1);
	glVertex2f(4.0,1.0);
	glVertex2f(4.5,1.5);
	glVertex2f(4.5,2.0);
    glVertex2f(0.5,2.0);
    glVertex2f(1.5,1.0);

    glColor3f(0.2,0.5,0.6);
    glVertex2f(4.0,2.0);
	glVertex2f(4.0,2.5);
	glVertex2f(2.5,2.5);
	glVertex2f(2.0,2.0);

	glEnd();


glPopMatrix();

//3rd

glPushMatrix();
glTranslatef(0, -3.7, 0.0);
glScalef(0.5, 0.5, 0.90);
glColor3f(1.0,0.4,0.2);
	glBegin(GL_POLYGON);
glColor3f(0,1,0);
	glVertex2f(4.0,1.0);
	glVertex2f(4.5,1.5);
	glVertex2f(4.5,2.0);
    glVertex2f(0.5,2.0);
    glVertex2f(1.5,1.0);

    glColor3f(0.2,0.5,0.6);
    glVertex2f(4.0,2.0);
	glVertex2f(4.0,2.5);
	glVertex2f(2.5,2.5);
	glVertex2f(2.0,2.0);

	glEnd();


glPopMatrix();

//4th
glPushMatrix();
glTranslatef(0, -4.7, 0.0);
glScalef(0.5, 0.5, 0.90);
glColor3f(1.0,0.4,0.2);
	glBegin(GL_POLYGON);
glColor3f(0.9,0.8,0.2);
	glVertex2f(4.0,1.0);
	glVertex2f(4.5,1.5);
	glVertex2f(4.5,2.0);
    glVertex2f(0.5,2.0);
    glVertex2f(1.5,1.0);

    glColor3f(0.2,0.5,0.6);
    glVertex2f(4.0,2.0);
	glVertex2f(4.0,2.5);
	glVertex2f(2.5,2.5);
	glVertex2f(2.0,2.0);

	glEnd();


glPopMatrix();


//5th
glPushMatrix();
glTranslatef(0, -5.7, 0.0);
glScalef(0.5, 0.5, 0.90);
glColor3f(1.0,0.4,0.2);
	glBegin(GL_POLYGON);
glColor3f(0,0,1);
	glVertex2f(4.0,1.0);
	glVertex2f(4.5,1.5);
	glVertex2f(4.5,2.0);
    glVertex2f(0.5,2.0);
    glVertex2f(1.5,1.0);

    glColor3f(0.2,0.5,0.6);
    glVertex2f(4.0,2.0);
	glVertex2f(4.0,2.5);
	glVertex2f(2.5,2.5);
	glVertex2f(2.0,2.0);

	glEnd();


glPopMatrix();


//6th
glPushMatrix();
glTranslatef(0, -6.7, 0.0);
glScalef(0.5, 0.5, 0.90);
glColor3f(1.0,0.4,0.2);
	glBegin(GL_POLYGON);
glColor3f(0.9,0.8,0.2);
	glVertex2f(4.0,1.0);
	glVertex2f(4.5,1.5);
	glVertex2f(4.5,2.0);
    glVertex2f(0.5,2.0);
    glVertex2f(1.5,1.0);

    glColor3f(0.2,0.5,0.6);
    glVertex2f(4.0,2.0);
	glVertex2f(4.0,2.5);
	glVertex2f(2.5,2.5);
	glVertex2f(2.0,2.0);

	glEnd();


glPopMatrix();

glPopMatrix();

////////////////////////

//mesile
glPushMatrix();
glTranslatef(flow, randomY, 0.0);
glScalef(0.5, 0.5, 0.90);
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2f(.9,-.6);
glVertex2f(.1,-.6);
glVertex2f(-.2,-.45);
glColor3f(1.0,0.0,0);
glVertex2f(.1,-0.3);
glVertex2f(.9,-0.3);
glEnd();
glPopMatrix();

/////////

//Water
glPushMatrix();
glColor3f(0.0,0.0,1);
glBegin(GL_POLYGON);
	glVertex2f(6,-6.0);
	glVertex2f(-6,-6);
glColor3f(.10,.10,.10);
	glVertex2f(-6.8,0);
	glVertex2f(6.8,0);
glEnd();
glPopMatrix();


glPopMatrix();
colCheck();
cout<<"score: "<<scoreCount<<endl;
    levelUp();


   glFlush();
glutSwapBuffers();

}
/////////////
//Keyboard

/*
void keyboard (unsigned char key, int x, int y)
{
  if(key=='P' || key =='p'){
    paused = true;
  }
   if(key=='M' || key =='m'){
    paused = false;
  }
  if(key == 'X')
        exit(0);

}

*/

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {
case 's':
    case 'S':
    positionY -= speed;

    //PlaySound(TEXT("beep.wav"),NULL,SND_ASYNC);

    break;

case 'w':
    case 'W':
    positionY += speed;

    //PlaySound(TEXT("beep.wav"),NULL,SND_ASYNC);
    break;

case 'a':
    case 'A':
    positionX -= speed;

    //PlaySound(TEXT("beep.wav"),NULL,SND_ASYNC);

    break;

case 'd':
    case 'D':
    positionX += speed;

   //PlaySound(TEXT("beep.wav"),NULL,SND_ASYNC);
    break;


case 'Q':
             exit(0);
             break;
case 'q':
             exit(0);
             break;
    glutPostRedisplay();
	}
}


/////////////////////////////

void update(int value)
 {
     scoreCount+=0.5;
     flow-=0.1;
     if(flow<-6){
        flow = 5.4;
        temp=-ran2()-ran()+ran();
        if(temp>-3.4 && temp<0){
        randomY=temp;
        }
        else randomY=-0.3;
     }


     //sun
       _angl_1 += 0.007;
	if (_angl_1 > 12)
	{
		_angl_1 -= 11;
	}
//boat

        if(paused == false){
        _angl_2+= .005;
        if (_angl_2 > 10 ) {
            _angl_2 -= 11;
        }
    }

	_angl_3 += 1.6f;
	if (_angl_3 > 360)
	{
		_angl_3 -= 360;
	}
	_angl_4 += 1.1f;
	if (_angl_4 > 360)
	{
		_angl_4 -= 360;
	}
	_angl_5 += 1.0f;
	if (_angl_5 > 360)
	{
		_angl_5 -= 360;
	}
	_angl_6 += 1.3f;
	if (_angl_6 > 360)
	{
		_angl_6 -= 360;
	}
	_angl_7 += 1.8f;
	if (_angl_7 > 360)
	{
		_angl_7 -= 360;
	}
	_angl_8 += 2.0f;
	if (_angl_8 > 360)
	{
		_angl_8 -= 360;
	}



	//
	  if(positionX > 2.8)
        positionX = 2.8;
    else if (positionX<-5.2){
        positionX=-5.2;}

    if(positionY > -0.6)
        positionY = -0.6;
    else if (positionY<-3.15){
        positionY=-3.15;}

	//

	glutPostRedisplay();

glutTimerFunc(time, update, 0);
	//glutTimerFunc(25, update, 0);
}


///////////////////////////////


////////////////////main func///////////////////
int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1350, 690);
	glutInitWindowPosition(0,0);
   // cout<<"for going up press W\n";
	//Create the window
	glutCreateWindow("Battle Ware");
	initRendering();
   //glutFullScreen();

	//Set handler functions
	glutDisplayFunc(drawScene);


	glutReshapeFunc(handleResize);
    glutKeyboardFunc(handleKeypress);
	glutTimerFunc(22, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}
