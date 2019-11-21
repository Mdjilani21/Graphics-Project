#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <windows.h>
#include <glut.h>
#define PI 3.1416


/*using namespace std;

typedef struct Vect {
	float x;
	float y;
}Vector2D;

typedef struct s {
	Vector2D pos;
}Star;

//star size
float star_size = 1.00f;
Star stars[1000];
int n_stars = 100;*/



double circle_x=0.0;
double circle_y=0.0;
double moon_x=0.0;
double moon_y=0.0;

double cloud_x=-40.0;

int flag=0;
int move_sun=0;
int move_moon=0;



void drawTriangle1(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double R, double G, double B){
    glColor3f(R, G, B);
    glBegin(GL_TRIANGLES);
    {
        glVertex3f(x1,y1,z1);
        glVertex3f(x2,y2,z2);
        glVertex3f(x3,y3,z3);
    }
    glEnd();
}


void drawLine1()
{

    glBegin(GL_LINES);

    //1st pyramid
    glColor3f(0, 0, 0);//black
    glVertex3f(43, -30, 0);
    glVertex3f(73, -30, 0);

    glVertex3f(46, -26, 0);
    glVertex3f(71, -26, 0);

    glVertex3f(49, -22, 0);
    glVertex3f(69.5, -22, 0);

    glVertex3f(52, -18, 0);
    glVertex3f(68, -18, 0);

    glVertex3f(50, -14, 0);
    glVertex3f(66, -14, 0);

    glVertex3f(49, -10, 0);
    glVertex3f(64.25, -10, 0);

    glVertex3f(47, -6, 0);
    glVertex3f(63, -6, 0);

    glVertex3f(45, -2, 0);
    glVertex3f(61.25, -2, 0);

    glVertex3f(46, 2, 0);
    glVertex3f(59.5, 2, 0);

    glVertex3f(46.5, 6, 0);
    glVertex3f(58, 6, 0);

    glVertex3f(47.5, 10, 0);
    glVertex3f(56.25, 10, 0);

    glVertex3f(48, 14, 0);
    glVertex3f(54.5, 14, 0);

    glEnd();

}

void drawLine2()
{

    glBegin(GL_LINES);

    //2st pyramid
    glColor3f(0, 0, 0);//black
    glVertex3f(9, -32, 0);
    glVertex3f(57.75, -32, 0);

    glVertex3f(5, -26, 0);
    glVertex3f(55.5, -26, 0);

    glVertex3f(10, -20, 0);
    glVertex3f(53, -20, 0);

    glVertex3f(12, -14, 0);
    glVertex3f(51, -14, 0);

    glVertex3f(14, -8, 0);
    glVertex3f(48.5, -8, 0);

    glVertex3f(17.75, -2, 0);
    glVertex3f(46.5, -2, 0);

    glVertex3f(19, 4, 0);
    glVertex3f(44.5, 4, 0);

    glVertex3f(20, 10, 0);
    glVertex3f(41.5, 10, 0);

    glVertex3f(21.75, 16, 0);
    glVertex3f(39, 16, 0);

    glVertex3f(22.75, 22, 0);
    glVertex3f(37, 22, 0);

    glVertex3f(23.75, 28, 0);
    glVertex3f(34.75, 28, 0);

    glEnd();

}

void drawLine3()
{

    glBegin(GL_LINES);
    glColor3f(0,0,0); //black

    glVertex3f(-19, -40, 0);
    glVertex3f(33.25, -40, 0);

    glVertex3f(-18, -35, 0);
    glVertex3f(31.5, -35, 0);

    glVertex3f(-17, -30, 0);
    glVertex3f(29.5, -30, 0);

    glVertex3f(-16, -25, 0);
    glVertex3f(28, -25, 0);

    glVertex3f(-15, -20, 0);
    glVertex3f(26.25, -20, 0);

    glVertex3f(-14, -15, 0);
    glVertex3f(24.65, -15, 0);

    glVertex3f(-13, -10, 0);
    glVertex3f(22.65, -10, 0);

    glVertex3f(-12, -10, 0);
    glVertex3f(20.65, -10, 0);

    glVertex3f(-12, -5, 0);
    glVertex3f(21, -5, 0);

    glVertex3f(-11, 0, 0);
    glVertex3f(19.25, 0, 0);

    glVertex3f(-10, 5, 0);
    glVertex3f(17.5, 5, 0);

    glVertex3f(-9, 10, 0);
    glVertex3f(16, 10, 0);

    glVertex3f(-8, 15, 0);
    glVertex3f(14, 15, 0);

    glVertex3f(-7, 20, 0);
    glVertex3f(12.25, 20, 0);

    glVertex3f(-6, 25, 0);
    glVertex3f(10.5, 25, 0);

    glVertex3f(-5, 30, 0);
    glVertex3f(8.75, 30, 0);

    glVertex3f(-4, 35, 0);
    glVertex3f(7, 35, 0);

    glEnd();
}

void drawLine4()
{
    glBegin(GL_QUADS);
    glColor3f(0.34,0.18,0.05); //light wood
    glVertex3f(-70, -45, 0);
    glVertex3f(-60, -45, 0);
    glVertex3f(-60, 0, 0);
    glVertex3f(-70, 0, 0);

    glEnd();
}


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

void halfCircle(float radius_x, float radius_y){
    int i = 0;
    float angle = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++){
        angle = 2 * (PI/1.9) * i / 100;
        glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
    }

    glEnd();
}


void cloudCircle(float radius_x, float radius_y)
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

void drawSky(){

    glBegin(GL_QUADS);

    {
        glColor3f(.95, .95, .95);
            glVertex3f(-100,-19.95,0);
        glColor3f(.95, .95, .95);
            glVertex3f(100,-19.95,0);
        glColor3f( 0.24902, 0.247059, 0.957059);
            glVertex3f(100,100,0);
        glColor3f(0.24902, 0.247059, 0.957059);
            glVertex3f(-100,100,0);
    }
    glEnd();

}
void draw_nightSky(){

    glBegin(GL_QUADS);

    {
        glColor3f(0.05, 0.05, 0.05);
            glVertex3f(-100,-19.95,0);
        glColor3f(0.2, 0.2, 0.2);
            glVertex3f(100,-19.95,0);
        glColor3f(0.05, 0.05, 0.05);
            glVertex3f(100,100,0);
        glColor3f(0.27, 0.37, 0.47);
            glVertex3f(-100,100,0);
    }
    glEnd();

}

void drawGround()
{

    glColor3f(.93,.79,.69);
    glBegin(GL_QUADS);
    {
        //glColor3f(.43, .43, .43);
        glVertex3f(-100,-100,0);
        //glColor3f(.35, .35, .35);
        glVertex3f(100,-100,0);
        //glColor3f(.24 , .24, .24);
        glVertex3f(100,-20,0);
        //glColor3f(.12, .12, .12);
        glVertex3f(-100,-20,0);

    }
    glEnd();
}

void draw_NightGround()
{

    glColor3f(0.47, 0.42, 0.23);
    glBegin(GL_QUADS);
    {
        //glColor3f(.43, .43, .43);
        glVertex3f(-100,-100,0);
        //glColor3f(.35, .35, .35);
        glVertex3f(100,-100,0);
        //glColor3f(.24 , .24, .24);
        glVertex3f(100,-20,0);
        //glColor3f(.12, .12, .12);
        glVertex3f(-100,-20,0);

    }
    glEnd();
}

void drawRec1(){
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);//green

        glVertex3f(-62, -60, 0);
        glVertex3f(-58, -60, 0);
        glVertex3f(-58, -26, 0);
        glVertex3f(-62, -26, 0);

    glEnd();


}

void drawRec2(){
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);//green

        glVertex3f(-58, -50, 0);
        glVertex3f(-54, -50, 0);
        glVertex3f(-54, -45, 0);
        glVertex3f(-58, -45, 0);

    glEnd();


}

void drawRec3(){
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);//green

        glVertex3f(-56, -45, 0);
        glVertex3f(-54, -45, 0);
        glVertex3f(-54, -35, 0);
        glVertex3f(-56, -35, 0);

    glEnd();


}

void drawRec4(){
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);//green

        glVertex3f(-66, -45, 0);
        glVertex3f(-62, -45, 0);
        glVertex3f(-62, -40, 0);
        glVertex3f(-66, -40, 0);

    glEnd();


}

void drawRec5(){
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);//green

        glVertex3f(-66, -40, 0);
        glVertex3f(-64, -40, 0);
        glVertex3f(-64, -30, 0);
        glVertex3f(-66, -30, 0);

    glEnd();


}

void dLine1(){
    glBegin(GL_LINES);
    glColor3f(0, 1, 0);//green

        glVertex3f(-58,-52,0);
        glVertex3f(-57,-52,0);

        glVertex3f(-58,-52,0);
        glVertex3f(-57,-51,0);

        glVertex3f(-58,-26,0);
        glVertex3f(-57,-26,0);

        glVertex3f(-58,-26,0);
        glVertex3f(-57,-27,0);

        glVertex3f(-58,-30,0);
        glVertex3f(-57,-31,0);

        glVertex3f(-58,-30,0);
        glVertex3f(-57,-30,0);

        glVertex3f(-58,-35,0);
        glVertex3f(-57,-35,0);

        glVertex3f(-58,-35,0);
        glVertex3f(-57,-36,0);

        glVertex3f(-58,-40,0);
        glVertex3f(-57,-40,0);

        glVertex3f(-58,-40,0);
        glVertex3f(-57,-41,0);

        glVertex3f(-62,-35,0);
        glVertex3f(-63,-35,0);

        glVertex3f(-62,-35,0);
        glVertex3f(-63,-34,0);

        glVertex3f(-62,-28,0);
        glVertex3f(-63,-28,0);

        glVertex3f(-62,-28,0);
        glVertex3f(-63,-29,0);

        glVertex3f(-62,-47,0);
        glVertex3f(-63,-47,0);

        glVertex3f(-62,-47,0);
        glVertex3f(-63,-48,0);

        glVertex3f(-62,-52,0);
        glVertex3f(-63,-52,0);

        glVertex3f(-62,-52,0);
        glVertex3f(-63,-53,0);

        glVertex3f(-54,-45,0);
        glVertex3f(-53,-45,0);

        glVertex3f(-54,-45,0);
        glVertex3f(-53,-46,0);


        glVertex3f(-54,-40,0);
        glVertex3f(-53,-40,0);

        glVertex3f(-54,-40,0);
        glVertex3f(-53,-41,0);

        glVertex3f(-54,-35,0);
        glVertex3f(-53,-35,0);

        glVertex3f(-54,-35,0);
        glVertex3f(-53,-36,0);

        glVertex3f(-66,-42,0);
        glVertex3f(-67,-42,0);

        glVertex3f(-66,-42,0);
        glVertex3f(-67,-43,0);

        glVertex3f(-66,-38,0);
        glVertex3f(-67,-38,0);

        glVertex3f(-66,-38,0);
        glVertex3f(-67,-37,0);

        glVertex3f(-66,-34,0);
        glVertex3f(-67,-34,0);

        glVertex3f(-66,-34,0);
        glVertex3f(-67,-35,0);

    glEnd();
}

void cactus(){
            glPushMatrix();
            dLine1();
            glPushMatrix();
            glTranslatef(-65,-30,0);
            glColor3f(0, 1, 0);
            halfCircle(1,1);
            glPopMatrix();
            glPushMatrix();
            glTranslatef(-55,-35,0);
            glColor3f(0, 1, 0);
            halfCircle(1,1);
            glPopMatrix();
            glPushMatrix();
            glTranslatef(-60,-26,0);
            glColor3f(0, 1, 0);
            halfCircle(2,2);
            glPopMatrix();
            drawRec5();
            drawRec4();
            drawRec3();
            drawRec2();
            drawRec1();
            glTranslatef(-60,-60,0);
            glColor3f(0, 1, 0);
            halfCircle(6,6);
            glPopMatrix();
        }


//Draw Star Background
/*void drawStar(float size) {

	glBegin(GL_TRIANGLES);
	glVertex2f(size/3, size/3);
	glVertex2f(-size/3, size/3);
	glVertex2f(0, -1.414*size/3);
	glVertex2f(size/3, -size/3);
	glVertex2f(-size/3, -size/3);
	glVertex2f(0, 1.414*size/3);
	glEnd();
}*/

//void starCreator() {
//
//
//	int i;
//	for (i=0; i<n_stars; i++)
//	{
//		Star temp;
//		temp.pos.x = (-100 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(100+100))));
//		temp.pos.y = (-20 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(100+100))));
//
//		stars[i] = temp;
//	}
//}

//void star(){
//
//    int a;
//	for (a=0; a<n_stars; a++)
//	{
//		glTranslatef(stars[a].pos.x, stars[a].pos.y, 0.1f);
//		glColor3f(1.0f, 1.0f, 1.0f);
//		drawStar(star_size);
//
//	}
//    starCreator();
//}

void display(){
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

    //Draw stars


    //day
    if(flag==0){

        //pyramid
        glPushMatrix();
        drawLine3();
        drawTriangle1(-35,-35,0, -20,-45, 0, 0, 55, 0, .18, .18, .12);//6
        drawTriangle1(-20,-45,0, 35,-45, 0, 0, 55, 0, 0.8, 0.498039, 0.137255);//5
        drawLine2();
        drawTriangle1(-10,-20,0, 10,-38, 0, 28, 45, 0, .18, .18, .12);//4
        drawTriangle1(10,-38,0, 60,-38, 0, 28, 45, 0, 0.858824, 0.858824, 0.439216);//3
        drawLine1();
        drawTriangle1(30,-20,0, 40,-35, 0, 50, 25, 0, .18, .18, .12);//2
        drawTriangle1(40,-35,0, 75,-35, 0, 50, 25, 0, 0.8, 0.498039, 0.137255);//1
        glPopMatrix();

        //cloud
        glPushMatrix();
        glTranslatef(-40+cloud_x,75,0);
        glColor3f(1,1,1);
        cloudCircle(10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-55+cloud_x,70,0);
        glColor3f(1,1,1);
        cloudCircle(10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-50+cloud_x,85,0);
        glColor3f(1,1,1);
        cloudCircle(10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-40+cloud_x,60,0);
        glColor3f(1,1,1);
        cloudCircle(10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-55+cloud_x,55,0);
        glColor3f(1,1,1);
        cloudCircle(10,10);
        glPopMatrix();

        //sun
        glPushMatrix();
        glTranslatef(70-circle_x,80-circle_y,0);
        glColor3f(1, .84, 0);
        circle(10,10);
        glPopMatrix();

        //ground hill
        glPushMatrix();
        glTranslatef(92,-20,0);
        glColor3f(.93,.79,.69);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(77,-20,0);
        glColor3f(.93,.79,.69);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-35,-20,0);
        glColor3f(.93,.79,.69);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-50,-20,0);
        glColor3f(.93,.79,.69);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-65,-20,0);
        glColor3f(.93,.79,.69);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-80,-20,0);
        glColor3f(.93,.79,.69);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-95,-20,0);
        glColor3f(.93,.79,.69);
        halfCircle(8,8);
        glPopMatrix();

        //sky
        glPushMatrix();
        drawSky();
        glPopMatrix();


         //draw cactus
         glPushMatrix();
            glTranslatef(-60,-45,0);
            glScalef(.5,.5,0);
            cactus();
        glPopMatrix();
         glPushMatrix();
            glTranslatef(-55,-57,0);
            glScalef(.5,.5,0);
            cactus();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-63,-58,0);
            glScalef(.5,.5,0);
            cactus();
        glPopMatrix();


        //ground
        glPushMatrix();
        drawGround();
        glPopMatrix();
    }

    //night
    if(flag==1){

        //pyramid
        drawLine3();
        drawTriangle1(-35,-35,0, -20,-45, 0, 0, 55, 0, .18, .18, .12);//6
        drawTriangle1(-20,-45,0, 35,-45, 0, 0, 55, 0, 0.34, 0.18, 0.06);//5
        drawLine2();
        drawTriangle1(-10,-20,0, 10,-38, 0, 28, 45, 0, .18, .18, .12);//4
        drawTriangle1(10,-38,0, 60,-38, 0, 28, 45, 0, 0.32, 0.32, 0.08);//3
        drawLine1();
        drawTriangle1(30,-20,0, 40,-35, 0, 50, 25, 0, .18, .18, .12);//2
        drawTriangle1(40,-35,0, 75,-35, 0, 50, 25, 0, 0.34, 0.18, 0.06);//1

        //cloud
        glPushMatrix();
        glTranslatef(-40+cloud_x,75,0);
        glColor3f(.7,.7,.7);
        cloudCircle(10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-55+cloud_x,70,0);
        glColor3f(.7,.7,.7);
        cloudCircle(10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-50+cloud_x,85,0);
        glColor3f(.7,.7 ,.7);
        cloudCircle(10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-40+cloud_x,60,0);
        glColor3f(.7,.7,.7);
        cloudCircle(10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-55+cloud_x,55,0);
        glColor3f(.7,.7,.7);
        cloudCircle(10,10);
        glPopMatrix();

        //moon
        glPushMatrix();
        glTranslatef(moon_x,moon_y,0);
        glColor3f(.9, .9, .9);
        circle(10,10);
        glPopMatrix();

        //ground hill
        glPushMatrix();
        glTranslatef(92,-20,0);
        glColor3f(0.47, 0.42, 0.23);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(77,-20,0);
        glColor3f(0.47, 0.42, 0.23);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-35,-20,0);
        glColor3f(0.47, 0.42, 0.23);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-50,-20,0);
        glColor3f(0.47, 0.42, 0.23);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-65,-20,0);
        glColor3f(0.47, 0.42, 0.23);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-80,-20,0);
        glColor3f(0.47, 0.42, 0.23);
        halfCircle(8,8);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-95,-20,0);
        glColor3f(0.47, 0.42, 0.23);
        halfCircle(8,8);
        glPopMatrix();


        /*glPushMatrix();
        for(int i = 1; i < 12; i++)
        {
            glPushMatrix();
            glTranslatef(-100 + ((float)rand())/((float)(RAND_MAX)/200),-15 + ((float)rand())/((float)(RAND_MAX)/115),0);
            glColor3f(1,1,1);
            glutSolidSphere(0.3,10,10);
            glPopMatrix();
        }
        glPopMatrix();*/

        //night_sky
        glPushMatrix();
        draw_nightSky();
        glPopMatrix();

        //draw cactus
        /*glPushMatrix();
            drawCactus();
            glTranslatef(-55,-55,0);
            glColor3f(0, 1, 0);
            halfCircle(8,8);
        glPopMatrix();*/

         //draw cactus
         glPushMatrix();
            glTranslatef(-60,-45,0);
            glScalef(.5,.5,0);
            cactus();
        glPopMatrix();
         glPushMatrix();
            glTranslatef(-55,-57,0);
            glScalef(.5,.5,0);
            cactus();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-63,-58,0);
            glScalef(.5,.5,0);
            cactus();
        glPopMatrix();

        //ground
        glPushMatrix();
        draw_NightGround();
        glPopMatrix();


    }




    //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
    glutSwapBuffers();
}
void specialKeyListener(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        move_sun=1;

    }else if (key == GLUT_KEY_DOWN){
        //printf("==>hello");
        move_moon=1;
        circle_x=70;
        circle_y=80;

    }
    else if (key == GLUT_KEY_LEFT)
    {

    }
    else if (key == GLUT_KEY_RIGHT)
    {

    }
    else if (key == GLUT_KEY_PAGE_UP)
    {

    }
    else if (key == GLUT_KEY_PAGE_DOWN)
    {

    }
}
void animate()
{
    //codes for any changes in Models, Camera

    //this will call the display AGAIN
    //sun_set
    if(circle_x<=68&&move_sun==1&&move_moon==0){
        circle_x=circle_x+0.01;
        circle_y=circle_y+0.01;

    }
    //moon_rise
    else if(circle_x>=68&&moon_x<=70&&move_moon==0){
        flag=1;
        moon_x=moon_x+0.01;
        moon_y=moon_y+0.01;
        //printf("==>%f\n",moon_x);

    }
    //moon_set
    if(move_moon==1&&moon_x>=0){
        moon_x=moon_x-0.01;
        moon_y=moon_y-0.01;
        //printf("==>%f\n",moon_x);

    }
    //sun_rise
    else if(moon_x<=0&&circle_x>=0&&move_moon==1){
        flag=0;
        circle_x=circle_x-0.01;
        circle_y=circle_y-0.01;

    }
    //cloud
    if(cloud_x>=170){
        cloud_x=-40.0;
    }
    else{
        cloud_x=cloud_x+0.01;

    }

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

    gluPerspective(90, 1, 0.1, 10000.0);

}

int main(int argc, char **argv)
{
    //initialize the GLUT library
    glutInit(&argc, argv);

    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);

    /*
    glutInitDisplayMode - inits display mode
    GLUT_DOUBLE - allows for display on the double buffer window
    GLUT_RGBA - shows color (Red, green, blue) and an alpha
    GLUT_DEPTH - allows for depth buffer
    */
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

    glutCreateWindow("Pyramid");

    //codes for initialization
    init();

    //enable Depth Testing
    glEnable(GL_DEPTH_TEST);

    //display callback function
    glutDisplayFunc(display);

    glutSpecialFunc(specialKeyListener);


    //what you want to do in the idle time (when no drawing is occurring)
    glutIdleFunc(animate);

    //The main loop of OpenGL
    glutMainLoop();


    return 0;
}

