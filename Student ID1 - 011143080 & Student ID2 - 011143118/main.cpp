#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1416

static float mx	=  0.0,my	=  0.0;
float p=-200.0,q= 120.0;
int f=0,g=0;

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


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();


    if(p<=+50.0)
        p=p+0.05;

    else
        p=-200;
    glutPostRedisplay();
    glClear(GL_COLOR_BUFFER_BIT);


    if(q>=-100.0)
        q=q-0.05;

    else
        q=120;
    glutPostRedisplay();
    glClear(GL_COLOR_BUFFER_BIT);

//background
//sky
    glPushMatrix();
    glTranslatef(0,30,0);
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.9, 0.9);
    glVertex2d(100, 74);
    glColor3f(0.6, 0.9, 0.9);
    glVertex2d(-100, 74);
    glColor3f(0.6, 0.9, 0.9);
    glVertex2d(-100, 0);
    glColor3f(0.6, 0.9, 0.9);
    glVertex2d(100, 0);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(58.5,81,0);
    glColor3f(0, 0, 0);
    circle(8.8,8.8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(71.7,83,0);
    glColor3f(0, 0, 0);
    circle(10.7,10.7);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(58.5,81,0);
    glColor3f(.8, .8, .7);
    circle(8,8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(71.7,83,0);
    glColor3f(.8, .8, .7);
    circle(10,10);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(65,80.5,0);
    glColor3f(0, 0, 0);
    circle(8.48,8.48);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(75.7,81,0);
    glColor3f(0, 0, 0);
    circle(10.2,10.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(85,80.5,0);
    glColor3f(0, 0, 0);
    circle(8.48,8.48);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(65,80.5,0);
    glColor3f(1, 0.96, 0.93);
    circle(7.67,7.67);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(75.7,81,0);
    glColor3f(1, 0.96, 0.93);
    circle(9.5,9.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(85,80.5,0);
    glColor3f(1, 0.96, 0.93);
    circle(7.67,7.67);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(8,80.5,0);
    glColor3f(0, 0, 0);
    circle(8.48,8.48);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18.7,81,0);
    glColor3f(0, 0, 0);
    circle(10.2,10.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(28,80.5,0);
    glColor3f(0, 0, 0);
    circle(8.48,8.48);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8,80.5,0);
    glColor3f(1, 0.96, 0.93);
    circle(7.67,7.67);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18.7,81,0);
    glColor3f(1, 0.96, 0.93);
    circle(9.5,9.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(28,80.5,0);
    glColor3f(1, 0.96, 0.93);
    circle(7.67,7.67);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-73,70,0);
    glColor3f(1, 0.8, 0.5);
    circle(11,11);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-73,70,0);
    glColor3f(1, 0.8, 0.4);
    circle(10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-73,70,0);
    glColor3f(1, .8, 0);
    circle(8,8);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-75,40,0);
    glColor3f(0, .80, 0);
    circle(12,15);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-80,40,0);
    glColor3f(0.133, .55, 0.133);
    circle(13,13);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-60,40,0);
    glColor3f(0, .80, 0);
    circle(13,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-45,35,0);
    glColor3f(0.133, .55, 0.133);
    circle(10,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40,35,0);
    glColor3f(0.133, .55, 0.133);
    circle(10,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-42,35,0);
    glColor3f(0.133, .55, 0.133);
    circle(13,15);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-40,38,0);
    glColor3f(0.133, .55, 0.133);
    circle(20,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8,35,0);
    glColor3f(0.133, .55, 0.133);
    circle(8,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,35,0);
    glColor3f(0.133, .55, 0.133);
    circle(10,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-13,35,0);
    glColor3f(0.133, .55, 0.133);
    circle(15,15);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0,32,0);
    glColor3f(0.5, 0.7, 0);
    circle(8,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,20,0);
    glColor3f(0.5, 0.7, 0);
    circle(10,8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,32,0);
    glColor3f(0.5, 0.7, 0);
    circle(10,13);
    glPopMatrix();


     glPushMatrix();
    glTranslatef(10,40,0);
    glColor3f(0.133, .55, 0.133);
    circle(8,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,40,0);
    glColor3f(0.133, .55, 0.133);
    circle(10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25,40,0);
    glColor3f(0.133, .55, 0.133);
    circle(12,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,35,0);
    glColor3f(0.5, 0.7, 0);
    circle(8,12);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25,35,0);
    glColor3f(0.3, .60, 0.1);
    circle(12,12);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(45,35,0);
    glColor3f(0.133, .55, 0.133);
    circle(8,12);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(45,35,0);
    glColor3f(0.133, .55, 0.133);
    circle(10,12);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(50,35,0);
    glColor3f(0.133, .55, 0.133);
    circle(10,12);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60,36,0);
    glColor3f(0.133, .55, 0.133);
    circle(15,14);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(85,37,0);
    glColor3f(0.133, .55, 0.133);
    circle(20,16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(75,37,0);
    glColor3f(0.133, .55, 0.133);
    circle(17,15);
    glPopMatrix();

//hill
    glPushMatrix();
    glTranslatef(-90,30,0);
    glBegin(GL_TRIANGLES);
    glColor3f(.9, .6, .2);
    glVertex2d(35, 0);
    glColor3f(.48, .35, .2);
    glVertex2d(0, 35);
    glColor3f(.48, .34, .1);
    glVertex2d(-35, -0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-67,30,0);
    glBegin(GL_TRIANGLES);
    glColor3f(.9, .6, .4);
    glVertex2d(25, 5);
    glColor3f(.5, .25, .1);
    glVertex2d(5, 30);
    glColor3f(.5, .25, .1);
    glVertex2d(-25, -5);
    glEnd();
    glPopMatrix();

//river
    glPushMatrix();
    glTranslatef(0,-35,0);
    glBegin(GL_QUADS);
    glColor3f(.2, .7, .6);
    glVertex2d(100, 75);
    glColor3f(.2, .81, .98);
    glVertex2d(-100, 75);
    glColor3f(.25, .41, .88);
    glVertex2d(-100, 0);
    glColor3f(.2, .8, .8);
    glVertex2d(100, 0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1,-14,0);
    glColor3f(0.133, .55, 0.133);
    circle(10,11);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12,-16,0);
    glColor3f(0.133, .55, 0.133);
    circle(5,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10.5,-16,0);
    glColor3f(0.6, .8, 0.1);
    circle(4,4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-15,0);
    glColor3f(0.5, 0.7, 0);
    circle(9,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(17,-15,0);
    glColor3f(0.133, .55, 0.133);
    circle(14,13);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(17,-16,0);
    glColor3f(0.3, .60, 0.1);
    circle(13,12);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,-14.5,0);
    glColor3f(0.5, 0.7, 0);
    circle(5,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(32.5,-14.5,0);
    glColor3f(0.6, .8, 0.1);
    circle(4,4);
    glPopMatrix();
    //middle...

    glPushMatrix();
    glTranslatef(-98,-24,0);
    glColor3f(0.133, .55, 0.133);
    circle(10,11);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-90,-24,0);
    glColor3f(0.5, 0.7, 0);
    circle(9,10);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-72,-24,0);
    glColor3f(0.133, .55, 0.133);
    circle(14,13);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-72,-25,0);
    glColor3f(0.3, .60, 0.1);
    circle(13,12);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60,-24,0);
    glColor3f(0.5, 0.7, 0);
    circle(5,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-58,-24.,0);
    glColor3f(0.6, .8, 0.1);
    circle(4,4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(88,-6,0);
    glColor3f(0.133, .55, 0.133);
    circle(10,11);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(78,-9.8,0);
    glColor3f(0.133, .55, 0.133);
    circle(5,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80.5,-9.8,0);
    glColor3f(0.6, .8, 0.1);
    circle(4,4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,-6,0);
    glColor3f(0.5, 0.7, 0);
    circle(9,10);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-84,-25,0);
    glRotatef(10, 0.0, 0.0, 1.0);

    glPushMatrix();
    glColor3f(0.196, .80, 0.196);
    glTranslatef(-7,-2,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, .39, 0);
    glColor3f(0.133, .55, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-1,0);
    glColor3f(0.133, .55, 0.133);
    glColor3f(0, .39, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(94,-8,0);
    glRotatef(-10, 0.0, 0.0, 1.0);

    glPushMatrix();
    glColor3f(0.42, .56, 0.14);
    glTranslatef(-7,-2,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.42, .56, 0.14);
    glColor3f(0, .39, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-1,0);
    glColor3f(0.42, .56, 0.14);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();



// beach

    glPushMatrix();
    glTranslatef(0,-100,0);
    glBegin(GL_QUADS);
    glColor3f(.9, .4, 0.0);
    glVertex2d(100, 94);
    glColor3f(.9, .4, 0.2);
    glVertex2d(-100, 74);
    glColor3f(.9, .5, 0.1);
    glVertex2d(-100, 0);
    glColor3f(.9, .5, 0.0);
    glVertex2d(100, 0);
    glEnd();


//rock and stone
    glTranslatef(147,-60,0);

    glPushMatrix();
    glTranslatef(-90,60,0);
    glColor3f(0.9, .6, 0.2);
    circle(7,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-80,65,0);
    glColor3f(.9, .2, 0);
    circle(10,12);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-65,55,0);
    glColor3f(1, .6, 0.2);
    circle(12,16);
    glPopMatrix();



    glPopMatrix();

// ground

    glPushMatrix();
    glTranslatef(10,-10,0);

    glPushMatrix();
    glColor3f(0.42, .56, 0.14);
    glColor3f(0, .39, 0);
    glTranslatef(-10,-6,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(-5, 30);
    glVertex2d(8, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.196, .80, 0.196);
    glTranslatef(-7,-6,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 30);
    glVertex2d(5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-6,0);
    glColor3f(0.42, .56, 0.14);
    glColor3f(0, .39, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-5.9,0);
    glColor3f(0.133, .55, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(60,-100,0);
    glRotatef(10, 0.0, 0.0, 1.0);

    glPushMatrix();
    glColor3f(0.42, .56, 0.14);
    glTranslatef(-7,-2,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.42, .56, 0.14);
    glColor3f(0, .39, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-1,0);
    glColor3f(0.42, .56, 0.14);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-93,-98,0);
    glRotatef(-10, 0.0, 0.0, 1.0);

    glPushMatrix();
    glColor3f(0.196, .80, 0.196);
    glTranslatef(-7,-2,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, .39, 0);
    glColor3f(0.133, .55, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-1,0);
    glColor3f(0.133, .55, 0.133);
    glColor3f(0, .39, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-5, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();

//ground ends


    if (f==1 && f!=2)
    {
        glTranslatef(p+100,0,0);
    }


// boat

    glPushMatrix();

    glTranslatef(q-100,0,0);
    glTranslatef(-20,-31,0);


    glPushMatrix();
    glTranslatef(59,55,0);
    glColor3f(0.42, .56, 0.14);
    glColor3f(0.8, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 21);
    glVertex2d(-8, 5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60,55,0);
    glColor3f(0.42, .56, 0.14);
    glColor3f(0, .39, 9);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(-8, 5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(70,65.5,0);
    glRotatef(-18, 0.0, 0.0, 1.0);
    glColor3f(0, 0, 0);
    glRectf(4.5,2.25,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(74.5,64,0);
    glRotatef(0, 0.0, 0.0, 1.0);
    glColor3f(0, 0, 0);
    glRectf(8.2,2.25,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(82,64,0);
    glRotatef(27, 0.0, 0.0, 1.0);
    glColor3f(0, 0, 0);
    glRectf(4.5,2.25,0,0);
    glPopMatrix();
    //2
    glTranslatef(-21,-10,0);
    glPushMatrix();
    glTranslatef(99,75,0);
    glColor3f(0.7, .6, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 21);
    glVertex2d(-8, 5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(102,75,0);
    glColor3f(0.42, .56, 0.14);
    glColor3f(0.8, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 21);
    glVertex2d(-8, 5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(70,65.5,0);
    glRotatef(-18, 0.0, 0.0, 1.0);
    glColor3f(0, 0, 0);
    glRectf(4.5,2.25,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(74.5,64,0);
    glRotatef(0, 0.0, 0.0, 1.0);
    glColor3f(0, 0, 0);
    glRectf(8.2,2.25,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(82,64,0);
    glRotatef(27, 0.0, 0.0, 1.0);//line
    glColor3f(0, 0, 0);
    glRectf(4.5,2.25,0,0);
    glPopMatrix();

    glPopMatrix();



//BayMax body collect from internet

    if(f==1 && f!=2)
    {
        glScalef(1.3,1.3,0);
        glTranslatef(-10,10,0);
    }

    if(f!=1)
    {
        glTranslatef(mx,my,0);
        glScalef(2.8,2.8,0);
        glTranslatef(-25,-22,0);
    }



//hands

//right hand......

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(20.0, 0.0, 0.0, 1.0);//right border
    glTranslatef(12.3,2.0,0);
    circle(3.5,8.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(-14.5, 0.0, 0.0, 1.0);//right border1
    glTranslatef(12.0,1.8,0);
    circle(0.99,1.6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    //glColor3f(1, .96, .93);
    glRotatef(-14.0, 0.0, 0.0, 1.0);//right
    glTranslatef(12.0,1.8,0);
    circle(0.9,1.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(-12.5, 0.0, 0.0, 1.0);//right border2
    glTranslatef(13.2,1.8,0);
    circle(0.99,1.6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    //glColor3f(1, .96, .93);
    glRotatef(-12.5, 0.0, 0.0, 1.0);//right2
    glTranslatef(13.2,1.8,0);
    circle(0.9,1.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    //glColor3f(1, .96, .93);
    glRotatef(20.0, 0.0, 0.0, 1.0);//right1
    glTranslatef(12.3,2.0,0);
    circle(3.3,8.4);
    glPopMatrix();



//left hand

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(-55.5, 0.0, 0.0, 1.0);//right border
    glTranslatef(-9.9,2.5,0);
    circle(3.5,5.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(0.75, 0.0, 0.0, 1.0);//right border
    glTranslatef(-5.5,11.5,0);
    circle(3.0,6.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    //glColor3f(1, .96, .93);
    glRotatef(-55.5, 0.0, 0.0, 1.0);//left1
    glTranslatef(-9.9,2.5,0);
    circle(3.3,4.8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(0.75, 0.0, 0.0, 1.0);//left2 shade1
    glTranslatef(-5.5,11.5,0);
    circle(2.8,6.4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    //glColor3f(1, .96, .93);
    glRotatef(0.75, 0.0, 0.0, 1.0);//left
    glTranslatef(-5.44,12.88,0);
    circle(2.75,3.7);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(0.15, 0.0, 0.0, 1.0);//left2 shade finger
    glTranslatef(-4.43,14.86,0);
    circle(1.02,1.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    //glColor3f(1, .96, .93);
    glRotatef(0.15, 0.0, 0.0, 1.0);//left2 finger
    glTranslatef(-4.35,14.84,0);
    circle(0.88,1.0);
    glPopMatrix();


    //finger

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(-10.8, 0.0, 0.0, 1.0);//last border
    glTranslatef(-6.96,14.99,0);
    circle(0.70,1.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(-10.8, 0.0, 0.0, 1.0);//last shade border
    glTranslatef(-6.96,14.99,0);
    circle(0.59,1.02);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    //glColor3f(1, .96, .93);
    glRotatef(-10.8, 0.0, 0.0, 1.0);//last white border
    glTranslatef(-6.96,15.25,0);
    circle(0.52,0.6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(-8.76, 0.0, 0.0, 1.0);//right border
    glTranslatef(-7.5,16.76,0);
    circle(0.70,1.55);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(-8.8, 0.0, 0.0, 1.0);//right shade border
    glTranslatef(-7.5,16.76,0);
    circle(0.48,1.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    glRotatef(-8.8, 0.0, 0.0, 1.0);//right white border
    glTranslatef(-7.38,16.76,0);
    circle(0.35,1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(0.75, 0.0, 0.0, 1.0);//middle border
    glTranslatef(-5.8,17.53,0);
    circle(0.70,1.52);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(0.75, 0.0, 0.0, 1.0);//middle shade border
    glTranslatef(-5.8,17.53,0);
    circle(0.5,1.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    glRotatef(0.75, 0.0, 0.0, 1.0);//middle white border
    glTranslatef(-5.7,17.53,0);
    circle(0.40,1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(8.95, 0.0, 0.0, 1.0);//left border
    glTranslatef(-4.3,17.89,0);
    circle(0.70,1.39);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(8.95, 0.0, 0.0, 1.0);//left shade border
    glTranslatef(-4.3,17.89,0);
    circle(0.5,1.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    glRotatef(8.95, 0.0, 0.0, 1.0);//left white border
    glTranslatef(-4.2,17.89,0);
    circle(0.4,1.0);
    glPopMatrix();

//finger ends
//hand ends

// legs
 //right

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right border
    glTranslatef(7.0,-4.8,0);
    circle(3.0,8.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right border
    glTranslatef(6.5,-7.0,0);
    circle(3.4,8.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right border
    glTranslatef(6.5,-10.5,0);
    circle(2.85,4.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right
    glTranslatef(7.0,-4.8,0);
    circle(2.84,8.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right
    glTranslatef(6.5,-6.87,0);
    circle(3.2,7.97);
    glPopMatrix();
    //..........
    //left

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right border
    glTranslatef(0.05,-4.8,0);
    circle(3.0,8.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right border
    glTranslatef(0.09,-7.0,0);
    circle(3.4,8.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right border
    glTranslatef(0.09,-10.5,0);
    circle(2.85,4.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right
    glTranslatef(0.09,-4.8,0);
    circle(2.84,8.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    glRotatef(0, 0.0, 0.0, 1.0);//right
    glTranslatef(0.09,-6.87,0);
    circle(3.2,7.97);
    glPopMatrix();
    //..........

    //side borders

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(3.0, 0.0, 0.0, 1.0);//left border
    glTranslatef(-3.09,-6.2,0);
    circle(.7,3.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    glRotatef(3.0, 0.0, 0.0, 1.0);//left
    glTranslatef(-3.09,-6.2,0);
    circle(.58,2.6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(5.0, 0.0, 0.0, 1.0);//left lowest border
    glTranslatef(-0.99,-13.25,0);
    circle(2.02,1.52);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(5.0, 0.0, 0.0, 1.0);//lowest left
    glTranslatef(-0.99,-13.24,0);
    circle(1.88,1.42);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(-3.0, 0.0, 0.0, 1.0);//right border
    glTranslatef(9.5,-6.0,0);
    circle(.75,3.2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(.85, .85, .80);
    glRotatef(-3.0, 0.0, 0.0, 1.0);//right
    glTranslatef(9.5,-6.0,0);
    circle(.59,2.7);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(5.0, 0.0, 0.0, 1.0);//right lowest border
    glTranslatef(5.58,-13.84,0);
    circle(2.02,1.52);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(5.0, 0.0, 0.0, 1.0);//lowest right
    glTranslatef(5.58,-13.84,0);
    circle(1.88,1.42);
    glPopMatrix();


    //.............

     //ball
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(16.0,-12.00,0); //upper body border
    circle(4.0,4.4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.9, 0, .1);
    glTranslatef(16.0,-12.00,0); //upper body border
    circle(3.89,4.28);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(16.15,-12.00,0); //upper body border
    circle(2.5,4.4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    glTranslatef(16.15,-12.00,0); //upper body border
    circle(2.38,4.28);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(16.15,-12.00,0); //upper body border
    circle(1.08,4.4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.9, 0, .1);
    glTranslatef(16.15,-12.00,0); //upper body border
    circle(0.93,4.2);
    glPopMatrix();
    //ball ends........

//body............

    //body border


    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(-20.0, 0.0, 0.0, 1.0);//left
    glTranslatef(-5.2,9.3,0);
    circle(1.5,3.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0); //lower body1
    glTranslatef(3.7,8.5,0);
    circle(5.99,8.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0); //lower body1
    glTranslatef(3.7,7.5,0);
    circle(6.99,8.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0); //lower body1
    glTranslatef(3.69,2.8,0);
    circle(8.5,10.5);
    glPopMatrix();

    //bodyShape

    glPushMatrix();
    glColor3f(1, .96, .93); //lower body1
    glTranslatef(3.7,8.5,0);
    circle(5.8,8.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93); //lower body1
    glTranslatef(3.7,7.5,0);
    circle(6.8,8.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93); //lower body1
    glTranslatef(3.7,2.6,0);
    circle(8.3,10.0);
    glPopMatrix();

   //logo
    glPushMatrix();
    glColor3f(0, 0, 0); //border
    glTranslatef(6.99,12.2,0);
    circle(1.3,1.13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93); //circle
    glTranslatef(6.99,12.2,0);
    circle(1.1,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.5,11.6,0);
    glRotatef(30, 0.0, 0.0, 0.0);//border line black
    glColor3f(0, 0, 0);
    glRectf(1.0,1.1,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.95,12.0,0);
    glRotatef(30, 0.0, 0.0, 0.0);//line black
    glColor3f(0, 0, 0);
    glRectf(2.42,0.3,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.5,11.3,0);
    glRotatef(30, 0.0, 0.0, 0.0);//border line white
    glColor3f(1, .96, .93);
    glRectf(1.0,1.1,0,0);
    glPopMatrix();

    //logo end

    //side shade

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(16.0, 0.0, 0.0, 1.0);//right border
    glTranslatef(12.3,3.5,0);
    circle(.7,3.3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(16.0, 0.0, 0.0, 1.0);//right
    glTranslatef(12.3,3.5,0);
    circle(.55,3.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glColor3f(1, .96, .93);
    glRotatef(-16.0, 0.0, 0.0, 1.0);//left border
    glTranslatef(-5.1,4.7,0);
    circle(.7,3.3);
    glPopMatrix();


    glPushMatrix();
    glColor3f(.85, .85, .80);
    //glColor3f(1, .96, .93);
    glRotatef(-16.0, 0.0, 0.0, 1.0);//left
    glTranslatef(-5.1,4.7,0);
    circle(.6,3.2);
    glPopMatrix();

//head


    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(3.68,17.35,0); //upper body border
    glRotatef(-20.0, 0.0, 0.0, 1.0);
    circle(3.67,3.10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, .96, .93);
    glTranslatef(3.68,17.35,0);  //upper body
    glRotatef(-20.0, 0.0, 0.0, 1.0);
    circle(3.5,2.86);
    glPopMatrix();

//eyes

    glPushMatrix();
    glColor3f(0, 0, 0);
    glRotatef(-0.5, 0.0, 0.0, 1.0);
    glTranslatef(5.0,17.5,0);
    glRotatef(10.5, 0.0, 0.0, 1.0);//left eye
    circle(.5,.6);//left leg
    glPopMatrix();


    glPushMatrix();
    glColor3f(0, 0, 0);
    glRotatef(-0.5, 0.0, 0.0, 1.0);
    glTranslatef(1.99,18.0,0);
    glRotatef(-20.5, 0.0, 0.0, 1.0);//right eye
    circle(.5,.6);//left leg
    glPopMatrix();


    glPushMatrix();
    glTranslatef(2.0,17.69,0);
    glRotatef(-10, 0.0, 0.0, 1.0);
    glColor3f(0, 0, 0);
    glRectf(3.5,0.25,0,0);
    glPopMatrix();


    glPopMatrix(); //last stack
    glFlush();

}



void init(void)
{
    glClearColor (0.96, .64, 0.38, 0.0);
    glOrtho(-100.0, 100.0, -100.0,100.0, -1.0, 1.0);

}


void spe_key(int key, int x, int y)
{
    switch (key)
    {

    case GLUT_KEY_LEFT:

        if(mx>=-100 && mx!=0)
        {
            mx -=2;
        }

        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:

        if(mx>=-100 && mx<=90)
        {
            mx +=2;
        }
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        if (my>=-70 && my!=0)
            my -=2;
        glutPostRedisplay();
        break;

    case GLUT_KEY_UP:
        if(my<=30)
            my +=2;
        glutPostRedisplay();
        break;
    default:
        break;
    }

}



int main()
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 600);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("baymax playing with ball");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutMainLoop();
    return 0;
}

