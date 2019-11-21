#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <windows.h>
#include <glut.h>

int col=0; //collision
int score=0;
int pause = 0;

//double x=0.01, y=0;

double MX[12]; //meteor x-axis
double MY[12]; //meteor y-axis

int dis=70; //meteor to meteor distance

float x=0; //rocket x
float y=0; //rock y
float s=15; // change position of whole rocket

double speed = 0.05;
double mult = 0.00001; //gradual increase value


void collision(){
    for(int i=0; i<12; ++i){
        if(MY[i]==2.5 && s==-15 && MX[i]<=40){
            col=1;
            printf("GAME OVER! \n");
        }
        if(MY[i]==2.5 && s==15 && MX[i]<=10){
            MX[i]=70*12+mult;
            score+=10;
            printf("Score: %d \n", score);
        }

        if(MY[i]==32.5 && s==15 && MX[i]<=40){
            col=1;
            printf("GAME OVER! \n");
        }
        if(MY[i]==32.5 && s==-15 && MX[i]<=10){
            MX[i]=70*12+mult;
            score+=10;
            printf("Score: %d \n", score);
        }
    }
}

void circle(float radius_x, float radius_y){
    int i = 0;
	float angle = 0.0;
	float PI=3.14159;

  // glColor3f(1, 1, 1);//white
	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();

}

void background(){

    glPushMatrix();

    glTranslatef(50,30,0);

    glPushMatrix();
    glColor3f(0.57, 0.50, 0.50);
    glTranslatef(-10,60,0);
    circle(2,2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.57, 0.57, 0.57);
    glTranslatef(80,-60,0);
    circle(3,3);
    glTranslatef(5,-15,0);
    circle(3,3);
    glTranslatef(5,120,0);
    circle(3,3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.51, 0.52, 0.55);
    glTranslatef(-10,-25,0);
    circle(2,2);
    glTranslatef(-5,-30,0);
    circle(3,3);
    glTranslatef(40,60,0);
    circle(3,3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.74, 0.75, 0.69);
    glTranslatef(30,20,0);
    circle(3,3);
    glTranslatef(-10,-10,0);
    circle(1,1);
    glTranslatef(40,50,0);
    circle(2,2);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.57, 0.50, 0.50);
    glTranslatef(50,-15,0);
    circle(3,3);
    glTranslatef(15,-10,0);
    circle(2,2);
    glTranslatef(5,30,0);
    circle(1,1);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(60,50,0);
    circle(1,1);
    glTranslatef(50,-60,0);
    circle(3,3);
    glTranslatef(5,30,0);
    circle(2,2);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.74, 0.75, 0.69);
    glTranslatef(5,-10,0);
    circle(2,2);
    glTranslatef(5,-30,0);
    circle(3,3);
    glTranslatef(-5,60,0);
    circle(1,1);
    glPopMatrix();

    glPopMatrix();

 }

void drawRocket(){

   glColor3f(0, 0, 1); //BACK BOTTOM
	glBegin(GL_TRIANGLES);
	{
	    glVertex3f(x, y+25+s, 0);
	    glVertex3f(x+5, y+28+s, 0);
	    glVertex3f(x, y+30+s, 0);
    }
	glEnd();

	 glColor3f(0, 0, 1); //BACK TOP
	glBegin(GL_TRIANGLES);
	{
	    glVertex3f(x, y+30+s, 0);
	    glVertex3f(x+5, y+32+s, 0);
	    glVertex3f(x, y+35+s, 0);
    }
	glEnd();


    glColor3f(0.8, 0.8, 0.8); //BODY
	glBegin(GL_QUADS);
	{
	    glVertex3f(x+5, y+25+s, 0);
	    glVertex3f(x+25, y+25+s, 0);
	    glVertex3f(x+25, y+35+s, 0);
	    glVertex3f(x+5, y+35+s, 0);
	}
	glEnd();

    glColor3f(0, 0.5, 0.5); //HEAD
	glBegin(GL_TRIANGLES);
	{
	    glVertex3f(x+25, y+25+s, 0);
	    glVertex3f(x+35, y+30+s, 0);
	    glVertex3f(x+25, y+35+s, 0);
    }
	glEnd();

	glColor3f(0, 0.5, 0.5); //WING TOP
	glBegin(GL_TRIANGLES);
	{
	    glVertex3f(x+7, y+35+s, 0);
	    glVertex3f(x+16, y+35+s, 0);
	    glVertex3f(x+7, y+45+s, 0);
    }
	glEnd();

	glColor3f(0, 0.5, 0.5); //WING BOTTOM
	glBegin(GL_TRIANGLES);
	{
	    glVertex3f(x+7, y+25+s, 0);
	    glVertex3f(x+16, y+25+s, 0);
	    glVertex3f(x+7, y+15+s, 0);
    }
	glEnd();

}

void meteor(float mx, float my){
   glColor3f(1, 0.62, 0); //orange
	glBegin(GL_QUADS);
	{
	    glVertex3f(mx+15, my+15, 0);
	    glVertex3f(mx+20, my+15, 0);
	    glVertex3f(mx+20, my+20, 0);
	    glVertex3f(mx+15, my+20, 0);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
	    glVertex3f(mx+10, my+5, 0);
	    glVertex3f(mx+15, my+5, 0);
	    glVertex3f(mx+15, my+10, 0);
	    glVertex3f(mx+10, my+10, 0);
	}
	glEnd();

  glColor3f(0.5, 0.34, 0.13); //brown
	glBegin(GL_QUADS);
	{
	    glVertex3f(mx, my, 0);
	    glVertex3f(mx+25, my, 0);
	    glVertex3f(mx+25, my+25, 0);
	    glVertex3f(mx, my+25, 0);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
	    glVertex3f(mx-5, my+5, 0);
	    glVertex3f(mx+30, my+5, 0);
	    glVertex3f(mx+30, my+20, 0);
	    glVertex3f(mx-5, my+20, 0);
	}
	glEnd();

}

void guideline(){

    glBegin(GL_LINES);
    glColor3f(0, 1, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(1000, 0, 0);

	glColor3f(0, 1, 1);
	glVertex3f(0, 30, 0);
	glVertex3f(1000, 30, 0);

	glColor3f(0, 1, 1);
	glVertex3f(0, 60, 0);
	glVertex3f(1000, 60, 0);
    glEnd();
}

void boom(){

    glColor3f(1, 0, 0); //red
	glBegin(GL_QUADS);
	{
	    glVertex3f(-500, -500, 0);
	    glVertex3f(500, -500, 0);
	    glVertex3f(500, 500, 0);
	    glVertex3f(-500, 500, 0);
	}
	glEnd();

	glColor3f(1, 1, 0);

}

void display(){
	glClearColor(0, 0, 0, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/***************************
	/ set-up camera (view) here
	****************************/

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(90,30,100,	90,30,0,	0,1,0);

	//guideline();
	//meteor(60, 32.5);
	//meteor(50, 2.5);

	if(col==1){
        boom();
	}else{
        for(int i=0; i<12; i++){
            meteor(MX[i], MY[i]);
        }
        drawRocket();
        background();
	}

	glutSwapBuffers();
}

void move(){
   speed+=mult;
   for(int i=0; i<12; ++i){
        MX[i]-=speed;
    }
}

void specialKeyListener(int key, int x, int y){
    if(col==0){
	if (key == GLUT_KEY_UP){
		if(s!=15){
            s=15;
        }
	}
	else if (key == GLUT_KEY_DOWN){
		if(s!=-15){
            s=-15;
        }
	}

	else if (key == GLUT_KEY_LEFT){
            if(pause!=1){
            pause=1;
            printf("Game paused\n");
            }
	}
	else if (key == GLUT_KEY_RIGHT){
            if(pause!=0){
            pause=0;
            printf("Game resumed\n");
            }
	}
    }
	else if (key == GLUT_KEY_PAGE_UP){

	}
	else if (key == GLUT_KEY_PAGE_DOWN){

	}
}

void animate(){

	if(col==0 && pause==0){
        collision();
        move();
	}

	glutPostRedisplay();
}

void init(){
    printf("Into Space\n");
    for(int i=0; i<12; ++i){
        MX[i]=dis;
        dis+=dis;

        if(i%2==0) MY[i]=2.5;
        else MY[i]=32.5;
    }

	glClearColor(0, 0, 0, 0);

	/************************
	/ set-up projection here
	************************/

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(70, 1.5, 0.1, 10000.0);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);

	glutInitWindowSize(750, 500);
	glutInitWindowPosition(50, 100);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Into Space");

	init();
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeyListener);
	glutIdleFunc(animate);
	glutMainLoop();

	return 0;
}

