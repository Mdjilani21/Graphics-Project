#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <windows.h>
#include <glut.h>
#include <vector>

using namespace std;

int barx = -15,bary = -55;
double ballx = 0,bally = -46;
int temp1 = 0,temp2 = 0,temp3 = 0,temp4 = 0,temp5 = 0;
bool b = false;
double barballtouch = 0;
double speedx = 0.01,speedy = 0.02;
double barspeed = 6;


struct brick
{
    double x1;
    double x2;
    double y1;
    double y2;
    double R,G,B;
};

vector<brick> arr;

void drawBricks(){

    int i,j;
    int x = -66,y = 58;
	glBegin(GL_QUADS);
	{
	    for(i = 0; i <= 3; i++){
           for(j = 0; j < 6; j++){

                brick b;
                b.x1 = x;
                b.x2 = x+20;
                b.y1 = y;
                b.y2 = y+10;
                b.R = 0;
                b.G = 1;
                b.B = 1;

                arr.push_back(b);

                x += 22;


            }
            x = -66;
            y -= 11;
	    }

	}
	glEnd();
}


void printBricks(brick b){

    glColor3f(b.R, b.G, b.B);
	glBegin(GL_QUADS);
	{
        glVertex3f(b.x1, b.y1, 0);
        glVertex3f(b.x2, b.y1, 0);
        glVertex3f(b.x2, b.y2, 0);
        glVertex3f(b.x1, b.y2, 0);

	}
	glEnd();
}

void drawDown(){
    glColor3f(5, 0, 0);
    glBegin(GL_QUADS);
	{
        glVertex3f(-70, -70, 0);
        glVertex3f(70, -70, 0);
        glVertex3f(70, -55, 0);
        glVertex3f(-70, -55, 0);

	}
	glEnd();
}

void drawBar(){
    glColor3f(5, 5, 0);

    glBegin(GL_QUADS);
	{
        glVertex3f(barx, bary, 0);
        glVertex3f(barx+30, bary, 0);
        glVertex3f(barx+30, bary+5, 0);
        glVertex3f(barx, bary+5, 0);

	}
	glEnd();
}

void drawBall(){
    double t = 0.0;
	double a = 0.02;
	int r = 4;
	double PI_2 = 2*acos(-1);
	glColor3f(1, 1, 0);
	glBegin(GL_TRIANGLES);
	{
	    for(t = 0; t <= PI_2; t += a){
            glVertex3f(ballx, bally, 0);

            glVertex3f(r*cos(t-a)+ballx, r*sin(t-a)+bally, 0);
            glVertex3f(r*cos(t)+ballx, r*sin(t)+bally, 0);
	    }
	}
	glEnd();
}



void specialKeyListener(int key, int x, int y)
{

	if (key == GLUT_KEY_LEFT)
	{
	    if(barx >= -70)
            barx -= barspeed;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
	    if(barx <= 40)
		barx += barspeed;
	}
	else if (key == GLUT_KEY_UP)
	{
        b = true;

	}

}

void display()
{

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

	gluLookAt(0,0,100,	0,0,0,	0,1,0);

    drawBall();
    drawDown();
    drawBar();
    //drawBricks();
    for(int i = 0; i < arr.size(); i++){
        printBricks(arr[i]);
    }

	glutSwapBuffers();
}



void animate()
{


    if(b == true)
    {
        fflush(stdin);
        int xx = 0;

        if(ballx >= barx && ballx <= barx + 30 && bally >= bary && bally <= bary+5){
            barballtouch = abs(abs(barx+30)-abs(ballx));
            barballtouch = barballtouch/30; //normalization
            barballtouch = 1 - barballtouch;

            if(barballtouch >= 0.5){

                barballtouch = barballtouch;
                temp1 = 0;
                temp2 = 0;
                temp3 = 0;
                temp4 = 0;
                temp5 = 1;

            }
            else{
                barballtouch = -barballtouch;
                temp1 = 1;
                temp2 = 0;
                temp3 = 0;
                temp4 = 0;
                temp5 = 0;

            }

           // speedx = barballtouch/10;



            //printf("in at 5 \n");

        }

        else if(ballx <= 64.5 && ballx >= 63.5){
            temp1 = 1;
            temp2 = 0;
            temp3 = 0;
            temp4 = 0;
            temp5 = 0;

        }
        else if(ballx >= -63.5 && ballx <= -62.5 ){
            temp1 = 0;
            temp2 = 1;
            temp3 = 0;
            temp4 = 0;
            temp5 = 0;
        }

        else if(bally <= 64.5 && bally >= 63.5){
            temp1 = 0;
            temp2 = 0;
            temp3 = 1;
            temp4 = 0;
            temp5 = 0;
        }
        else if(bally >= -64.5 && bally <= -63.5){
            temp1 = 0;
            temp2 = 0;
            temp3 = 0;
            temp4 = 1;
            temp5 = 0;
        }
        else{
            for(int i = 0; i < arr.size(); i++){
                if(ballx >= arr[i].x1 && ballx <= arr[i].x2 && bally >= arr[i].y1 && bally <= arr[i].y2){
                    temp1 = 0;
                    temp2 = 0;
                    temp3 = 1;
                    temp4 = 0;
                    temp5 = 0;

                    arr.erase(arr.begin() + i);
                }
                else if(ballx >= arr[i].x1 && ballx <= arr[i].x2 && bally >= arr[i].y1+10 && bally <= arr[i].y2+10){
                    temp1 = 1;
                    temp2 = 0;
                    temp3 = 0;
                    temp4 = 0;
                    temp5 = 0;

                    arr.erase(arr.begin() + i);
                }
            }
        }
        //printf(" %d %d %d %d \n",temp1,temp2,temp3,temp4);
        //printf("%f %f \n",ballx,bally);

        if(temp1 == 1){
            ballx -= speedx;
            bally += speedy;
            //printf("11: %f %f \n",ballx,bally);
            //printf("in at 11111 \n");
        }
        else if(temp2 == 1){
            ballx += speedx;
            bally -= speedy;
            //printf("22: %f %f \n",ballx,bally);
            //printf("in at 22222 \n");
        }

        else if(temp3 == 1){
            ballx -= speedx;
            bally -= speedy;
            //printf("33: %f %f \n",ballx,bally);
            //printf("in at 33333 \n");
        }

        else if(temp5 == 1){

            ballx += (speedx);
            bally += speedy;
            //printf("in at 55555 \n");

        }

        else if(temp4 == 1){
            exit(0);

            //ballx += speedx;
            //bally += speedy;
            //printf("44: %f %f \n",ballx,bally);
        }

        if(temp1 == 0 && temp2 == 0 && temp3 == 0 && temp4 == 0 && temp5 == 0){
            ballx += speedx;
            bally += speedy;
            //printf("in \n");
        }
        fflush(stdout);

    }
	glutPostRedisplay();

}

void init()
{



    glClearColor(0, 0, 0, 0);

	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();


	gluPerspective(70, 1, 0.1, 10000.0);

}

int main(int argc, char **argv)
{
	//initialize the GLUT library
	glutInit(&argc, argv);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("Bricks Breaker");

	//codes for initialization
	init();

	//enable Depth Testing
	glEnable(GL_DEPTH_TEST);

	//display callback function
	drawBricks();
	glutDisplayFunc(display);

	glutSpecialFunc(specialKeyListener);

	glutIdleFunc(animate);

	//The main loop of OpenGL
	glutMainLoop();

	return 0;
}
