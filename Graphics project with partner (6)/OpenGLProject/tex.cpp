#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <WINDOWS.H>
#include <glut.h>
#include <GLAux.h>

double a=0.0,b=0.0,c=15.0;
GLfloat	l_t=0;
GLuint texture[50];
void LoadGLTextures()
{
	AUX_RGBImageRec* TextureImage;

	glGenTextures(10,texture); ///aray of texture of size 10

	if (TextureImage = auxDIBImageLoad("wall3.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("wall.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("wall2.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

}

void quad()
{
    // Draw A Quad

           glBindTexture(GL_TEXTURE_2D, texture[0]);
           glBegin(GL_QUADS);


            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,8.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (left)

            //glColor3f(0.0f,1.0f,0.0f);

            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					    // Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (right)

            glEnd();

            glBindTexture(GL_TEXTURE_2D, texture[1]);
            glBegin(GL_QUADS);

            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,1.0f,1.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,1.0f,8.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Right front Of The Quad (bottom)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Right back Of The Quad (bottom)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);				    // Left back Of The Quad (bottom)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);				    // Left front Of The Quad (bottom)

           glEnd();

            glBindTexture(GL_TEXTURE_2D, texture[2]);
            glBegin(GL_QUADS);

            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);

            glTexCoord2f(0.0f,1.0f);
            glVertex3f(-1.0f,1.0f,8.0f);
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(1.0f,1.0f,8.0f);
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(1.0f,-1.0f,8.0f);
            glTexCoord2d(0.0f, 0.0f);
            glVertex3f(-1.0f,-1.0f,8.0f);


            /*glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,8.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Bottom Right Of The Quad (Front)
*/
        glEnd();

}


void init(void)
{
   LoadGLTextures();
   glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);      // GL_COLOR_BUFFER_BIT indicates that the buffer is currently enabled for color writing
   glMatrixMode(GL_PROJECTION);       // Specify which matrix is the current matrix mode
   glLoadIdentity();                  // Replace the current matrix with the identity matrix
   int w=glutGet(GLUT_WINDOW_WIDTH);
   int h=glutGet(GLUT_WINDOW_HEIGHT);
   gluPerspective(40,w/h,0.1,100);    // fovy specifies the field of view angle in degrees in y direction, aspect specifies aspect ratio that determines the field of view in the x direction, znear and zfar specifies the distance from viewer to the near and far clipping plane respectively (always positive)
   glMatrixMode(GL_MODELVIEW);       //  To allow transformation on 3D object

   glLoadIdentity();
   gluLookAt(                       //  eyex, eyey, eyez specify the position of the eye point, centerx, centery, centerz specify the position of reference point, upx, upy, upz specify the direction of up vector
               a,b,c,
               0,0,0,
               0,1,0
             );
   glPushMatrix();
       glRotatef(l_t,0.0f,1.0f,0.0f);

       glEnable(GL_TEXTURE_2D);
       quad();
       glDisable(GL_TEXTURE_2D);
    glPopMatrix();

   glFlush(); // Force execution of GL commands in finite time

}

void my_keyboard(unsigned char key, int p, int q)
{
switch (key)
{
    case 'f':  //front view
        a=0.0,b=0.0,c=15.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'l':  //left view
        a=-100.0,b=0.0,c=4.0,l_t=0.0;
        glutPostRedisplay();
		break;
    case 'r':  //right view
        a=100.0,b=0.0,c=5.0,l_t=0.0;
        glutPostRedisplay();
		break;
    case 'b':  //back view
        a=0.0,b=0.0,c=-15.0,l_t=0.0;
        glutPostRedisplay();
		break;
    case 't': //top view
        a=0.0,b=100.0,c=4.0,l_t=0.0;
        glutPostRedisplay();
		break;

    case 'm': //bottom view
        a=0.0,b=-100.0,c=5.0,l_t=0.0;
        glutPostRedisplay();
		break;
     default:
        break;
}
}

void spinDisplay_left(void)		//spin speed
{

    l_t =l_t+0.2;
    glutPostRedisplay();
}

void specialKeys(int key,int x,int y)
{
    if(key==GLUT_KEY_RIGHT)
           a+=0.02;
    else if(key==GLUT_KEY_LEFT)
            a-=0.02;
    else if(key==GLUT_KEY_UP)
            c--;
   else if(key==GLUT_KEY_DOWN)
            c++;
    glutPostRedisplay();
}

void mouse(int button, int state, int s, int t)
{

   switch (button)
   {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

int main()
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Texturing");
	init();
    glutSpecialFunc(specialKeys);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(my_keyboard);
    glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
